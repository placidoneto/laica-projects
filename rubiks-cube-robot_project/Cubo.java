
public class Cubo {

    private Face front;
    private Face back;
    private Face top;
    private Face bottom;
    private Face left;
    private Face rigth;
    private int aux1;
    private int aux2;

    int[][] matriz = {{1, 1, 1}, {2, 2, 2}, {3, 3, 3}};

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

    public void rightTurnRight90() {
        rigth.turnRight90();
        int aux1[] = top.getRightI();
        int aux2[] = back.getLeftI();
        int aux3[] = bottom.getRight();
        top.setRight(front.getRight());
        back.setLeft(aux1);
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

    public void bottomTurnRight90() {
        bottom.turnRight90();
        int aux1[] = front.getBottom();
        int aux2[] = rigth.getBottom();
        int aux3[] = back.getBottom();
        front.setBottom(left.getBottom());
        rigth.setBottom(aux1);
        back.setBottom(aux2);
        left.setBottom(aux3);
    }

    public void bottomTurn180() {
        bottomTurnRight90();
        bottomTurnRight90();
    }

    public void bottomTurnLeft90() {
        bottomTurnRight90();
        bottomTurnRight90();
        bottomTurnRight90();
    }

    public void backTurnRight90() {
        back.turnRight90();
        int aux1[] = top.getTopI();
        int aux2[] = left.getLeft();
        int aux3[] = bottom.getBottomI();
        top.setTop(rigth.getRight());
        left.setLeft(aux1);
        bottom.setBottom(aux2);
        rigth.setRight(aux3);
    }

    public void backTurn180() {
        backTurnRight90();
        backTurnRight90();
    }

    public void backTurnLeft90() {
        backTurnRight90();
        backTurnRight90();
        backTurnRight90();
    }

    public void topTurnRight90() {
        top.turnRight90();
        int aux1[] = back.getTop();
        int aux2[] = rigth.getTop();
        int aux3[] = front.getTop();
        back.setTop(left.getTop());
        rigth.setTop(aux1);
        front.setTop(aux2);
        left.setTop(aux3);
    }

    public void topTurn180() {
        topTurnRight90();
        topTurnRight90();

    }

    public void topTurnLeft90() {
        topTurnRight90();
        topTurnRight90();
        topTurnRight90();
    }

    public void leftTurnRight90() {
        left.turnRight90();
        int aux1[] = top.getLeft();
        int aux2[] = front.getLeft();
        int aux3[] = bottom.getLeftI();
        top.setLeft(back.getRightI());
        front.setLeft(aux1);
        bottom.setLeft(aux2);
        back.setRight(aux3);
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
