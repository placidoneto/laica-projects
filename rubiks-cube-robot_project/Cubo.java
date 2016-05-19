
public class Cubo {

    private Face front;
    private Face back;
    private Face top;
    private Face bottom;
    private Face left;
    private Face rigth;
    private int aux1;
    private int aux2;

    

    public Cubo(Face front, Face back, Face top, Face bottom, Face left, Face rigth) {
        this.front = front;
        this.back = back;
        this.top = top;
        this.bottom = bottom;
        this.left = left;
        this.rigth = rigth;
    }

    
    
    public void frontTurnRight90() {
        front.turnRight90();
        int aux1[] = top.getBottom();
        int aux2[] = rigth.getLeftI();
        int aux3[] = bottom.getTop();
        top.setBottom(left.getRightI());
        rigth.setLeft(aux1);
        bottom.setTop(aux2);
        left.setRight(aux3);
    }

    public void frontTurn180() {
        frontTurnRight90();
        frontTurnRight90();
    }

    public void frontTurnLeft90() {
        frontTurnRight90();
        frontTurnRight90();
        frontTurnRight90();
    }

    
    public void rightTurnRight90(){
        rigth.turnRight90();
        int aux1[] = top.getRightI();
        int aux2[] = back.getRightI();
        int aux3[] = bottom.getRight();
        top.setRight(front.getRight());
        back.setRight(aux1);
        bottom.setRight(aux2);
        front.setRight(aux3);
    }
    
    public void rightTurn180(){
        rightTurnRight90();
        rightTurnRight90();
    }

    public void rightTurnLeft90(){
        rightTurnRight90();
        rightTurnRight90();
        rightTurnRight90();
    }
    
    
    public void leftTurnRight90(){
        left.turnRight90();
        int aux1[] = top.getLeft();
        int aux2[] = front.getLeft();
        int aux3[] = bottom.getLeftI();
        top.setLeft(back.getLeftI());
        front.setLeft(aux1);
        bottom.setLeft(aux2);
        back.setLeft(aux3);
    }
    
    public void leftTurn180(){
        leftTurnRight90();
        leftTurnRight90();
    }

    public void leftTurnLeft90(){
        leftTurnRight90();
        leftTurnRight90();
        leftTurnRight90();
    }
    
    
    public void topTurnRight90(){
        
        top.turnRight90();
        int aux1[] = rigth.getTop();
        int aux2[] = front.getTop();
        int aux3[] = left.getTopI();
        rigth.setTop(back.getTopI());
        front.setTop(aux1);
        left.setTop(aux2);
        back.setTop(aux3);
    }
    
    public void topTurn180(){
        topTurnRight90();
        topTurnRight90();
    }

    public void topTurnLeft90(){
        topTurnRight90();
        topTurnRight90();
        topTurnRight90();
    }
    
    public void bottomTurnLeft90(){
        bottom.turnLeft90();
        int aux1[] = rigth.getBottom();
        int aux2[] = front.getBottom();
        int aux3[] = left.getBottomI();
        rigth.setBottom(back.getBottomI());
        front.setBottom(aux1);
        left.setBottom(aux2);
        back.setBottom(aux3);
    }
    
    public void bottomTurn180(){
        bottomTurnLeft90();
        bottomTurnLeft90();
    }

    public void bottomTurnRight90(){
        bottomTurnLeft90();
        bottomTurnLeft90();
        bottomTurnLeft90();
    }
    
    
    public void backTurnRight90(){
        back.turnRight90();
        int aux1[] = top.getTop();
        int aux2[] = rigth.getRightI();
        int aux3[] = bottom.getBottom();
        top.setTop(left.getLeftI());
        rigth.setRight(aux1);
        bottom.setBottom(aux2);
        left.setLeft(aux3);
    }
    
    public void backTurn180(){
        backTurnRight90();
        backTurnRight90();
    }

    public void backTurnLeft90(){
        backTurnRight90();
        backTurnRight90();
        backTurnRight90();

    }
    
    
    /*
    public void rightTurnRight90(){
        rigth.turnRight90();
        int aux1[] = top.getRightI();
        int aux2[] = back.getRightI();
        int aux3[] = bottom.getRight();
        top.setRight(front.getRight());
        back.setRight(aux1);
        bottom.setRight(aux2);
        front.setRight(aux3);
    }
    
    
    public void rightTurn180() {
        rightTurnRight90();
        rightTurnRight90();
        
    }

    public void rightTurnLeft90() {
        rightTurnRight90();
        rightTurnRight90();
        rightTurnRight90();
        
    }
    
    
    public void leftTurnRight90(){
        left.turnRight90();
        int aux1[] = top.getLeft();
        int aux2[] = back.getLeft();
        int aux3[] = bottom.getLeftI();
        top.setLeft(front.getLeftI());
        front.setLeft(aux1);
        bottom.setLeft(aux2);
        back.setLeft(aux3);
    }
    
     public void leftTurn180() {
        leftTurnRight90();
        leftTurnRight90();
        
    }

    public void leftTurnLeft90() {
        leftTurnRight90();
        leftTurnRight90();
        leftTurnRight90();
        
    }
*/
    
    
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
