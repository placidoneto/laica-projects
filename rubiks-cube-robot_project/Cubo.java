
public class Cubo {

    private Face front;
    private Face back;
    private Face top;
    private Face bottom;
    private Face left;
    private Face rigth;
    private int aux1;
    private int aux2;
    String historyMoviments = "";


    public String getHistoryMoviments() {
        return historyMoviments;
    }
    

    public Cubo(Face front, Face back, Face top, Face bottom, Face left, Face rigth) {
        this.front = front;
        this.back = back;
        this.top = top;
        this.bottom = bottom;
        this.left = left;
        this.rigth = rigth;
    }

    public void frontClock() {
        front.turnClock();
        int aux1[] = top.getBottom();
        int aux2[] = rigth.getLeftI();
        int aux3[] = bottom.getTop();
        top.setBottom(left.getRightI());
        rigth.setLeft(aux1);
        bottom.setTop(aux2);
        left.setRight(aux3);
        historyMoviments += "frontClock\n";
    }

    public void frontClock180() {
        frontClock();
        frontClock();
        historyMoviments += "frontClock180\n";
    }

    public void frontIClock() {
        frontClock();
        frontClock();
        frontClock();
        historyMoviments += "frontIClock\n";
    }

    public void rightClock() {
        rigth.turnClock();
        int aux1[] = top.getRightI();
        int aux2[] = back.getRightI();
        int aux3[] = bottom.getRight();
        top.setRight(front.getRight());
        back.setRight(aux1);
        bottom.setRight(aux2);
        front.setRight(aux3);
        historyMoviments += "rightClock\n";
    }

    public void rightClock180() {
        rightClock();
        rightClock();
        historyMoviments += "rightClock180\n";
    }

    public void rightIClock() {
        rightClock();
        rightClock();
        rightClock();
        historyMoviments += "rightIClock\n";
    }

    public void leftClock() {
        left.turnClock();
        int aux1[] = top.getLeft();
        int aux2[] = front.getLeft();
        int aux3[] = bottom.getLeftI();
        top.setLeft(back.getLeftI());
        front.setLeft(aux1);
        bottom.setLeft(aux2);
        back.setLeft(aux3);
        historyMoviments += "leftClock\n";
    }

    public void leftClock180() {
        leftClock();
        leftClock();
        historyMoviments += "leftClock180\n";
    }

    public void leftIClock() {
        leftClock();
        leftClock();
        leftClock();
        historyMoviments += "leftIClock\n";
    }

    public void bottomIClock() {
        bottom.turnIClock();
        int aux1[] = rigth.getBottom();
        int aux2[] = front.getBottom();
        int aux3[] = left.getBottomI();
        rigth.setBottom(back.getBottomI());
        front.setBottom(aux1);
        left.setBottom(aux2);
        back.setBottom(aux3);
        historyMoviments += "bottomIClock\n";
    }

    public void bottomClock180() {
        bottomIClock();
        bottomIClock();
        historyMoviments += "bottomClock180\n";
    }

    public void bottomClock() {
        bottomIClock();
        bottomIClock();
        bottomIClock();
        historyMoviments += "bottomClock\n";
    }

    public void backIClock() {
        back.turnClock();
        int aux1[] = top.getTop();
        int aux2[] = rigth.getRightI();
        int aux3[] = bottom.getBottom();
        top.setTop(left.getLeftI());
        rigth.setRight(aux1);
        bottom.setBottom(aux2);
        left.setLeft(aux3);
        historyMoviments += "backIClock\n";
    }

    public void backClock180() {
        backIClock();
        backIClock();
        historyMoviments += "backClock180\n";
    }

    public void backClock() {
        backIClock();
        backIClock();
        backIClock();
        historyMoviments += "backClock\n";

    }

    public void topClock() {

        top.turnClock();
        int aux1[] = rigth.getTop();
        int aux2[] = front.getTop();
        int aux3[] = left.getTopI();
        rigth.setTop(back.getTopI());
        front.setTop(aux1);
        left.setTop(aux2);
        back.setTop(aux3);
        historyMoviments += "topClock\n";
    }

