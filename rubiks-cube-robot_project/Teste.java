//Autoras: Camila Jordana e Helora Dana

public class Teste {
     /*
     Verde(front): 3
     Branco(bottom): 1
     Vermelho(Left): 5
     Amarelo(top): 2
     Laranja(rigth): 4
     Azul(back): 6
     */

         
        int[][] front = new int[3][3];
        int[][] top = new int[3][3];
        int[][] right = new int[3][3];
        int[][] left = new int[3][3];
        int[][] bottom = new int[3][3];
        int[][] back = new int[3][3];

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                front[i][j] = 3;
            }
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                top[i][j] = 2;
            }
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                right[i][j] = 4;
            }
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                left[i][j] = 5;
            }
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                bottom[i][j] = 1;
            }
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                back[i][j] = 6;
            }
        }


        Face face_Front = new Face(front);
        Face face_Top = new Face(top);
        Face face_Right = new Face(right);
        Face face_Left = new Face(left);
        Face face_Bottom = new Face(bottom);
        Face face_Back = new Face(back);

        Cubo cubo = new Cubo(face_Front, face_Back, face_Top, face_Bottom, face_Left, face_Right);

        cubo.leftTurn180();
        cubo.backTurnRight90();
        cubo.bottomTurnLeft90();
        cubo.topTurnRight90();
        cubo.frontTurn180();
        cubo.backTurn180();
        cubo.topTurn180();
        cubo.leftTurnRight90();

        System.out.println("FRONT: ");
        cubo.exibir_Front();
        System.out.println("\nTOP: ");
        cubo.exibir_Top();
        System.out.println("\nRIGHT: ");
        cubo.exibir_Right();
        System.out.println("\nBOTTOM: ");
        cubo.exibir_Bottom();
        System.out.println("\nLEFT: ");
        cubo.exibir_Left();
        System.out.println("\nBACK: ");
        cubo.exibir_Back();

    }

}
