
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

    
    public void rightClock(){
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
    
    public void rightClock180(){
        rightClock();
        rightClock();
        historyMoviments += "rightClock180\n";
    }

    public void rightIClock(){
        rightClock();
        rightClock();
        rightClock();
        historyMoviments += "rightIClock\n";
    }
    
    
    public void leftClock(){
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
    
    public void leftClock180(){
        leftClock();
        leftClock();
        historyMoviments += "leftClock180\n";
    }

    public void leftIClock(){
        leftClock();
        leftClock();
        leftClock();
        historyMoviments += "leftIClock\n";
    }
    
    
    public void topClock(){
        
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
    
    public void topClock180(){
        topClock();
        topClock();
        historyMoviments += "topClock180\n";
    }

    public void topIClock(){
        topClock();
        topClock();
        topClock();
        historyMoviments += "topIClock\n";
    }
    
    public void bottomClock(){
        bottom.turnIClock();
        int aux1[] = rigth.getBottom();
        int aux2[] = front.getBottom();
        int aux3[] = left.getBottomI();
        rigth.setBottom(back.getBottomI());
        front.setBottom(aux1);
        left.setBottom(aux2);
        back.setBottom(aux3);
        historyMoviments += "bottomClock\n";
    }
    
    public void bottomClock180(){
        bottomClock();
        bottomClock();
        historyMoviments += "bottomClock180\n";
    }

    public void bottomIClock(){
        bottomClock();
        bottomClock();
        bottomClock();
        historyMoviments += "bottomIClock\n";
    }
    
    
    public void backClock(){
        back.turnClock();
        int aux1[] = top.getTop();
        int aux2[] = rigth.getRightI();
        int aux3[] = bottom.getBottom();
        top.setTop(left.getLeftI());
        rigth.setRight(aux1);
        bottom.setBottom(aux2);
        left.setLeft(aux3);
        historyMoviments += "backClock\n";
    }
    
    public void backClock180(){
        backClock();
        backClock();
        historyMoviments += "backClock180\n";
    }

    public void backIClock(){
        backClock();
        backClock();
        backClock();
        historyMoviments += "backIClock\n";

    }
    
 
    public void exibir_Front() {
        int[][] matriz_front = front.getFace();
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                System.out.print(matriz_front[i][j] + " ");
            }
            System.out.println("");
        }
    }

    public void exibir_Left() {
        int matriz_left[][] = left.getFace();
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                System.out.print(matriz_left[i][j] + " ");
            }
            System.out.println("");
        }
    }

    public void exibir_Right() {
        int matriz_right[][] = rigth.getFace();
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                System.out.print(matriz_right[i][j] + " ");
            }
            System.out.println("");
        }
    }

    public void exibir_Top() {
        int matriz_top[][] = top.getFace();
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                System.out.print(matriz_top[i][j] + " ");
            }
            System.out.println("");
        }
    }

    public void exibir_Back() {
        int matriz_back[][] = back.getFace();
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                System.out.print(matriz_back[i][j] + " ");
            }
            System.out.println("");
        }
    }

    public void exibir_Bottom() {
        int matriz_bottom[][] = bottom.getFace();
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                System.out.print(matriz_bottom[i][j] + " ");
            }
            System.out.println("");
        }
    }

}