    public void topClock180() {
        topClock();
        topClock();
        historyMoviments += "topClock180\n";
    }

    public void topIClock() {
        topClock();
        topClock();
        topClock();
        historyMoviments += "topIClock\n";
    }

    public void exibir_Cubo() {
        int matriz_front[][] = front.getFace();
        int matriz_left[][] = left.getFace();
        int matriz_right[][] = rigth.getFace();
        int matriz_top[][] = top.getFace();
        int matriz_back[][] = back.getFace();
        int matriz_bottom[][] = bottom.getFace();

        System.out.print("        ");
        System.out.println(matriz_top[0][0] + " " + matriz_top[0][1] + " " + matriz_top[0][2]);
        System.out.print("        ");
        System.out.println(matriz_top[1][0] + " " + matriz_top[1][1] + " " + matriz_top[1][2]);
        System.out.print("        ");
        System.out.println(matriz_top[2][0] + " " + matriz_top[2][1] + " " + matriz_top[2][2]);

        System.out.println(matriz_left[0][0] + " " + matriz_left[0][1] + " " + matriz_left[0][2] + "   " + matriz_front[0][0] + " " + matriz_front[0][1] + " " + matriz_front[0][2] + "   " + matriz_right[0][0] + " " + matriz_right[0][1] + " " + matriz_right[0][2] + "   " + matriz_back[0][2] + " " + matriz_back[0][1] + " " + matriz_back[0][0]);
        System.out.println(matriz_left[1][0] + " " + matriz_left[1][1] + " " + matriz_left[1][2] + "   " + matriz_front[1][0] + " " + matriz_front[1][1] + " " + matriz_front[1][2] + "   " + matriz_right[1][0] + " " + matriz_right[1][1] + " " + matriz_right[1][2] + "   " + matriz_back[1][2] + " " + matriz_back[1][1] + " " + matriz_back[1][0]);
        System.out.println(matriz_left[2][0] + " " + matriz_left[2][1] + " " + matriz_left[2][2] + "   " + matriz_front[2][0] + " " + matriz_front[2][1] + " " + matriz_front[2][2] + "   " + matriz_right[2][0] + " " + matriz_right[2][1] + " " + matriz_right[2][2] + "   " + matriz_back[2][2] + " " + matriz_back[2][1] + " " + matriz_back[2][0]);

        System.out.print("        ");
        System.out.println(matriz_bottom[0][0] + " " + matriz_bottom[0][1] + " " + matriz_bottom[0][2]);
        System.out.print("        ");
        System.out.println(matriz_bottom[1][0] + " " + matriz_bottom[1][1] + " " + matriz_bottom[1][2]);
        System.out.print("        ");
        System.out.println(matriz_bottom[2][0] + " " + matriz_bottom[2][1] + " " + matriz_bottom[2][2]);

    }

    
    public void cruzBranca() {
        
        int matriz_front[][] = front.getFace();
        int matriz_left[][] = left.getFace();
        int matriz_right[][] = rigth.getFace();
        int matriz_top[][] = top.getFace();
        int matriz_back[][] = back.getFace();
        int matriz_bottom[][] = bottom.getFace();

        //(1,3)
        if(matriz_bottom[1][2] == 1 && matriz_right[2][1] == 3) {
            bottomIClock();
        } else if(matriz_bottom[2][1] == 1 && matriz_back[2][1] == 3){
            bottomClock180();
        } else if(matriz_bottom[1][0] == 1 && matriz_left[2][1] == 3){
            bottomClock();
        } else if(matriz_front[2][1] == 1 && matriz_bottom[0][1] == 3){
            frontIClock();
            rightIClock();
            bottomIClock();
        } else if(matriz_front[1][2] == 1 && matriz_right[1][0] == 3){
            rightIClock();
            bottomIClock();
        } else if(matriz_front[0][1] == 1 && matriz_top[2][1] == 3){
            topClock();
            leftClock();
            frontIClock();
        }

    }

}
