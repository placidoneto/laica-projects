//Autoras: Camila Jordana e Helora Dana

import java.io.IOException;
import java.io.UnsupportedEncodingException;
import java.net.*;

public class RubiksSolver
{
/*
     Verde(Front): 3
     Azul(Back): 5
     Vermelho(Right): 4
     Laranja(Left): 6
     Branco(Top): 2
     Amarelo(Bottom): 1
*/

    private static void strToFace(String data, int[][] face) throws Exception
    {
        if (data.length() != 9)
            throw new Exception("Cannot read face state from: " + data + ". Invalid length.");
        for (int i = 0; i < data.length(); ++i)
        {
            face[i / 3][i % 3] = Integer.parseInt(new String(new char[]{ data.charAt(i) }));
        }
    }

    private static void send(DatagramSocket clientSocket, InetAddress ipaddress, String message) throws IOException {
        byte[] sendData = message.getBytes("UTF-8");
        DatagramPacket sendPacket = new DatagramPacket(sendData, message.length(), ipaddress, 4572);
        clientSocket.send(sendPacket);
    }

    private static void sendToFrontEnd(DatagramSocket clientSocket, InetAddress ipaddress, Cubo cubo) throws IOException, InterruptedException {
        String json;
        for (Rotation r : cubo.getHistory())
        {
            json = "{\"name\":\"rotate\", \"params\": { \"face\": \"" + r.getFaceAsString() + "\", \"times\": " + String.valueOf(r.getAmount()) + ", \"duration\":0.5}}";
            System.out.println(json);
            send(clientSocket, ipaddress, json);
            Thread.sleep(100);
        }
    }

    public static void main(String[] args) throws Exception
    {

        int[][] front = new int[3][3];
        int[][] top = new int[3][3];
        int[][] right = new int[3][3];
        int[][] left = new int[3][3];
        int[][] bottom = new int[3][3];
        int[][] back = new int[3][3];

        if (args.length < 6)
        {
            System.err.println("Invalid input.");
        }
        else
        {
            strToFace(args[0], front);
            strToFace(args[1], back);
            strToFace(args[2], right);
            strToFace(args[3], left);
            strToFace(args[4], top);
            strToFace(args[5], bottom);

            Face face_Front = new Face(front);
            Face face_Top = new Face(top);
            Face face_Right = new Face(right);
            Face face_Left = new Face(left);
            Face face_Bottom = new Face(bottom);
            Face face_Back = new Face(back);

            Cubo cubo = new Cubo(face_Front, face_Back, face_Top, face_Bottom, face_Left, face_Right);

            cubo.exibirCubo();

            DatagramSocket clientSocket = new DatagramSocket();
            InetAddress ipaddress = InetAddress.getByName("localhost");

            cubo.frontClock();
            cubo.leftIClock();
            cubo.topClock180();
            cubo.backIClock();
            cubo.bottomClock();
            cubo.rightClock();

            System.out.println("Embaralhando!");
            message(clientSocket, ipaddress, "Embaralhando");
            sendToFrontEnd(clientSocket, ipaddress, cubo);
            Thread.sleep(cubo.getHistory().size() * 500 + 1000);

            System.out.println("Resolvendo!");
            message(clientSocket, ipaddress, "Resolvendo");
            cubo.getHistory().clear();
            cubo.solve();
            cubo.primeiraCamada();
            cubo.exibirCubo();
            sendToFrontEnd(clientSocket, ipaddress, cubo);
        }
    }

    private static void message(DatagramSocket clientSocket, InetAddress ipaddress, String mensagem) throws InterruptedException, IOException {
        send(clientSocket, ipaddress, "{\"name\":\"message\",\"params\":{\"message\":\"" + mensagem + "\"}}");
        Thread.sleep(100);
    }
}
