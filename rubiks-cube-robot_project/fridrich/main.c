/* 
 * File:   main.c
 * Author: camila
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Face {
    int face[3][3];
};

typedef struct Cubo {
    struct Face front;
    struct Face top;
    struct Face bottom;
    struct Face right;
    struct Face left;
    struct Face back;
};

char historyMoviments[1000000];

int montando = 0;

int top_1[3];
int top_2[3];

int topI_1[3];
int topI_2[3];

int bottom_1[3];
int bottom_2[3];

int bottomI_1[3];
int bottomI_2[3];


int left_1[3];
int left_2[3];

int leftI_1[3];
int leftI_2[3];

int right_1[3];
int right_2[3];

int rightI_1[3];
int rightI_2[3];

int contMovimentos = 0;

void turnClock(int face[][3]) {
    int aux1, aux2;
    //girando os elementos das pontas
    aux1 = face[0][0];
    aux2 = face[0][2];
    face[0][2] = aux1;
    aux1 = face[2][2];
    face[2][2] = aux2;
    aux2 = face[2][0];
    face[2][0] = aux1;
    face[0][0] = aux2;
    //girando os elementos do meio
    aux1 = face[0][1];
    aux2 = face[1][2];
    face[1][2] = aux1;
    aux1 = face[2][1];
    face[2][1] = aux2;
    aux2 = face[1][0];
    face[1][0] = aux1;
    face[0][1] = aux2;
}

void turnClock180(int face[][3]) {
    turnClock(face);
    turnClock(face);
}

void turnIClock(int face[][3]) {
    turnClock(face);
    turnClock(face);
    turnClock(face);
}

void getTop(int face[][3], int v) {
    if (v == 1) {
        top_1[0] = face[0][0];
        top_1[1] = face[0][1];
        top_1[2] = face[0][2];
    } else {
        top_2[0] = face[0][0];
        top_2[1] = face[0][1];
        top_2[2] = face[0][2];
    }
}

void getTopI(int face[][3], int v) {
    if (v == 1) {
        topI_1[0] = face[0][2];
        topI_1[1] = face[0][1];
        topI_1[2] = face[0][0];
    } else {
        topI_2[0] = face[0][2];
        topI_2[1] = face[0][1];
        topI_2[2] = face[0][0];
    }
}

void setTop(int face[][3], int t[]) {
    face[0][0] = t[0];
    face[0][1] = t[1];
    face[0][2] = t[2];
}

void getBottom(int face[][3], int v) {
    if (v == 1) {
        bottom_1[0] = face[2][0];
        bottom_1[1] = face[2][1];
        bottom_1[2] = face[2][2];
    } else {
        bottom_2[0] = face[2][0];
        bottom_2[1] = face[2][1];
        bottom_2[2] = face[2][2];
    }
}

void getBottomI(int face[][3], int v) {
    if (v == 1) {
        bottomI_1[0] = face[2][2];
        bottomI_1[1] = face[2][1];
        bottomI_1[2] = face[2][0];
    } else {
        bottomI_2[0] = face[2][2];
        bottomI_2[1] = face[2][1];
        bottomI_2[2] = face[2][0];
    }
}

void setBottom(int face[][3], int b[]) {
    face[2][0] = b[0];
    face[2][1] = b[1];
    face[2][2] = b[2];
}

void getLeft(int face[][3], int v) {
    if (v == 1) {
        left_1[0] = face[0][0];
        left_1[1] = face[1][0];
        left_1[2] = face[2][0];
    } else {
        left_2[0] = face[0][0];
        left_2[1] = face[1][0];
        left_2[2] = face[2][0];
    }
}

void getLeftI(int face[][3], int v) {
    if (v == 1) {
        leftI_1[0] = face[2][0];
        leftI_1[1] = face[1][0];
        leftI_1[2] = face[0][0];
    } else {
        leftI_2[0] = face[2][0];
        leftI_2[1] = face[1][0];
        leftI_2[2] = face[0][0];
    }
}

void setLeft(int face[][3], int l[]) {
    face[0][0] = l[0];
    face[1][0] = l[1];
    face[2][0] = l[2];
}

void getRight(int face[][3], int v) {
    if (v == 1) {
        right_1[0] = face[0][2];
        right_1[1] = face[1][2];
        right_1[2] = face[2][2];
    } else {
        right_2[0] = face[0][2];
        right_2[1] = face[1][2];
        right_2[2] = face[2][2];
    }
}

void getRightI(int face[][3], int v) {
    if (v == 1) {
        rightI_1[0] = face[2][2];
        rightI_1[1] = face[1][2];
        rightI_1[2] = face[0][2];
    } else {
        rightI_2[0] = face[2][2];
        rightI_2[1] = face[1][2];
        rightI_2[2] = face[0][2];
    }
}

void setRight(int face[][3], int r[]) {
    face[0][2] = r[0];
    face[1][2] = r[1];
    face[2][2] = r[2];
}

//MÉTODOS DA CLASSE CUBO

void girandoFront(int left_f[][3], int front_f[][3], int right_f[][3], int top_f[][3], int bottom_f[][3], int back_f[][3]) {

    turnClock(front_f);
    getBottom(top_f, 1);
    getLeftI(right_f, 1);
    getTop(bottom_f, 1);
    getRightI(left_f, 1);
    setBottom(top_f, rightI_1);
    setLeft(right_f, bottom_1);
    setTop(bottom_f, leftI_1);
    setRight(left_f, top_1);
    // if (montando == 1) {
    //     strcat(historyMoviments, "frontClock\n");
    // }

}

void frontClock(int left_f[][3], int front_f[][3], int right_f[][3], int top_f[][3], int bottom_f[][3], int back_f[][3]) {
    girandoFront(left_f, front_f, right_f, top_f, bottom_f, back_f);
    if (montando == 1) {
        strcat(historyMoviments, "frontClock\n");
        contMovimentos++;
    }
}

void frontClock180(int left_f[][3], int front_f[][3], int right_f[][3], int top_f[][3], int bottom_f[][3], int back_f[][3]) {

    girandoFront(left_f, front_f, right_f, top_f, bottom_f, back_f);
    girandoFront(left_f, front_f, right_f, top_f, bottom_f, back_f);
    if (montando == 1) {
        strcat(historyMoviments, "frontClock180\n");
        contMovimentos++;
    }

}

void frontIClock(int left_f[][3], int front_f[][3], int right_f[][3], int top_f[][3], int bottom_f[][3], int back_f[][3]) {

    girandoFront(left_f, front_f, right_f, top_f, bottom_f, back_f);
    girandoFront(left_f, front_f, right_f, top_f, bottom_f, back_f);
    girandoFront(left_f, front_f, right_f, top_f, bottom_f, back_f);
    if (montando == 1) {
        strcat(historyMoviments, "frontIClock\n");
        contMovimentos++;
    }
}

void girandoRight(int left_f[][3], int front_f[][3], int right_f[][3], int top_f[][3], int bottom_f[][3], int back_f[][3]) {
    turnClock(right_f);
    getRightI(top_f, 1);
    getRightI(back_f, 2);
    getRight(bottom_f, 1);
    getRight(front_f, 2);
    setRight(top_f, right_2);
    setRight(back_f, rightI_1);
    setRight(bottom_f, rightI_2);
    setRight(front_f, right_1);
    // if (montando == 1) {
    //   strcat(historyMoviments, "rightClock\n");
    // }
}

void rightClock(int left_f[][3], int front_f[][3], int right_f[][3], int top_f[][3], int bottom_f[][3], int back_f[][3]) {
    girandoRight(left_f, front_f, right_f, top_f, bottom_f, back_f);
    if (montando == 1) {
        strcat(historyMoviments, "rightClock\n");
        contMovimentos++;
    }
}

void rightClock180(int left_f[][3], int front_f[][3], int right_f[][3], int top_f[][3], int bottom_f[][3], int back_f[][3]) {

    girandoRight(left_f, front_f, right_f, top_f, bottom_f, back_f);
    girandoRight(left_f, front_f, right_f, top_f, bottom_f, back_f);
    if (montando == 1) {
        strcat(historyMoviments, "rightClock180\n");
        contMovimentos++;
    }

}

void rightIClock(int left_f[][3], int front_f[][3], int right_f[][3], int top_f[][3], int bottom_f[][3], int back_f[][3]) {

    girandoRight(left_f, front_f, right_f, top_f, bottom_f, back_f);
    girandoRight(left_f, front_f, right_f, top_f, bottom_f, back_f);
    girandoRight(left_f, front_f, right_f, top_f, bottom_f, back_f);
    if (montando == 1) {
        strcat(historyMoviments, "rightIClock\n");
        contMovimentos++;
    }
    //historyMoviments += "rightIClock\n";
}

void girandoLeft(int left_f[][3], int front_f[][3], int right_f[][3], int top_f[][3], int bottom_f[][3], int back_f[][3]) {
    turnClock(left_f);
    getLeft(top_f, 1);
    getLeft(front_f, 2);
    getLeftI(bottom_f, 1);
    getLeftI(back_f, 2);
    setLeft(top_f, leftI_2);
    setLeft(front_f, left_1);
    setLeft(bottom_f, left_2);
    setLeft(back_f, leftI_1);
    //if (montando == 1) {
    //    strcat(historyMoviments, "leftClock\n");
    //}
}

void leftClock(int left_f[][3], int front_f[][3], int right_f[][3], int top_f[][3], int bottom_f[][3], int back_f[][3]) {
    girandoLeft(left_f, front_f, right_f, top_f, bottom_f, back_f);
    if (montando == 1) {
        strcat(historyMoviments, "leftClock\n");
        contMovimentos++;
    }
}

void leftClock180(int left_f[][3], int front_f[][3], int right_f[][3], int top_f[][3], int bottom_f[][3], int back_f[][3]) {

    girandoLeft(left_f, front_f, right_f, top_f, bottom_f, back_f);
    girandoLeft(left_f, front_f, right_f, top_f, bottom_f, back_f);
    if (montando == 1) {
        strcat(historyMoviments, "leftClock180\n");
        contMovimentos++;
    }
    //historyMoviments += "leftClock180\n";
}

void leftIClock(int left_f[][3], int front_f[][3], int right_f[][3], int top_f[][3], int bottom_f[][3], int back_f[][3]) {
    girandoLeft(left_f, front_f, right_f, top_f, bottom_f, back_f);
    girandoLeft(left_f, front_f, right_f, top_f, bottom_f, back_f);
    girandoLeft(left_f, front_f, right_f, top_f, bottom_f, back_f);
    if (montando == 1) {
        strcat(historyMoviments, "leftIClock\n");
        contMovimentos++;
    }
    //historyMoviments += "leftIClock\n";
}

void girandoBottom(int left_f[][3], int front_f[][3], int right_f[][3], int top_f[][3], int bottom_f[][3], int back_f[][3]) {
    turnIClock(bottom_f);
    getBottom(right_f, 1);
    getBottom(front_f, 2);
    getBottomI(left_f, 1);
    getBottomI(back_f, 2);
    setBottom(right_f, bottomI_2);
    setBottom(front_f, bottom_1);
    setBottom(left_f, bottom_2);
    setBottom(back_f, bottomI_1);
    //if (montando == 1) {
    //     strcat(historyMoviments, "bottomIClock\n");
    //}
}

void bottomIClock(int left_f[][3], int front_f[][3], int right_f[][3], int top_f[][3], int bottom_f[][3], int back_f[][3]) {
    girandoBottom(left_f, front_f, right_f, top_f, bottom_f, back_f);
    if (montando == 1) {
        strcat(historyMoviments, "bottomIClock\n");
        contMovimentos++;
    }
}

void bottomClock180(int left_f[][3], int front_f[][3], int right_f[][3], int top_f[][3], int bottom_f[][3], int back_f[][3]) {

    girandoBottom(left_f, front_f, right_f, top_f, bottom_f, back_f);
    girandoBottom(left_f, front_f, right_f, top_f, bottom_f, back_f);
    if (montando == 1) {
        strcat(historyMoviments, "bottomClock180\n");
        contMovimentos++;
    }
    //historyMoviments += "bottomClock180\n";
}

void bottomClock(int left_f[][3], int front_f[][3], int right_f[][3], int top_f[][3], int bottom_f[][3], int back_f[][3]) {

    girandoBottom(left_f, front_f, right_f, top_f, bottom_f, back_f);
    girandoBottom(left_f, front_f, right_f, top_f, bottom_f, back_f);
    girandoBottom(left_f, front_f, right_f, top_f, bottom_f, back_f);
    if (montando == 1) {
        strcat(historyMoviments, "bottomClock\n");
        contMovimentos++;
    }
    //historyMoviments += "bottomClock\n";
}

void girandoBack(int left_f[][3], int front_f[][3], int right_f[][3], int top_f[][3], int bottom_f[][3], int back_f[][3]) {
    turnClock(back_f);
    getTop(top_f, 1);
    getRightI(right_f, 1);
    getBottom(bottom_f, 1);
    getLeftI(left_f, 1);
    setTop(top_f, leftI_1);
    setRight(right_f, top_1);
    setBottom(bottom_f, rightI_1);
    setLeft(left_f, bottom_1);
    // if (montando == 1) {
    //     strcat(historyMoviments, "backIClock\n");
    // }

}

void backIClock(int left_f[][3], int front_f[][3], int right_f[][3], int top_f[][3], int bottom_f[][3], int back_f[][3]) {
    girandoBack(left_f, front_f, right_f, top_f, bottom_f, back_f);
    if (montando == 1) {
        strcat(historyMoviments, "backIClock\n");
        contMovimentos++;
    }
}

void backClock180(int left_f[][3], int front_f[][3], int right_f[][3], int top_f[][3], int bottom_f[][3], int back_f[][3]) {

    girandoBack(left_f, front_f, right_f, top_f, bottom_f, back_f);
    girandoBack(left_f, front_f, right_f, top_f, bottom_f, back_f);
    if (montando == 1) {
        strcat(historyMoviments, "backClock180\n");
        contMovimentos++;
    }
    //historyMoviments += "backClock180\n";
}

void backClock(int left_f[][3], int front_f[][3], int right_f[][3], int top_f[][3], int bottom_f[][3], int back_f[][3]) {

    girandoBack(left_f, front_f, right_f, top_f, bottom_f, back_f);
    girandoBack(left_f, front_f, right_f, top_f, bottom_f, back_f);
    girandoBack(left_f, front_f, right_f, top_f, bottom_f, back_f);
    if (montando == 1) {
        strcat(historyMoviments, "backClock\n");
        contMovimentos++;
    }
    //historyMoviments += "backClock\n";

}

void girandoTop(int left_f[][3], int front_f[][3], int right_f[][3], int top_f[][3], int bottom_f[][3], int back_f[][3]) {
    turnClock(top_f);
    getTop(right_f, 1);
    getTop(front_f, 2);
    getTopI(left_f, 1);
    getTopI(back_f, 2);
    setTop(right_f, topI_2);
    setTop(front_f, top_1);
    setTop(left_f, top_2);
    setTop(back_f, topI_1);
    //   if (montando == 1) {
    //     strcat(historyMoviments, "topClock\n");
    // }

}

void topClock(int left_f[][3], int front_f[][3], int right_f[][3], int top_f[][3], int bottom_f[][3], int back_f[][3]) {
    girandoTop(left_f, front_f, right_f, top_f, bottom_f, back_f);
    if (montando == 1) {
        strcat(historyMoviments, "topClock\n");
        contMovimentos++;
    }
}

void topClock180(int left_f[][3], int front_f[][3], int right_f[][3], int top_f[][3], int bottom_f[][3], int back_f[][3]) {

    girandoTop(left_f, front_f, right_f, top_f, bottom_f, back_f);
    girandoTop(left_f, front_f, right_f, top_f, bottom_f, back_f);
    if (montando == 1) {
        strcat(historyMoviments, "topClock180\n");
        contMovimentos++;
    }
    //historyMoviments += "topClock180\n";
}

void topIClock(int left_f[][3], int front_f[][3], int right_f[][3], int top_f[][3], int bottom_f[][3], int back_f[][3]) {

    girandoTop(left_f, front_f, right_f, top_f, bottom_f, back_f);
    girandoTop(left_f, front_f, right_f, top_f, bottom_f, back_f);
    girandoTop(left_f, front_f, right_f, top_f, bottom_f, back_f);
    if (montando == 1) {
        strcat(historyMoviments, "topIClock\n");
        contMovimentos++;
    }
    //historyMoviments += "topIClock\n";
}

void cruz(int left_f[][3], int front_f[][3], int right_f[][3], int top_f[][3], int bottom_f[][3], int back_f[][3]) {

    //(1,3)
    if (bottom_f[1][2] == 1 && right_f[2][1] == 3) {
        bottomIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (bottom_f[2][1] == 1 && back_f[2][1] == 3) {
        bottomClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (bottom_f[1][0] == 1 && left_f[2][1] == 3) {
        bottomClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[2][1] == 1 && bottom_f[0][1] == 3) {
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        bottomIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[1][2] == 1 && right_f[1][0] == 3) {
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        bottomIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[0][1] == 1 && top_f[2][1] == 3) {
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[1][0] == 1 && left_f[1][2] == 3) {
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        bottomClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[1][2] == 1 && front_f[1][0] == 3) {
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[2][1] == 1 && bottom_f[1][0] == 3) {
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][1] == 1 && top_f[1][0] == 3) {
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[1][0] == 1 && back_f[1][0] == 3) {
        leftClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[1][0] == 1 && front_f[1][2] == 3) {
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[2][1] == 1 && bottom_f[1][2] == 3) {
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[1][2] == 1 && back_f[1][2] == 3) {
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[0][1] == 1 && top_f[1][2] == 3) {
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[2][1] == 1 && front_f[0][1] == 3) {
        frontClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[1][0] == 1 && left_f[0][1] == 3) {
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[1][2] == 1 && right_f[0][1] == 3) {
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[0][1] == 1 && back_f[0][1] == 3) {
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][1] == 1 && top_f[0][1] == 3) {
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[1][0] == 1 && left_f[1][0] == 3) {
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        bottomClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[1][2] == 1 && right_f[1][2] == 3) {
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        bottomIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[2][1] == 1 && bottom_f[2][1] == 3) {
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        bottomClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }

    //(1,6)
    if (bottom_f[2][1] == 1 && back_f[2][1] == 6) {
        backClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (bottom_f[1][2] == 1 && right_f[2][1] == 6) {
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[2][1] == 1 && bottom_f[1][0] == 6) {
        leftClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[1][2] == 1 && front_f[1][0] == 6) {
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][1] == 1 && top_f[1][0] == 6) {
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[1][0] == 1 && back_f[1][0] == 6) {
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[1][0] == 1 && front_f[1][2] == 6) {
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[0][1] == 1 && top_f[1][2] == 6) {
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[1][2] == 1 && back_f[1][2] == 6) {
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[2][1] == 1 && bottom_f[1][2] == 6) {
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[1][0] == 1 && left_f[1][2] == 6) {
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[0][1] == 1 && top_f[2][1] == 6) {
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[1][2] == 1 && right_f[1][0] == 6) {
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[2][1] == 1 && front_f[0][1] == 6) {
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[1][0] == 1 && left_f[0][1] == 6) {
        leftClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[0][1] == 1 && back_f[0][1] == 6) {
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[1][2] == 1 && right_f[0][1] == 6) {
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[2][1] == 1 && bottom_f[2][1] == 6) {
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[1][0] == 1 && left_f[1][0] == 6) {
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[1][2] == 1 && right_f[1][2] == 6) {
        backClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][1] == 1 && top_f[0][1] == 6) {
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }

    //(1,5)
    if (bottom_f[1][2] == 1 && right_f[2][1] == 5) {
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[1][0] == 1 && back_f[1][0] == 5) {
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[1][2] == 1 && front_f[1][0] == 5) {
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][1] == 1 && top_f[1][0] == 5) {
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[1][0] == 1 && front_f[1][2] == 5) {
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[0][1] == 1 && top_f[1][2] == 5) {
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[1][2] == 1 && back_f[1][2] == 5) {
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[2][1] == 1 && bottom_f[1][2] == 5) {
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[1][0] == 1 && left_f[1][2] == 5) {
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[1][2] == 1 && right_f[1][0] == 5) {
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[0][1] == 1 && top_f[2][1] == 5) {
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[2][1] == 1 && front_f[0][1] == 5) {
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[1][0] == 1 && left_f[0][1] == 5) {
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[1][2] == 1 && right_f[0][1] == 5) {
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[0][1] == 1 && back_f[0][1] == 5) {
        backClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][1] == 1 && top_f[0][1] == 5) {
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[1][0] == 1 && left_f[1][0] == 5) {
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[1][2] == 1 && right_f[1][2] == 5) {
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[2][1] == 1 && bottom_f[2][1] == 5) {
        backClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }


    //(1,4)
    if (right_f[2][1] == 1 && bottom_f[1][2] == 4) {
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[1][0] == 1 && front_f[1][2] == 4) {
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[0][1] == 1 && top_f[1][2] == 4) {
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[1][2] == 1 && back_f[1][2] == 4) {
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[1][0] == 1 && left_f[1][2] == 4) {
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[1][2] == 1 && right_f[1][0] == 4) {
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[0][1] == 1 && top_f[2][1] == 4) {
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][1] == 1 && top_f[1][0] == 4) {
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[1][2] == 1 && front_f[1][0] == 4) {
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[1][0] == 1 && back_f[1][0] == 4) {
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[2][1] == 1 && front_f[0][1] == 4) {
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[1][2] == 1 && right_f[0][1] == 4) {
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[1][0] == 1 && left_f[0][1] == 4) {
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[0][1] == 1 && back_f[0][1] == 4) {
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[1][2] == 1 && right_f[1][2] == 4) {
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[1][0] == 1 && left_f[1][0] == 4) {
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][1] == 1 && top_f[0][1] == 4) {
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }

}

void f2l(int left_f[][3], int front_f[][3], int right_f[][3], int top_f[][3], int bottom_f[][3], int back_f[][3]) {

    // EASY CASES (1-4)
    // 1º (U (R U' R')) - 16 possibilidades

    if (front_f[0][2] == 1 && top_f[2][2] == 3 && right_f[0][0] == 4 && top_f[1][2] == 3 && right_f[0][1] == 4) {
        // 1ª possibilidade
        printf("[EASY CASE 1º CASO]  1ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][2] == 1 && top_f[2][0] == 3 && front_f[0][0] == 4 && top_f[2][1] == 3 && front_f[0][1] == 4) {
        //2ª possibilidade
        printf("[EASY CASE 1º CASO] [TESTE] 2ª possibilidade\n");
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][0] == 1 && top_f[0][0] == 3 && top_f[1][0] == 3 && left_f[0][0] == 4 && left_f[0][1] == 4) {
        //3ª possibilidade
        printf("[EASY CASE 1º CASO] [TESTE] 3ª possibilidade\n");
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[0][2] == 1 && top_f[0][1] == 3 && top_f[0][2] == 3 && back_f[0][2] == 4 && back_f[0][1] == 4) {
        //4ª possibilidade
        printf("[EASY CASE 1º CASO] [TESTE] 4ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[0][2] == 1 && top_f[2][2] == 6 && top_f[1][2] == 6 && right_f[0][0] == 3 && right_f[0][1] == 3) {
        // 5ª possibilidade
        printf("[EASY CASE 1º CASO] [TESTE] 5ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][2] == 1 && top_f[2][0] == 6 && top_f[2][1] == 6 && front_f[0][0] == 3 && front_f[0][1] == 3) {
        //6ª possibilidade
        printf("[EASY CASE 1º CASO] [TESTE] 6ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][0] == 1 && top_f[0][0] == 6 && top_f[1][0] == 6 && left_f[0][0] == 3 && left_f[0][1] == 3) {
        //7ª possibilidade
        printf("[EASY CASE 1º CASO] [TESTE] 7ª possibilidade\n");
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[0][2] == 1 && top_f[0][2] == 6 && top_f[0][1] == 6 && back_f[0][1] == 3 && back_f[0][2] == 3) {
        //8ª possibilidade
        printf("[EASY CASE 1º CASO] [TESTE] 8ª possibilidade\n");
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[0][2] == 1 && top_f[2][2] == 5 && top_f[1][2] == 5 && right_f[0][0] == 6 && right_f[0][1] == 6) {
        //9ª possibilidade
        printf("[EASY CASE 1º CASO] [TESTE] 9ª possibilidade\n");
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][2] == 1 && top_f[2][0] == 5 && top_f[2][1] == 5 && front_f[0][0] == 6 && front_f[0][1] == 6) {
        //10ª possibilidade
        printf("[EASY CASE 1º CASO] [TESTE] 10ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][0] == 1 && top_f[0][0] == 5 && top_f[1][0] == 5 && left_f[0][0] == 6 && left_f[0][1] == 6) {
        //11ª possibilidade
        printf("[EASY CASE 1º CASO] [TESTE] 11ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[0][2] == 1 && top_f[0][1] == 5 && top_f[0][2] == 5 && back_f[0][1] == 6 && back_f[0][2] == 6) {
        //12ª possibilidade
        printf("[EASY CASE 1º CASO] [TESTE] 12ª possibilidade\n");
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[0][2] == 1 && top_f[2][2] == 4 && top_f[1][2] == 4 && right_f[0][0] == 5 && right_f[0][1] == 5) {
        //13ª possibilidade
        printf("[EASY CASE 1º CASO] [TESTE] 13ª possibilidade\n");
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][2] == 1 && top_f[2][0] == 4 && top_f[2][1] == 4 && front_f[0][0] == 5 && front_f[0][1] == 5) {
        //14ª possibilidade
        printf("[EASY CASE 1º CASO] [TESTE] 14ª possibilidade\n");
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][0] == 1 && top_f[0][0] == 4 && top_f[1][0] == 4 && left_f[0][0] == 5 && left_f[0][1] == 5) {
        //15ª possibilidade
        printf("[EASY CASE 1º CASO] [TESTE] 15ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[0][2] == 1 && top_f[0][1] == 4 && top_f[0][2] == 4 && back_f[0][1] == 5 && back_f[0][2] == 5) {
        //16ª possibilidade
        printf("[EASY CASE 1º CASO] [TESTE] 16ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }

    // FIM do 1º (U (R U' R')) 


    // 2º (y' (R' U' R)) ==> F'U'F  - 16 possibilidades

    if (front_f[0][2] == 1 && top_f[2][2] == 3 && right_f[0][0] == 4 && top_f[1][0] == 4 && left_f[0][1] == 3) {
        //1ª possibilidade
        printf("[EASY CASE 2º CASO] [TESTE] 1ª possibilidade\n");
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][2] == 1 && top_f[2][0] == 3 && front_f[0][0] == 4 && top_f[0][1] == 4 && back_f[0][1] == 3) {
        //2ª possibilidade
        printf("[EASY CASE 2º CASO] [TESTE] 2ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][0] == 1 && left_f[0][0] == 4 && top_f[0][0] == 3 && top_f[1][2] == 4 && right_f[0][1] == 3) {
        //3ª possibilidade
        printf("[EASY CASE 2º CASO] [TESTE] 3ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[0][2] == 1 && top_f[0][2] == 3 && back_f[0][2] == 4 && top_f[2][1] == 4 && front_f[0][1] == 3) {
        //4ª possibilidade
        printf("[EASY CASE 2º CASO] [TESTE] 4ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][2] == 1 && top_f[2][0] == 6 && front_f[0][0] == 3 && top_f[0][1] == 3 && back_f[0][1] == 6) {
        //5ª possibilidade
        printf("[EASY CASE 2º CASO] [TESTE] 5ª possibilidade\n");
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][0] == 1 && left_f[0][0] == 3 && top_f[0][0] == 6 && top_f[1][2] == 3 && right_f[0][1] == 6) {
        //6ª possibilidade
        printf("[EASY CASE 2º CASO] [TESTE] 6ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[0][2] == 1 && top_f[0][2] == 6 && back_f[0][2] == 3 && top_f[2][1] == 3 && front_f[0][1] == 6) {
        //7ª possibilidade
        printf("[EASY CASE 2º CASO] [TESTE] 7ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[0][2] == 1 && top_f[2][2] == 6 && right_f[0][0] == 3 && top_f[1][0] == 3 && left_f[0][1] == 6) {
        //8ª possibilidade
        printf("[EASY CASE 2º CASO] [TESTE] 8ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][0] == 1 && top_f[0][0] == 5 && left_f[0][0] == 6 && top_f[1][2] == 6 && right_f[0][1] == 5) {
        //9ª possibilidade
        printf("[EASY CASE 2º CASO] [TESTE] 9ª possibilidade\n");
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[0][2] == 1 && top_f[0][2] == 5 && back_f[0][2] == 6 && top_f[2][1] == 6 && front_f[0][1] == 5) {
        //10ª possibilidade
        printf("[EASY CASE 2º CASO] [TESTE] 10ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[0][2] == 1 && top_f[2][2] == 5 && right_f[0][0] == 6 && top_f[1][0] == 6 && left_f[0][1] == 5) {
        //11ª possibilidade
        printf("[EASY CASE 2º CASO] [TESTE] 11ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][2] == 1 && top_f[2][0] == 5 && front_f[0][0] == 6 && top_f[0][1] == 6 && back_f[0][1] == 5) {
        //12ª possibilidade
        printf("[EASY CASE 2º CASO] [TESTE] 12ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[0][2] == 1 && top_f[0][2] == 4 && back_f[0][2] == 5 && top_f[2][1] == 5 && front_f[0][1] == 4) {
        //13ª possibilidade
        printf("[EASY CASE 2º CASO] [TESTE] 13ª possibilidade\n");
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[0][2] == 1 && top_f[2][2] == 4 && right_f[0][0] == 5 && top_f[1][0] == 5 && left_f[0][1] == 4) {
        //14ª possibilidade
        printf("[EASY CASE 2º CASO] [TESTE] 14ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][2] == 1 && top_f[2][0] == 4 && front_f[0][0] == 5 && top_f[0][1] == 5 && back_f[0][1] == 4) {
        //15ª possibilidade
        printf("[EASY CASE 2º CASO] [TESTE] 15ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][0] == 1 && top_f[0][0] == 4 && left_f[0][0] == 5 && top_f[1][2] == 5 && right_f[0][1] == 4) {
        //16ª possibilidade
        printf("[EASY CASE 2º CASO] [TESTE] 16ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }

    // FIM do 2º (y' (R' U' R)) ==> F'U'F


    // 3º (y' U' (R' U R)) ==> U' F' U F  - 16 possibilidades

    if (top_f[2][1] == 4 && top_f[2][2] == 4 && right_f[0][0] == 1 && front_f[0][1] == 3 && front_f[0][2] == 3) {
        //1ª possibilidade
        printf("[EASY CASE 3º CASO] [TESTE] 1ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[0][0] == 1 && top_f[2][0] == 4 && top_f[1][0] == 4 && left_f[0][1] == 3 && left_f[0][2] == 3) {
        //2ª possibilidade
        printf("[EASY CASE 3º CASO] [TESTE] 2ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][0] == 1 && top_f[0][0] == 4 && top_f[0][1] == 4 && back_f[0][0] == 3 && back_f[0][1] == 3) {
        //3ª possibilidade
        printf("[EASY CASE 3º CASO] [TESTE] 3ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][2] == 1 && top_f[0][2] == 4 && top_f[1][2] == 4 && right_f[0][1] == 3 && right_f[0][2] == 3) {
        //4ª possibilidade
        printf("[EASY CASE 3º CASO] [TESTE] 4ª possibilidade\n");
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[0][0] == 1 && top_f[1][0] == 3 && top_f[2][0] == 3 && left_f[0][1] == 6 && left_f[0][2] == 6) {
        //5ª possibilidade
        printf("[EASY CASE 3º CASO] [TESTE] 5ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][0] == 1 && top_f[0][0] == 3 && top_f[0][1] == 3 && back_f[0][0] == 6 && back_f[0][1] == 6) {
        //6ª possibilidade
        printf("[EASY CASE 3º CASO] [TESTE] 6ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][2] == 1 && top_f[0][2] == 3 && top_f[1][2] == 3 && right_f[0][1] == 6 && right_f[0][2] == 6) {
        //7ª possibilidade
        printf("[EASY CASE 3º CASO] [TESTE] 7ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[0][0] == 1 && top_f[2][1] == 3 && top_f[2][2] == 3 && front_f[0][1] == 6 && front_f[0][2] == 6) {
        //8ª possibilidade
        printf("[EASY CASE 3º CASO] [TESTE] 8ª possibilidade\n");
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][0] == 1 && top_f[0][0] == 6 && top_f[0][1] == 6 && back_f[0][0] == 5 && back_f[0][1] == 5) {
        //9ª possibilidade
        printf("[EASY CASE 3º CASO] [TESTE] 9ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][2] == 1 && top_f[0][2] == 6 && top_f[1][2] == 6 && right_f[0][1] == 5 && right_f[0][2] == 5) {
        //10ª possibilidade
        printf("[EASY CASE 3º CASO] [TESTE] 10ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[0][0] == 1 && top_f[2][1] == 6 && top_f[2][2] == 6 && front_f[0][1] == 5 && front_f[0][2] == 5) {
        //11ª possibilidade
        printf("[EASY CASE 3º CASO] [TESTE] 11ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[0][0] == 1 && top_f[1][0] == 6 && top_f[2][0] == 6 && left_f[0][1] == 5 && left_f[0][2] == 5) {
        //12ª possibilidade
        printf("[EASY CASE 3º CASO] [TESTE] 12ª possibilidade\n");
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][2] == 1 && top_f[0][2] == 5 && top_f[1][2] == 5 && right_f[0][1] == 4 && right_f[0][2] == 4) {
        //13ª possibilidade
        printf("[EASY CASE 3º CASO] [TESTE] 13ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[0][0] == 1 && top_f[2][1] == 5 && top_f[2][2] == 5 && front_f[0][1] == 4 && front_f[0][2] == 4) {
        //14ª possibilidade
        printf("[EASY CASE 3º CASO] [TESTE] 14ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[0][0] == 1 && top_f[1][0] == 5 && top_f[2][0] == 5 && left_f[0][1] == 4 && left_f[0][2] == 4) {
        //15ª possibilidade
        printf("[EASY CASE 3º CASO] [TESTE] 15ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][0] == 1 && top_f[0][0] == 5 && top_f[0][1] == 5 && back_f[0][0] == 4 && back_f[0][1] == 4) {
        //16ª possibilidade
        printf("[EASY CASE 3º CASO] [TESTE] 16ª possibilidade\n");
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }

    // FIM do 3º (y' U' (R' U R)) ==> U' F' U F


    // 4º (R U R')  - 16 possibilidades
    if (right_f[0][0] == 1 && top_f[2][2] == 4 && front_f[0][2] == 3 && top_f[0][1] == 3 && back_f[0][1] == 4) {
        //1ª possibilidade
        printf("[EASY CASE 4º CASO] [TESTE] 1ª possibilidade\n");
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[0][0] == 1 && top_f[2][0] == 4 && left_f[0][2] == 3 && top_f[1][2] == 3 && right_f[0][1] == 4) {
        //2ª possibilidade
        printf("[EASY CASE 4º CASO] [TESTE] 2ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][0] == 1 && top_f[0][0] == 4 && back_f[0][0] == 3 && top_f[2][1] == 3 && front_f[0][1] == 4) {
        //3ª possibilidade
        printf("[EASY CASE 4º CASO] [TESTE] 3ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][2] == 1 && top_f[0][2] == 4 && right_f[0][2] == 3 && top_f[1][0] == 3 && left_f[0][1] == 4) {
        //4ª possibilidade
        printf("[EASY CASE 4º CASO] [TESTE] 4ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[0][0] == 1 && top_f[2][0] == 3 && left_f[0][2] == 6 && top_f[1][2] == 6 && right_f[0][1] == 3) {
        //5ª possibilidade
        printf("[EASY CASE 4º CASO] [TESTE] 5ª possibilidade\n");
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][0] == 1 && top_f[0][0] == 3 && back_f[0][0] == 6 && top_f[2][1] == 6 && front_f[0][1] == 3) {
        //6ª possibilidade
        printf("[EASY CASE 4º CASO] [TESTE] 6ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][2] == 1 && top_f[0][2] == 3 && right_f[0][2] == 6 && top_f[1][0] == 6 && left_f[0][1] == 3) {
        //7ª possibilidade
        printf("[EASY CASE 4º CASO] [TESTE] 7ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[0][0] == 1 && top_f[2][2] == 3 && front_f[0][2] == 6 && top_f[0][1] == 6 && back_f[0][1] == 3) {
        //8ª possibilidade
        printf("[EASY CASE 4º CASO] [TESTE] 8ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][0] == 1 && top_f[0][0] == 6 && back_f[0][0] == 5 && top_f[2][1] == 5 && front_f[0][1] == 6) {
        //9ª possibilidade
        printf("[EASY CASE 4º CASO] [TESTE] 9ª possibilidade\n");
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][2] == 1 && top_f[0][2] == 6 && right_f[0][2] == 5 && top_f[1][0] == 5 && left_f[0][1] == 6) {
        //10ª possibilidade
        printf("[EASY CASE 4º CASO] [TESTE] 10ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[2][2] == 6 && front_f[0][2] == 5 && right_f[0][0] == 1 && top_f[0][1] == 5 && back_f[0][1] == 6) {
        //11ª possibilidade
        printf("[EASY CASE 4º CASO] [TESTE] 11ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[0][0] == 1 && top_f[2][0] == 6 && left_f[0][2] == 5 && top_f[1][2] == 5 && right_f[0][1] == 6) {
        //12ª possibilidade
        printf("[EASY CASE 4º CASO] [TESTE] 12ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[0][2] == 5 && right_f[0][2] == 4 && back_f[0][2] == 1 && top_f[1][0] == 4 && left_f[0][1] == 5) {
        //13ª possibilidade
        printf("[EASY CASE 4º CASO] [TESTE] 13ª possibilidade\n");
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[0][0] == 1 && top_f[2][2] == 5 && front_f[0][2] == 4 && top_f[0][1] == 4 && back_f[0][1] == 5) {
        //14ª possibilidade
        printf("[EASY CASE 4º CASO] [TESTE] 14ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[0][0] == 1 && top_f[2][0] == 5 && left_f[0][2] == 4 && top_f[1][2] == 4 && right_f[0][1] == 5) {
        //15ª possibilidade
        printf("[EASY CASE 4º CASO] [TESTE] 15ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][0] == 1 && top_f[0][0] == 5 && back_f[0][0] == 4 && top_f[2][1] == 4 && front_f[0][1] == 5) {
        //16ª possibilidade
        printf("[EASY CASE 4º CASO] [TESTE] 16ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }

    // FIM do // 4º (R U R')

    // FIM do EASY CASES (1-4)

    // REPOSITION EDGE (5-8)

    // 1º ((U' R U R') U² (R U' R')) - 16 possibilidades

    if (front_f[0][2] == 1 && top_f[2][2] == 3 && right_f[0][0] == 4 && top_f[0][1] == 3 && back_f[0][1] == 4) {
        //1ª possibilidade
        printf("[REPOSITION EDGE 1º CASO] [TESTE] 1ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][2] == 1 && top_f[2][0] == 3 && front_f[0][0] == 4 && top_f[1][2] == 3 && right_f[0][1] == 4) {
        //2ª possibilidade
        printf("[REPOSITION EDGE 1º CASO] [TESTE] 2ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][0] == 1 && left_f[0][0] == 4 && top_f[0][0] == 3 && top_f[2][1] == 3 && front_f[0][1] == 4) {
        //3ª possibilidade
        printf("[REPOSITION EDGE 1º CASO] [TESTE] 3ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[0][2] == 1 && top_f[0][2] == 3 && back_f[0][2] == 4 && top_f[1][0] == 3 && left_f[0][1] == 4) {
        //4ª possibilidade
        printf("[REPOSITION EDGE 1º CASO] [TESTE] 4ª possibilidade\n");
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][2] == 1 && top_f[2][0] == 6 && front_f[0][0] == 3 && top_f[1][2] == 6 && right_f[0][1] == 3) {
        //5ª possibilidade
        printf("[REPOSITION EDGE 1º CASO] [TESTE] 5ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][0] == 1 && top_f[0][0] == 6 && left_f[0][0] == 3 && top_f[2][1] == 6 && front_f[0][1] == 3) {
        //6ª possibilidade
        printf("[REPOSITION EDGE 1º CASO] [TESTE] 6ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[0][2] == 6 && right_f[0][2] == 1 && back_f[0][2] == 3 && top_f[1][0] == 6 && left_f[0][1] == 3) {
        //7ª possibilidade
        printf("[REPOSITION EDGE 1º CASO] [TESTE] 7ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[0][2] == 1 && top_f[2][2] == 6 && right_f[0][0] == 3 && top_f[0][1] == 6 && back_f[0][1] == 3) {
        //8ª possibilidade
        printf("[REPOSITION EDGE 1º CASO] [TESTE] 8ª possibilidade\n");
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[0][0] == 5 && back_f[0][0] == 1 && left_f[0][0] == 6 && top_f[2][1] == 5 && front_f[0][1] == 6) {
        //9ª possibilidade
        printf("[REPOSITION EDGE 1º CASO] [TESTE] 9ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[0][2] == 1 && top_f[0][2] == 5 && back_f[0][2] == 6 && top_f[1][0] == 5 && left_f[0][1] == 6) {
        //10ª possibilidade
        printf("[REPOSITION EDGE 1º CASO] [TESTE] 10ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[0][2] == 1 && top_f[2][2] == 5 && right_f[0][0] == 6 && top_f[0][1] == 5 && back_f[0][1] == 6) {
        //11ª possibilidade
        printf("[REPOSITION EDGE 1º CASO] [TESTE] 11ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][2] == 1 && top_f[2][0] == 5 && front_f[0][0] == 6 && top_f[1][2] == 5 && right_f[0][1] == 6) {
        //12ª possibilidade
        printf("[REPOSITION EDGE 1º CASO] [TESTE] 12ª possibilidade\n");
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[0][2] == 1 && top_f[0][2] == 4 && back_f[0][2] == 5 && top_f[1][0] == 4 && left_f[0][1] == 5) {
        //13ª possibilidade
        printf("[REPOSITION EDGE 1º CASO] [TESTE] 13ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[0][2] == 1 && top_f[2][2] == 4 && right_f[0][0] == 5 && top_f[0][1] == 4 && back_f[0][1] == 5) {
        //14ª possibilidade
        printf("[REPOSITION EDGE 1º CASO] [TESTE] 14ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][2] == 1 && top_f[2][0] == 4 && front_f[0][0] == 5 && top_f[1][2] == 4 && right_f[0][1] == 5) {
        //15ª possibilidade
        printf("[REPOSITION EDGE 1º CASO] [TESTE] 15ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][0] == 1 && left_f[0][0] == 5 && top_f[0][0] == 4 && top_f[2][1] == 4 && front_f[0][1] == 5) {
        //16ª possibilidade
        printf("[REPOSITION EDGE 1º CASO] [TESTE] 16ª possibilidade\n");
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }

    // FIM do 1º ((U' R U R') U² (R U' R'))


    // 2º (U' (R U² R') U² (R U' R')) - 16 possibilidades

    if (front_f[0][2] == 1 && top_f[2][2] == 3 && right_f[0][0] == 4 && top_f[1][0] == 3 && left_f[0][1] == 4) {
        //1ª possibilidade
        printf("[REPOSITION EDGE 2º CASO] [TESTE] 1ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][2] == 1 && top_f[2][0] == 3 && front_f[0][0] == 4 && top_f[0][1] == 3 && back_f[0][1] == 4) {
        //2ª possibilidade
        printf("[REPOSITION EDGE 2º CASO] [TESTE] 2ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][0] == 1 && top_f[0][0] == 3 && left_f[0][0] == 4 && top_f[1][2] == 3 && right_f[0][1] == 4) {
        //3ª possibilidade
        printf("[REPOSITION EDGE 2º CASO] [TESTE] 3ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[0][2] == 1 && top_f[0][2] == 3 && back_f[0][2] == 4 && top_f[2][1] == 3 && front_f[0][1] == 4) {
        //4ª possibilidade
        printf("[REPOSITION EDGE 2º CASO] [TESTE] 4ª possibilidade\n");
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][2] == 1 && top_f[2][0] == 6 && front_f[0][0] == 3 && top_f[0][1] == 6 && back_f[0][1] == 3) {
        //5ª possibilidade
        printf("[REPOSITION EDGE 2º CASO] [TESTE] 5ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][0] == 1 && top_f[0][0] == 6 && left_f[0][0] == 3 && top_f[1][2] == 6 && right_f[0][1] == 3) {
        //6ª possibilidade
        printf("[REPOSITION EDGE 2º CASO] [TESTE] 6ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[0][2] == 1 && top_f[0][2] == 6 && back_f[0][2] == 3 && top_f[2][1] == 6 && front_f[0][1] == 3) {
        //7ª possibilidade
        printf("[REPOSITION EDGE 2º CASO] [TESTE] 7ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[0][2] == 1 && top_f[2][2] == 6 && right_f[0][0] == 3 && top_f[1][0] == 6 && left_f[0][1] == 3) {
        //8ª possibilidade
        printf("[REPOSITION EDGE 2º CASO] [TESTE] 8ª possibilidade\n");
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][0] == 1 && top_f[0][0] == 5 && left_f[0][0] == 6 && top_f[1][2] == 5 && right_f[0][1] == 6) {
        //9ª possibilidade
        printf("[REPOSITION EDGE 2º CASO] [TESTE] 9ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[0][2] == 1 && top_f[0][2] == 5 && back_f[0][2] == 6 && top_f[2][1] == 5 && front_f[0][1] == 6) {
        //10ª possibilidade
        printf("[REPOSITION EDGE 2º CASO] [TESTE] 10ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[0][2] == 1 && top_f[2][2] == 5 && right_f[0][0] == 6 && top_f[1][0] == 5 && left_f[0][1] == 6) {
        //11ª possibilidade
        printf("[REPOSITION EDGE 2º CASO] [TESTE] 11ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][2] == 1 && top_f[2][0] == 5 && front_f[0][0] == 6 && top_f[0][1] == 5 && back_f[0][1] == 6) {
        //12ª possibilidade
        printf("[REPOSITION EDGE 2º CASO] [TESTE] 12ª possibilidade\n");
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[0][2] == 1 && top_f[0][2] == 4 && back_f[0][2] == 5 && top_f[2][1] == 4 && front_f[0][1] == 5) {
        //13ª possibilidade
        printf("[REPOSITION EDGE 2º CASO] [TESTE] 13ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[0][2] == 1 && top_f[2][2] == 4 && right_f[0][0] == 5 && top_f[1][0] == 4 && left_f[0][1] == 5) {
        //14ª possibilidade
        printf("[REPOSITION EDGE 2º CASO] [TESTE] 14ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][2] == 1 && top_f[2][0] == 4 && front_f[0][0] == 5 && top_f[0][1] == 4 && back_f[0][1] == 5) {
        //15ª possibilidade
        printf("[REPOSITION EDGE 2º CASO] [TESTE] 15ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][0] == 1 && top_f[0][0] == 4 && left_f[0][0] == 5 && top_f[1][2] == 4 && right_f[0][1] == 5) {
        //16ª possibilidade
        printf("[REPOSITION EDGE 2º CASO] [TESTE] 16ª possibilidade\n");
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }

    // FIM da 2ª (U' (R U² R') U² (R U' R'))

    // 3º (d (R' U' R) U² (R' U R)) ==> U F' U' F U² F' U F - 16 possibilidades

    if (front_f[0][2] == 3 && top_f[2][2] == 4 && right_f[0][0] == 1 && top_f[1][0] == 4 && left_f[0][1] == 3) {
        // 1ª possibilidade
        printf("[REPOSITION EDGE 3º CASO] [TESTE] 1ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[0][0] == 1 && top_f[2][0] == 4 && left_f[0][2] == 3 && top_f[0][1] == 4 && back_f[0][1] == 3) {
        // 2ª possibilidade
        printf("[REPOSITION EDGE 3º CASO] [TESTE] 2ª possibilidade\n");
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[0][0] == 4 && left_f[0][0] == 1 && back_f[0][0] == 3 && top_f[1][2] == 4 && right_f[0][1] == 3) {
        // 3ª possibilidade
        printf("[REPOSITION EDGE 3º CASO] [TESTE] 3ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][2] == 1 && top_f[0][2] == 4 && right_f[0][2] == 3 && top_f[2][1] == 4 && front_f[0][1] == 3) {
        // 4ª possibilidade
        printf("[REPOSITION EDGE 3º CASO] [TESTE] 4ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[0][0] == 1 && top_f[2][0] == 3 && left_f[0][2] == 6 && top_f[0][1] == 3 && back_f[0][1] == 6) {
        // 5ª possibilidade
        printf("[REPOSITION EDGE 3º CASO] [TESTE] 5ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][0] == 1 && top_f[0][0] == 3 && back_f[0][0] == 6 && top_f[1][2] == 3 && right_f[0][1] == 6) {
        // 6ª possibilidade
        printf("[REPOSITION EDGE 3º CASO] [TESTE] 6ª possibilidade\n");
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][2] == 1 && top_f[0][2] == 3 && right_f[0][2] == 6 && top_f[2][1] == 3 && front_f[0][1] == 6) {
        // 7ª possibilidade
        printf("[REPOSITION EDGE 3º CASO] [TESTE] 7ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[2][2] == 3 && front_f[0][2] == 6 && right_f[0][0] == 1 && top_f[1][0] == 3 && left_f[0][1] == 6) {
        // 8ª possibilidade
        printf("[REPOSITION EDGE 3º CASO] [TESTE] 8ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][0] == 1 && top_f[0][0] == 6 && back_f[0][0] == 5 && top_f[1][2] == 6 && right_f[0][1] == 5) {
        // 9ª possibilidade
        printf("[REPOSITION EDGE 3º CASO] [TESTE] 9ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[0][2] == 6 && back_f[0][2] == 1 && right_f[0][2] == 5 && top_f[2][1] == 6 && front_f[0][1] == 5) {
        // 10ª possibilidade
        printf("[REPOSITION EDGE 3º CASO] [TESTE] 10ª possibilidade\n");
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[2][2] == 6 && right_f[0][0] == 1 && front_f[0][2] == 5 && top_f[1][0] == 6 && left_f[0][1] == 5) {
        // 11ª possibilidade
        printf("[REPOSITION EDGE 3º CASO] [TESTE] 11ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[0][0] == 1 && top_f[2][0] == 6 && left_f[0][2] == 5 && top_f[0][1] == 6 && back_f[0][1] == 5) {
        // 12ª possibilidade
        printf("[REPOSITION EDGE 3º CASO] [TESTE] 12ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][2] == 1 && right_f[0][2] == 4 && top_f[0][2] == 5 && top_f[2][1] == 5 && front_f[0][1] == 4) {
        // 13ª possibilidade
        printf("[REPOSITION EDGE 3º CASO] [TESTE] 13ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[0][2] == 4 && top_f[2][2] == 5 && right_f[0][0] == 1 && top_f[1][0] == 5 && left_f[0][1] == 4) {
        // 14ª possibilidade
        printf("[REPOSITION EDGE 3º CASO] [TESTE] 14ª possibilidade\n");
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[0][0] == 1 && top_f[2][0] == 5 && left_f[0][2] == 4 && top_f[0][1] == 5 && back_f[0][1] == 4) {
        // 15ª possibilidade
        printf("[REPOSITION EDGE 3º CASO] [TESTE] 15ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][0] == 1 && top_f[0][0] == 5 && back_f[0][0] == 4 && top_f[1][2] == 5 && right_f[0][1] == 4) {
        // 16ª possibilidade
        printf("[REPOSITION EDGE 3º CASO] [TESTE] 16ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }

    // FIM da 3ª (d (R' U' R) U² (R' U R)) ==> U F' U' F U² F' U F

    // 4º (d (R' U² R) U² (R' U R)) ==> U F' U² F U² F' U F - 16 possibilidades

    if (front_f[0][2] == 3 && top_f[2][2] == 4 && right_f[0][0] == 1 && top_f[0][1] == 4 && back_f[0][1] == 3) {
        // 1ª possibilidade
        printf("[REPOSITION EDGE 4º CASO] [TESTE] 1ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[0][0] == 1 && top_f[2][0] == 4 && left_f[0][2] == 3 && top_f[1][2] == 4 && right_f[0][1] == 3) {
        // 2ª possibilidade
        printf("[REPOSITION EDGE 4º CASO] [TESTE] 2ª possibilidade\n");
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][0] == 1 && top_f[0][0] == 4 && back_f[0][0] == 3 && top_f[2][1] == 4 && front_f[0][1] == 3) {
        // 3ª possibilidade
        printf("[REPOSITION EDGE 4º CASO] [TESTE] 3ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][2] == 1 && top_f[0][2] == 4 && right_f[0][2] == 3 && top_f[1][0] == 4 && left_f[0][1] == 3) {
        // 4ª possibilidade
        printf("[REPOSITION EDGE 4º CASO] [TESTE] 4ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[0][0] == 1 && top_f[2][0] == 3 && left_f[0][2] == 6 && top_f[1][2] == 3 && right_f[0][1] == 6) {
        // 5ª possibilidade
        printf("[REPOSITION EDGE 4º CASO] [TESTE] 5ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][0] == 1 && top_f[0][0] == 3 && back_f[0][0] == 6 && top_f[2][1] == 3 && front_f[0][1] == 6) {
        // 6ª possibilidade
        printf("[REPOSITION EDGE 4º CASO] [TESTE] 6ª possibilidade\n");
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][2] == 1 && top_f[0][2] == 3 && right_f[0][2] == 6 && top_f[1][0] == 3 && left_f[0][1] == 6) {
        // 7ª possibilidade
        printf("[REPOSITION EDGE 4º CASO] [TESTE] 7ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[2][2] == 3 && front_f[0][2] == 6 && right_f[0][0] == 1 && top_f[0][1] == 3 && back_f[0][1] == 6) {
        // 8ª possibilidade
        printf("[REPOSITION EDGE 4º CASO] [TESTE] 8ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][0] == 1 && top_f[0][0] == 6 && back_f[0][0] == 5 && top_f[2][1] == 6 && front_f[0][1] == 5) {
        // 9ª possibilidade
        printf("[REPOSITION EDGE 4º CASO] [TESTE] 9ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[0][2] == 6 && back_f[0][2] == 1 && right_f[0][2] == 5 && top_f[1][0] == 6 && left_f[0][1] == 5) {
        // 10ª possibilidade
        printf("[REPOSITION EDGE 4º CASO] [TESTE] 10ª possibilidade\n");
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[2][2] == 6 && right_f[0][0] == 1 && front_f[0][2] == 5 && top_f[0][1] == 6 && back_f[0][1] == 5) {
        // 11ª possibilidade
        printf("[REPOSITION EDGE 4º CASO] [TESTE] 11ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[0][0] == 1 && top_f[2][0] == 6 && left_f[0][2] == 5 && top_f[1][2] == 6 && right_f[0][1] == 5) {
        // 12ª possibilidade
        printf("[REPOSITION EDGE 4º CASO] [TESTE] 12ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][2] == 1 && right_f[0][2] == 4 && top_f[0][2] == 5 && top_f[1][0] == 5 && left_f[0][1] == 4) {
        // 13ª possibilidade
        printf("[REPOSITION EDGE 4º CASO] [TESTE] 13ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[0][2] == 4 && top_f[2][2] == 5 && right_f[0][0] == 1 && top_f[0][1] == 5 && back_f[0][1] == 4) {
        // 14ª possibilidade
        printf("[REPOSITION EDGE 4º CASO] [TESTE] 14ª possibilidade\n");
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[0][0] == 1 && top_f[2][0] == 5 && left_f[0][2] == 4 && top_f[1][2] == 5 && right_f[0][1] == 4) {
        // 15ª possibilidade
        printf("[REPOSITION EDGE 4º CASO] [TESTE] 15ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][0] == 1 && top_f[0][0] == 5 && back_f[0][0] == 4 && top_f[2][1] == 5 && front_f[0][1] == 4) {
        // 16ª possibilidade
        printf("[REPOSITION EDGE 4º CASO] [TESTE] 16ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }

    // FIM da 4ª ((d (R' U² R) U² (R' U R)) ==> U F' U² F U² F' U F

    // FIM do REPOSITION EDGE (5-8)

    // REPOSITION EDGE AND FLIP CORNER (9-14)

    // 1º (d (R' U' R U')(R' U' R)) ==> U F' U' F U' F' U' F - 16 possibilidades

    if (front_f[0][2] == 1 && top_f[2][2] == 3 && right_f[0][0] == 4 && top_f[0][1] == 4 && back_f[0][1] == 3) {
        // 1ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 1º CASO] [TESTE] 1ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][2] == 1 && top_f[2][0] == 3 && front_f[0][0] == 4 && top_f[1][2] == 4 && right_f[0][1] == 3) {
        // 2ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 1º CASO] [TESTE] 2ª possibilidade\n");
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][0] == 1 && top_f[0][0] == 3 && left_f[0][0] == 4 && top_f[2][1] == 4 && front_f[0][1] == 3) {
        // 3ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 1º CASO] [TESTE] 3ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[0][2] == 1 && top_f[0][2] == 3 && back_f[0][2] == 4 && top_f[1][0] == 4 && left_f[0][1] == 3) {
        // 4ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 1º CASO] [TESTE] 4ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][2] == 1 && top_f[2][0] == 6 && front_f[0][0] == 3 && top_f[1][2] == 3 && right_f[0][1] == 6) {
        // 5ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 1º CASO] [TESTE] 5ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][0] == 1 && top_f[0][0] == 6 && left_f[0][0] == 3 && top_f[2][1] == 3 && front_f[0][1] == 6) {
        // 6ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 1º CASO] [TESTE] 6ª possibilidade\n");
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[0][2] == 1 && top_f[0][2] == 6 && back_f[0][2] == 3 && top_f[1][0] == 3 && left_f[0][1] == 6) {
        // 7ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 1º CASO] [TESTE] 7ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[0][2] == 1 && top_f[2][2] == 6 && right_f[0][0] == 3 && top_f[0][1] == 3 && back_f[0][1] == 6) {
        // 8ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 1º CASO] [TESTE] 8ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][0] == 1 && top_f[0][0] == 5 && left_f[0][0] == 6 && top_f[2][1] == 6 && front_f[0][1] == 5) {
        // 9ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 1º CASO] [TESTE] 9ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[0][2] == 1 && top_f[0][2] == 5 && back_f[0][2] == 6 && top_f[1][0] == 6 && left_f[0][1] == 5) {
        // 10ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 1º CASO] [TESTE] 10ª possibilidade\n");
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[0][2] == 1 && top_f[2][2] == 5 && right_f[0][0] == 6 && top_f[0][1] == 6 && back_f[0][1] == 5) {
        // 11ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 1º CASO] [TESTE] 11ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][2] == 1 && top_f[2][0] == 5 && front_f[0][0] == 6 && top_f[1][2] == 6 && right_f[0][1] == 5) {
        // 12ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 1º CASO] [TESTE] 12ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[0][2] == 1 && top_f[0][2] == 4 && back_f[0][2] == 5 && top_f[1][0] == 5 && left_f[0][1] == 4) {
        // 13ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 1º CASO] [TESTE] 13ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[0][2] == 1 && top_f[2][2] == 4 && right_f[0][0] == 5 && top_f[0][1] == 5 && back_f[0][1] == 3) {
        // 14ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 1º CASO] [TESTE] 14ª possibilidade\n");
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][2] == 1 && top_f[2][0] == 4 && front_f[0][0] == 5 && top_f[1][2] == 5 && right_f[0][1] == 4) {
        // 15ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 1º CASO] [TESTE] 15ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][0] == 1 && top_f[0][0] == 4 && left_f[0][0] == 5 && top_f[2][1] == 5 && front_f[0][1] == 4) {
        // 16ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 1º CASO] [TESTE] 16ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }

    // FIM da 1ª (d (R' U' R U')(R' U' R)) ==> U F' U' F U' F' U' F

    // 2º U' (R U 2 ' R') d (R' U' R) ==> U' R U² R' U F' U' F - 16 possibilidades

    if (front_f[0][2] == 1 && top_f[2][2] == 3 && top_f[1][2] == 4 && right_f[0][0] == 4 && right_f[0][1] == 3) {
        // 1ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 2º CASO] [TESTE] 1ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][2] == 1 && top_f[2][0] == 3 && top_f[2][1] == 4 && front_f[0][0] == 4 && front_f[0][1] == 3) {
        // 2ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 2º CASO] [TESTE] 2ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][0] == 1 && top_f[0][0] == 3 && top_f[1][0] == 4 && left_f[0][0] == 4 && left_f[0][1] == 3) {
        // 3ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 2º CASO] [TESTE] 3ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[0][2] == 1 && top_f[0][2] == 3 && top_f[0][1] == 4 && back_f[0][2] == 4 && back_f[0][1] == 3) {
        // 4ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 2º CASO] [TESTE] 4ª possibilidade\n");
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][2] == 1 && top_f[2][0] == 6 && top_f[2][1] == 3 && front_f[0][0] == 3 && front_f[0][1] == 6) {
        // 5ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 2º CASO] [TESTE] 5ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][0] == 1 && top_f[0][0] == 6 && top_f[1][0] == 3 && left_f[0][0] == 3 && left_f[0][1] == 6) {
        // 6ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 2º CASO] [TESTE] 6ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[0][2] == 1 && top_f[0][1] == 3 && top_f[0][2] == 6 && back_f[0][1] == 6 && back_f[0][2] == 3) {
        // 7ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 2º CASO] [TESTE] 7ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[0][2] == 1 && top_f[1][2] == 3 && top_f[2][2] == 6 && right_f[0][0] == 3 && right_f[0][1] == 6) {
        // 8ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 2º CASO] [TESTE] 8ª possibilidade\n");
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][0] == 1 && top_f[0][0] == 5 && top_f[1][0] == 6 && left_f[0][0] == 6 && left_f[0][1] == 5) {
        // 9ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 2º CASO] [TESTE] 9ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[0][2] == 1 && top_f[0][1] == 6 && top_f[0][2] == 5 && back_f[0][1] == 5 && back_f[0][2] == 6) {
        // 10ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 2º CASO] [TESTE] 10ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[0][2] == 1 && top_f[2][2] == 5 && top_f[1][2] == 6 && right_f[0][0] == 6 && right_f[0][1] == 5) {
        // 11ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 2º CASO] [TESTE] 11ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][2] == 1 && top_f[2][0] == 5 && top_f[2][1] == 6 && front_f[0][0] == 6 && front_f[0][1] == 5) {
        // 12ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 2º CASO] [TESTE] 12ª possibilidade\n");
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[0][2] == 1 && top_f[0][1] == 5 && top_f[0][2] == 4 && back_f[0][1] == 4 && back_f[0][2] == 5) {
        // 13ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 2º CASO] [TESTE] 13ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[0][2] == 1 && top_f[1][2] == 5 && top_f[2][2] == 4 && right_f[0][0] == 5 && right_f[0][1] == 4) {
        // 14ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 2º CASO] [TESTE] 14ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][2] == 1 && top_f[2][0] == 4 && top_f[2][1] == 5 && front_f[0][0] == 5 && front_f[0][1] == 4) {
        // 15ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 2º CASO] [TESTE] 15ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][0] == 1 && top_f[0][0] == 4 && top_f[1][0] == 5 && left_f[0][0] == 5 && left_f[0][1] == 4) {
        // 16ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 2º CASO] [TESTE] 16ª possibilidade\n");
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }

    // FIM da 2ª U' (R U 2 ' R') d (R' U' R) ==> U' R U² R' U F' U' F

    // 3º d (R' U R U')(R' U' R) ==> U F' U F U' F' U' F - 16 possibilidades

    if (front_f[0][2] == 1 && front_f[0][1] == 3 && top_f[2][1] == 4 && top_f[2][2] == 3 && right_f[0][0] == 4) {
        // 1ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 3º CASO] [TESTE] 1ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][2] == 1 && left_f[0][1] == 3 && front_f[0][0] == 4 && top_f[1][0] == 4 && top_f[2][0] == 3) {
        // 2ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 3º CASO] [TESTE] 2ª possibilidade\n");
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][0] == 1 && back_f[0][1] == 3 && top_f[0][0] == 3 && top_f[0][1] == 4 && left_f[0][0] == 4) {
        // 3ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 3º CASO] [TESTE] 3ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][2] == 4 && right_f[0][2] == 1 && right_f[0][1] == 3 && top_f[0][2] == 3 && top_f[1][2] == 4) {
        // 4ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 3º CASO] [TESTE] 4ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[0][0] == 3 && top_f[2][0] == 6 && top_f[1][0] == 3 && left_f[0][2] == 1 && left_f[0][1] == 6) {
        // 5ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 3º CASO] [TESTE] 5ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][0] == 3 && top_f[0][0] == 6 && top_f[0][1] == 3 && back_f[0][0] == 1 && back_f[0][1] == 6) {
        // 6ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 3º CASO] [TESTE] 6ª possibilidade\n");
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][2] == 3 && top_f[0][2] == 6 && top_f[1][2] == 3 && right_f[0][2] == 1 && right_f[0][1] == 6) {
        // 7ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 3º CASO] [TESTE] 7ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[0][0] == 3 && front_f[0][2] == 1 && front_f[0][1] == 6 && top_f[2][1] == 3 && top_f[2][2] == 6) {
        // 8ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 3º CASO] [TESTE] 8ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][0] == 6 && top_f[0][0] == 5 && top_f[0][1] == 6 && back_f[0][0] == 1 && back_f[0][1] == 5) {
        // 9ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 3º CASO] [TESTE] 9ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][2] == 6 && top_f[0][2] == 5 && top_f[1][2] == 6 && right_f[0][2] == 1 && right_f[0][1] == 5) {
        // 10ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 3º CASO] [TESTE] 10ª possibilidade\n");
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[0][0] == 6 && top_f[2][1] == 6 && top_f[2][2] == 5 && front_f[0][2] == 1 && front_f[0][1] == 5) {
        // 11ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 3º CASO] [TESTE] 11ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[0][0] == 6 && top_f[1][0] == 6 && top_f[2][0] == 5 && left_f[0][2] == 1 && left_f[0][1] == 5) {
        // 12ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 3º CASO] [TESTE] 12ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][2] == 5 && top_f[0][2] == 4 && top_f[1][2] == 5 && right_f[0][2] == 1 && right_f[0][1] == 4) {
        // 13ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 3º CASO] [TESTE] 13ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[0][0] == 5 && top_f[2][1] == 5 && top_f[2][2] == 4 && front_f[0][1] == 4 && front_f[0][2] == 1) {
        // 14ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 3º CASO] [TESTE] 14ª possibilidade\n");
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[0][0] == 5 && top_f[2][0] == 4 && top_f[1][0] == 5 && left_f[0][2] == 1 && left_f[0][1] == 4) {
        // 15ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 3º CASO] [TESTE] 15ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][0] == 5 && top_f[0][0] == 4 && top_f[0][1] == 5 && back_f[0][0] == 1 && back_f[0][1] == 4) {
        // 16ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 3º CASO] [TESTE] 16ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }

    // FIM da 3ª d (R' U R U')(R' U' R) ==> U F' U F U' F' U' F

    // 4º U' (R U R' U)(R U R') - 16 possibilidades

    if (right_f[0][0] == 1 && top_f[2][2] == 4 && front_f[0][2] == 3 && top_f[1][0] == 3 && left_f[0][1] == 4) {
        // 1ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 4º CASO] [TESTE] 1ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[0][0] == 1 && left_f[0][2] == 3 && top_f[2][0] == 4 && top_f[0][1] == 3 && back_f[0][1] == 4) {
        // 2ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 4º CASO] [TESTE] 2ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][0] == 1 && top_f[0][0] == 4 && back_f[0][0] == 3 && top_f[1][2] == 3 && right_f[0][1] == 4) {
        // 3ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 4º CASO] [TESTE] 3ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][2] == 1 && top_f[0][2] == 4 && right_f[0][2] == 3 && top_f[2][1] == 3 && front_f[0][1] == 4) {
        // 4ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 4º CASO] [TESTE] 4ª possibilidade\n");
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[0][0] == 1 && top_f[2][0] == 3 && left_f[0][2] == 6 && top_f[0][1] == 6 && back_f[0][1] == 3) {
        // 5ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 4º CASO] [TESTE] 5ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][0] == 1 && top_f[0][0] == 3 && back_f[0][0] == 6 && top_f[1][2] == 6 && right_f[0][1] == 3) {
        // 6ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 4º CASO] [TESTE] 6ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][2] == 1 && top_f[0][2] == 3 && right_f[0][2] == 6 && top_f[2][1] == 6 && front_f[0][1] == 3) {
        // 7ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 4º CASO] [TESTE] 7ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[0][0] == 1 && top_f[2][2] == 3 && front_f[0][2] == 6 && top_f[1][0] == 6 && left_f[0][1] == 3) {
        // 8ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 4º CASO] [TESTE] 8ª possibilidade\n");
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][0] == 1 && back_f[0][0] == 5 && top_f[0][0] == 6 && top_f[1][2] == 5 && right_f[0][1] == 6) {
        // 9ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 4º CASO] [TESTE] 9ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][2] == 1 && top_f[0][2] == 6 && right_f[0][2] == 5 && top_f[2][1] == 5 && front_f[0][1] == 6) {
        // 10ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 4º CASO] [TESTE] 10ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[0][0] == 1 && top_f[2][2] == 6 && front_f[0][2] == 5 && top_f[1][0] == 5 && left_f[0][1] == 6) {
        // 11ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 4º CASO] [TESTE] 11ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[0][0] == 1 && top_f[2][0] == 6 && left_f[0][2] == 5 && top_f[0][1] == 5 && back_f[0][1] == 6) {
        // 12ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 4º CASO] [TESTE] 12ª possibilidade\n");
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][2] == 1 && top_f[0][2] == 5 && right_f[0][2] == 4 && top_f[2][1] == 4 && front_f[0][1] == 5) {
        // 13ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 4º CASO] [TESTE] 13ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[2][2] == 5 && right_f[0][0] == 1 && front_f[0][2] == 4 && top_f[1][0] == 4 && left_f[0][1] == 5) {
        // 14ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 4º CASO] [TESTE] 14ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[0][0] == 1 && top_f[2][0] == 5 && left_f[0][2] == 4 && top_f[0][1] == 4 && back_f[0][1] == 5) {
        // 15ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 4º CASO] [TESTE] 15ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][0] == 1 && back_f[0][0] == 4 && top_f[0][0] == 5 && top_f[1][2] == 4 && right_f[0][1] == 5) {
        // 16ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 4º CASO] [TESTE] 16ª possibilidade\n");
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }

    // FIM da 4ª U' (R U R' U)(R U R')

    // 5º d (R' U 2 R) d' (R U R') ==> R U' R' U R U' R' U² R U' R' - 16 possibilidades

    if (right_f[0][0] == 1 && top_f[2][1] == 3 && top_f[2][2] == 4 && front_f[0][1] == 4 && front_f[0][2] == 3) {
        // 1ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 5º CASO] [TESTE] 1ª possibilidade\n");
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[0][0] == 1 && top_f[1][0] == 3 && top_f[2][0] == 4 && left_f[0][1] == 4 && left_f[0][2] == 3) {
        // 2ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 5º CASO] [TESTE] 2ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][0] == 1 && top_f[0][0] == 4 && top_f[0][1] == 3 && back_f[0][0] == 3 && back_f[0][1] == 4) {
        // 3ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 5º CASO] [TESTE] 3ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][2] == 1 && top_f[0][2] == 4 && top_f[1][2] == 3 && right_f[0][2] == 3 && right_f[0][1] == 4) {
        // 4ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 5º CASO] [TESTE] 4ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[0][0] == 1 && top_f[2][0] == 3 && top_f[1][0] == 6 && left_f[0][2] == 6 && left_f[0][1] == 3) {
        // 5ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 5º CASO] [TESTE] 5ª possibilidade\n");
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][0] == 1 && top_f[0][0] == 3 && top_f[0][1] == 6 && back_f[0][0] == 6 && back_f[0][1] == 3) {
        // 6ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 5º CASO] [TESTE] 6ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][2] == 1 && top_f[0][2] == 3 && top_f[1][2] == 6 && right_f[0][2] == 6 && right_f[0][1] == 3) {
        // 7ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 5º CASO] [TESTE] 7ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[0][0] == 1 && top_f[2][1] == 6 && top_f[2][2] == 3 && front_f[0][1] == 3 && front_f[0][2] == 6) {
        // 8ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 5º CASO] [TESTE] 8ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][0] == 1 && top_f[0][0] == 6 && top_f[0][1] == 5 && back_f[0][0] == 5 && back_f[0][1] == 6) {
        // 9ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 5º CASO] [TESTE] 9ª possibilidade\n");
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][2] == 1 && top_f[0][2] == 6 && top_f[1][2] == 5 && right_f[0][2] == 5 && right_f[0][1] == 6) {
        // 10ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 5º CASO] [TESTE] 10ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[0][0] == 1 && top_f[2][1] == 5 && top_f[2][2] == 6 && front_f[0][1] == 6 && front_f[0][2] == 5) {
        // 11ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 5º CASO] [TESTE] 11ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[0][0] == 1 && top_f[2][0] == 6 && top_f[1][0] == 5 && left_f[0][1] == 6 && left_f[0][2] == 5) {
        // 12ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 5º CASO] [TESTE] 12ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][2] == 1 && top_f[0][2] == 5 && top_f[1][2] == 4 && right_f[0][1] == 5 && right_f[0][2] == 4) {
        // 13ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 5º CASO] [TESTE] 13ª possibilidade\n");
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[0][0] == 1 && top_f[2][1] == 4 && top_f[2][2] == 5 && front_f[0][1] == 5 && front_f[0][2] == 4) {
        // 14ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 5º CASO] [TESTE] 14ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[0][0] == 1 && top_f[1][0] == 4 && top_f[2][0] == 5 && left_f[0][2] == 4 && left_f[0][1] == 5) {
        // 15ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 5º CASO] [TESTE] 15ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][0] == 1 && top_f[0][0] == 5 && top_f[0][1] == 4 && back_f[0][0] == 4 && back_f[0][1] == 5) {
        // 16ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 5º CASO] [TESTE] 16ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }

    // FIM da d (R' U 2 R) d' (R U R') ==> R U' R' U R U' R' U² R U' R'

    // 6º U' (R U' R' U)(R U R') - 16 possibilidades

    if (front_f[0][2] == 3 && top_f[2][2] == 4 && top_f[1][2] == 3 && right_f[0][0] == 1 && right_f[0][1] == 4) {
        // 1ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 6º CASO] [TESTE] 1ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][2] == 3 && front_f[0][0] == 1 && front_f[0][1] == 4 && top_f[2][0] == 4 && top_f[2][1] == 3) {
        // 2ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 6º CASO] [TESTE] 2ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][0] == 3 && top_f[0][0] == 4 && top_f[1][0] == 3 && left_f[0][0] == 1 && left_f[0][1] == 4) {
        // 3ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 6º CASO] [TESTE] 3ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[0][2] == 3 && top_f[0][1] == 3 && top_f[0][2] == 4 && back_f[0][1] == 4 && back_f[0][2] == 1) {
        // 4ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 6º CASO] [TESTE] 4ª possibilidade\n");
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][2] == 6 && front_f[0][0] == 1 && front_f[0][1] == 3 && top_f[2][0] == 3 && top_f[2][1] == 6) {
        // 5ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 6º CASO] [TESTE] 5ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][0] == 6 && top_f[0][0] == 3 && top_f[1][0] == 6 && left_f[0][0] == 1 && left_f[0][1] == 3) {
        // 6ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 6º CASO] [TESTE] 6ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[0][2] == 6 && top_f[0][1] == 6 && top_f[0][2] == 3 && back_f[0][2] == 1 && back_f[0][1] == 3) {
        // 7ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 6º CASO] [TESTE] 7ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[0][2] == 6 && top_f[2][2] == 3 && top_f[1][2] == 6 && right_f[0][0] == 1 && right_f[0][1] == 3) {
        // 8ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 6º CASO] [TESTE] 8ª possibilidade\n");
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][0] == 5 && top_f[0][0] == 6 && top_f[1][0] == 5 && left_f[0][0] == 1 && left_f[0][1] == 6) {
        // 9ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 6º CASO] [TESTE] 9ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[0][2] == 5 && top_f[0][1] == 5 && top_f[0][2] == 6 && back_f[0][2] == 1 && back_f[0][1] == 6) {
        // 10ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 6º CASO] [TESTE] 10ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[0][2] == 5 && top_f[2][2] == 6 && top_f[1][2] == 5 && right_f[0][0] == 1 && right_f[0][1] == 6) {
        // 11ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 6º CASO] [TESTE] 11ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][2] == 5 && front_f[0][0] == 1 && front_f[0][1] == 6 && top_f[2][0] == 6 && top_f[2][1] == 5) {
        // 12ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 6º CASO] [TESTE] 12ª possibilidade\n");
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[0][2] == 4 && top_f[0][1] == 4 && top_f[0][2] == 5 && back_f[0][2] == 1 && back_f[0][1] == 5) {
        // 13ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 6º CASO] [TESTE] 13ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[0][2] == 4 && top_f[2][2] == 5 && top_f[1][2] == 4 && right_f[0][0] == 1 && right_f[0][1] == 5) {
        // 14ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 6º CASO] [TESTE] 14ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][2] == 4 && front_f[0][0] == 1 && front_f[0][1] == 5 && top_f[2][0] == 5 && top_f[2][1] == 4) {
        // 15ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 6º CASO] [TESTE] 15ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][0] == 4 && top_f[0][0] == 5 && top_f[1][0] == 4 && left_f[0][0] == 1 && left_f[0][1] == 5) {
        // 16ª possibilidade
        printf("[REPOSITION EDGE AND FLIP CORNER 6º CASO] [TESTE] 16ª possibilidade\n");
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }

    // FIM da 6ª U' (R U' R' U)(R U R')

    // FIM do REPOSITION EDGE AND FLIP CORNER (9-14)

    // SPLIT PAIR BY GOING OVER (15-18)

    // 1º y' (R' U R U') d' (R U R') ==> F' U F U² R U R' - 16 possibilidades

    if (right_f[0][0] == 4 && top_f[2][1] == 3 && top_f[2][2] == 3 && front_f[0][1] == 4 && front_f[0][2] == 1) {
        // 1ª possibilidade
        printf("[SPLIT PAIR BY GOING OVER 1º CASO] [TESTE] 1ª possibilidade\n");
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[0][0] == 4 && top_f[1][0] == 3 && top_f[2][0] == 3 && left_f[0][2] == 1 && left_f[0][1] == 4) {
        // 2ª possibilidade
        printf("[SPLIT PAIR BY GOING OVER 1º CASO] [TESTE] 2ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][0] == 4 && top_f[0][1] == 3 && top_f[0][0] == 3 && back_f[0][0] == 1 && back_f[0][1] == 4) {
        // 3ª possibilidade
        printf("[SPLIT PAIR BY GOING OVER 1º CASO] [TESTE] 3ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][2] == 4 && top_f[0][2] == 3 && top_f[1][2] == 3 && right_f[0][1] == 4 && right_f[0][2] == 1) {
        // 4ª possibilidade
        printf("[SPLIT PAIR BY GOING OVER 1º CASO] [TESTE] 4ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[0][0] == 3 && top_f[1][0] == 6 && top_f[2][0] == 6 && left_f[0][2] == 1 && left_f[0][1] == 3) {
        // 5ª possibilidade
        printf("[SPLIT PAIR BY GOING OVER 1º CASO] [TESTE] 5ª possibilidade\n");
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][0] == 3 && top_f[0][0] == 6 && top_f[0][1] == 6 && back_f[0][0] == 1 && back_f[0][1] == 3) {
        // 6ª possibilidade
        printf("[SPLIT PAIR BY GOING OVER 1º CASO] [TESTE] 6ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][2] == 3 && top_f[0][2] == 6 && top_f[1][2] == 6 && right_f[0][2] == 1 && right_f[0][1] == 3) {
        // 7ª possibilidade
        printf("[SPLIT PAIR BY GOING OVER 1º CASO] [TESTE] 7ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[0][0] == 3 && top_f[2][1] == 6 && top_f[2][2] == 6 && front_f[0][1] == 3 && front_f[0][2] == 1) {
        // 8ª possibilidade
        printf("[SPLIT PAIR BY GOING OVER 1º CASO] [TESTE] 8ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][0] == 6 && top_f[0][0] == 5 && top_f[0][1] == 5 && back_f[0][0] == 1 && back_f[0][1] == 6) {
        // 9ª possibilidade
        printf("[SPLIT PAIR BY GOING OVER 1º CASO] [TESTE] 9ª possibilidade\n");
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][2] == 6 && top_f[0][2] == 5 && top_f[1][2] == 5 && right_f[0][2] == 1 && right_f[0][1] == 6) {
        // 10ª possibilidade
        printf("[SPLIT PAIR BY GOING OVER 1º CASO] [TESTE] 10ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[0][0] == 6 && top_f[2][1] == 5 && top_f[2][2] == 5 && front_f[0][1] == 6 && front_f[0][2] == 1) {
        // 11ª possibilidade
        printf("[SPLIT PAIR BY GOING OVER 1º CASO] [TESTE] 11ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[0][0] == 6 && top_f[2][0] == 5 && top_f[1][0] == 5 && left_f[0][1] == 6 && left_f[0][2] == 1) {
        // 12ª possibilidade
        printf("[SPLIT PAIR BY GOING OVER 1º CASO] [TESTE] 12ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][2] == 5 && top_f[0][2] == 4 && top_f[1][2] == 4 && right_f[0][2] == 1 && right_f[0][1] == 5) {
        // 13ª possibilidade
        printf("[SPLIT PAIR BY GOING OVER 1º CASO] [TESTE] 13ª possibilidade\n");
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[0][0] == 5 && top_f[2][1] == 4 && top_f[2][2] == 4 && front_f[0][1] == 5 && front_f[0][2] == 1) {
        // 14ª possibilidade
        printf("[SPLIT PAIR BY GOING OVER 1º CASO] [TESTE] 14ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[0][0] == 5 && top_f[1][0] == 4 && top_f[2][0] == 4 && left_f[0][2] == 1 && left_f[0][1] == 5) {
        // 15ª possibilidade
        printf("[SPLIT PAIR BY GOING OVER 1º CASO] [TESTE] 15ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][0] == 5 && top_f[0][0] == 4 && top_f[0][1] == 4 && back_f[0][0] == 1 && back_f[0][1] == 5) {
        // 16ª possibilidade
        printf("[SPLIT PAIR BY GOING OVER 1º CASO] [TESTE] 16ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }

    //FIM da 1ª y' (R' U R U') d' (R U R') ==> F' U F U² R U R'


    // 2º (R U 2 R') U' (R U R') - 16 possibilidades

    if (front_f[0][2] == 4 && top_f[2][2] == 1 && top_f[1][2] == 3 && right_f[0][0] == 3 && right_f[0][1] == 4) {
        // 1ª possibilidade
        printf("[SPLIT PAIR BY GOING OVER 2º CASO] [TESTE] 1ª possibilidade\n");
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][2] == 4 && top_f[2][0] == 1 && top_f[2][1] == 3 && front_f[0][0] == 3 && front_f[0][1] == 4) {
        // 2ª possibilidade
        printf("[SPLIT PAIR BY GOING OVER 2º CASO] [TESTE] 2ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][0] == 4 && top_f[0][0] == 1 && top_f[1][0] == 3 && left_f[0][0] == 3 && left_f[0][1] == 4) {
        // 3ª possibilidade
        printf("[SPLIT PAIR BY GOING OVER 2º CASO] [TESTE] 3ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[0][2] == 4 && top_f[0][1] == 3 && top_f[0][2] == 1 && back_f[0][2] == 3 && back_f[0][1] == 4) {
        // 4ª possibilidade
        printf("[SPLIT PAIR BY GOING OVER 2º CASO] [TESTE] 4ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][2] == 3 && top_f[2][0] == 1 && top_f[2][1] == 6 && front_f[0][0] == 6 && front_f[0][1] == 3) {
        // 5ª possibilidade
        printf("[SPLIT PAIR BY GOING OVER 2º CASO] [TESTE] 5ª possibilidade\n");
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][0] == 3 && top_f[0][0] == 1 && top_f[1][0] == 6 && left_f[0][0] == 6 && left_f[0][1] == 3) {
        // 6ª possibilidade
        printf("[SPLIT PAIR BY GOING OVER 2º CASO] [TESTE] 6ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[0][2] == 3 && top_f[0][1] == 6 && top_f[0][2] == 1 && back_f[0][2] == 6 && back_f[0][1] == 3) {
        // 7ª possibilidade
        printf("[SPLIT PAIR BY GOING OVER 2º CASO] [TESTE] 7ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[0][2] == 3 && top_f[2][2] == 1 && top_f[1][2] == 6 && right_f[0][0] == 6 && right_f[0][1] == 3) {
        // 8ª possibilidade
        printf("[SPLIT PAIR BY GOING OVER 2º CASO] [TESTE] 8ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][0] == 6 && top_f[0][0] == 1 && top_f[1][0] == 5 && left_f[0][0] == 5 && left_f[0][1] == 6) {
        // 9ª possibilidade
        printf("[SPLIT PAIR BY GOING OVER 2º CASO] [TESTE] 9ª possibilidade\n");
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[0][2] == 6 && top_f[0][1] == 5 && top_f[0][2] == 1 && back_f[0][1] == 6 && back_f[0][2] == 5) {
        // 10ª possibilidade
        printf("[SPLIT PAIR BY GOING OVER 2º CASO] [TESTE] 10ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[0][2] == 6 && top_f[2][2] == 1 && top_f[1][2] == 5 && right_f[0][0] == 5 && right_f[0][1] == 6) {
        // 11ª possibilidade
        printf("[SPLIT PAIR BY GOING OVER 2º CASO] [TESTE] 11ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][2] == 6 && top_f[2][0] == 1 && top_f[2][1] == 5 && front_f[0][0] == 5 && front_f[0][1] == 6) {
        // 12ª possibilidade
        printf("[SPLIT PAIR BY GOING OVER 2º CASO] [TESTE] 12ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[0][2] == 5 && top_f[0][1] == 4 && top_f[0][2] == 1 && back_f[0][1] == 5 && back_f[0][2] == 4) {
        // 13ª possibilidade
        printf("[SPLIT PAIR BY GOING OVER 2º CASO] [TESTE] 13ª possibilidade\n");
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[0][2] == 5 && top_f[2][2] == 1 && top_f[1][2] == 4 && right_f[0][0] == 4 && right_f[0][1] == 5) {
        // 14ª possibilidade
        printf("[SPLIT PAIR BY GOING OVER 2º CASO] [TESTE] 14ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][2] == 5 && top_f[2][0] == 1 && top_f[2][1] == 4 && front_f[0][0] == 4 && front_f[0][1] == 5) {
        // 15ª possibilidade
        printf("[SPLIT PAIR BY GOING OVER 2º CASO] [TESTE] 15ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][0] == 5 && top_f[0][0] == 1 && top_f[1][0] == 4 && left_f[0][0] == 4 && left_f[0][1] == 5) {
        // 16ª possibilidade
        printf("[SPLIT PAIR BY GOING OVER 2º CASO] [TESTE] 16ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }

    // FIM da 2ª (R U 2 R') U' (R U R')

    // 3º (R U' R' U) d (R' U' R) ==> (R U' R') U 2 (F' U' F) - 16 possibilidades

    if (front_f[0][2] == 3 && top_f[2][2] == 4 && top_f[1][2] == 4 && right_f[0][0] == 1 && right_f[0][1] == 3) {
        // 1ª possibilidade
        printf("[SPLIT PAIR BY GOING OVER 3º CASO] [TESTE] 1ª possibilidade\n");
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][2] == 3 && front_f[0][0] == 1 && front_f[0][1] == 3 && top_f[2][0] == 4 && top_f[2][1] == 4) {
        // 2ª possibilidade
        printf("[SPLIT PAIR BY GOING OVER 3º CASO] [TESTE] 2ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][0] == 3 && top_f[0][0] == 4 && top_f[1][0] == 4 && left_f[0][0] == 1 && left_f[0][1] == 3) {
        // 3ª possibilidade
        printf("[SPLIT PAIR BY GOING OVER 3º CASO] [TESTE] 3ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[0][2] == 3 && top_f[0][1] == 4 && top_f[0][2] == 4 && back_f[0][1] == 3 && back_f[0][2] == 1) {
        // 4ª possibilidade
        printf("[SPLIT PAIR BY GOING OVER 3º CASO] [TESTE] 4ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][2] == 6 && top_f[2][0] == 3 && top_f[2][1] == 3 && front_f[0][0] == 1 && front_f[0][1] == 6) {
        // 5ª possibilidade
        printf("[SPLIT PAIR BY GOING OVER 3º CASO] [TESTE] 5ª possibilidade\n");
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][0] == 6 && top_f[0][0] == 3 && top_f[1][0] == 3 && left_f[0][0] == 1 && left_f[0][1] == 6) {
        // 6ª possibilidade
        printf("[SPLIT PAIR BY GOING OVER 3º CASO] [TESTE] 6ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[0][2] == 6 && top_f[0][2] == 3 && top_f[0][1] == 3 && back_f[0][1] == 6 && back_f[0][2] == 1) {
        // 7ª possibilidade
        printf("[SPLIT PAIR BY GOING OVER 3º CASO] [TESTE] 7ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[0][2] == 6 && top_f[2][2] == 3 && top_f[1][2] == 3 && right_f[0][0] == 1 && right_f[0][1] == 6) {
        // 8ª possibilidade
        printf("[SPLIT PAIR BY GOING OVER 3º CASO] [TESTE] 8ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][0] == 5 && top_f[0][0] == 6 && top_f[1][0] == 6 && left_f[0][0] == 1 && left_f[0][1] == 5) {
        // 9ª possibilidade
        printf("[SPLIT PAIR BY GOING OVER 3º CASO] [TESTE] 9ª possibilidade\n");
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[0][2] == 5 && top_f[0][1] == 6 && top_f[0][2] == 6 && back_f[0][2] == 1 && back_f[0][1] == 5) {
        // 10ª possibilidade
        printf("[SPLIT PAIR BY GOING OVER 3º CASO] [TESTE] 10ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[0][2] == 5 && top_f[1][2] == 6 && top_f[2][2] == 6 && right_f[0][0] == 1 && right_f[0][1] == 5) {
        // 11ª possibilidade
        printf("[SPLIT PAIR BY GOING OVER 3º CASO] [TESTE] 11ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][2] == 5 && top_f[2][0] == 6 && top_f[2][1] == 6 && front_f[0][0] == 1 && front_f[0][1] == 5) {
        // 12ª possibilidade
        printf("[SPLIT PAIR BY GOING OVER 3º CASO] [TESTE] 12ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[0][2] == 4 && top_f[0][1] == 5 && top_f[0][2] == 5 && back_f[0][2] == 1 && back_f[0][1] == 4) {
        // 13ª possibilidade
        printf("[SPLIT PAIR BY GOING OVER 3º CASO] [TESTE] 13ª possibilidade\n");
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[0][2] == 4 && top_f[2][2] == 5 && top_f[1][2] == 5 && right_f[0][0] == 1 && right_f[0][1] == 4) {
        // 14ª possibilidade
        printf("[SPLIT PAIR BY GOING OVER 3º CASO] [TESTE] 14ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][2] == 4 && top_f[2][0] == 5 && top_f[2][1] == 5 && front_f[0][0] == 1 && front_f[0][1] == 4) {
        // 15ª possibilidade
        printf("[SPLIT PAIR BY GOING OVER 3º CASO] [TESTE] 15ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][0] == 4 && top_f[0][0] == 5 && top_f[1][0] == 5 && left_f[0][0] == 1 && left_f[0][1] == 4) {
        // 16ª possibilidade
        printf("[SPLIT PAIR BY GOING OVER 3º CASO] [TESTE] 16ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }

    // FIM da 3ª (R U' R' U) d (R' U' R) ==> (R U' R') U 2 (F' U' F)

    // 4º y' (R' U 2 R) U (R' U' R) ==> F' U² F U F' U' F - 16 possibilidades

    if (right_f[0][0] == 3 && front_f[0][1] == 3 && front_f[0][2] == 4 && top_f[2][1] == 4 && top_f[2][2] == 1) {
        // 1ª possibilidade
        printf("[SPLIT PAIR BY GOING OVER 4º CASO] [TESTE] 1ª possibilidade\n");
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[0][0] == 3 && top_f[2][0] == 1 && top_f[1][0] == 4 && left_f[0][1] == 3 && left_f[0][2] == 4) {
        // 2ª possibilidade
        printf("[SPLIT PAIR BY GOING OVER 4º CASO] [TESTE] 2ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][0] == 3 && top_f[0][0] == 1 && top_f[0][1] == 4 && back_f[0][0] == 4 && back_f[0][1] == 3) {
        // 3ª possibilidade
        printf("[SPLIT PAIR BY GOING OVER 4º CASO] [TESTE] 3ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][2] == 3 && top_f[0][2] == 1 && top_f[1][2] == 4 && right_f[0][2] == 4 && right_f[0][1] == 3) {
        // 4ª possibilidade
        printf("[SPLIT PAIR BY GOING OVER 4º CASO] [TESTE] 4ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[0][0] == 6 && top_f[2][0] == 1 && top_f[1][0] == 3 && left_f[0][1] == 6 && left_f[0][2] == 3) {
        // 5ª possibilidade
        printf("[SPLIT PAIR BY GOING OVER 4º CASO] [TESTE] 5ª possibilidade\n");
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][0] == 6 && top_f[0][0] == 1 && top_f[0][1] == 3 && back_f[0][0] == 3 && back_f[0][1] == 6) {
        // 6ª possibilidade
        printf("[SPLIT PAIR BY GOING OVER 4º CASO] [TESTE] 6ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][2] == 6 && top_f[0][2] == 1 && top_f[1][2] == 3 && right_f[0][2] == 3 && right_f[0][1] == 6) {
        // 7ª possibilidade
        printf("[SPLIT PAIR BY GOING OVER 4º CASO] [TESTE] 7ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[0][0] == 6 && top_f[2][1] == 3 && top_f[2][2] == 1 && front_f[0][1] == 6 && front_f[0][2] == 3) {
        // 8ª possibilidade
        printf("[SPLIT PAIR BY GOING OVER 4º CASO] [TESTE] 8ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][0] == 5 && top_f[0][0] == 1 && top_f[0][1] == 6 && back_f[0][0] == 6 && back_f[0][1] == 5) {
        // 9ª possibilidade
        printf("[SPLIT PAIR BY GOING OVER 4º CASO] [TESTE] 9ª possibilidade\n");
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][2] == 5 && top_f[0][2] == 1 && top_f[1][2] == 6 && right_f[0][2] == 6 && right_f[0][1] == 5) {
        // 10ª possibilidade
        printf("[SPLIT PAIR BY GOING OVER 4º CASO] [TESTE] 10ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[0][0] == 5 && front_f[0][1] == 5 && front_f[0][2] == 6 && top_f[2][1] == 6 && top_f[2][2] == 1) {
        // 11ª possibilidade
        printf("[SPLIT PAIR BY GOING OVER 4º CASO] [TESTE] 11ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[0][0] == 5 && top_f[2][0] == 1 && top_f[1][0] == 6 && left_f[0][2] == 6 && left_f[0][1] == 5) {
        // 12ª possibilidade
        printf("[SPLIT PAIR BY GOING OVER 4º CASO] [TESTE] 12ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][2] == 4 && top_f[0][2] == 1 && top_f[1][2] == 5 && right_f[0][1] == 4 && right_f[0][2] == 5) {
        // 13ª possibilidade
        printf("[SPLIT PAIR BY GOING OVER 4º CASO] [TESTE] 13ª possibilidade\n");
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[0][0] == 4 && top_f[2][2] == 1 && top_f[2][1] == 5 && front_f[0][1] == 4 && front_f[0][2] == 5) {
        // 14ª possibilidade
        printf("[SPLIT PAIR BY GOING OVER 4º CASO] [TESTE] 14ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[0][0] == 4 && top_f[2][0] == 1 && top_f[1][0] == 5 && left_f[0][2] == 5 && left_f[0][1] == 4) {
        // 15ª possibilidade
        printf("[SPLIT PAIR BY GOING OVER 4º CASO] [TESTE] 15ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][0] == 4 && top_f[0][0] == 1 && top_f[0][1] == 5 && back_f[0][0] == 5 && back_f[0][1] == 4) {
        // 16ª possibilidade
        printf("[SPLIT PAIR BY GOING OVER 4º CASO] [TESTE] 16ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }

    // FIM do 4º y' (R' U 2 R) U (R' U' R) ==> F' U² F U F' U' F

    // FIM do SPLIT PAIR BY GOING OVER (15-18)

    // PAIR MADE ON SIDE (19-22)

    // 1º U (R U 2 R') U (R U' R') - 16 possibilidades

    if (front_f[0][2] == 4 && top_f[2][2] == 1 && right_f[0][0] == 3 && top_f[0][1] == 3 && back_f[0][1] == 4) {
        // 1ª possibilidade
        printf("[PAIR MADE ON SIDE 1º CASO] [TESTE] 1ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][2] == 4 && top_f[2][0] == 1 && front_f[0][0] == 3 && top_f[1][2] == 3 && right_f[0][1] == 4) {
        // 2ª possibilidade
        printf("[PAIR MADE ON SIDE 1º CASO] [TESTE] 2ª possibilidade\n");
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][0] == 4 && top_f[0][0] == 1 && left_f[0][0] == 3 && top_f[2][1] == 3 && front_f[0][1] == 4) {
        // 3ª possibilidade
        printf("[PAIR MADE ON SIDE 1º CASO] [TESTE] 3ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[0][2] == 1 && back_f[0][2] == 3 && right_f[0][2] == 4 && top_f[1][0] == 3 && left_f[0][1] == 4) {
        // 4ª possibilidade
        printf("[PAIR MADE ON SIDE 1º CASO] [TESTE] 4ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[2][0] == 1 && left_f[0][2] == 3 && front_f[0][0] == 6 && top_f[1][2] == 6 && right_f[0][1] == 3) {
        // 5ª possibilidade
        printf("[PAIR MADE ON SIDE 1º CASO] [TESTE] 5ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][0] == 3 && top_f[0][0] == 1 && left_f[0][0] == 6 && top_f[2][1] == 6 && front_f[0][1] == 3) {
        // 6ª possibilidade
        printf("[PAIR MADE ON SIDE 1º CASO] [TESTE] 6ª possibilidade\n");
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[0][2] == 1 && back_f[0][2] == 6 && right_f[0][2] == 3 && top_f[1][0] == 6 && left_f[0][1] == 3) {
        // 7ª possibilidade
        printf("[PAIR MADE ON SIDE 1º CASO] [TESTE] 7ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[2][2] == 1 && front_f[0][2] == 3 && right_f[0][0] == 6 && top_f[0][1] == 6 && back_f[0][1] == 3) {
        // 8ª possibilidade
        printf("[PAIR MADE ON SIDE 1º CASO] [TESTE] 8ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[0][0] == 1 && back_f[0][0] == 6 && left_f[0][0] == 5 && top_f[2][1] == 5 && front_f[0][1] == 6) {
        // 9ª possibilidade
        printf("[PAIR MADE ON SIDE 1º CASO] [TESTE] 9ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[0][2] == 1 && back_f[0][2] == 5 && right_f[0][2] == 6 && top_f[1][0] == 5 && left_f[0][1] == 6) {
        // 10ª possibilidade
        printf("[PAIR MADE ON SIDE 1º CASO] [TESTE] 10ª possibilidade\n");
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[2][2] == 1 && front_f[0][2] == 6 && right_f[0][0] == 5 && top_f[0][1] == 5 && back_f[0][1] == 6) {
        // 11ª possibilidade
        printf("[PAIR MADE ON SIDE 1º CASO] [TESTE] 11ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[2][0] == 1 && front_f[0][0] == 5 && left_f[0][2] == 6 && top_f[1][2] == 5 && right_f[0][1] == 6) {
        // 12ª possibilidade
        printf("[PAIR MADE ON SIDE 1º CASO] [TESTE] 12ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[0][2] == 1 && back_f[0][2] == 4 && right_f[0][2] == 5 && top_f[1][0] == 4 && left_f[0][1] == 5) {
        // 13ª possibilidade
        printf("[PAIR MADE ON SIDE 1º CASO] [TESTE] 13ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[2][2] == 1 && front_f[0][2] == 5 && right_f[0][0] == 4 && top_f[0][1] == 4 && back_f[0][1] == 5) {
        // 14ª possibilidade
        printf("[PAIR MADE ON SIDE 1º CASO] [TESTE] 14ª possibilidade\n");
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[2][0] == 1 && front_f[0][0] == 4 && left_f[0][2] == 5 && top_f[1][2] == 4 && right_f[0][1] == 5) {
        // 15ª possibilidade
        printf("[PAIR MADE ON SIDE 1º CASO] [TESTE] 15ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[0][0] == 1 && back_f[0][0] == 5 && left_f[0][0] == 4 && top_f[2][1] == 4 && front_f[0][1] == 5) {
        // 16ª possibilidade
        printf("[PAIR MADE ON SIDE 1º CASO] [TESTE] 16ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }

    // FIM do 1º U (R U 2 R') U (R U' R')

    // 2º U² (R U R' U)(R U' R') - 16 possibilidades

    if (top_f[2][2] == 1 && front_f[0][2] == 4 && right_f[0][0] == 3 && top_f[1][0] == 3 && left_f[0][1] == 4) {
        // 1ª possibilidade
        printf("[PAIR MADE ON SIDE 2º CASO] [TESTE] 1ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[2][0] == 1 && front_f[0][0] == 3 && left_f[0][2] == 4 && top_f[0][1] == 3 && back_f[0][1] == 4) {
        // 2ª possibilidade
        printf("[PAIR MADE ON SIDE 2º CASO] [TESTE] 2ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[0][0] == 1 && back_f[0][0] == 4 && left_f[0][0] == 3 && top_f[1][2] == 3 && right_f[0][1] == 4) {
        // 3ª possibilidade
        printf("[PAIR MADE ON SIDE 2º CASO] [TESTE] 3ª possibilidade\n");
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[0][2] == 1 && right_f[0][2] == 4 && back_f[0][2] == 3 && top_f[2][1] == 3 && front_f[0][1] == 4) {
        // 4ª possibilidade
        printf("[PAIR MADE ON SIDE 2º CASO] [TESTE] 4ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[2][0] == 1 && front_f[0][0] == 6 && left_f[0][2] == 3 && top_f[0][1] == 6 && back_f[0][1] == 3) {
        // 5ª possibilidade
        printf("[PAIR MADE ON SIDE 2º CASO] [TESTE] 5ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[0][0] == 1 && back_f[0][0] == 3 && left_f[0][0] == 6 && top_f[1][2] == 6 && right_f[0][1] == 3) {
        // 6ª possibilidade
        printf("[PAIR MADE ON SIDE 2º CASO] [TESTE] 6ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[0][2] == 1 && back_f[0][2] == 6 && right_f[0][2] == 3 && top_f[2][1] == 6 && front_f[0][1] == 3) {
        // 7ª possibilidade
        printf("[PAIR MADE ON SIDE 2º CASO] [TESTE] 7ª possibilidade\n");
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[2][2] == 1 && front_f[0][2] == 3 && right_f[0][0] == 6 && top_f[1][0] == 6 && left_f[0][1] == 3) {
        // 8ª possibilidade
        printf("[PAIR MADE ON SIDE 2º CASO] [TESTE] 8ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[0][0] == 1 && back_f[0][0] == 6 && left_f[0][0] == 5 && top_f[1][2] == 5 && right_f[0][1] == 6) {
        // 9ª possibilidade
        printf("[PAIR MADE ON SIDE 2º CASO] [TESTE] 9ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[0][2] == 1 && back_f[0][2] == 5 && right_f[0][2] == 6 && top_f[2][1] == 5 && front_f[0][1] == 6) {
        // 10ª possibilidade
        printf("[PAIR MADE ON SIDE 2º CASO] [TESTE] 10ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[2][2] == 1 && front_f[0][2] == 6 && right_f[0][0] == 5 && top_f[1][0] == 5 && left_f[0][1] == 6) {
        // 11ª possibilidade
        printf("[PAIR MADE ON SIDE 2º CASO] [TESTE] 11ª possibilidade\n");
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[2][0] == 1 && front_f[0][0] == 5 && left_f[0][2] == 6 && top_f[0][1] == 5 && back_f[0][1] == 6) {
        // 12ª possibilidade
        printf("[PAIR MADE ON SIDE 2º CASO] [TESTE] 12ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[0][2] == 1 && back_f[0][2] == 4 && right_f[0][2] == 5 && top_f[2][1] == 4 && front_f[0][1] == 5) {
        // 13ª possibilidade
        printf("[PAIR MADE ON SIDE 2º CASO] [TESTE] 13ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[2][2] == 1 && front_f[0][2] == 5 && right_f[0][0] == 4 && top_f[1][0] == 4 && left_f[0][1] == 5) {
        // 14ª possibilidade
        printf("[PAIR MADE ON SIDE 2º CASO] [TESTE] 14ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[2][0] == 1 && front_f[0][0] == 4 && left_f[0][2] == 5 && top_f[0][1] == 4 && back_f[0][1] == 5) {
        // 15ª possibilidade
        printf("[PAIR MADE ON SIDE 2º CASO] [TESTE] 15ª possibilidade\n");
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[0][0] == 1 && back_f[0][0] == 5 && left_f[0][0] == 4 && top_f[1][2] == 4 && right_f[0][1] == 5) {
        // 16ª possibilidade
        printf("[PAIR MADE ON SIDE 2º CASO] [TESTE] 16ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }

    // FIM da 2º U² (R U R' U)(R U' R') 

    // 3º y' U' (R' U² R) U' (R' U R) ==> U' F' U² F U' F' U F - 16 possibilidades

    if (top_f[2][2] == 1 && front_f[0][2] == 4 && right_f[0][0] == 3 && top_f[1][0] == 4 && left_f[0][1] == 3) {
        // 1ª possibilidade
        printf("[PAIR MADE ON SIDE 3º CASO] [TESTE] 1ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[2][0] == 1 && front_f[0][0] == 3 && left_f[0][2] == 4 && top_f[0][1] == 4 && back_f[0][1] == 3) {
        // 2ª possibilidade
        printf("[PAIR MADE ON SIDE 3º CASO] [TESTE] 2ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[0][0] == 1 && back_f[0][0] == 4 && left_f[0][0] == 3 && top_f[1][2] == 4 && right_f[0][1] == 3) {
        // 3ª possibilidade
        printf("[PAIR MADE ON SIDE 3º CASO] [TESTE] 3ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[0][2] == 1 && back_f[0][2] == 3 && right_f[0][2] == 4 && top_f[2][1] == 4 && front_f[0][1] == 3) {
        // 4ª possibilidade
        printf("[PAIR MADE ON SIDE 3º CASO] [TESTE] 4ª possibilidade\n");
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[2][0] == 1 && front_f[0][0] == 6 && left_f[0][2] == 3 && top_f[0][1] == 3 && back_f[0][1] == 6) {
        // 5ª possibilidade
        printf("[PAIR MADE ON SIDE 3º CASO] [TESTE] 5ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[0][0] == 1 && back_f[0][0] == 3 && left_f[0][0] == 6 && top_f[1][2] == 3 && right_f[0][1] == 6) {
        // 6ª possibilidade
        printf("[PAIR MADE ON SIDE 3º CASO] [TESTE] 6ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[0][2] == 1 && back_f[0][2] == 6 && right_f[0][2] == 3 && top_f[2][1] == 3 && front_f[0][1] == 6) {
        // 7ª possibilidade
        printf("[PAIR MADE ON SIDE 3º CASO] [TESTE] 7ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[2][2] == 1 && front_f[0][2] == 3 && right_f[0][0] == 6 && top_f[1][0] == 3 && left_f[0][1] == 6) {
        // 8ª possibilidade
        printf("[PAIR MADE ON SIDE 3º CASO] [TESTE] 8ª possibilidade\n");
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[0][0] == 1 && back_f[0][0] == 6 && left_f[0][0] == 5 && top_f[1][2] == 6 && right_f[0][1] == 5) {
        // 9ª possibilidade
        printf("[PAIR MADE ON SIDE 3º CASO] [TESTE] 9ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[0][2] == 1 && back_f[0][2] == 5 && right_f[0][2] == 6 && top_f[2][1] == 6 && front_f[0][1] == 5) {
        // 10ª possibilidade
        printf("[PAIR MADE ON SIDE 3º CASO] [TESTE] 10ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[2][2] == 1 && front_f[0][2] == 6 && right_f[0][0] == 5 && top_f[1][0] == 6 && left_f[0][1] == 5) {
        // 11ª possibilidade
        printf("[PAIR MADE ON SIDE 3º CASO] [TESTE] 11ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[2][0] == 1 && front_f[0][0] == 5 && left_f[0][2] == 6 && top_f[0][1] == 6 && back_f[0][1] == 5) {
        // 12ª possibilidade
        printf("[PAIR MADE ON SIDE 3º CASO] [TESTE] 12ª possibilidade\n");
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[0][2] == 1 && back_f[0][2] == 4 && right_f[0][2] == 5 && top_f[2][1] == 5 && front_f[0][1] == 4) {
        // 13ª possibilidade
        printf("[PAIR MADE ON SIDE 3º CASO] [TESTE] 13ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[2][2] == 1 && front_f[0][2] == 5 && right_f[0][0] == 4 && top_f[1][0] == 5 && left_f[0][1] == 4) {
        // 14ª possibilidade
        printf("[PAIR MADE ON SIDE 3º CASO] [TESTE] 14ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[2][0] == 1 && front_f[0][0] == 4 && left_f[0][2] == 5 && top_f[0][1] == 5 && back_f[0][1] == 4) {
        // 15ª possibilidade
        printf("[PAIR MADE ON SIDE 3º CASO] [TESTE] 15ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[0][0] == 1 && back_f[0][0] == 5 && left_f[0][0] == 4 && top_f[1][2] == 5 && right_f[0][1] == 4) {
        // 16ª possibilidade
        printf("[PAIR MADE ON SIDE 3º CASO] [TESTE] 16ª possibilidade\n");
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }

    // FIM da 3º y' U' (R' U² R) U' (R' U R) ==> U' F' U² F U' F' U F 

    // 4º y' U 2 (R' U' R U')(R' U R) ==> U² F' U' F U' F' U F - 16 possibilidades

    if (top_f[2][2] == 1 && front_f[0][2] == 4 && right_f[0][0] == 3 && top_f[0][1] == 4 && back_f[0][1] == 3) {
        // 1ª possibilidade
        printf("[PAIR MADE ON SIDE 4º CASO] [TESTE] 1ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[2][0] == 1 && front_f[0][0] == 3 && left_f[0][2] == 4 && top_f[1][2] == 4 && right_f[0][1] == 3) {
        // 2ª possibilidade
        printf("[PAIR MADE ON SIDE 4º CASO] [TESTE] 2ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[0][0] == 1 && back_f[0][0] == 4 && left_f[0][0] == 3 && top_f[2][1] == 4 && front_f[0][1] == 3) {
        // 3ª possibilidade
        printf("[PAIR MADE ON SIDE 4º CASO] [TESTE] 3ª possibilidade\n");
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[0][2] == 1 && back_f[0][2] == 3 && right_f[0][2] == 4 && top_f[1][0] == 4 && left_f[0][1] == 3) {
        // 4ª possibilidade
        printf("[PAIR MADE ON SIDE 4º CASO] [TESTE] 4ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[2][0] == 1 && front_f[0][0] == 6 && left_f[0][2] == 3 && top_f[1][2] == 3 && right_f[0][1] == 6) {
        // 5ª possibilidade
        printf("[PAIR MADE ON SIDE 4º CASO] [TESTE] 5ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[0][0] == 1 && back_f[0][0] == 3 && left_f[0][0] == 6 && top_f[2][1] == 3 && front_f[0][1] == 6) {
        // 6ª possibilidade
        printf("[PAIR MADE ON SIDE 4º CASO] [TESTE] 6ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[0][2] == 1 && back_f[0][2] == 6 && right_f[0][2] == 3 && top_f[1][0] == 3 && left_f[0][1] == 6) {
        // 7ª possibilidade
        printf("[PAIR MADE ON SIDE 4º CASO] [TESTE] 7ª possibilidade\n");
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[2][2] == 1 && front_f[0][2] == 3 && right_f[0][0] == 6 && top_f[0][1] == 3 && back_f[0][1] == 6) {
        // 8ª possibilidade
        printf("[PAIR MADE ON SIDE 4º CASO] [TESTE] 8ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[0][0] == 1 && back_f[0][0] == 6 && left_f[0][0] == 5 && top_f[2][1] == 6 && front_f[0][1] == 5) {
        // 9ª possibilidade
        printf("[PAIR MADE ON SIDE 4º CASO] [TESTE] 9ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[0][2] == 1 && back_f[0][2] == 5 && right_f[0][2] == 6 && top_f[1][0] == 6 && left_f[0][1] == 5) {
        // 10ª possibilidade
        printf("[PAIR MADE ON SIDE 4º CASO] [TESTE] 10ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[2][2] == 1 && front_f[0][2] == 6 && right_f[0][0] == 5 && top_f[0][1] == 6 && back_f[0][1] == 5) {
        // 11ª possibilidade
        printf("[PAIR MADE ON SIDE 4º CASO] [TESTE] 11ª possibilidade\n");
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[2][0] == 1 && front_f[0][0] == 5 && left_f[0][2] == 6 && top_f[1][2] == 6 && right_f[0][1] == 5) {
        // 12ª possibilidade
        printf("[PAIR MADE ON SIDE 4º CASO] [TESTE] 12ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[0][2] == 1 && back_f[0][2] == 4 && right_f[0][2] == 5 && top_f[1][0] == 5 && left_f[0][1] == 4) {
        // 13ª possibilidade
        printf("[PAIR MADE ON SIDE 4º CASO] [TESTE] 13ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[2][2] == 1 && front_f[0][2] == 5 && right_f[0][0] == 4 && top_f[0][1] == 5 && back_f[0][1] == 4) {
        // 14ª possibilidade
        printf("[PAIR MADE ON SIDE 4º CASO] [TESTE] 14ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[2][0] == 1 && front_f[0][0] == 4 && left_f[0][2] == 5 && top_f[1][2] == 5 && right_f[0][1] == 4) {
        // 15ª possibilidade
        printf("[PAIR MADE ON SIDE 4º CASO] [TESTE] 15ª possibilidade\n");
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[0][0] == 1 && back_f[0][0] == 5 && left_f[0][0] == 4 && top_f[2][1] == 5 && front_f[0][1] == 4) {
        // 16ª possibilidade
        printf("[PAIR MADE ON SIDE 4º CASO] [TESTE] 16ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }


    //FIM da 4º y' U 2 (R' U' R U')(R' U R) ==> U² F' U' F U' F' U F

    // FIM do PAIR MADE ON SIDE (19-22)

    // WEIRD (23-24)

    // 1º U2 R2 U2 (R' U' R U') R2 - 16 possibilidades

    if (top_f[2][2] == 1 && top_f[2][1] == 3 && front_f[0][1] == 4 && front_f[0][2] == 4 && right_f[0][0] == 3) {
        // 1ª possibilidade
        printf("[WEIRD 1º CASO] [TESTE] 1ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[0][0] == 3 && top_f[1][0] == 3 && top_f[2][0] == 1 && left_f[0][1] == 4 && left_f[0][2] == 4) {
        // 2ª possibilidade
        printf("[WEIRD 1º CASO] [TESTE] 2ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][0] == 3 && top_f[0][0] == 1 && top_f[0][1] == 3 && back_f[0][0] == 4 && back_f[0][1] == 4) {
        // 3ª possibilidade
        printf("[WEIRD 1º CASO] [TESTE] 3ª possibilidade\n");
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][2] == 3 && top_f[0][2] == 1 && top_f[1][2] == 3 && right_f[0][2] == 4 && right_f[0][1] == 4) {
        // 4ª possibilidade
        printf("[WEIRD 1º CASO] [TESTE] 4ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[0][0] == 6 && top_f[1][0] == 6 && top_f[2][0] == 1 && left_f[0][2] == 3 && left_f[0][1] == 3) {
        // 5ª possibilidade
        printf("[WEIRD 1º CASO] [TESTE] 5ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][0] == 6 && top_f[0][0] == 1 && top_f[0][1] == 6 && back_f[0][0] == 3 && back_f[0][1] == 3) {
        // 6ª possibilidade
        printf("[WEIRD 1º CASO] [TESTE] 6ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][2] == 6 && top_f[0][2] == 1 && top_f[1][2] == 6 && right_f[0][2] == 3 && right_f[0][1] == 3) {
        // 7ª possibilidade
        printf("[WEIRD 1º CASO] [TESTE] 7ª possibilidade\n");
        frontClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[0][0] == 6 && top_f[2][1] == 6 && top_f[2][2] == 1 && front_f[0][1] == 3 && front_f[0][2] == 3) {
        // 8ª possibilidade
        printf("[WEIRD 1º CASO] [TESTE] 8ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][0] == 5 && top_f[0][0] == 1 && top_f[0][1] == 5 && back_f[0][0] == 6 && back_f[0][1] == 6) {
        // 9ª possibilidade
        printf("[WEIRD 1º CASO] [TESTE] 9ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][2] == 5 && top_f[0][2] == 1 && top_f[1][2] == 5 && right_f[0][2] == 6 && right_f[0][1] == 6) {
        // 10ª possibilidade
        printf("[WEIRD 1º CASO] [TESTE] 10ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[0][0] == 5 && top_f[2][1] == 5 && top_f[2][2] == 1 && front_f[0][1] == 6 && front_f[0][2] == 6) {
        // 11ª possibilidade
        printf("[WEIRD 1º CASO] [TESTE] 11ª possibilidade\n");
        leftClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[0][0] == 5 && top_f[1][0] == 5 && top_f[2][0] == 1 && left_f[0][2] == 6 && left_f[0][1] == 6) {
        // 12ª possibilidade
        printf("[WEIRD 1º CASO] [TESTE] 12ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][2] == 4 && top_f[0][2] == 1 && top_f[1][2] == 4 && right_f[0][1] == 5 && right_f[0][2] == 5) {
        // 13ª possibilidade
        printf("[WEIRD 1º CASO] [TESTE] 13ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[0][0] == 4 && top_f[2][1] == 4 && top_f[2][2] == 1 && front_f[0][1] == 5 && front_f[0][2] == 5) {
        // 14ª possibilidade
        printf("[WEIRD 1º CASO] [TESTE] 14ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[0][0] == 4 && top_f[1][0] == 4 && top_f[2][0] == 1 && left_f[0][2] == 5 && left_f[0][1] == 5) {
        // 15ª possibilidade
        printf("[WEIRD 1º CASO] [TESTE] 15ª possibilidade\n");
        backClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][0] == 4 && top_f[0][0] == 1 && top_f[0][1] == 4 && back_f[0][0] == 5 && back_f[0][1] == 5) {
        // 16ª possibilidade
        printf("[WEIRD 1º CASO] [TESTE] 16ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }

    // FIM da 1º U2 R2 U2 (R' U' R U') R2

    // 2º y' U 2 R 2 U 2 (R U R' U) R 2 --> F U R U' R' F' R U' R' - 16 possibilidades

    if (front_f[0][2] == 4 && top_f[1][2] == 4 && top_f[2][2] == 1 && right_f[0][0] == 3 && right_f[0][1] == 3) {
        // 1ª possibilidade
        printf("[WEIRD 2º CASO] [TESTE] 1ª possibilidade\n");
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][2] == 4 && top_f[2][0] == 1 && top_f[2][1] == 4 && front_f[0][0] == 3 && front_f[0][1] == 3) {
        // 2ª possibilidade
        printf("[WEIRD 2º CASO] [TESTE] 2ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][0] == 4 && top_f[0][0] == 1 && top_f[1][0] == 4 && left_f[0][0] == 3 && left_f[0][1] == 3) {
        // 3ª possibilidade
        printf("[WEIRD 2º CASO] [TESTE] 3ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[0][2] == 4 && top_f[0][1] == 4 && top_f[0][2] == 1 && back_f[0][1] == 3 && back_f[0][2] == 3) {
        // 4ª possibilidade
        printf("[WEIRD 2º CASO] [TESTE] 4ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][2] == 3 && top_f[2][0] == 1 && top_f[2][1] == 3 && front_f[0][0] == 6 && front_f[0][1] == 6) {
        // 5ª possibilidade
        printf("[WEIRD 2º CASO] [TESTE] 5ª possibilidade\n");
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][0] == 3 && top_f[0][0] == 1 && top_f[1][0] == 3 && left_f[0][0] == 6 && left_f[0][1] == 6) {
        // 6ª possibilidade
        printf("[WEIRD 2º CASO] [TESTE] 6ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[0][2] == 3 && top_f[0][1] == 3 && top_f[0][2] == 1 && back_f[0][1] == 6 && back_f[0][2] == 6) {
        // 7ª possibilidade
        printf("[WEIRD 2º CASO] [TESTE] 7ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[0][2] == 3 && top_f[1][2] == 3 && top_f[2][2] == 1 && right_f[0][0] == 6 && right_f[0][1] == 6) {
        // 8ª possibilidade
        printf("[WEIRD 2º CASO] [TESTE] 8ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][0] == 6 && top_f[1][0] == 6 && top_f[0][0] == 1 && left_f[0][0] == 5 && left_f[0][1] == 5) {
        // 9ª possibilidade
        printf("[WEIRD 2º CASO] [TESTE] 9ª possibilidade\n");
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[0][2] == 6 && top_f[0][1] == 6 && top_f[0][2] == 1 && back_f[0][2] == 5 && back_f[0][1] == 5) {
        // 10ª possibilidade
        printf("[WEIRD 2º CASO] [TESTE] 10ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[0][2] == 6 && top_f[2][2] == 1 && top_f[1][2] == 6 && right_f[0][0] == 5 && right_f[0][1] == 5) {
        // 11ª possibilidade
        printf("[WEIRD 2º CASO] [TESTE] 11ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][2] == 6 && top_f[2][0] == 1 && top_f[2][1] == 6 && front_f[0][0] == 5 && front_f[0][1] == 5) {
        // 12ª possibilidade
        printf("[WEIRD 2º CASO] [TESTE] 12ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[0][2] == 5 && top_f[0][1] == 5 && top_f[0][2] == 1 && back_f[0][2] == 4 && back_f[0][1] == 4) {
        // 13ª possibilidade
        printf("[WEIRD 2º CASO] [TESTE] 13ª possibilidade\n");
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[0][2] == 5 && top_f[1][2] == 5 && top_f[2][2] == 1 && right_f[0][0] == 4 && right_f[0][1] == 4) {
        // 14ª possibilidade
        printf("[WEIRD 2º CASO] [TESTE] 14ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][2] == 5 && top_f[2][0] == 1 && top_f[2][1] == 5 && front_f[0][0] == 4 && front_f[0][1] == 4) {
        // 15ª possibilidade
        printf("[WEIRD 2º CASO] [TESTE] 15ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][0] == 5 && top_f[0][0] == 1 && top_f[1][0] == 5 && left_f[0][0] == 4 && left_f[0][1] == 4) {
        // 16ª possibilidade
        printf("[WEIRD 2º CASO] [TESTE] 16ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }


    // FIM da 2º y' U 2 R 2 U 2 (R U R' U) R 2 --> F U R U' R' F' R U' R'

    // FIM do WEIRD

    // CORNER IN PLACE, EDGE IN U FACE (25-30)

    //1º U' (F' U F) U (R U' R') - 16 possibilidades

    if (front_f[2][2] == 3 && right_f[2][0] == 4 && bottom_f[0][2] == 1 && top_f[1][2] == 3 && right_f[0][1] == 4) {
        // 1ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 1º CASO] [TESTE] 1ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[2][2] == 3 && right_f[2][0] == 4 && bottom_f[0][2] == 1 && top_f[2][1] == 3 && front_f[0][1] == 4) {
        // 2ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 1º CASO] [TESTE] 2ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[2][2] == 3 && right_f[2][0] == 4 && bottom_f[0][2] == 1 && top_f[1][0] == 3 && left_f[0][1] == 4) {
        // 3ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 1º CASO] [TESTE] 3ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[2][2] == 3 && right_f[2][0] == 4 && bottom_f[0][2] == 1 && top_f[0][1] == 3 && back_f[0][1] == 4) {
        // 4ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 1º CASO] [TESTE] 4ª possibilidade\n");
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[2][2] == 6 && bottom_f[0][0] == 1 && front_f[2][0] == 3 && top_f[2][1] == 6 && front_f[0][1] == 3) {
        // 5ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 1º CASO] [TESTE] 5ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[2][2] == 6 && bottom_f[0][0] == 1 && front_f[2][0] == 3 && top_f[1][0] == 6 && left_f[0][1] == 3) {
        // 6ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 1º CASO] [TESTE] 6ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[2][2] == 6 && bottom_f[0][0] == 1 && front_f[2][0] == 3 && top_f[0][1] == 6 && back_f[0][1] == 3) {
        // 7ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 1º CASO] [TESTE] 7ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[2][2] == 6 && bottom_f[0][0] == 1 && front_f[2][0] == 3 && top_f[1][2] == 6 && right_f[0][1] == 3) {
        // 8ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 1º CASO] [TESTE] 8ª possibilidade\n");
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[2][0] == 5 && bottom_f[2][0] == 1 && left_f[2][0] == 6 && top_f[1][0] == 5 && left_f[0][1] == 6) {
        // 9ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 1º CASO] [TESTE] 9ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[2][0] == 5 && bottom_f[2][0] == 1 && left_f[2][0] == 6 && top_f[0][1] == 5 && back_f[0][1] == 6) {
        // 10ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 1º CASO] [TESTE] 10ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[2][0] == 5 && bottom_f[2][0] == 1 && left_f[2][0] == 6 && top_f[1][2] == 5 && right_f[0][1] == 6) {
        // 11ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 1º CASO] [TESTE] 11ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[2][0] == 5 && bottom_f[2][0] == 1 && left_f[2][0] == 6 && top_f[2][1] == 5 && front_f[0][1] == 6) {
        // 12ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 1º CASO] [TESTE] 12ª possibilidade\n");
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[2][2] == 4 && bottom_f[2][2] == 1 && back_f[2][2] == 5 && top_f[0][1] == 4 && back_f[0][1] == 5) {
        // 13ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 1º CASO] [TESTE] 13ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[2][2] == 4 && bottom_f[2][2] == 1 && back_f[2][2] == 5 && top_f[1][2] == 4 && right_f[0][1] == 5) {
        // 14ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 1º CASO] [TESTE] 14ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[2][2] == 4 && bottom_f[2][2] == 1 && back_f[2][2] == 5 && top_f[2][1] == 4 && front_f[0][1] == 5) {
        // 15ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 1º CASO] [TESTE] 15ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[2][2] == 4 && bottom_f[2][2] == 1 && back_f[2][2] == 5 && top_f[1][0] == 4 && left_f[0][1] == 5) {
        // 16ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 1º CASO] [TESTE] 16ª possibilidade\n");
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }

    // FIM do 1º U' (F' U F) U (R U' R')

    // 2º (R U' R' U)(R U' R') - 16 possibilidades

    if (front_f[2][2] == 1 && bottom_f[0][2] == 4 && right_f[2][0] == 3 && top_f[1][2] == 3 && right_f[0][1] == 4) {
        // 1ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 2º CASO] [TESTE] 1ª possibilidade\n");
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[2][2] == 1 && bottom_f[0][2] == 4 && right_f[2][0] == 3 && top_f[2][1] == 3 && front_f[0][1] == 4) {
        // 2ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 2º CASO] [TESTE] 2ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[2][2] == 1 && bottom_f[0][2] == 4 && right_f[2][0] == 3 && top_f[1][0] == 3 && left_f[0][1] == 4) {
        // 3ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 2º CASO] [TESTE] 3ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[2][2] == 1 && bottom_f[0][2] == 4 && right_f[2][0] == 3 && top_f[0][1] == 3 && back_f[0][1] == 4) {
        // 4ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 2º CASO] [TESTE] 4ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[2][2] == 1 && front_f[2][0] == 6 && bottom_f[0][0] == 3 && top_f[2][1] == 6 && front_f[0][1] == 3) {
        // 5ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 2º CASO] [TESTE] 5ª possibilidade\n");
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[2][2] == 1 && front_f[2][0] == 6 && bottom_f[0][0] == 3 && top_f[1][0] == 6 && left_f[0][1] == 3) {
        // 6ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 2º CASO] [TESTE] 6ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[2][2] == 1 && front_f[2][0] == 6 && bottom_f[0][0] == 3 && top_f[0][1] == 6 && back_f[0][1] == 3) {
        // 7ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 2º CASO] [TESTE] 7ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[2][2] == 1 && front_f[2][0] == 6 && bottom_f[0][0] == 3 && top_f[1][2] == 6 && right_f[0][1] == 3) {
        // 8ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 2º CASO] [TESTE] 8ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[2][0] == 1 && bottom_f[2][0] == 6 && left_f[2][0] == 5 && top_f[1][0] == 5 && left_f[0][1] == 6) {
        // 9ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 2º CASO] [TESTE] 9ª possibilidade\n");
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[2][0] == 1 && bottom_f[2][0] == 6 && left_f[2][0] == 5 && top_f[0][1] == 5 && back_f[0][1] == 6) {
        // 10ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 2º CASO] [TESTE] 10ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[2][0] == 1 && bottom_f[2][0] == 6 && left_f[2][0] == 5 && top_f[1][2] == 5 && right_f[0][1] == 6) {
        // 11ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 2º CASO] [TESTE] 11ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[2][0] == 1 && bottom_f[2][0] == 6 && left_f[2][0] == 5 && top_f[2][1] == 5 && front_f[0][1] == 6) {
        // 12ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 2º CASO] [TESTE] 12ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[2][2] == 1 && back_f[2][2] == 4 && bottom_f[2][2] == 5 && top_f[0][1] == 4 && back_f[0][1] == 5) {
        // 13ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 2º CASO] [TESTE] 13ª possibilidade\n");
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[2][2] == 1 && back_f[2][2] == 4 && bottom_f[2][2] == 5 && top_f[1][2] == 4 && right_f[0][1] == 5) {
        // 14ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 2º CASO] [TESTE] 14ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[2][2] == 1 && back_f[2][2] == 4 && bottom_f[2][2] == 5 && top_f[2][1] == 4 && front_f[0][1] == 5) {
        // 15ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 2º CASO] [TESTE] 15ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[2][2] == 1 && back_f[2][2] == 4 && bottom_f[2][2] == 5 && top_f[1][0] == 4 && left_f[0][1] == 5) {
        // 16ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 2º CASO] [TESTE] 16ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }

    // FIM da 2ª (R U' R' U)(R U' R')


    // 3º y' (R' U' R U)(R' U' R) ==> R' F R F' U R U' R' - 16 possibilidades

    if (front_f[2][2] == 1 && right_f[2][0] == 3 && bottom_f[0][2] == 4 && top_f[2][1] == 4 && front_f[0][1] == 3) {
        // 1ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 3º CASO] [TESTE] 1ª possibilidade\n");
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[2][2] == 1 && right_f[2][0] == 3 && bottom_f[0][2] == 4 && top_f[1][0] == 4 && left_f[0][1] == 3) {
        // 2ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 3º CASO] [TESTE] 2ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[2][2] == 1 && right_f[2][0] == 3 && bottom_f[0][2] == 4 && top_f[0][1] == 4 && back_f[0][1] == 3) {
        // 3ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 3º CASO] [TESTE] 3ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[2][2] == 1 && right_f[2][0] == 3 && bottom_f[0][2] == 4 && top_f[1][2] == 4 && right_f[0][1] == 3) {
        // 4ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 3º CASO] [TESTE] 4ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[2][2] == 1 && bottom_f[0][0] == 3 && front_f[2][0] == 6 && top_f[1][0] == 3 && left_f[0][1] == 6) {
        // 5ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 3º CASO] [TESTE] 5ª possibilidade\n");
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[2][2] == 1 && bottom_f[0][0] == 3 && front_f[2][0] == 6 && top_f[0][1] == 3 && back_f[0][1] == 6) {
        // 6ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 3º CASO] [TESTE] 6ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[2][2] == 1 && bottom_f[0][0] == 3 && front_f[2][0] == 6 && top_f[1][2] == 3 && right_f[0][1] == 6) {
        // 7ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 3º CASO] [TESTE] 7ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[2][2] == 1 && bottom_f[0][0] == 3 && front_f[2][0] == 6 && top_f[2][1] == 3 && front_f[0][1] == 6) {
        // 8ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 3º CASO] [TESTE] 8ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[2][0] == 1 && bottom_f[2][0] == 6 && left_f[2][0] == 5 && top_f[0][1] == 6 && back_f[0][1] == 5) {
        // 9ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 3º CASO] [TESTE] 9ª possibilidade\n");
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[2][0] == 1 && bottom_f[2][0] == 6 && left_f[2][0] == 5 && top_f[1][2] == 6 && right_f[0][1] == 5) {
        // 10ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 3º CASO] [TESTE] 10ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[2][0] == 1 && bottom_f[2][0] == 6 && left_f[2][0] == 5 && top_f[2][1] == 6 && front_f[0][1] == 5) {
        // 11ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 3º CASO] [TESTE] 11ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[2][0] == 1 && bottom_f[2][0] == 6 && left_f[2][0] == 5 && top_f[1][0] == 6 && left_f[0][1] == 5) {
        // 12ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 3º CASO] [TESTE] 12ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[2][2] == 1 && bottom_f[2][2] == 5 && back_f[2][2] == 4 && top_f[1][2] == 5 && right_f[0][1] == 4) {
        // 13ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 3º CASO] [TESTE] 13ª possibilidade\n");
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[2][2] == 1 && bottom_f[2][2] == 5 && back_f[2][2] == 4 && top_f[2][1] == 5 && front_f[0][1] == 4) {
        // 14ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 3º CASO] [TESTE] 14ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[2][2] == 1 && bottom_f[2][2] == 5 && back_f[2][2] == 4 && top_f[1][0] == 5 && left_f[0][1] == 4) {
        // 15ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 3º CASO] [TESTE] 15ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[2][2] == 1 && bottom_f[2][2] == 5 && back_f[2][2] == 4 && top_f[0][1] == 5 && back_f[0][1] == 4) {
        // 16ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 3º CASO] [TESTE] 16ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }

    // FIM do 3º y' (R' U' R U)(R' U' R) ==> R' F R F' U R U' R'

    // 4º U (R U' R') U' (F' U F)

    if (front_f[2][2] == 3 && right_f[2][0] == 4 && bottom_f[0][2] == 1 && top_f[2][1] == 4 && front_f[0][1] == 3) {
        // 1ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 4º CASO] [TESTE] 1ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[2][2] == 3 && right_f[2][0] == 4 && bottom_f[0][2] == 1 && top_f[1][0] == 4 && left_f[0][1] == 3) {
        // 2ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 4º CASO] [TESTE] 2ª possibilidade\n");
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[2][2] == 3 && right_f[2][0] == 4 && bottom_f[0][2] == 1 && top_f[0][1] == 4 && back_f[0][1] == 3) {
        // 3ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 4º CASO] [TESTE] 3ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[2][2] == 3 && right_f[2][0] == 4 && bottom_f[0][2] == 1 && top_f[1][2] == 4 && right_f[0][1] == 3) {
        // 4ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 4º CASO] [TESTE] 4ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[2][2] == 6 && bottom_f[0][0] == 1 && front_f[2][0] == 3 && top_f[1][0] == 3 && left_f[0][1] == 6) {
        // 5ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 4º CASO] [TESTE] 5ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[2][2] == 6 && bottom_f[0][0] == 1 && front_f[2][0] == 3 && top_f[0][1] == 3 && back_f[0][1] == 6) {
        // 6ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 4º CASO] [TESTE] 6ª possibilidade\n");
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[2][2] == 6 && bottom_f[0][0] == 1 && front_f[2][0] == 3 && top_f[1][2] == 3 && right_f[0][1] == 6) {
        // 7ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 4º CASO] [TESTE] 7ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[2][2] == 6 && bottom_f[0][0] == 1 && front_f[2][0] == 3 && top_f[2][1] == 3 && front_f[0][1] == 6) {
        // 8ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 4º CASO] [TESTE] 8ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[2][0] == 5 && bottom_f[2][0] == 1 && left_f[2][0] == 6 && top_f[0][1] == 6 && back_f[0][1] == 5) {
        // 9ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 4º CASO] [TESTE] 9ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[2][0] == 5 && bottom_f[2][0] == 1 && left_f[2][0] == 6 && top_f[1][2] == 6 && right_f[0][1] == 5) {
        // 10ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 4º CASO] [TESTE] 10ª possibilidade\n");
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[2][0] == 5 && bottom_f[2][0] == 1 && left_f[2][0] == 6 && top_f[2][1] == 6 && front_f[0][1] == 5) {
        // 11ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 4º CASO] [TESTE] 11ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[2][0] == 5 && bottom_f[2][0] == 1 && left_f[2][0] == 6 && top_f[1][0] == 6 && left_f[0][1] == 5) {
        // 12ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 4º CASO] [TESTE] 12ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[2][2] == 4 && back_f[2][2] == 5 && bottom_f[2][2] == 1 && top_f[1][2] == 5 && right_f[0][1] == 4) {
        // 13ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 4º CASO] [TESTE] 13ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[2][2] == 4 && back_f[2][2] == 5 && bottom_f[2][2] == 1 && top_f[2][1] == 5 && front_f[0][1] == 4) {
        // 14ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 4º CASO] [TESTE] 14ª possibilidade\n");
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[2][2] == 4 && back_f[2][2] == 5 && bottom_f[2][2] == 1 && top_f[1][0] == 5 && left_f[0][1] == 4) {
        // 15ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 4º CASO] [TESTE] 15ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[2][2] == 4 && back_f[2][2] == 5 && bottom_f[2][2] == 1 && top_f[0][1] == 5 && back_f[0][1] == 4) {
        // 16ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 4º CASO] [TESTE] 16ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }

    // FIM do 4º U (R U' R') U' (F' U F)

    // 5º (R U' R') U 2 (F' U F) - 16 possibilidades

    if (bottom_f[0][2] == 3 && front_f[2][2] == 4 && right_f[2][0] == 1 && top_f[2][1] == 4 && front_f[0][1] == 3) {
        // 1ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 5º CASO] [TESTE] 1ª possibilidade\n");
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (bottom_f[0][2] == 3 && front_f[2][2] == 4 && right_f[2][0] == 1 && top_f[1][0] == 4 && left_f[0][1] == 3) {
        // 2ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 5º CASO] [TESTE] 2ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (bottom_f[0][2] == 3 && front_f[2][2] == 4 && right_f[2][0] == 1 && top_f[0][1] == 4 && back_f[0][1] == 3) {
        // 3ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 5º CASO] [TESTE] 3ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (bottom_f[0][2] == 3 && front_f[2][2] == 4 && right_f[2][0] == 1 && top_f[1][2] == 4 && right_f[0][1] == 3) {
        // 4ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 5º CASO] [TESTE] 4ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[2][0] == 1 && left_f[2][2] == 3 && bottom_f[0][0] == 6 && top_f[1][0] == 3 && left_f[0][1] == 6) {
        // 5ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 5º CASO] [TESTE] 5ª possibilidade\n");
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[2][0] == 1 && left_f[2][2] == 3 && bottom_f[0][0] == 6 && top_f[0][1] == 3 && back_f[0][1] == 6) {
        // 6ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 5º CASO] [TESTE] 6ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[2][0] == 1 && left_f[2][2] == 3 && bottom_f[0][0] == 6 && top_f[1][2] == 3 && right_f[0][1] == 6) {
        // 7ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 5º CASO] [TESTE] 7ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[2][0] == 1 && left_f[2][2] == 3 && bottom_f[0][0] == 6 && top_f[2][1] == 3 && front_f[0][1] == 6) {
        // 8ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 5º CASO] [TESTE] 8ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[2][0] == 1 && back_f[2][0] == 6 && bottom_f[2][0] == 5 && top_f[0][1] == 6 && back_f[0][1] == 5) {
        // 9ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 5º CASO] [TESTE] 9ª possibilidade\n");
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[2][0] == 1 && back_f[2][0] == 6 && bottom_f[2][0] == 5 && top_f[1][2] == 6 && right_f[0][1] == 5) {
        // 10ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 5º CASO] [TESTE] 10ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[2][0] == 1 && back_f[2][0] == 6 && bottom_f[2][0] == 5 && top_f[2][1] == 6 && front_f[0][1] == 5) {
        // 11ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 5º CASO] [TESTE] 11ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[2][0] == 1 && back_f[2][0] == 6 && bottom_f[2][0] == 5 && top_f[1][0] == 6 && left_f[0][1] == 5) {
        // 12ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 5º CASO] [TESTE] 12ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[2][2] == 5 && bottom_f[2][2] == 4 && back_f[2][2] == 1 && top_f[1][2] == 5 && right_f[0][1] == 4) {
        // 13ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 5º CASO] [TESTE] 13ª possibilidade\n");
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[2][2] == 5 && bottom_f[2][2] == 4 && back_f[2][2] == 1 && top_f[2][1] == 5 && front_f[0][1] == 4) {
        // 14ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 5º CASO] [TESTE] 14ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[2][2] == 5 && bottom_f[2][2] == 4 && back_f[2][2] == 1 && top_f[1][0] == 5 && left_f[0][1] == 4) {
        // 15ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 5º CASO] [TESTE] 15ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[2][2] == 5 && bottom_f[2][2] == 4 && back_f[2][2] == 1 && top_f[0][1] == 5 && back_f[0][1] == 4) {
        // 16ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 5º CASO] [TESTE] 16ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }

    // FIM do 5º (R U' R') U 2 (F' U F)

    // 6º (R U R' U')(R U R')

    if (front_f[2][2] == 4 && bottom_f[0][2] == 3 && right_f[2][0] == 1 && top_f[1][2] == 3 && right_f[0][1] == 4) {
        // 1ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 6º CASO] [TESTE] 1ª possibilidade\n");
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[2][2] == 4 && bottom_f[0][2] == 3 && right_f[2][0] == 1 && top_f[2][1] == 3 && front_f[0][1] == 4) {
        // 2ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 6º CASO] [TESTE] 2ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[2][2] == 4 && bottom_f[0][2] == 3 && right_f[2][0] == 1 && top_f[1][0] == 3 && left_f[0][1] == 4) {
        // 3ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 6º CASO] [TESTE] 3ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[2][2] == 4 && bottom_f[0][2] == 3 && right_f[2][0] == 1 && top_f[0][1] == 3 && back_f[0][1] == 4) {
        // 4ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 6º CASO] [TESTE] 4ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[2][0] == 1 && bottom_f[0][0] == 6 && left_f[2][2] == 3 && top_f[2][1] == 6 && front_f[0][1] == 3) {
        // 5ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 6º CASO] [TESTE] 5ª possibilidade\n");
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[2][0] == 1 && bottom_f[0][0] == 6 && left_f[2][2] == 3 && top_f[1][0] == 6 && left_f[0][1] == 3) {
        // 6ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 6º CASO] [TESTE] 6ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[2][0] == 1 && bottom_f[0][0] == 6 && left_f[2][2] == 3 && top_f[0][1] == 6 && back_f[0][1] == 3) {
        // 7ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 6º CASO] [TESTE] 7ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[2][0] == 1 && bottom_f[0][0] == 6 && left_f[2][2] == 3 && top_f[1][2] == 6 && right_f[0][1] == 3) {
        // 8ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 6º CASO] [TESTE] 8ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (bottom_f[2][0] == 5 && back_f[2][0] == 6 && left_f[2][0] == 1 && top_f[1][0] == 5 && left_f[0][1] == 6) {
        // 9ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 6º CASO] [TESTE] 9ª possibilidade\n");
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (bottom_f[2][0] == 5 && back_f[2][0] == 6 && left_f[2][0] == 1 && top_f[0][1] == 5 && back_f[0][1] == 6) {
        // 10ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 6º CASO] [TESTE] 10ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (bottom_f[2][0] == 5 && back_f[2][0] == 6 && left_f[2][0] == 1 && top_f[1][2] == 5 && right_f[0][1] == 6) {
        // 11ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 6º CASO] [TESTE] 11ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (bottom_f[2][0] == 5 && back_f[2][0] == 6 && left_f[2][0] == 1 && top_f[2][1] == 5 && front_f[0][1] == 6) {
        // 12ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 6º CASO] [TESTE] 12ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (bottom_f[2][2] == 4 && right_f[2][2] == 5 && back_f[2][2] == 1 && top_f[0][1] == 4 && back_f[0][1] == 5) {
        // 13ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 6º CASO] [TESTE] 13ª possibilidade\n");
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (bottom_f[2][2] == 4 && right_f[2][2] == 5 && back_f[2][2] == 1 && top_f[1][2] == 4 && right_f[0][1] == 5) {
        // 14ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 6º CASO] [TESTE] 14ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (bottom_f[2][2] == 4 && right_f[2][2] == 5 && back_f[2][2] == 1 && top_f[2][1] == 4 && front_f[0][1] == 5) {
        // 15ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 6º CASO] [TESTE] 15ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (bottom_f[2][2] == 4 && right_f[2][2] == 5 && back_f[2][2] == 1 && top_f[1][0] == 4 && left_f[0][1] == 5) {
        // 16ª possibilidade
        printf("[CORNER IN PLACE, EDGE IN U FACE 6º CASO] [TESTE] 16ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }

    // FIM do 6º (R U R' U')(R U R')

    // FIM do CORNER IN PLACE, EDGE IN U FACE

    // EDGE IN PLACE, CORNER IN U FACE (31-36)

    // 1º (R U' R' U)(F' U F) - 16 possibilidades

    if (front_f[1][2] == 4 && right_f[1][0] == 3 && top_f[2][2] == 1 && front_f[0][2] == 4 && right_f[0][0] == 3) {
        // 1ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 1º CASO] [TESTE] 1ª possibilidade\n");
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[1][2] == 4 && right_f[1][0] == 3 && top_f[2][0] == 1 && front_f[0][0] == 3 && left_f[0][2] == 4) {
        // 2ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 1º CASO] [TESTE] 2ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[1][2] == 4 && right_f[1][0] == 3 && top_f[0][0] == 1 && back_f[0][0] == 4 && left_f[0][0] == 3) {
        // 3ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 1º CASO] [TESTE] 3ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[1][2] == 4 && right_f[1][0] == 3 && top_f[0][2] == 1 && back_f[0][2] == 3 && right_f[0][2] == 4) {
        // 4ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 1º CASO] [TESTE] 4ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[1][2] == 3 && front_f[1][0] == 6 && top_f[2][0] == 1 && front_f[0][0] == 6 && left_f[0][2] == 3) {
        // 5ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 1º CASO] [TESTE] 5ª possibilidade\n");
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[1][2] == 3 && front_f[1][0] == 6 && top_f[0][0] == 1 && back_f[0][0] == 3 && left_f[0][0] == 6) {
        // 6ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 1º CASO] [TESTE] 6ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[1][2] == 3 && front_f[1][0] == 6 && top_f[0][2] == 1 && back_f[0][2] == 6 && right_f[0][2] == 3) {
        // 7ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 1º CASO] [TESTE] 7ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[1][2] == 3 && front_f[1][0] == 6 && top_f[2][2] == 1 && front_f[0][2] == 3 && right_f[0][0] == 6) {
        // 8ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 1º CASO] [TESTE] 8ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[1][0] == 5 && back_f[1][0] == 6 && top_f[0][0] == 1 && back_f[0][0] == 6 && left_f[0][0] == 5) {
        // 9ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 1º CASO] [TESTE] 9ª possibilidade\n");
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[1][0] == 5 && back_f[1][0] == 6 && top_f[0][2] == 1 && back_f[0][2] == 5 && right_f[0][2] == 6) {
        // 10ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 1º CASO] [TESTE] 10ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[1][0] == 5 && back_f[1][0] == 6 && top_f[2][2] == 1 && front_f[0][2] == 6 && right_f[0][0] == 5) {
        // 11ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 1º CASO] [TESTE] 11ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[1][0] == 5 && back_f[1][0] == 6 && top_f[2][0] == 1 && front_f[0][0] == 5 && left_f[0][2] == 6) {
        // 12ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 1º CASO] [TESTE] 12ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[1][2] == 5 && back_f[1][2] == 4 && top_f[0][2] == 1 && back_f[0][2] == 4 && right_f[0][2] == 5) {
        // 13ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 1º CASO] [TESTE] 13ª possibilidade\n");
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[1][2] == 5 && back_f[1][2] == 4 && top_f[2][2] == 1 && front_f[0][2] == 5 && right_f[0][0] == 4) {
        // 14ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 1º CASO] [TESTE] 14ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[1][2] == 5 && back_f[1][2] == 4 && top_f[2][0] == 1 && front_f[0][0] == 4 && left_f[0][2] == 5) {
        // 15ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 1º CASO] [TESTE] 15ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[1][2] == 5 && back_f[1][2] == 4 && top_f[0][0] == 1 && back_f[0][0] == 5 && left_f[0][0] == 4) {
        // 16ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 1º CASO] [TESTE] 16ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }

    // FIM do 1º (R U' R' U)(F' U F)

    // 2º (U' R U' R') U 2 (R U' R') - 16 possibilidades

    if (front_f[1][2] == 3 && right_f[1][0] == 4 && top_f[2][2] == 3 && front_f[0][2] == 1 && right_f[0][0] == 4) {
        // 1ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 2º CASO] [TESTE] 1ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[1][2] == 3 && right_f[1][0] == 4 && left_f[0][2] == 1 && top_f[2][0] == 3 && front_f[0][0] == 4) {
        // 2ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 2º CASO] [TESTE] 2ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[1][2] == 3 && right_f[1][0] == 4 && top_f[0][0] == 3 && back_f[0][0] == 1 && left_f[0][0] == 4) {
        // 3ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 2º CASO] [TESTE] 3ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[1][2] == 3 && right_f[1][0] == 4 && top_f[0][2] == 3 && right_f[0][2] == 1 && back_f[0][2] == 4) {
        // 4ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 2º CASO] [TESTE] 4ª possibilidade\n");
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[1][2] == 6 && front_f[1][0] == 3 && left_f[0][2] == 1 && top_f[2][0] == 6 && front_f[0][0] == 3) {
        // 5ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 2º CASO] [TESTE] 5ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[1][2] == 6 && front_f[1][0] == 3 && back_f[0][0] == 1 && top_f[0][0] == 6 && left_f[0][0] == 3) {
        // 6ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 2º CASO] [TESTE] 6ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[1][2] == 6 && front_f[1][0] == 3 && top_f[0][2] == 6 && back_f[0][2] == 3 && right_f[0][2] == 1) {
        // 7ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 2º CASO] [TESTE] 7ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[1][2] == 6 && front_f[1][0] == 3 && front_f[0][2] == 1 && top_f[2][2] == 6 && right_f[0][0] == 3) {
        // 8ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 2º CASO] [TESTE] 8ª possibilidade\n");
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[1][0] == 6 && back_f[1][0] == 5 && back_f[0][0] == 1 && top_f[0][0] == 5 && left_f[0][0] == 6) {
        // 9ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 2º CASO] [TESTE] 9ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[1][0] == 6 && back_f[1][0] == 5 && top_f[0][2] == 5 && back_f[0][2] == 6 && right_f[0][2] == 1) {
        // 10ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 2º CASO] [TESTE] 10ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[1][0] == 6 && back_f[1][0] == 5 && front_f[0][2] == 1 && top_f[2][2] == 5 && right_f[0][0] == 6) {
        // 11ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 2º CASO] [TESTE] 11ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[1][0] == 6 && back_f[1][0] == 5 && front_f[0][0] == 6 && top_f[2][0] == 5 && left_f[0][2] == 1) {
        // 12ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 2º CASO] [TESTE] 12ª possibilidade\n");
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[1][2] == 4 && back_f[1][2] == 5 && right_f[0][2] == 1 && top_f[0][2] == 4 && back_f[0][2] == 5) {
        // 13ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 2º CASO] [TESTE] 13ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[1][2] == 4 && back_f[1][2] == 5 && front_f[0][2] == 1 && top_f[2][2] == 4 && right_f[0][0] == 5) {
        // 14ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 2º CASO] [TESTE] 14ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[1][2] == 4 && back_f[1][2] == 5 && left_f[0][2] == 1 && top_f[2][0] == 4 && front_f[0][0] == 5) {
        // 15ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 2º CASO] [TESTE] 15ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[1][2] == 4 && back_f[1][2] == 5 && back_f[0][0] == 1 && top_f[0][0] == 4 && left_f[0][0] == 5) {
        // 16ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 2º CASO] [TESTE] 16ª possibilidade\n");
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }

    // FIM do 2º (U' R U' R') U 2 (R U' R')

    // 3º U 2 (R U' R') U' (F' U' F) - 16 possibilidades

    if (front_f[1][2] == 4 && right_f[1][0] == 3 && front_f[0][2] == 1 && top_f[2][2] == 3 && right_f[0][0] == 4) {
        // 1ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 3º CASO] [TESTE] 1ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[1][2] == 4 && right_f[1][0] == 3 && left_f[0][2] == 1 && top_f[2][0] == 3 && front_f[0][0] == 4) {
        // 2ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 3º CASO] [TESTE] 2ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[1][2] == 4 && right_f[1][0] == 3 && back_f[0][0] == 1 && top_f[0][0] == 3 && left_f[0][0] == 4) {
        // 3ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 3º CASO] [TESTE] 3ª possibilidade\n");
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[1][2] == 4 && right_f[1][0] == 3 && back_f[0][2] == 4 && top_f[0][2] == 3 && right_f[0][2] == 1) {
        // 4ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 3º CASO] [TESTE] 4ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[1][2] == 3 && front_f[1][0] == 6 && top_f[2][0] == 6 && front_f[0][0] == 3 && left_f[0][2] == 1) {
        // 5ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 3º CASO] [TESTE] 5ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[1][2] == 3 && front_f[1][0] == 6 && back_f[0][0] == 1 && top_f[0][0] == 6 && left_f[0][0] == 3) {
        // 6ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 3º CASO] [TESTE] 6ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[1][2] == 3 && front_f[1][0] == 6 && top_f[0][2] == 6 && right_f[0][2] == 1 && back_f[0][2] == 3) {
        // 7ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 3º CASO] [TESTE] 7ª possibilidade\n");
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[1][2] == 3 && front_f[1][0] == 6 && front_f[0][2] == 1 && top_f[2][2] == 6 && right_f[0][0] == 3) {
        // 8ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 3º CASO] [TESTE] 8ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[1][0] == 6 && left_f[1][0] == 5 && back_f[0][0] == 1 && top_f[0][0] == 5 && left_f[0][0] == 6) {
        // 9ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 3º CASO] [TESTE] 9ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[1][0] == 6 && left_f[1][0] == 5 && right_f[0][2] == 1 && back_f[0][2] == 6 && top_f[0][2] == 5) {
        // 10ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 3º CASO] [TESTE] 10ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[1][0] == 6 && left_f[1][0] == 5 && front_f[0][2] == 1 && top_f[2][2] == 5 && right_f[0][0] == 6) {
        // 11ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 3º CASO] [TESTE] 11ª possibilidade\n");
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[1][0] == 6 && left_f[1][0] == 5 && left_f[0][2] == 1 && front_f[0][0] == 6 && top_f[2][0] == 5) {
        // 12ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 3º CASO] [TESTE] 12ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[1][2] == 5 && back_f[1][2] == 4 && right_f[0][2] == 1 && top_f[0][2] == 4 && back_f[0][2] == 5) {
        // 13ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 3º CASO] [TESTE] 13ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[1][2] == 5 && back_f[1][2] == 4 && front_f[0][2] == 1 && top_f[2][2] == 4 && right_f[0][0] == 5) {
        // 14ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 3º CASO] [TESTE] 14ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[1][2] == 5 && back_f[1][2] == 4 && left_f[0][2] == 1 && front_f[0][0] == 5 && top_f[2][0] == 4) {
        // 15ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 3º CASO] [TESTE] 15ª possibilidade\n");
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[1][2] == 5 && back_f[1][2] == 4 && back_f[0][0] == 1 && top_f[0][0] == 4 && left_f[0][0] == 5) {
        // 16ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 3º CASO] [TESTE] 16ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }

    // FIM do 3º U 2 (R U' R') U' (F' U' F)

    // 4º (R U R' U')(R U R' U')(R U R') - 16 possibilidades

    if (front_f[1][2] == 3 && right_f[1][0] == 4 && top_f[2][2] == 1 && front_f[0][2] == 4 && right_f[0][0] == 3) {
        // 1ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 4º CASO] [TESTE] 1ª possibilidade\n");
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[1][2] == 3 && right_f[1][0] == 4 && top_f[2][0] == 1 && front_f[0][0] == 3 && left_f[0][2] == 4) {
        // 2ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 4º CASO] [TESTE] 2ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[1][2] == 3 && right_f[1][0] == 4 && top_f[0][0] == 1 && back_f[0][0] == 4 && left_f[0][0] == 3) {
        // 3ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 4º CASO] [TESTE] 3ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[1][2] == 3 && right_f[1][0] == 4 && top_f[0][2] == 1 && back_f[0][2] == 3 && right_f[0][2] == 4) {
        // 4ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 4º CASO] [TESTE] 4ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[1][0] == 3 && left_f[1][2] == 6 && top_f[2][0] == 1 && front_f[0][0] == 6 && left_f[0][2] == 3) {
        // 5ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 4º CASO] [TESTE] 5ª possibilidade\n");
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[1][0] == 3 && left_f[1][2] == 6 && top_f[0][0] == 1 && back_f[0][0] == 3 && left_f[0][0] == 6) {
        // 6ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 4º CASO] [TESTE] 6ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[1][0] == 3 && left_f[1][2] == 6 && top_f[0][2] == 1 && back_f[0][2] == 6 && right_f[0][2] == 3) {
        // 7ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 4º CASO] [TESTE] 7ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[1][0] == 3 && left_f[1][2] == 6 && top_f[2][2] == 1 && front_f[0][2] == 3 && right_f[0][0] == 6) {
        // 8ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 4º CASO] [TESTE] 8ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[1][0] == 6 && back_f[1][0] == 5 && top_f[0][0] == 1 && back_f[0][0] == 6 && left_f[0][0] == 5) {
        // 9ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 4º CASO] [TESTE] 9ª possibilidade\n");
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[1][0] == 6 && back_f[1][0] == 5 && top_f[0][2] == 1 && back_f[0][2] == 5 && right_f[0][2] == 6) {
        // 10ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 4º CASO] [TESTE] 10ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[1][0] == 6 && back_f[1][0] == 5 && top_f[2][2] == 1 && front_f[0][2] == 6 && right_f[0][0] == 5) {
        // 11ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 4º CASO] [TESTE] 11ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[1][0] == 6 && back_f[1][0] == 5 && top_f[2][0] == 1 && front_f[0][0] == 5 && left_f[0][2] == 6) {
        // 12ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 4º CASO] [TESTE] 12ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[1][2] == 4 && back_f[1][2] == 5 && top_f[0][2] == 1 && back_f[0][2] == 4 && right_f[0][2] == 5) {
        // 13ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 4º CASO] [TESTE] 13ª possibilidade\n");
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[1][2] == 4 && back_f[1][2] == 5 && top_f[2][2] == 1 && front_f[0][2] == 5 && right_f[0][0] == 4) {
        // 14ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 4º CASO] [TESTE] 14ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[1][2] == 4 && back_f[1][2] == 5 && top_f[2][0] == 1 && front_f[0][0] == 4 && left_f[0][2] == 5) {
        // 15ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 4º CASO] [TESTE] 15ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[1][2] == 4 && back_f[1][2] == 5 && top_f[0][0] == 1 && back_f[0][0] == 5 && left_f[0][0] == 4) {
        // 16ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 4º CASO] [TESTE] 16ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }

    // FIM do 4º (R U R' U')(R U R' U')(R U R')

    // 5º U' (R U2  R') U (R U R') - 16 possibilidades

    if (front_f[1][2] == 3 && right_f[1][0] == 4 && right_f[0][0] == 1 && front_f[0][2] == 3 && top_f[2][2] == 4) {
        // 1ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 5º CASO] [TESTE] 1ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[1][2] == 3 && right_f[1][0] == 4 && front_f[0][0] == 1 && top_f[2][0] == 4 && left_f[0][2] == 3) {
        // 2ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 5º CASO] [TESTE] 2ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[1][2] == 3 && right_f[1][0] == 4 && back_f[0][0] == 3 && top_f[0][0] == 4 && left_f[0][0] == 1) {
        // 3ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 5º CASO] [TESTE] 3ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[1][2] == 3 && right_f[1][0] == 4 && back_f[0][2] == 1 && top_f[0][2] == 4 && right_f[0][2] == 3) {
        // 4ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 5º CASO] [TESTE] 4ª possibilidade\n");
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[1][0] == 3 && left_f[1][2] == 6 && front_f[0][0] == 1 && top_f[2][0] == 3 && left_f[0][2] == 6) {
        // 5ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 5º CASO] [TESTE] 5ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[1][0] == 3 && left_f[1][2] == 6 && top_f[0][0] == 3 && left_f[0][0] == 1 && back_f[0][0] == 6) {
        // 6ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 5º CASO] [TESTE] 6ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[1][0] == 3 && left_f[1][2] == 6 && back_f[0][2] == 1 && top_f[0][2] == 3 && right_f[0][2] == 6) {
        // 7ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 5º CASO] [TESTE] 7ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[1][0] == 3 && left_f[1][2] == 6 && right_f[0][0] == 1 && top_f[2][2] == 3 && front_f[0][2] == 6) {
        // 8ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 5º CASO] [TESTE] 8ª possibilidade\n");
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[1][0] == 6 && back_f[1][0] == 5 && top_f[0][0] == 6 && left_f[0][0] == 1 && back_f[0][0] == 5) {
        // 9ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 5º CASO] [TESTE] 9ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[1][0] == 6 && back_f[1][0] == 5 && top_f[0][2] == 6 && back_f[0][2] == 1 && right_f[0][2] == 5) {
        // 10ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 5º CASO] [TESTE] 10ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[1][0] == 6 && back_f[1][0] == 5 && right_f[0][0] == 1 && top_f[2][2] == 6 && front_f[0][2] == 5) {
        // 11ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 5º CASO] [TESTE] 11ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[1][0] == 6 && back_f[1][0] == 5 && top_f[2][0] == 6 && front_f[0][0] == 1 && left_f[0][2] == 5) {
        // 12ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 5º CASO] [TESTE] 12ª possibilidade\n");
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[1][2] == 4 && back_f[1][2] == 5 && top_f[0][2] == 5 && right_f[0][2] == 4 && back_f[0][2] == 1) {
        // 13ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 5º CASO] [TESTE] 13ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[1][2] == 4 && back_f[1][2] == 5 && front_f[0][2] == 4 && top_f[2][2] == 5 && right_f[0][0] == 1) {
        // 14ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 5º CASO] [TESTE] 14ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[1][2] == 4 && back_f[1][2] == 5 && front_f[0][0] == 1 && top_f[2][0] == 5 && left_f[0][2] == 4) {
        // 15ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 5º CASO] [TESTE] 15ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[1][2] == 4 && back_f[1][2] == 5 && top_f[0][0] == 5 && back_f[0][0] == 4 && left_f[0][0] == 1) {
        // 16ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 5º CASO] [TESTE] 16ª possibilidade\n");
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }


    // FIM do 5º U' (R U 2 ' R') U (R U R')

    // 6º d (R' U' R) d' (R U R') ==> U F' U' F U' R U R' - 16 possibilidades

    if (front_f[1][2] == 4 && right_f[1][0] == 3 && front_f[0][2] == 3 && right_f[0][0] == 1 && top_f[2][2] == 4) {
        // 1ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 6º CASO] [TESTE] 1ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[1][2] == 4 && right_f[1][0] == 3 && front_f[0][0] == 1 && top_f[2][0] == 4 && left_f[0][2] == 3) {
        // 2ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 6º CASO] [TESTE] 2ª possibilidade\n");
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[1][2] == 4 && right_f[1][0] == 3 && top_f[0][0] == 4 && back_f[0][0] == 3 && left_f[0][0] == 1) {
        // 3ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 6º CASO] [TESTE] 3ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[1][2] == 4 && right_f[1][0] == 3 && top_f[0][2] == 4 && back_f[0][2] == 1 && right_f[0][2] == 3) {
        // 4ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 6º CASO] [TESTE] 4ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[1][0] == 6 && left_f[1][2] == 3 && front_f[0][0] == 1 && top_f[2][0] == 3 && left_f[0][2] == 6) {
        // 5ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 6º CASO] [TESTE] 5ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[1][0] == 6 && left_f[1][2] == 3 && top_f[0][0] == 3 && back_f[0][0] == 6 && left_f[0][0] == 1) {
        // 6ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 6º CASO] [TESTE] 6ª possibilidade\n");
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[1][0] == 6 && left_f[1][2] == 3 && top_f[0][2] == 3 && back_f[0][2] == 1 && right_f[0][2] == 6) {
        // 7ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 6º CASO] [TESTE] 7ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[1][0] == 6 && left_f[1][2] == 3 && front_f[0][2] == 6 && top_f[2][2] == 3 && right_f[0][0] == 1) {
        // 8ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 6º CASO] [TESTE] 8ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[1][0] == 6 && left_f[1][0] == 5 && left_f[0][0] == 1 && top_f[0][0] == 6 && back_f[0][0] == 5) {
        // 9ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 6º CASO] [TESTE] 9ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[1][0] == 6 && left_f[1][0] == 5 && top_f[0][2] == 6 && back_f[0][2] == 1 && right_f[0][2] == 5) {
        // 10ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 6º CASO] [TESTE] 10ª possibilidade\n");
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[1][0] == 6 && left_f[1][0] == 5 && front_f[0][2] == 5 && top_f[2][2] == 6 && right_f[0][0] == 1) {
        // 11ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 6º CASO] [TESTE] 11ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[1][0] == 6 && left_f[1][0] == 5 && front_f[0][0] == 1 && top_f[2][0] == 6 && left_f[0][2] == 5) {
        // 12ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 6º CASO] [TESTE] 12ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[1][2] == 5 && back_f[1][2] == 4 && back_f[0][2] == 1 && top_f[0][2] == 5 && right_f[0][2] == 4) {
        // 13ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 6º CASO] [TESTE] 13ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[1][2] == 5 && back_f[1][2] == 4 && front_f[0][2] == 4 && top_f[2][2] == 5 && right_f[0][0] == 1) {
        // 14ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 6º CASO] [TESTE] 14ª possibilidade\n");
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[1][2] == 5 && back_f[1][2] == 4 && front_f[0][0] == 1 && top_f[2][0] == 5 && left_f[0][2] == 4) {
        // 15ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 6º CASO] [TESTE] 15ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[1][2] == 5 && back_f[1][2] == 4 && left_f[0][0] == 1 && back_f[0][0] == 4 && top_f[0][0] == 5) {
        // 16ª possibilidade
        printf("[EDGE IN PLACE, CORNER IN U FACE 6º CASO] [TESTE] 16ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }

    // FIM do 6º d (R' U' R) d' (R U R') ==> U F' U' F U' R U R'

    // FIM do EDGE IN PLACE, CORNER IN U FACE

    // EDGE AND CORNER IN PLACE (37-42)

    // 1º (R U' R') U' (R U R') U 2 (R U' R') - 4 possibilidades

    if (front_f[1][2] == 3 && right_f[1][0] == 4 && front_f[2][2] == 1 && right_f[2][0] == 3 && bottom_f[0][2] == 4) {
        // 1ª possibilidade
        printf("[EDGE AND CORNER IN PLACE 1º CASO] [TESTE] 1ª possibilidade\n");
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[1][2] == 6 && front_f[1][0] == 3 && left_f[2][2] == 1 && front_f[2][0] == 6 && bottom_f[0][0] == 3) {
        // 2ª possibilidade
        printf("[EDGE AND CORNER IN PLACE 1º CASO] [TESTE] 2ª possibilidade\n");
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[1][0] == 6 && back_f[1][0] == 5 && left_f[2][0] == 5 && back_f[2][0] == 1 && bottom_f[2][0] == 6) {
        // 3ª possibilidade
        printf("[EDGE AND CORNER IN PLACE 1º CASO] [TESTE] 3ª possibilidade\n");
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[1][2] == 4 && back_f[1][2] == 5 && right_f[2][2] == 1 && back_f[2][2] == 4 && bottom_f[2][2] == 5) {
        // 4ª possibilidade
        printf("[EDGE AND CORNER IN PLACE 1º CASO] [TESTE] 4ª possibilidade\n");
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }

    // FIM do 1º (R U' R') U' (R U R') U 2 (R U' R')

    // 2º (R U' R') d (R' U' R U')(R' U' R) ==> R U' R' U F' U' F U' F' U' F - 4 possibilidades

    if (front_f[1][2] == 4 && front_f[2][2] == 1 && right_f[1][0] == 3 && front_f[2][0] == 3 && bottom_f[0][2] == 4) {
        // 1ª possibilidade
        printf("[EDGE AND CORNER IN PLACE 2º CASO] [TESTE] 1ª possibilidade\n");
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[1][0] == 6 && front_f[2][0] == 6 && left_f[1][2] == 3 && left_f[2][2] == 1 && bottom_f[0][0] == 3) {
        // 2ª possibilidade
        printf("[EDGE AND CORNER IN PLACE 2º CASO] [TESTE] 2ª possibilidade\n");
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[1][0] == 5 && left_f[2][0] == 5 && back_f[1][0] == 6 && back_f[2][0] == 1 && bottom_f[2][0] == 6) {
        // 3ª possibilidade
        printf("[EDGE AND CORNER IN PLACE 2º CASO] [TESTE] 3ª possibilidade\n");
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[1][2] == 4 && back_f[2][2] == 4 && right_f[1][2] == 5 && right_f[2][2] == 1 && bottom_f[2][2] == 5) {
        // 4ª possibilidade
        printf("[EDGE AND CORNER IN PLACE 2º CASO] [TESTE] 4ª possibilidade\n");
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }

    // FIM do 2º (R U' R') d (R' U' R U')(R' U' R) ==> R U' R' U F' U' F U' F' U' F 

    // 3º (R U' R') d (R' U 2 R) U 2 ' (R' U R) ==> R U R' U² R U² R' U F' U' F - 4 possibilidades

    if (front_f[2][2] == 3 && right_f[2][0] == 4 && bottom_f[0][2] == 1 && front_f[1][2] == 4 && right_f[1][0] == 3) {
        // 1ª possibilidade
        printf("[EDGE AND CORNER IN PLACE 3º CASO] [TESTE] 1ª possibilidade\n");
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[2][2] == 6 && front_f[2][0] == 3 && bottom_f[0][0] == 1 && front_f[1][0] == 6 && left_f[1][2] == 3) {
        // 2ª possibilidade
        printf("[EDGE AND CORNER IN PLACE 3º CASO] [TESTE] 2ª possibilidade\n");
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[2][0] == 5 && left_f[2][0] == 6 && bottom_f[2][0] == 1 && left_f[1][0] == 5 && back_f[1][0] == 6) {
        // 3ª possibilidade
        printf("[EDGE AND CORNER IN PLACE 3º CASO] [TESTE] 3ª possibilidade\n");
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[2][2] == 4 && back_f[2][2] == 5 && bottom_f[2][2] == 1 && right_f[1][2] == 5 && back_f[1][2] == 4) {
        // 4ª possibilidade
        printf("[EDGE AND CORNER IN PLACE 3º CASO] [TESTE] 4ª possibilidade\n");
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }

    // FIM do 3º (R U' R') d (R' U 2 R) U 2 ' (R' U R) ==> R U R' U² R U² R' U F' U' F

    // 4º (R U' R' U)(R U 2 ' R') U (R U' R') - 4 possibilidades

    if (front_f[1][2] == 3 && right_f[1][0] == 4 && front_f[2][2] == 4 && right_f[2][0] == 1 && bottom_f[0][2] == 3) {
        // 1ª possibilidade
        printf("[EDGE AND CORNER IN PLACE 4º CASO] [TESTE] 1ª possibilidade\n");
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[1][2] == 6 && front_f[1][0] == 3 && front_f[2][0] == 1 && left_f[2][2] == 3 && bottom_f[0][0] == 6) {
        // 2ª possibilidade
        printf("[EDGE AND CORNER IN PLACE 4º CASO] [TESTE] 2ª possibilidade\n");
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[1][0] == 6 && left_f[2][0] == 1 && back_f[1][0] == 5 && back_f[2][0] == 6 && bottom_f[2][0] == 5) {
        // 3ª possibilidade
        printf("[EDGE AND CORNER IN PLACE 4º CASO] [TESTE] 3ª possibilidade\n");
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[1][2] == 4 && right_f[2][2] == 5 && back_f[1][2] == 5 && back_f[2][2] == 1 && bottom_f[2][2] == 4) {
        // 4ª possibilidade
        printf("[EDGE AND CORNER IN PLACE 4º CASO] [TESTE] 4ª possibilidade\n");
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }

    // FIM do 4º (R U' R' U)(R U 2 ' R') U (R U' R')

    // 5º (R U R' U')(R U' R') U 2 (F' U' F)

    if (front_f[1][2] == 4 && front_f[2][2] == 4 && right_f[1][0] == 3 && right_f[2][0] == 1 && bottom_f[0][2] == 3) {
        // 1ª possibilidade
        printf("[EDGE AND CORNER IN PLACE 5º CASO] [TESTE] 1ª possibilidade\n");
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[1][0] == 6 && front_f[2][0] == 1 && left_f[1][2] == 3 && left_f[2][2] == 3 && bottom_f[0][0] == 6) {
        // 2ª possibilidade
        printf("[EDGE AND CORNER IN PLACE 5º CASO] [TESTE] 2ª possibilidade\n");
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[1][0] == 5 && left_f[2][0] == 1 && back_f[1][0] == 6 && back_f[2][0] == 6 && bottom_f[2][0] == 5) {
        // 3ª possibilidade
        printf("[EDGE AND CORNER IN PLACE 5º CASO] [TESTE] 3ª possibilidade\n");
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[1][2] == 5 && right_f[2][2] == 5 && back_f[1][2] == 4 && back_f[2][2] == 1 && bottom_f[2][2] == 4) {
        // 4ª possibilidade
        printf("[EDGE AND CORNER IN PLACE 5º CASO] [TESTE] 4ª possibilidade\n");
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }


    // 5º (R U R' U')(R U' R') U 2 (F' U' F)

    // FIM do EDGE AND CORNER IN PLACE
}

void primeiraCamada(int left_f[][3], int front_f[][3], int right_f[][3], int top_f[][3], int bottom_f[][3], int back_f[][3]) {
    //FINALIZANDO PRIMEIRA CAMADA
    //(1,3,4)
    if (bottom_f[0][0] == 1 && front_f[2][0] == 4 && left_f[2][2] == 3) {
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (bottom_f[2][0] == 1 && left_f[2][0] == 4 && back_f[2][0] == 3) {
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (bottom_f[2][2] == 1 && right_f[2][2] == 3 && back_f[2][2] == 4) {
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[2][2] == 1 && bottom_f[0][2] == 4 && right_f[2][0] == 3) {
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[2][0] == 1 && bottom_f[0][0] == 3 && left_f[2][2] == 4) {
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[0][2] == 1 && top_f[2][2] == 3 && right_f[0][0] == 4) {
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[0][0] == 1 && top_f[2][0] == 4 && left_f[0][2] == 3) {
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[2][2] == 1 && front_f[2][0] == 3 && bottom_f[0][0] == 4) {
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][2] == 1 && front_f[0][0] == 4 && top_f[2][0] == 3) {
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][0] == 1 && top_f[0][0] == 4 && back_f[0][0] == 3) {
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[2][0] == 1 && bottom_f[2][0] == 3 && back_f[2][0] == 4) {
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[2][0] == 1 && front_f[2][2] == 4 && bottom_f[0][2] == 3) {
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[0][0] == 1 && front_f[0][2] == 3 && top_f[2][2] == 4) {
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[0][2] == 1 && top_f[0][2] == 3 && back_f[0][2] == 4) {
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[2][2] == 1 && bottom_f[2][2] == 4 && back_f[2][2] == 3) {
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[2][2] == 1 && front_f[0][2] == 4 && right_f[0][0] == 3) {
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[2][0] == 1 && front_f[0][0] == 3 && left_f[0][2] == 4) {
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[0][2] == 1 && right_f[0][2] == 4 && back_f[0][2] == 3) {
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[0][0] == 1 && left_f[0][0] == 3 && back_f[0][0] == 4) {
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][0] == 1 && left_f[0][0] == 4 && top_f[0][0] == 3) {
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][2] == 1 && right_f[0][2] == 3 && top_f[0][2] == 4) {
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[2][2] == 1 && bottom_f[2][2] == 3 && right_f[2][2] == 4) {
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[2][0] == 1 && left_f[2][0] == 3 && bottom_f[2][0] == 4) {
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }

    //(1,3,6)
    if (bottom_f[2][0] == 1 && left_f[2][0] == 3 && back_f[2][0] == 6) {
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (bottom_f[2][2] == 1 && right_f[2][2] == 6 && back_f[2][2] == 3) {
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[2][0] == 1 && bottom_f[0][0] == 6 && left_f[2][2] == 3) {
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[0][0] == 1 && top_f[2][0] == 3 && left_f[0][2] == 6) {
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[0][2] == 1 && top_f[2][2] == 6 && right_f[0][0] == 3) {
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[2][2] == 1 && front_f[2][0] == 6 && bottom_f[0][0] == 3) {
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[2][0] == 1 && back_f[2][0] == 3 && bottom_f[2][0] == 6) {
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][2] == 1 && front_f[0][0] == 3 && top_f[2][0] == 6) {
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][0] == 1 && top_f[0][0] == 3 && back_f[0][0] == 6) {
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[0][0] == 1 && front_f[0][2] == 6 && top_f[2][2] == 3) {
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[0][2] == 1 && top_f[0][2] == 6 && back_f[0][2] == 3) {
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[2][2] == 1 && bottom_f[2][2] == 3 && back_f[2][2] == 6) {
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[2][0] == 1 && front_f[0][0] == 6 && left_f[0][2] == 3) {
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[2][2] == 1 && front_f[0][2] == 3 && right_f[0][0] == 6) {
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[0][2] == 1 && right_f[0][2] == 3 && back_f[0][2] == 6) {
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[0][0] == 1 && left_f[0][0] == 6 && back_f[0][0] == 3) {
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][0] == 1 && left_f[0][0] == 3 && top_f[0][0] == 6) {
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][2] == 1 && top_f[0][2] == 3 && right_f[0][2] == 6) {
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[2][0] == 1 && bottom_f[2][0] == 3 && left_f[2][0] == 6) {
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[2][2] == 1 && right_f[2][2] == 3 && bottom_f[2][2] == 6) {
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }

    //(1, 6, 5)
    if (bottom_f[2][2] == 1 && right_f[2][2] == 5 && back_f[2][2] == 6) {
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[2][0] == 1 && bottom_f[2][0] == 6 && left_f[2][0] == 5) {
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[2][2] == 1 && bottom_f[2][2] == 5 && right_f[2][2] == 6) {
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][0] == 1 && top_f[0][0] == 5 && left_f[0][0] == 6) {
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][2] == 1 && top_f[0][2] == 6 && right_f[0][2] == 5) {
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[2][0] == 1 && bottom_f[2][0] == 5 && back_f[2][0] == 6) {
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][2] == 1 && front_f[0][0] == 6 && top_f[2][0] == 5) {
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][0] == 1 && top_f[0][0] == 6 && back_f[0][0] == 5) {
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[0][0] == 1 && front_f[0][2] == 5 && top_f[2][2] == 6) {
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[0][2] == 1 && top_f[0][2] == 5 && back_f[0][2] == 6) {
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[2][2] == 1 && bottom_f[2][2] == 6 && back_f[2][2] == 5) {
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[0][0] == 1 && top_f[2][0] == 6 && left_f[0][2] == 5) {
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[0][2] == 1 && top_f[2][2] == 5 && right_f[0][0] == 6) {
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[2][0] == 1 && front_f[0][0] == 5 && left_f[0][2] == 6) {
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[2][2] == 1 && front_f[0][2] == 6 && right_f[0][0] == 5) {
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[0][0] == 1 && left_f[0][0] == 5 && back_f[0][0] == 6) {
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[0][2] == 1 && right_f[0][2] == 6 && back_f[0][2] == 5) {
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }

    //(1, 4, 5)
    if (right_f[2][2] == 1 && bottom_f[2][2] == 5 && back_f[2][2] == 4) {
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[0][2] == 1 && top_f[0][2] == 4 && back_f[0][2] == 5) {
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[0][0] == 1 && front_f[0][2] == 4 && top_f[2][2] == 5) {
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][2] == 1 && front_f[0][0] == 5 && top_f[2][0] == 4) {
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][0] == 1 && top_f[0][0] == 5 && back_f[0][0] == 4) {
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[0][0] == 1 && top_f[2][0] == 5 && left_f[0][2] == 4) {
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[0][2] == 1 && top_f[2][2] == 4 && right_f[0][0] == 5) {
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[2][2] == 1 && right_f[2][2] == 5 && bottom_f[2][2] == 4) {
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][2] == 1 && right_f[0][2] == 4 && top_f[0][2] == 5) {
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][0] == 1 && top_f[0][0] == 4 && left_f[0][0] == 5) {
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[0][0] == 1 && back_f[0][0] == 5 && left_f[0][0] == 4) {
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[0][2] == 1 && back_f[0][2] == 4 && right_f[0][2] == 5) {
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[2][0] == 1 && front_f[0][0] == 4 && left_f[0][2] == 5) {
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[2][2] == 1 && front_f[0][2] == 5 && right_f[0][0] == 4) {
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }
}

void segundaCamada(int left_f[][3], int front_f[][3], int right_f[][3], int top_f[][3], int bottom_f[][3], int back_f[][3]) {

    //(3, 4)
    if (front_f[1][0] == 3 && left_f[1][2] == 4) {
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[0][1] == 3 && top_f[2][1] == 4) {
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[1][2] == 3 && front_f[1][0] == 4) {
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[1][0] == 3 && back_f[1][0] == 4) {
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][1] == 3 && top_f[1][0] == 4) {
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[1][0] == 3 && front_f[1][2] == 4) {
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[0][1] == 3 && top_f[1][2] == 4) {
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[1][2] == 3 && back_f[1][2] == 4) {
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[1][0] == 3 && left_f[1][0] == 4) {
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[1][2] == 3 && right_f[1][2] == 4) {
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][1] == 3 && top_f[0][1] == 4) {
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[2][1] == 3 && front_f[0][1] == 4) {
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[1][0] == 3 && left_f[0][1] == 4) {
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[1][2] == 3 && right_f[0][1] == 4) {
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[0][1] == 3 && back_f[0][1] == 4) {
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }

    //(3, 6)
    if (front_f[0][1] == 3 && top_f[2][1] == 6) {
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[1][2] == 3 && front_f[1][0] == 6) {
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][1] == 3 && top_f[1][0] == 6) {
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[1][0] == 3 && back_f[1][0] == 6) {
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[1][0] == 3 && left_f[1][0] == 6) {
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[1][2] == 3 && right_f[1][2] == 6) {
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][1] == 3 && top_f[0][1] == 6) {
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[1][2] == 3 && back_f[1][2] == 6) {
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[0][1] == 3 && top_f[1][2] == 6) {
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[1][0] == 3 && left_f[0][1] == 6) {
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[2][1] == 3 && front_f[0][1] == 6) {
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[1][2] == 3 && right_f[0][1] == 6) {
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[0][1] == 3 && back_f[0][1] == 6) {
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }


    //(6, 5)

    if (front_f[0][1] == 6 && top_f[2][1] == 5) {
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][1] == 6 && top_f[1][0] == 5) {
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[1][0] == 6 && left_f[1][0] == 5) {
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[1][2] == 6 && right_f[1][2] == 5) {
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][1] == 6 && top_f[0][1] == 5) {
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[1][2] == 6 && back_f[1][2] == 5) {
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[0][1] == 6 && top_f[1][2] == 5) {
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[2][1] == 6 && front_f[0][1] == 5) {
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[1][2] == 6 && right_f[0][1] == 5) {
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[1][0] == 6 && left_f[0][1] == 5) {
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[0][1] == 6 && back_f[0][1] == 5) {
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }


    //(4, 5)

    if (front_f[0][1] == 4 && top_f[2][1] == 5) {
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][1] == 4 && top_f[1][0] == 5) {
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][1] == 4 && top_f[0][1] == 5) {
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[1][2] == 4 && right_f[1][2] == 5) {
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[0][1] == 4 && top_f[1][2] == 5) {
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[1][0] == 4 && left_f[0][1] == 5) {
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[2][1] == 4 && front_f[0][1] == 5) {
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[1][2] == 4 && right_f[0][1] == 5) {
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[0][1] == 4 && back_f[0][1] == 5) {
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }

}

void oll(int left_f[][3], int front_f[][3], int right_f[][3], int top_f[][3], int bottom_f[][3], int back_f[][3]) {

    // All Edges Oriented Correctly
    // CRUZ PRONTA
    if (top_f[0][1] == 2 && top_f[1][0] == 2 && top_f[1][2] == 2 && top_f[2][1] == 2) {
        // 1º R U R' U' R U' R' 
        if (top_f[0][2] == 2 && right_f[0][0] == 2 && front_f[0][0] == 2 && left_f[0][0] == 2) {
            // 1ª possibilidade
            printf("[ALL EDGES ORIENTED CORRECTLY 1º CASO (OLL)] [TESTE] 1ª possibilidade\n");
            rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
            rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        } else if (top_f[2][2] == 2 && front_f[0][0] == 2 && left_f[0][0] == 2 && back_f[0][2] == 2) {
            // 2ª possibilidade
            printf("[ALL EDGES ORIENTED CORRECTLY 1º CASO (OLL)] [TESTE] 2ª possibilidade\n");
            topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
            rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        } else if (top_f[2][0] == 2 && right_f[0][0] == 2 && back_f[0][2] == 2 && left_f[0][0] == 2) {
            // 3ª possibilidade
            printf("[ALL EDGES ORIENTED CORRECTLY 1º CASO (OLL)] [TESTE] 3ª possibilidade\n");
            topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
            rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
            rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        } else if (top_f[0][0] == 2 && front_f[0][0] == 2 && right_f[0][0] == 2 && back_f[0][2] == 2) {
            // 4ª possibilidade
            printf("[ALL EDGES ORIENTED CORRECTLY 1º CASO (OLL)] [TESTE] 4ª possibilidade\n");
            topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
            rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        }

        // 2º F (R U R' U') (R U R' U') (R U R' U') F'
        if (front_f[0][0] == 2 && front_f[0][2] == 2 && back_f[0][0] == 2 && back_f[0][2] == 2) {
            // 1ª possibilidade
            printf("[ALL EDGES ORIENTED CORRECTLY 2º CASO (OLL)] [TESTE] 1ª possibilidade\n");
            frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        } else if (left_f[0][0] == 2 && left_f[0][2] == 2 && right_f[0][0] == 2 && right_f[0][2] == 2) {
            // 2ª possibilidade
            printf("[ALL EDGES ORIENTED CORRECTLY 2º CASO (OLL)] [TESTE] 2ª possibilidade\n");
            topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        }


        // 3º L F R' F' L' F R F'
        if (top_f[0][2] == 2 && top_f[2][2] == 2 && front_f[0][0] == 2 && back_f[0][0] == 2) {
            // 1ª possibilidade
            printf("[ALL EDGES ORIENTED CORRECTLY 3º CASO (OLL)] [TESTE] 1ª possibilidade\n");
            leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        } else if (top_f[2][0] == 2 && top_f[2][2] == 2 && right_f[0][2] == 2 && left_f[0][0] == 2) {
            // 2ª possibilidade
            printf("[ALL EDGES ORIENTED CORRECTLY 3º CASO (OLL)] [TESTE] 2ª possibilidade\n");
            topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        } else if (top_f[0][0] == 2 && top_f[2][0] == 2 && front_f[0][2] == 2 && back_f[0][2] == 2) {
            // 3ª possibilidade
            printf("[ALL EDGES ORIENTED CORRECTLY 3º CASO (OLL)] [TESTE] 3ª possibilidade\n");
            topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
            leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        } else if (top_f[0][0] == 2 && top_f[0][2] == 2 && right_f[0][0] == 2 && left_f[0][2] == 2) {
            // 4ª possibilidade
            printf("[ALL EDGES ORIENTED CORRECTLY 3º CASO (OLL)] [TESTE] 4ª possibilidade\n");
            topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        }

        // 4º R [D (R' U ) R] [D' (R' U ) R']
        if (top_f[0][0] == 2 && top_f[0][2] == 2 && front_f[0][0] == 2 && front_f[0][2] == 2) {
            // 1ª possibilidade
            printf("[ALL EDGES ORIENTED CORRECTLY 4º CASO (OLL)] [TESTE] 1ª possibilidade\n");
            rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
            bottomClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
            rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            bottomIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
            rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        } else if (top_f[0][2] == 2 && top_f[2][2] == 2 && left_f[0][0] == 2 && left_f[0][2] == 2) {
            // 2ª possibilidade
            printf("[ALL EDGES ORIENTED CORRECTLY 4º CASO (OLL)] [TESTE] 2ª possibilidade\n");
            topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
            bottomClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
            rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            bottomIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
            rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        } else if (top_f[2][0] == 2 && top_f[2][2] == 2 && back_f[0][0] == 2 && back_f[0][2] == 2) {
            // 3ª possibilidade
            printf("[ALL EDGES ORIENTED CORRECTLY 4º CASO (OLL)] [TESTE] 3ª possibilidade\n");
            topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
            rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
            bottomClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
            rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            bottomIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
            rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        } else if (top_f[0][0] == 2 && top_f[2][0] == 2 && right_f[0][0] == 2 && right_f[0][2] == 2) {
            // 4ª possibilidade
            printf("[ALL EDGES ORIENTED CORRECTLY 4º CASO (OLL)] [TESTE] 4ª possibilidade\n");
            topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
            bottomClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
            rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            bottomIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
            rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        }


        // 5º (R U R' U) R U² R'
        if (top_f[2][0] == 2 && front_f[0][2] == 2 && right_f[0][2] == 2 && back_f[0][0] == 2) {
            // 1ª possibilidade
            printf("[ALL EDGES ORIENTED CORRECTLY 5º CASO (OLL)] [TESTE] 1ª possibilidade\n");
            rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
            rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        } else if (top_f[0][0] == 2 && front_f[0][2] == 2 && right_f[0][2] == 2 && left_f[0][2] == 2) {
            // 2ª possibilidade
            printf("[ALL EDGES ORIENTED CORRECTLY 5º CASO (OLL)] [TESTE] 2ª possibilidade\n");
            topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
            rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        } else if (top_f[0][2] == 2 && front_f[0][2] == 2 && left_f[0][2] == 2 && back_f[0][0] == 2) {
            // 3ª possibilidade
            printf("[ALL EDGES ORIENTED CORRECTLY 5º CASO (OLL)] [TESTE] 3ª possibilidade\n");
            topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
            rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
            rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        } else if (top_f[2][2] == 2 && left_f[0][2] == 2 && back_f[0][0] == 2 && right_f[0][2] == 2) {
            // 4ª possibilidade
            printf("[ALL EDGES ORIENTED CORRECTLY 5º CASO (OLL)] [TESTE] 4ª possibilidade\n");
            topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
            rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        }

        // 6º R U2 R2 U' R2 U' R2 U2 R
        if (front_f[0][2] == 2 && left_f[0][0] == 2 && left_f[0][2] == 2 && back_f[0][2] == 2) {
            // 1ª possibilidade
            printf("[ALL EDGES ORIENTED CORRECTLY 6º CASO (OLL)] [TESTE] 1ª possibilidade\n");
            rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
            rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
            topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
            topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
            topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
            rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        } else if (right_f[0][0] == 2 && left_f[0][2] == 2 && back_f[0][0] == 2 && back_f[0][2] == 2) {
            // 2ª possibilidade
            printf("[ALL EDGES ORIENTED CORRECTLY 6º CASO (OLL)] [TESTE] 2ª possibilidade\n");
            topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
            rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
            topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
            topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
            topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
            rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        } else if (front_f[0][0] == 2 && right_f[0][0] == 2 && right_f[0][2] == 2 && back_f[0][0] == 2) {
            // 3ª possibilidade
            printf("[ALL EDGES ORIENTED CORRECTLY 6º CASO (OLL)] [TESTE] 3ª possibilidade\n");
            topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
            rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
            rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
            topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
            topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
            topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
            rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        } else if (front_f[0][0] == 2 && front_f[0][2] == 2 && right_f[0][2] == 2 && left_f[0][0] == 2) {
            // 4ª possibilidade
            printf("[ALL EDGES ORIENTED CORRECTLY 6º CASO (OLL)] [TESTE] 4ª possibilidade\n");
            topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
            rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
            topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
            topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
            topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
            rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        }

        // 7º L F' L' B L F L' B'
        if (top_f[2][0] == 2 && top_f[0][2] == 2 && front_f[0][2] == 2 && left_f[0][0] == 2) {
            // 1ª possibilidade
            printf("[ALL EDGES ORIENTED CORRECTLY 7º CASO (OLL)] [TESTE] 1ª possibilidade\n");
            leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        } else if (top_f[2][2] == 2 && top_f[0][0] == 2 && left_f[0][2] == 2 && back_f[0][2] == 2) {
            // 2ª possibilidade
            printf("[ALL EDGES ORIENTED CORRECTLY 7º CASO (OLL)] [TESTE] 2ª possibilidade\n");
            topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        } else if (top_f[2][0] == 2 && top_f[0][2] == 2 && right_f[0][0] == 2 && back_f[0][0] == 2) {
            // 3ª possibilidade
            printf("[ALL EDGES ORIENTED CORRECTLY 7º CASO (OLL)] [TESTE] 3ª possibilidade\n");
            topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
            leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        } else if (top_f[0][0] == 2 && top_f[2][2] == 2 && front_f[0][0] == 2 && right_f[0][2] == 2) {
            // 4ª possibilidade
            printf("[ALL EDGES ORIENTED CORRECTLY 7º CASO (OLL)] [TESTE] 4ª possibilidade\n");
            topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
            backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        }

    }
    // (FIM DA CRUZ FEITA) - ALL EDGES ORIENTED CORRECTLY

    // CORNERS CORRECT, EDGES FLIPPED
    // 1º L F R' F' L' R U R U' R' - 4 possibilidades
    if (top_f[0][0] == 2 && top_f[0][1] == 2 && top_f[0][2] == 2 && top_f[1][0] == 2 && top_f[1][1] == 2 && top_f[2][0] == 2 && top_f[2][2] == 2 && front_f[0][1] == 2 && right_f[0][1] == 2) {
        // 1ª possibilidade
        printf("[CORNERS CORRECT, EDGES FLIPPED 1º CASO (OLL)] [TESTE] 1ª possibilidade\n");
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][0] == 2 && top_f[0][1] == 2 && top_f[0][2] == 2 && top_f[1][1] == 2 && top_f[1][2] == 2 && top_f[2][0] == 2 && top_f[2][2] == 2 && front_f[0][1] == 2 && left_f[0][1] == 2){
        // 2ª possibilidade
        printf("[CORNERS CORRECT, EDGES FLIPPED 1º CASO (OLL)] [TESTE] 2ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][0] == 2 && top_f[0][2] == 2 && top_f[1][1] == 2 && top_f[1][2] == 2 && top_f[2][0] == 2 && top_f[2][1] == 2 && top_f[2][2] == 2 && left_f[0][1] == 2 && back_f[0][1] == 2){
        // 3ª possibilidade
        printf("[CORNERS CORRECT, EDGES FLIPPED 1º CASO (OLL)] [TESTE] 3ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][0] == 2 && top_f[0][2] == 2 && top_f[1][0] == 2 && top_f[1][1] == 2 && top_f[2][0] == 2 && top_f[2][1] == 2 && top_f[2][2] == 2 && back_f[0][1] == 2 && right_f[0][1] == 2){
        // 4ª possibilidade
        printf("[CORNERS CORRECT, EDGES FLIPPED 1º CASO (OLL)] [TESTE] 4ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }

    // 2º R U R' U' R' L F R F' L'
    if(top_f[0][0] == 2 && top_f[0][2] == 2 && top_f[1][0] && top_f[1][1] == 2 && top_f[1][2] == 2 && top_f[2][0] == 2 && top_f[2][2] == 2 && front_f[0][1] == 2 && back_f[0][1] == 2){
        // 1ª possibilidade
        printf("[CORNERS CORRECT, EDGES FLIPPED 2º CASO (OLL)] [TESTE] 1ª possibilidade\n");
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][0] == 2 && top_f[0][1] == 2 && top_f[0][2] && top_f[1][1] == 2 && top_f[2][0] == 2 && top_f[2][1] == 2 && top_f[2][2] == 2 && left_f[0][1] == 2 && right_f[0][1] == 2){
        // 2ª possibilidade
        printf("[CORNERS CORRECT, EDGES FLIPPED 2º CASO (OLL)] [TESTE] 2ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }
    
    // FIM do CORNERS CORRECT, EDGES FLIPPED
    
    // P-SHAPES
    
    // 1º f (R U R' U') f': F U R U' R' F'
    if(top_f[0][0] == 2 && top_f[0][1] == 2 && top_f[1][0] == 2 && top_f[1][1]== 2 && top_f[2][0] && front_f[0][1] == 2 && right_f[0][0] == 2 && right_f[0][1] == 2 && right_f[0][2] == 2){
        // 1ª possibilidade
        printf("[P-SHAPES 1º CASO (OLL)] [TESTE] 1ª possibilidade\n");
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][0] == 2 && top_f[0][1] == 2 && top_f[0][2] == 2 && top_f[1][1] == 2 && top_f[1][2] == 2 && front_f[0][0] == 2 && front_f[0][1] == 2 && front_f[0][2] == 2 && left_f[0][1] == 2){
        // 2ª possibilidade
        printf("[P-SHAPES 1º CASO (OLL)] [TESTE] 2ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][2] == 2 && top_f[1][1] == 2 && top_f[1][2] == 2 && top_f[2][1] == 2 && top_f[2][2] == 2 && left_f[0][0] == 2 && left_f[0][1] == 2 && left_f[0][2] == 2 && back_f[0][1] == 2){
        // 3ª possibilidade
        printf("[P-SHAPES 1º CASO (OLL)] [TESTE] 3ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[1][0] == 2 && top_f[1][1] == 2 && top_f[2][0] == 2 && top_f[2][1] == 2 && top_f[2][2] == 2 && right_f[0][1] == 2 && back_f[0][0] == 2 && back_f[0][1] == 2 && back_f[0][2] == 2){
        // 4ª possibilidade
        printf("[P-SHAPES 1º CASO (OLL)] [TESTE] 4ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }
    
    // 2º R U B' U' R' U R B R'
    if(top_f[0][2] == 2 && top_f[1][1] == 2 && top_f[1][2] == 2 && top_f[2][1] == 2 && top_f[2][2] == 2 && front_f[0][0] == 2 && left_f[0][1] == 2 && back_f[0][0] == 2 && back_f[0][1] == 2){
        // 1ª possibilidade
        printf("[P-SHAPES 2º CASO (OLL)] [TESTE] 1ª possibilidade\n");
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[1][0] == 2 && top_f[1][1] == 2 && top_f[2][0] == 2 && top_f[2][1] == 2 && top_f[2][2] == 2 && right_f[0][1] == 2 && right_f[0][2] == 2 && back_f[0][1] == 2 && left_f[0][0] == 2){
        // 2ª possibilidade
        printf("[P-SHAPES 2º CASO (OLL)] [TESTE] 2ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][0] == 2 && top_f[0][1] == 2 && top_f[1][0] == 2 && top_f[1][1] == 2 && top_f[2][0] == 2 && front_f[0][1] == 2 && front_f[0][2] == 2 && right_f[0][1] == 2 && back_f[0][2] == 2){
        // 3ª possibilidade
        printf("[P-SHAPES 2º CASO (OLL)] [TESTE] 3ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][0] == 2 && top_f[0][1] == 2 && top_f[0][2] == 2 && top_f[1][1] == 2 && top_f[1][2] == 2 && front_f[0][1] == 2 && right_f[0][0] == 2 && left_f[0][1] == 2 && left_f[0][2] == 2){
        // 4ª possibilidade
        printf("[P-SHAPES 2º CASO (OLL)] [TESTE] 4ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }
    
    // 3º f ' (L' U' L U) f - F' U' L' U L F
    
    if(top_f[0][1] == 2 && top_f[0][2] == 2 && top_f[1][1] == 2 && top_f[1][2] == 2 && top_f[2][2] == 2 && front_f[0][1] == 2 && left_f[0][0] == 2 && left_f[0][1] == 2 && left_f[0][2] == 2){
        // 1ª possibilidade
        printf("[P-SHAPES 3º CASO (OLL)] [TESTE] 1ª possibilidade\n");
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[1][1] == 2 && top_f[1][2] == 2 && top_f[2][0] == 2 && top_f[2][1] == 2 && top_f[2][2] == 2 && left_f[0][1] == 2 && back_f[0][0] == 2 && back_f[0][1] == 2 && back_f[0][2] == 2){
        // 2ª possibilidade
        printf("[P-SHAPES 3º CASO (OLL)] [TESTE] 2ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][0] == 2 && top_f[1][0] == 2 && top_f[1][1] == 2 && top_f[2][0] == 2 && top_f[2][1] == 2 && back_f[0][1] == 2 && right_f[0][0] == 2 && right_f[0][1] == 2 && right_f[0][2] == 2){
        // 3ª possibilidade
        printf("[P-SHAPES 3º CASO (OLL)] [TESTE] 3ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][0] == 2 && top_f[0][1] == 2 && top_f[0][2] == 2 && top_f[1][0] == 2 && top_f[1][1] == 2 && front_f[0][0] == 2 && front_f[0][1] == 2 && front_f[0][2] == 2 && right_f[0][1] == 2){
        // 4ª possibilidade
        printf("[P-SHAPES 3º CASO (OLL)] [TESTE] 4ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }
    
    // 4º R' U' F U R U' R' F' R
    if(top_f[0][1] == 2 && top_f[0][2] == 2 && top_f[1][1] == 2 && top_f[1][2] == 2 && top_f[2][2] == 2 && front_f[0][0] == 2 && front_f[0][1] == 2 && left_f[0][1] == 2 && back_f[0][0] == 2){
        // 1ª possibilidade
        printf("[P-SHAPES 4º CASO (OLL)] [TESTE] 1ª possibilidade\n");
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[1][1] == 2 && top_f[1][2] == 2 && top_f[2][0] == 2 && top_f[2][1] == 2 && top_f[2][2] == 2 && right_f[0][2] == 2 && back_f[0][1] == 2 && left_f[0][0] == 2 && left_f[0][1] == 2){
        // 2ª possibilidade
        printf("[P-SHAPES 4º CASO (OLL)] [TESTE] 2ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][0] == 2 && top_f[1][0] == 2 && top_f[1][1] == 2 && top_f[2][0] == 2 && top_f[2][1] == 2 && front_f[0][2] == 2 && right_f[0][1] == 2 && back_f[0][2] == 2 && back_f[0][1] == 2){
        // 3ª possibilidade
        printf("[P-SHAPES 4º CASO (OLL)] [TESTE] 3ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][0] == 2 && top_f[0][1] == 2 && top_f[0][2] == 2 && top_f[1][0] == 2 && top_f[1][1] == 2 && right_f[0][0] == 2 && right_f[0][1] == 2 && front_f[0][1] == 2 && left_f[0][2] == 2){
        // 4ª possibilidade
        printf("[P-SHAPES 4º CASO (OLL)] [TESTE] 4ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }
    
    // FIM do P-SHAPES
    
    // W-SHAPES
    
    //1º (L' U' L U') (L' U L U) (L F' L' F)
    if(top_f[0][0] == 2 && top_f[0][1] == 2 && top_f[1][1] == 2 && top_f[1][2] == 2 && top_f[2][2] == 2 && front_f[0][1] == 2 && left_f[0][1] == 2 && left_f[0][2] == 2 && back_f[0][2] == 2){
        // 1ª possibilidade
        printf("[W-SHAPES 1º CASO (OLL)] [TESTE] 1ª possibilidade\n");
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][2] == 2 && top_f[1][1] == 2 && top_f[1][2] == 2 && top_f[2][0] == 2 && top_f[2][1] == 2 && right_f[0][0] == 2 && back_f[0][0] == 2 && back_f[0][1] == 2 && left_f[0][1] == 2){
        // 2ª possibilidade
        printf("[W-SHAPES 1º CASO (OLL)] [TESTE] 2ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][0] == 2 && top_f[1][0] == 2 && top_f[1][1] == 2 && top_f[2][1] == 2 && top_f[2][2] == 2 && front_f[0][0] == 2 && back_f[0][1] == 2 && right_f[0][1] == 2 && right_f[0][2] == 2){
        // 3ª possibilidade
        printf("[W-SHAPES 1º CASO (OLL)] [TESTE] 3ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][1] == 2 && top_f[0][2] == 2 && top_f[1][0] == 2 && top_f[1][1] == 2 && top_f[2][0] == 2 && front_f[0][1] == 2 && front_f[0][2] == 2 && left_f[0][0] == 2 && right_f[0][1] == 2){
        // 4ª possibilidade
        printf("[W-SHAPES 1º CASO (OLL)] [TESTE] 4ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }
    
    // 2º (R U R' U) (R U' R' U') (R' F R F')
    if(top_f[0][1] == 2 && top_f[0][2] == 2 && top_f[1][0] == 2 && top_f[1][1] == 2 && top_f[2][0] == 2 && front_f[0][1] == 2 && right_f[0][0] == 2 && right_f[0][1] == 2 && back_f[0][0] == 2){
        // 1ª possibilidade
        printf("[W-SHAPES 2º CASO (OLL)] [TESTE] 1ª possibilidade\n");
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][0] == 2 && top_f[0][1] == 2 && top_f[1][1] == 2 && top_f[1][2] == 2 && top_f[2][2] == 2 && front_f[0][0] == 2 && front_f[0][1] == 2 && right_f[0][2] == 2 && left_f[0][1] == 2){
        // 2ª possibilidade
        printf("[W-SHAPES 2º CASO (OLL)] [TESTE] 2ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][2] == 2 && top_f[1][1] == 2 && top_f[1][2] == 2 && top_f[2][0] == 2 && top_f[2][1] == 2 && front_f[0][2] == 2 && left_f[0][0] == 2 && left_f[0][1] == 2 && back_f[0][1] == 2){
        // 3ª possibilidade
        printf("[W-SHAPES 2º CASO (OLL)] [TESTE] 3ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][0] == 2 && top_f[1][0] == 2 && top_f[1][1] == 2 && top_f[2][1] == 2 && top_f[2][2] == 2 && right_f[0][1] == 2 && left_f[0][2] == 2 && back_f[0][2] == 2 && back_f[0][1] == 2){
        // 4ª possibilidade
        printf("[W-SHAPES 2º CASO (OLL)] [TESTE] 4ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }
    
    // FIM do W-SHAPES
    
    // SQUARES
    
    // 1º r' U² (R U R' U) r - L' B² R B R' B L 
    if(top_f[1][1] == 2 && top_f[1][2] == 2 && top_f[2][1] == 2 && top_f[2][2] == 2 && left_f[0][1] == 2 && left_f[0][2] == 2 && right_f[0][2] == 2 && back_f[0][0] == 2 && back_f[0][1] == 2){
        // 1ª possibilidade
        printf("[SQUARES 1º CASO (OLL)] [TESTE] 1ª possibilidade\n");
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[1][0] == 2 && top_f[1][1] == 2 && top_f[2][0] == 2 && top_f[2][1] == 2 && front_f[0][2] == 2 && right_f[0][1] == 2 && right_f[0][2] == 2 && back_f[0][0] == 2 && back_f[0][1] == 2){
        // 2ª possibilidade
        printf("[SQUARES 1º CASO (OLL)] [TESTE] 2ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][0] == 2 && top_f[0][1] == 2 && top_f[1][0] == 2 && top_f[1][1] == 2 && front_f[0][1] == 2 && front_f[0][2] == 2 && right_f[0][1] == 2 && right_f[0][2] == 2 && left_f[0][2] == 2){
        // 3ª possibilidade
        printf("[SQUARES 1º CASO (OLL)] [TESTE] 3ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][1] == 2 && top_f[0][2] == 2 && top_f[1][1] == 2 && top_f[1][2] == 2 && front_f[0][1] == 2 && front_f[0][2] == 2 && back_f[0][0] == 2 && left_f[0][1] == 2 && left_f[0][2] == 2){
        // 4ª possibilidade
        printf("[SQUARES 1º CASO (OLL)] [TESTE] 4ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }
    
    // 2º r U² R' U' R U' r' - L F² R' F' R F' L'
    
    if(top_f[0][1] == 2 && top_f[0][2] == 2 && top_f[1][1] == 2 && top_f[1][2] == 2 && front_f[0][0] == 2 && front_f[0][1] == 2 && right_f[0][0] == 2 && left_f[0][0] == 2 && left_f[0][1] == 2){
        // 1ª possibilidade
        printf("[SQUARES 2º CASO (OLL)] [TESTE] 1ª possibilidade\n");
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[1][1] == 2 && top_f[1][2] == 2 && top_f[2][1] == 2 && top_f[2][2] == 2 && front_f[0][0] == 2 && left_f[0][0] == 2 && left_f[0][1] == 2 && back_f[0][1] == 2 && back_f[0][2] == 2){
        // 2ª possibilidade
        printf("[SQUARES 2º CASO (OLL)] [TESTE] 2ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[1][0] == 2 && top_f[1][1] == 2 && top_f[2][0] == 2 && top_f[2][1] == 2 && right_f[0][0] == 2 && right_f[0][1] == 2 && back_f[0][1] == 2 && back_f[0][2] == 2 && left_f[0][0] == 2){
        // 3ª possibilidade
        printf("[SQUARES 2º CASO (OLL)] [TESTE] 3ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][0] == 2 && top_f[0][1] == 2 && top_f[1][0] == 2 && top_f[1][1] == 2 && front_f[0][0] == 2 && front_f[0][1] == 2 && right_f[0][0] == 2 && right_f[0][1] == 2 && back_f[0][2] == 2){
        // 4ª possibilidade
        printf("[SQUARES 2º CASO (OLL)] [TESTE] 4ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }
    
    // FIM do Squares
    
    // L SHAPES
    
    // 1º F (R U R' U') (R U R' U') F'
    if(top_f[0][1] == 2 && top_f[1][0] == 2 && top_f[1][1] == 2 && front_f[0][1] == 2 && front_f[0][2] == 2 && right_f[0][1] == 2 && left_f[0][2] == 2 && left_f[0][0] == 2 && back_f[0][2] == 2){
        // 1ª possibilidade
        printf("[L SHAPES 1º CASO (OLL)] [TESTE] 1ª possibilidade\n");
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][1] == 2 && top_f[1][1] == 2 && top_f[1][2] == 2 && front_f[0][1] == 2 && right_f[0][0] == 2 && left_f[0][1] == 2 && left_f[0][2] == 2 && back_f[0][0] == 2 && back_f[0][2] == 2){
        // 2ª possibilidade
        printf("[L SHAPES 1º CASO (OLL)] [TESTE] 2ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[1][1] == 2 && top_f[1][2] == 2 && top_f[2][1] == 2 && front_f[0][0] == 2 && right_f[0][0] == 2 && right_f[0][2] == 2 && left_f[0][1] == 2 && back_f[0][0] == 2 && back_f[0][1] == 2){
        // 3ª possibilidade
        printf("[L SHAPES 1º CASO (OLL)] [TESTE] 3ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[1][0] == 2 && top_f[1][1] == 2 && top_f[2][1] == 2 && front_f[0][0] == 2 && front_f[0][2] == 2 && right_f[0][1] == 2 && right_f[0][2] == 2 && back_f[0][1] == 2 && left_f[0][0] == 2){
        // 4ª possibilidade
        printf("[L SHAPES 1º CASO (OLL)] [TESTE] 4ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }
    
    // 2º (R' F R' F') R² U² y ((R' F R F'): R' F R' F' R² U² B' R B R' 
    if(top_f[0][1] == 2 && top_f[1][1] == 2 && top_f[1][2] == 2 && front_f[0][1] == 2 && front_f[0][2] == 2 && left_f[0][0] == 2 && left_f[0][1] == 2 && left_f[0][2] == 2 && back_f[0][2] == 2){
        // 1ª possibilidade
        printf("[L SHAPES 2º CASO (OLL)] [TESTE] 1ª possibilidade\n");
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[1][1] == 2 && top_f[1][2] == 2 && top_f[2][1] == 2 && right_f[0][0] == 2 && left_f[0][1] == 2 && left_f[0][2] == 2 && back_f[0][0] == 2 && back_f[0][1] == 2 && back_f[0][2] == 2){
        // 2ª possibilidade
        printf("[L SHAPES 2º CASO (OLL)] [TESTE] 2ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[1][0] == 2 && top_f[1][1] == 2 && top_f[2][1] == 2 && front_f[0][0] == 2 && right_f[0][0] == 2 && right_f[0][1] && right_f[0][2] == 2 && back_f[0][0] == 2 && back_f[0][1] == 2){
        // 3ª possibilidade
        printf("[L SHAPES 2º CASO (OLL)] [TESTE] 3ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }else if(top_f[0][1] == 2 && top_f[1][0] == 2 && top_f[1][1] == 2 && front_f[0][0] == 2 && front_f[0][1] == 2 && front_f[0][2] == 2 && right_f[0][1] == 2 && right_f[0][2] == 2 && left_f[0][0] == 2){
        // 4ª possibilidade
        printf("[L SHAPES 2º CASO (OLL)] [TESTE] 4ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }
    
    // 3º l' U' L U' L' U L U' L' U² l: L' B² R B R' B' R B R' B L
    if(top_f[1][0] == 2 && top_f[1][1] == 2 && top_f[2][1] == 2 && front_f[0][0] == 2 && front_f[0][2] == 2 && right_f[0][1] == 2 && back_f[0][0] == 2 && back_f[0][1] == 2 && back_f[0][2] == 2){
        // 1ª possibilidade
        printf("[L SHAPES 3º CASO (OLL)] [TESTE] 1ª possibilidade\n");
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][1] == 2 && top_f[1][0] == 2 && top_f[1][1] == 2 && front_f[0][1] == 2 && right_f[0][0] == 2 && right_f[0][1] == 2 && right_f[0][2] == 2 && left_f[0][0] == 2 && left_f[0][2] == 2){
        // 2ª possibilidade
        printf("[L SHAPES 3º CASO (OLL)] [TESTE] 2ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][1] == 2 && top_f[1][1] == 2 && top_f[1][2] == 2 && front_f[0][0] == 2 && front_f[0][1] == 2 && front_f[0][2] == 2 && left_f[0][1] == 2 && back_f[0][0] == 2 && back_f[0][2] == 2){
        // 3ª possibilidade
        printf("[L SHAPES 3º CASO (OLL)] [TESTE] 3ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[1][1] == 2 && top_f[1][2] == 2 && top_f[2][1] == 2 && right_f[0][0] == 2 && right_f[0][2] == 2 && back_f[0][1] == 2 && left_f[0][0] == 2 && left_f[0][1] == 2 && left_f[0][2] == 2){
        // 4ª possibilidade
        printf("[L SHAPES 3º CASO (OLL)] [TESTE] 4ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }
    
    // 4º F' (L' U' L U) (L' U' L U) F
    if(top_f[0][1] == 2 && top_f[1][1] == 2 && top_f[1][2] == 2 && front_f[0][0] == 2 && front_f[0][1] == 2 && right_f[0][0] == 2 && right_f[0][2] == 2 && left_f[0][1] == 2 && back_f[0][0] == 2){
        // 1ª possibilidade
        printf("[L SHAPES 4º CASO (OLL)] [TESTE] 1ª possibilidade\n");
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[1][1] == 2 && top_f[1][2] == 2 && top_f[2][1] == 2 && front_f[0][0] == 2 && front_f[0][2] == 2 && right_f[0][2] == 2 && back_f[0][1] == 2 && left_f[0][0] == 2 && left_f[0][1] == 2){
        // 2ª possibilidade
        printf("[L SHAPES 4º CASO (OLL)] [TESTE] 2ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[1][0] == 2 && top_f[1][1] == 2 && top_f[2][1] == 2 && front_f[0][2] == 2 && right_f[0][1] == 2 && left_f[0][0] == 2 && left_f[0][2] == 2 && back_f[0][1] == 2 && back_f[0][2] == 2){
        // 3ª possibilidade
        printf("[L SHAPES 4º CASO (OLL)] [TESTE] 3ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][1] == 2 && top_f[1][0] == 2 && top_f[1][1] == 2 && front_f[0][1] == 2 && right_f[0][0] == 2 && right_f[0][1] == 2 && left_f[0][2] == 2 && back_f[0][0] == 2 && back_f[0][2] == 2){
        // 4ª possibilidade
        printf("[L SHAPES 4º CASO (OLL)] [TESTE] 4ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }
    
    // 5º R' F R² B' R² F' R² B R'
    if(top_f[0][1] == 2 && top_f[1][0] == 2 && top_f[1][1] == 2 && front_f[0][0] == 2 && front_f[0][1] == 2 && right_f[0][0] == 2 && right_f[0][1] == 2 && right_f[0][2] == 2 && back_f[0][0] == 2){
        // 1ª possibilidade
        printf("[L SHAPES 5º CASO (OLL)] [TESTE] 1ª possibilidade\n");
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][1] == 2 && top_f[1][1] == 2 && top_f[1][2] == 2 && front_f[0][0] == 2 && front_f[0][1] == 2 && front_f[0][2] == 2 && right_f[0][2] == 2 && left_f[0][0] == 2 && left_f[0][1] == 2){
        // 2ª possibilidade
        printf("[L SHAPES 5º CASO (OLL)] [TESTE] 2ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[1][1] == 2 && top_f[1][2] == 2 && top_f[2][1] == 2 && front_f[0][2] == 2 && left_f[0][0] == 2 && left_f[0][1] == 2 && left_f[0][2] == 2 && back_f[0][1] == 2 && back_f[0][2] == 2){
        // 3ª possibilidade
        printf("[L SHAPES 5º CASO (OLL)] [TESTE] 3ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[1][0] == 2 && top_f[1][1] == 2 && top_f[2][1] == 2 && right_f[0][0] == 2 && right_f[0][1] == 2 && left_f[0][2] == 2 && back_f[0][0] == 2 && back_f[0][1] == 2 && back_f[0][2] == 2){
        // 4ª possibilidade
        printf("[L SHAPES 5º CASO (OLL)] [TESTE] 4ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }
    
    // 6º (r U R' U) R U' R' U R U² r' - L F² R' F' R F R' F' R F' L'   
    if(top_f[0][1] == 2 && top_f[1][0] == 2 && top_f[1][1] == 2 && front_f[0][0] == 2 && front_f[0][1] == 2 && front_f[0][2] == 2 && right_f[0][1] == 2 && back_f[0][0] == 2 && back_f[0][2] == 2){
        // 1ª possibilidade
        printf("[L SHAPES 6º CASO (OLL)] [TESTE] 1ª possibilidade\n");
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][1] == 2 && top_f[1][1] == 2 && top_f[1][2] == 2 && front_f[0][1] == 2 && left_f[0][0] == 2 && left_f[0][1] == 2 && left_f[0][2] == 2 && right_f[0][0] == 2 && right_f[0][2] == 2){
        // 2ª possibilidade
        printf("[L SHAPES 6º CASO (OLL)] [TESTE] 2ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[1][1] == 2 && top_f[1][2] == 2 && top_f[2][1] == 2 && front_f[0][0] == 2 && front_f[0][2] == 2 && left_f[0][1] == 2 && back_f[0][0] == 2 && back_f[0][1] == 2 && back_f[0][2] == 2){
        // 3ª possibilidade
        printf("[L SHAPES 6º CASO (OLL)] [TESTE] 3ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[1][0] == 2 && top_f[1][1] == 2 && top_f[2][1] == 2 && right_f[0][0] == 2 && right_f[0][1] == 2 && right_f[0][2] == 2 && back_f[0][1] == 2 && left_f[0][0] == 2 && left_f[0][2] == 2){
        // 4ª possibilidade
        printf("[L SHAPES 6º CASO (OLL)] [TESTE] 4ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }
    
    // FIM do L SHAPES
    
    // FISH SHAPES
    
    // 1º (R U R' U') R' F R² U R' U' F'
    if(top_f[0][1] == 2 && top_f[1][0] == 2 && top_f[1][1] == 2 && top_f[2][2] == 2 && front_f[0][0] == 2 && front_f[0][1] == 2 && right_f[0][1] == 2 && back_f[0][2] == 2 && left_f[0][0] == 2){
        // 1ª possibilidade
        printf("[FISH SHAPES 1º CASO (OLL)] [TESTE] 1ª possibilidade\n");
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][1] == 2 && top_f[1][1] == 2 && top_f[1][2] == 2 && top_f[2][0] == 2 && front_f[0][1] == 2 && right_f[0][0] == 2 && left_f[0][0] == 2 && left_f[0][1] == 2 && back_f[0][2] == 2){
        // 2ª possibilidade
        printf("[FISH SHAPES 1º CASO (OLL)] [TESTE] 2ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][0] == 2 && top_f[1][1] == 2 && top_f[1][2] == 2 && top_f[2][1] == 2 && front_f[0][0] == 2 && right_f[0][0] == 2 && left_f[0][1] == 2 && back_f[0][1] == 2 && back_f[0][2] == 2){
        // 3ª possibilidade
        printf("[FISH SHAPES 1º CASO (OLL)] [TESTE] 3ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][2] == 2 && top_f[1][0] == 2 && top_f[1][1] == 2 && top_f[2][1] == 2 && front_f[0][0] == 2 && right_f[0][0] == 2 && right_f[0][1] == 2 && left_f[0][0] == 2 && back_f[0][1] == 2){
        // 4ª possibilidade
        printf("[FISH SHAPES 1º CASO (OLL)] [TESTE] 4ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }
    
    // 2º R U² R² F R F' R U² R'
    if(top_f[0][0] == 2 && top_f[1][1] == 2 && top_f[1][2] == 2 && top_f[2][1] == 2 && top_f[2][2] == 2 && front_f[0][0] == 2 && right_f[0][2] == 2 && back_f[0][1] == 2 && left_f[0][1] == 2){
        // 1ª possibilidade
        printf("[FISH SHAPES 2º CASO (OLL)] [TESTE] 1ª possibilidade\n");
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][2] == 2 && top_f[1][0] == 2 && top_f[1][1] == 2 && top_f[2][0] == 2 && top_f[2][1] == 2 && front_f[0][2] == 2 && right_f[0][1] == 2 && left_f[0][0] == 2 && back_f[0][1] == 2){
        // 2ª possibilidade
        printf("[FISH SHAPES 2º CASO (OLL)] [TESTE] 2ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][0] == 2 && top_f[0][1] == 2 && top_f[1][0] == 2 && top_f[1][1] == 2 && top_f[2][2] == 2 && front_f[0][1] == 2 && right_f[0][1] == 2 && left_f[0][2] == 2 && back_f[0][2] == 2){
        // 3ª possibilidade
        printf("[FISH SHAPES 2º CASO (OLL)] [TESTE] 3ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][1] == 2 && top_f[0][2] == 2 && top_f[1][1] == 2 && top_f[1][2] == 2 && top_f[2][0] == 2 && front_f[0][1] == 2 && right_f[0][0] == 2 && left_f[0][1] == 2 && back_f[0][0] == 2){
        // 4ª possibilidade
        printf("[FISH SHAPES 2º CASO (OLL)] [TESTE] 4ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }
    
    // 3º (R U R' U) (R' F R F') R U² R'
    if(top_f[0][2] == 2 && top_f[1][0] == 2 && top_f[1][1] == 2 && top_f[2][1] == 2 && front_f[0][2] == 2 && right_f[0][1] == 2 && left_f[0][2] == 2 && back_f[0][0] == 2 && back_f[0][1] == 2){
        // 1ª possibilidade
        printf("[FISH SHAPES 3º CASO (OLL)] [TESTE] 1ª possibilidade\n");
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][1] == 2 && top_f[1][0] == 2 && top_f[1][1] == 2 && top_f[2][2] == 2 && front_f[0][1] == 2 && right_f[0][1] == 2 && right_f[0][2] == 2 && left_f[0][2] == 2 && back_f[0][0] == 2){
        // 2ª possibilidade
        printf("[FISH SHAPES 3º CASO (OLL)] [TESTE] 2ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][1] == 2 && top_f[1][1] == 2 && top_f[1][2] == 2 && top_f[2][0] == 2 && front_f[0][1] == 2 && front_f[0][2] == 2 && right_f[0][2] == 2 && left_f[0][1] == 2 && back_f[0][0] == 2){
        // 3ª possibilidade
        printf("[FISH SHAPES 3º CASO (OLL)] [TESTE] 3ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][0] == 2 && top_f[1][1] == 2 && top_f[1][2] == 2 && top_f[2][1] == 2 && front_f[0][2] == 2 && right_f[0][2] == 2 && back_f[0][1] == 2 && left_f[0][1] == 2 && left_f[0][2]== 2){
        // 4ª possibilidade
        printf("[FISH SHAPES 3º CASO (OLL)] [TESTE] 4ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }
    
    
    // 4º F R U' R' U' R U R' F'
    if(top_f[0][0] == 2 && top_f[0][1] == 2 && top_f[1][0] == 2 && top_f[1][1] == 2 && top_f[2][2] == 2 && front_f[0][0] == 2 && front_f[0][1] == 2 && right_f[0][1] == 2 && right_f[0][2] == 2){
        // 1ª possibilidade
        printf("[FISH SHAPES 4º CASO (OLL)] [TESTE] 1ª possibilidade\n");
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][1] == 2 && top_f[0][2] == 2 && top_f[1][1] == 2 && top_f[1][2] == 2 && top_f[2][0] == 2 && front_f[0][1] == 2 && front_f[0][2] == 2 && left_f[0][0] == 2 && left_f[0][1] == 2){
        // 2ª possibilidade
        printf("[FISH SHAPES 4º CASO (OLL)] [TESTE] 2ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][0] == 2 && top_f[1][1] == 2 && top_f[1][2] == 2 && top_f[2][1] == 2 && top_f[2][2] && left_f[0][1] == 2 && left_f[0][2] == 2 && back_f[0][1] == 2 && back_f[0][2] == 2){
        // 3ª possibilidade
        printf("[FISH SHAPES 4º CASO (OLL)] [TESTE] 3ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][2] == 2 && top_f[1][0] == 2 && top_f[1][1] == 2 && top_f[2][0] == 2 && top_f[2][1] == 2 && right_f[0][0] == 2 && right_f[0][1] == 2 && back_f[0][0] == 2 && back_f[0][1] == 2){
        // 4ª possibilidade
        printf("[FISH SHAPES 4º CASO (OLL)] [TESTE] 4ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }
    
    // FIM do FISH SHAPES
    
    // AWKWARD SHAPES
    
    // 1º (R U R' U') R U' R' F' U' F R U R'
    if(top_f[0][1] == 2 && top_f[0][2] == 2 && top_f[1][0] == 2 && top_f[1][1] == 2 && top_f[2][2] == 2 && front_f[0][0] == 2 && front_f[0][1] == 2 && right_f[0][1] == 2 && back_f[0][0] == 2){
        // 1ª possibilidade
        printf("[AWKWARD SHAPES 1º CASO (OLL)] [TESTE] 1ª possibilidade\n");
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][1] == 2 && top_f[1][1] == 2 && top_f[1][2] == 2 && top_f[2][0] == 2 && top_f[2][2] == 2 && front_f[0][1] == 2 && left_f[0][0] == 2 && left_f[0][1] == 2 && right_f[0][2] == 2){
        // 2ª possibilidade
        printf("[AWKWARD SHAPES 1º CASO (OLL)] [TESTE] 2ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][0] == 2 && top_f[1][1] == 2 && top_f[1][2] == 2 && top_f[2][0] == 2 && top_f[2][1] == 2 && front_f[0][2] == 2 && left_f[0][1] == 2 && back_f[0][1] == 2 && back_f[0][2] == 2){
        // 3ª possibilidade
        printf("[AWKWARD SHAPES 1º CASO (OLL)] [TESTE] 3ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][0] == 2 && top_f[0][2] == 2 && top_f[1][0] == 2 && top_f[1][1] == 2 && top_f[2][1] == 2 && right_f[0][0] == 2 && right_f[0][1] == 2 && back_f[0][1] == 2 && left_f[0][2] == 2){
        // 4ª possibilidade
        printf("[AWKWARD SHAPES 1º CASO (OLL)] [TESTE] 4ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }
    
    // 2º R U R' U R U2 R' F R U R' U' F'
    if(top_f[0][1] == 2 && top_f[1][0] == 2 && top_f[1][1] == 2 && top_f[2][0] == 2 && top_f[2][2] == 2 && front_f[0][1] == 2 && right_f[0][1] == 2 && back_f[0][0] == 2 && back_f[0][2] == 2){
        // 1ª possibilidade
        printf("[AWKWARD SHAPES 2º CASO (OLL)] [TESTE] 1ª possibilidade\n");
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][0] == 2 && top_f[0][1] == 2 && top_f[1][1] == 2 && top_f[1][2] == 2 && top_f[2][0] == 2 && front_f[0][1] == 2 && right_f[0][0] == 2 && right_f[0][2] == 2 && left_f[0][1] == 2){
        // 2ª possibilidade
        printf("[AWKWARD SHAPES 2º CASO (OLL)] [TESTE] 2ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][0] == 2 && top_f[0][2] == 2 && top_f[1][1] == 2 && top_f[1][2] == 2 && top_f[2][1] == 2 && front_f[0][0] == 2 && front_f[0][2] == 2 && left_f[0][1] == 2 && back_f[0][1] == 2){
        // 3ª possibilidade
        printf("[AWKWARD SHAPES 2º CASO (OLL)] [TESTE] 3ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][2] == 2 && top_f[1][0] == 2 && top_f[1][1] == 2 && top_f[2][1] == 2 && top_f[2][2] == 2 && right_f[0][1] == 2 && back_f[0][1] == 2 && left_f[0][0] == 2 && left_f[0][2] == 2){
        // 4ª possibilidade
        printf("[AWKWARD SHAPES 2º CASO (OLL)] [TESTE] 4ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }
    
    // 3º R² U R' B' R U' R² U R B R'
    if(top_f[0][0] == 2 && top_f[0][2] == 2 && top_f[1][1] == 2 && top_f[1][2] == 2 && top_f[2][1] == 2 && right_f[0][0] == 2 && back_f[0][1] == 2 && left_f[0][1] == 2 && left_f[0][2] == 2){
        // 1ª possibilidade
        printf("[AWKWARD SHAPES 3º CASO (OLL)] [TESTE] 1ª possibilidade\n");
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][2] == 2 && top_f[1][0] == 2 && top_f[1][1] == 2 && top_f[2][1] == 2 && top_f[2][2] == 2 && front_f[0][0] == 2 && right_f[0][1] == 2 && back_f[0][0] == 2 && back_f[0][1] == 2){
        // 2ª possibilidade
        printf("[AWKWARD SHAPES 3º CASO (OLL)] [TESTE] 2ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][1] == 2 && top_f[1][0] == 2 && top_f[1][1] == 2 && top_f[2][0] == 2 && top_f[2][2] == 2 && front_f[0][1] == 2 && right_f[0][1] == 2 && right_f[0][2] == 2 && left_f[0][0] == 2){
        // 3ª possibilidade
        printf("[AWKWARD SHAPES 3º CASO (OLL)] [TESTE] 3ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][0] == 2 && top_f[0][1] == 2 && top_f[1][1] == 2 && top_f[1][2] == 2 && top_f[2][0] == 2 && front_f[0][1] == 2 && front_f[0][2] == 2 && back_f[0][2] == 2 && left_f[0][1] == 2){
        // 4ª possibilidade
        printf("[AWKWARD SHAPES 3º CASO (OLL)] [TESTE] 4ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }
    
    // 4º (R' F R F') (R' F R F') (R U R' U') (R U R')
    if(top_f[0][1] == 2 && top_f[0][2] == 2 && top_f[1][0] == 2 && top_f[1][1] == 2 && top_f[2][2] == 2 && front_f[0][1] == 2 && right_f[0][1] == 2 && left_f[0][0] == 2 && left_f[0][2] == 2){
        // 1ª possibilidade
        printf("[AWKWARD SHAPES 4º CASO (OLL)] [TESTE] 1ª possibilidade\n");
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][1] == 2 && top_f[1][1] == 2 && top_f[1][2] == 2 && top_f[2][0] == 2 && top_f[2][2] == 2 && front_f[0][1] == 2 && left_f[0][1] == 2 && back_f[0][0] == 2 && back_f[0][2] == 2){
        // 2ª possibilidade
        printf("[AWKWARD SHAPES 4º CASO (OLL)] [TESTE] 2ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][0] == 2 && top_f[1][1] == 2 && top_f[1][2] == 2 && top_f[2][0] == 2 && top_f[2][1] == 2 && right_f[0][0] == 2 && right_f[0][2] == 2 && left_f[0][1] == 2 && back_f[0][1] == 2){
        // 3ª possibilidade
        printf("[AWKWARD SHAPES 4º CASO (OLL)] [TESTE] 3ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][0] == 2 && top_f[0][2] == 2 && top_f[1][0] == 2 && top_f[1][1] == 2 && top_f[2][1] == 2 && front_f[0][0] == 2 && front_f[0][2] == 2 && right_f[0][1] == 2 && back_f[0][1] == 2){
        // 4ª possibilidade
        printf("[AWKWARD SHAPES 4º CASO (OLL)] [TESTE] 4ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }
    
    // FIM do AWKWARD SHAPES 
    
    // LIGHTNING BOLTS

    // 1º (r U R' U) R U² r': L F R' F R F² L'
    if(top_f[0][1] == 2 && top_f[1][0] == 2 && top_f[1][1] == 2 && top_f[2][0] == 2 && front_f[0][1] == 2 && front_f[0][2] == 2 && right_f[0][1] == 2 && right_f[0][2] == 2 && back_f[0][0] == 2){
        // 1ª possibilidade
        printf("[LIGHTNING BOLTS 1º CASO (OLL)] [TESTE] 1ª possibilidade\n");
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][0] == 2 && top_f[0][1] == 2 && top_f[1][1] == 2 && top_f[1][2] == 2 && front_f[0][1] == 2 && front_f[0][2] == 2 && right_f[0][2] == 2 && left_f[0][1] == 2 && left_f[0][2] == 2){
        // 2ª possibilidade
        printf("[LIGHTNING BOLTS 1º CASO (OLL)] [TESTE] 2ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][2] == 2 && top_f[1][1] == 2 && top_f[1][2] == 2 && top_f[2][1] == 2 && front_f[0][2] == 2 && left_f[0][1] == 2 && left_f[0][2] == 2 && back_f[0][0] == 2 && back_f[0][1] == 2){
        // 3ª possibilidade
        printf("[LIGHTNING BOLTS 1º CASO (OLL)] [TESTE] 3ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[1][0] == 2 && top_f[1][1] == 2 && top_f[2][1] == 2 && top_f[2][2] == 2 && left_f[0][2] == 2 && back_f[0][0] == 2 && back_f[0][1] == 2 && right_f[0][1] == 2 && right_f[0][2] == 2){
        // 4ª possibilidade
        printf("[LIGHTNING BOLTS 1º CASO (OLL)] [TESTE] 4ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }
    
    // 2º [F' (L' U' L U) F] y [F (R U R' U') F']: F' L' U' L U F R B U B' U' R'
    if(top_f[0][0] == 2 && top_f[1][0] == 2 && top_f[1][1] == 2 && top_f[2][1] == 2 && front_f[0][2] == 2 && right_f[0][1] == 2 && right_f[0][2] == 2 && left_f[0][2] == 2 && back_f[0][1] == 2){
        // 1ª possibilidade
        printf("[LIGHTNING BOLTS 2º CASO (OLL)] [TESTE] 1ª possibilidade\n");
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][1] == 2 && top_f[0][2] == 2 && top_f[1][0] == 2 && top_f[1][1] == 2 && front_f[0][1] == 2 && front_f[0][2] == 2 && right_f[0][1] == 2 && left_f[0][2] == 2 && back_f[0][0] == 2){
        // 2ª possibilidade
        printf("[LIGHTNING BOLTS 2º CASO (OLL)] [TESTE] 2ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][1] == 2 && top_f[1][1] == 2 && top_f[1][2] == 2 && top_f[2][2] == 2 && front_f[0][1] == 2 && right_f[0][2] == 2 && back_f[0][0] == 2 && left_f[0][1] == 2 && left_f[0][2] == 2){
        // 3ª possibilidade
        printf("[LIGHTNING BOLTS 2º CASO (OLL)] [TESTE] 3ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[1][1] == 2 && top_f[1][2] == 2 && top_f[2][0] == 2 && top_f[2][1] == 2 && front_f[0][2] == 2 && right_f[0][2] == 2 && back_f[0][0] == 2 && back_f[0][1] == 2 && left_f[0][1] == 2){
        // 4ª possibilidade
        printf("[LIGHTNING BOLTS 2º CASO (OLL)] [TESTE] 4ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }
    
    // 3º R B' R' U' R U B U' R'
    if(top_f[0][2] == 2 && top_f[1][0] == 2 && top_f[1][1] == 2 && top_f[1][2] == 2 && top_f[2][0] == 2 && front_f[0][1] == 2 && front_f[0][2] == 2 && left_f[0][0] == 2 && back_f[0][1] == 2){
        // 1ª possibilidade
        printf("[LIGHTNING BOLTS 3º CASO (OLL)] [TESTE] 1ª possibilidade\n");
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][0] == 2 && top_f[0][1] == 2 && top_f[1][1] == 2 && top_f[2][1] == 2 && top_f[2][2] == 2 && right_f[0][1] == 2 && left_f[0][1] == 2 && left_f[0][2] == 2 && back_f[0][2] == 2){
        // 2ª possibilidade
        printf("[LIGHTNING BOLTS 3º CASO (OLL)] [TESTE] 2ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][2] == 2 && top_f[1][0] == 2 && top_f[1][1] == 2 && top_f[1][2] == 2 && top_f[2][0] == 2 && front_f[0][1] == 2 && right_f[0][0] == 2 && back_f[0][0] == 2 && back_f[0][1] == 2){
        // 3ª possibilidade
        printf("[LIGHTNING BOLTS 3º CASO (OLL)] [TESTE] 3ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][0] == 2 && top_f[0][1] == 2 && top_f[1][1] == 2 && top_f[2][1] == 2 && top_f[2][2] == 2 && front_f[0][0] == 2 && right_f[0][1] == 2 && right_f[0][2] == 2 && left_f[0][1] == 2){
        // 4ª possibilidade
        printf("[LIGHTNING BOLTS 3º CASO (OLL)] [TESTE] 4ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }
    
    // 4º r' U' R U' R' U² r: L' B' R B' R' B² L
    if(top_f[0][0] == 2 && top_f[1][0] == 2 && top_f[1][1] == 2 && top_f[2][1] == 2 && front_f[0][0] == 2 && right_f[0][0] == 2 && right_f[0][1] == 2 && back_f[0][1] == 2 && back_f[0][2] == 2){
        // 1ª possibilidade
        printf("[LIGHTNING BOLTS 4º CASO (OLL)] [TESTE] 1ª possibilidade\n");
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][1] == 2 && top_f[0][2] == 2 && top_f[1][0] == 2 && top_f[1][1] == 2 && front_f[0][0] == 2 && front_f[0][1] == 2 && left_f[0][0] == 2 && right_f[0][0] == 2 && right_f[0][1] == 2){
        // 2ª possibilidade
        printf("[LIGHTNING BOLTS 4º CASO (OLL)] [TESTE] 2ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][1] == 2 && top_f[1][1] == 2 && top_f[1][2] == 2 && top_f[2][2] == 2 && front_f[0][0] == 2 && front_f[0][1] == 2 && left_f[0][0] == 2 && left_f[0][1] == 2 && back_f[0][2] == 2){
        // 3ª possibilidade
        printf("[LIGHTNING BOLTS 4º CASO (OLL)] [TESTE] 3ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[1][1] == 2 && top_f[1][2] == 2 && top_f[2][0] == 2 && top_f[2][1] == 2 && right_f[0][0] == 2 && back_f[0][1] == 2 && back_f[0][2] == 2 && left_f[0][0] == 2 && left_f[0][1] == 2){
        // 4ª possibilidade
        printf("[LIGHTNING BOLTS 4º CASO (OLL)] [TESTE] 4ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }
    
    
    // 5º [F (R U R' U') F'] U [F (R U R' U') F' ]
    if(top_f[0][2] == 2 && top_f[1][1] == 2 && top_f[1][2] == 2 && top_f[2][1] == 2 && front_f[0][0] == 2 && right_f[0][0] == 2 && left_f[0][0] == 2 && left_f[0][1] == 2 && back_f[0][1] == 2){
        // 1ª possibilidade
        printf("[LIGHTNING BOLTS 5º CASO (OLL)] [TESTE] 1ª possibilidade\n");
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[1][0] == 2 && top_f[1][1] == 2 && top_f[2][1] == 2 && top_f[2][2] == 2 && front_f[0][0] == 2 && right_f[0][1] == 2 && left_f[0][0] == 2 && back_f[0][1] == 2 && back_f[0][2] == 2){
        // 2ª possibilidade
        printf("[LIGHTNING BOLTS 5º CASO (OLL)] [TESTE] 2ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][1] == 2 && top_f[1][0] == 2 && top_f[1][1] == 2 && top_f[2][0] == 2 && front_f[0][1] == 2 && right_f[0][0] == 2 && right_f[0][1] == 2 && left_f[0][0] == 2 && back_f[0][2] == 2){
        // 3ª possibilidade
        printf("[LIGHTNING BOLTS 5º CASO (OLL)] [TESTE] 3ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][0] == 2 && top_f[0][1] == 2 && top_f[1][1] == 2 && top_f[1][2] == 2 && front_f[0][0] == 2 && front_f[0][1] == 2 && right_f[0][0] == 2 && left_f[0][1] == 2 && back_f[0][2] == 2){
        // 4ª possibilidade
        printf("[LIGHTNING BOLTS 5º CASO (OLL)] [TESTE] 4ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }

    // 6º R' [F (R U R' U') F'] U R
    if(top_f[0][0] == 2 && top_f[1][0] == 2 && top_f[1][1] == 2 && top_f[1][2] == 2 && top_f[2][2] == 2 && front_f[0][1] == 2 && left_f[0][2] == 2 && back_f[0][1] == 2 && back_f[0][2] == 2){
        // 1ª possibilidade
        printf("[LIGHTNING BOLTS 6º CASO (OLL)] [TESTE] 1ª possibilidade\n");
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][1] == 2 && top_f[0][2] == 2 && top_f[1][1] == 2 && top_f[2][0] == 2 && top_f[2][1] == 2 && right_f[0][0] == 2 && right_f[0][1] == 2 && back_f[0][0] == 2 && left_f[0][1] == 2){
        // 2ª possibilidade
        printf("[LIGHTNING BOLTS 6º CASO (OLL)] [TESTE] 2ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][0] == 2 && top_f[1][0] == 2 && top_f[1][1] == 2 && top_f[1][2] == 2 && top_f[2][2] == 2 && front_f[0][0] == 2 && front_f[0][1] == 2 && right_f[0][2] == 2 && back_f[0][1] == 2){
        // 3ª possibilidade
        printf("[LIGHTNING BOLTS 6º CASO (OLL)] [TESTE] 3ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][1] == 2 && top_f[0][2] == 2 && top_f[1][1] == 2 && top_f[2][0] == 2 && top_f[2][1] == 2 && front_f[0][2] == 2 && right_f[0][1] == 2 && left_f[0][0] == 2 && left_f[0][1] == 2){
        // 4ª possibilidade
        printf("[LIGHTNING BOLTS 6º CASO (OLL)] [TESTE] 4ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }
    
    
    // FIM do LIGHTNING BOLTS
    
    // T-SHAPES
    
    // 1º (R U R' U') (R' F R F')
    if(top_f[0][2] == 2 && top_f[1][0] == 2 && top_f[1][1] == 2 && top_f[1][2] == 2 && top_f[2][2] == 2 && front_f[0][0] == 2 && front_f[0][1] == 2 && back_f[0][0] == 2 && back_f[0][1] == 2){
        // 1ª possibilidade
        printf("[T-SHAPES 1º CASO (OLL)] [TESTE] 1ª possibilidade\n");
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][1] == 2 && top_f[1][1] == 2 && top_f[2][0] == 2 && top_f[2][1] == 2 && top_f[2][2] == 2 && right_f[0][1] == 2 && right_f[0][2] == 2 && left_f[0][0] == 2 && left_f[0][1] == 2){
        // 2ª possibilidade
        printf("[T-SHAPES 1º CASO (OLL)] [TESTE] 2ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][0] == 2 && top_f[1][0] == 2 && top_f[1][1] == 2 && top_f[1][2] == 2 && top_f[2][0] == 2 && front_f[0][1] == 2 && front_f[0][2] == 2 && back_f[0][1] == 2 && back_f[0][2] == 2){
        // 3ª possibilidade
        printf("[T-SHAPES 1º CASO (OLL)] [TESTE] 3ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][0] == 2 && top_f[0][1] == 2 && top_f[0][2] == 2 && top_f[1][1] == 2 && top_f[2][1] == 2 && right_f[0][0] == 2 && right_f[0][1] == 2 && left_f[0][2] == 2 && left_f[0][1] == 2){
        // 4ª possibilidade
        printf("[T-SHAPES 1º CASO (OLL)] [TESTE] 4ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }
    
    // 2º F (R U R' U') F'
    if(top_f[0][2] == 2 && top_f[1][0] == 2 && top_f[1][1] == 2 && top_f[1][2] == 2 && top_f[2][2] == 2 && front_f[0][1] == 2 && left_f[0][0] == 2 && left_f[0][2] == 2 && back_f[0][1] == 2){
        // 1ª possibilidade
        printf("[T-SHAPES 2º CASO (OLL)] [TESTE] 1ª possibilidade\n");
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][1] == 2 && top_f[1][1] == 2 && top_f[2][0] == 2 && top_f[2][1] == 2 && top_f[2][2] == 2 && right_f[0][1] == 2 && left_f[0][1] == 2 && back_f[0][0] == 2 && back_f[0][2] == 2){
        // 2ª possibilidade
        printf("[T-SHAPES 2º CASO (OLL)] [TESTE] 2ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][0] == 2 && top_f[1][0] == 2 && top_f[1][1] == 2 && top_f[1][2] == 2 && top_f[2][0] == 2 && front_f[0][1] == 2 && right_f[0][0] == 2 && right_f[0][2] == 2 && back_f[0][1] == 2){
        // 3ª possibilidade
        printf("[T-SHAPES 2º CASO (OLL)] [TESTE] 3ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][0] == 2 && top_f[0][1] == 2 && top_f[0][2] == 2 && top_f[1][1] == 2 && top_f[2][1] == 2 && front_f[0][0] == 2 && front_f[0][2] == 2 && right_f[0][1] == 2 && left_f[0][1] == 2){
        // 4ª possibilidade
        printf("[T-SHAPES 2º CASO (OLL)] [TESTE] 4ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }
    
    // FIM do T-SHAPES
    
    // C-SHAPES
    
    // 1º (R U R² U') (R' F) (R U) (R U') F'
    if(top_f[1][0] == 2 && top_f[1][1] == 2 && top_f[1][2] == 2 && top_f[2][0] == 2 && top_f[2][2] == 2 && front_f[0][1] == 2 && right_f[0][2] == 2 && left_f[0][0] == 2 && back_f[0][1] == 2){
        // 1ª possibilidade
        printf("[C-SHAPES 1º CASO (OLL)] [TESTE] 1ª possibilidade\n");
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][0] == 2 && top_f[0][1] == 2 && top_f[1][1] == 2 && top_f[2][0] == 2 && top_f[2][1] == 2 && front_f[0][2] == 2 && right_f[0][1] == 2 && left_f[0][1] == 2 && back_f[0][2] == 2){
        // 2ª possibilidade
        printf("[C-SHAPES 1º CASO (OLL)] [TESTE] 2ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][0] == 2 && top_f[0][2] == 2 && top_f[1][0] == 2 && top_f[1][1] == 2 && top_f[1][2] == 2 && front_f[0][1] == 2 && right_f[0][0] == 2 && left_f[0][2] == 2 && back_f[0][1] == 2){
        // 3ª possibilidade
        printf("[C-SHAPES 1º CASO (OLL)] [TESTE] 3ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][1] == 2 && top_f[0][2] == 2 && top_f[1][1] == 2 && top_f[2][1] == 2 && top_f[2][2] == 2 && front_f[0][0] == 2 && right_f[0][1] == 2 && left_f[0][1] == 2 && back_f[0][0] == 2){
        // 4ª possibilidade
        printf("[C-SHAPES 1º CASO (OLL)] [TESTE] 4ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }
    
    // 2º R' U' (R' F R F') U R
    if(top_f[0][0] == 2 && top_f[0][1] == 2 && top_f[1][1] == 2 && top_f[2][0] == 2 && top_f[2][1] == 2 && right_f[0][0] == 2 && right_f[0][1] == 2 && right_f[0][2] == 2 && left_f[0][1] == 2){
        // 1ª possibilidade
        printf("[C-SHAPES 2º CASO (OLL)] [TESTE] 1ª possibilidade\n");
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][0] == 2 && top_f[0][2] == 2 && top_f[1][0] == 2 && top_f[1][1] == 2 && top_f[1][2] == 2 && front_f[0][0] == 2 && front_f[0][1] == 2 && front_f[0][2] == 2 && back_f[0][1] == 2){
        // 2ª possibilidade
        printf("[C-SHAPES 2º CASO (OLL)] [TESTE] 2ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][1] == 2 && top_f[0][2] == 2 && top_f[1][1] == 2 && top_f[2][1] == 2 && top_f[2][2] == 2 && right_f[0][1] == 2 && left_f[0][0] == 2 && left_f[0][1] == 2 && left_f[0][2] == 2){
        // 3ª possibilidade
        printf("[C-SHAPES 2º CASO (OLL)] [TESTE] 3ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[1][0] == 2 && top_f[1][1] == 2 && top_f[1][2] == 2 && top_f[2][0] == 2 && top_f[2][2] == 2 && front_f[0][1] == 2 && back_f[0][0] == 2 && back_f[0][1] == 2 && back_f[0][2] == 2){
        // 4ª possibilidade
        printf("[C-SHAPES 2º CASO (OLL)] [TESTE] 4ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }
    
    // FIM do C-SHAPES
    
    // I SHAPES
    
    // 1º f (R U R' U') (R U R' U') f': B (U L U' L')(U L U' L') B'
    if(top_f[1][0] == 2 && top_f[1][1] == 2 && top_f[1][2] == 2 && front_f[0][1] == 2 && front_f[0][2] == 2 && back_f[0][1] == 2 && back_f[0][2] == 2 && left_f[0][0] == 2 && left_f[0][2] == 2){
        // 1ª possibilidade
        printf("[I SHAPES 1º CASO (OLL)] [TESTE] 1ª possibilidade\n");
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][1] == 2 && top_f[1][1] == 2 && top_f[2][1] == 2 && right_f[0][0] == 2 && right_f[0][1] == 2 && left_f[0][1] == 2 && left_f[0][2] == 2 && back_f[0][0] == 2 && back_f[0][2] == 2){
        // 2ª possibilidade
        printf("[I SHAPES 1º CASO (OLL)] [TESTE] 2ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[1][0] == 2 && top_f[1][1] == 2 && top_f[1][2] == 2 && front_f[0][0] == 2 && front_f[0][1] == 2 && right_f[0][0] == 2 && right_f[0][2] == 2 && back_f[0][0] == 2 && back_f[0][1] == 2){
        // 3ª possibilidade
        printf("[I SHAPES 1º CASO (OLL)] [TESTE] 3ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][1] == 2 && top_f[1][1] == 2 && top_f[2][1] == 2 && front_f[0][0] == 2 && front_f[0][2] == 2 && right_f[0][1] == 2 && right_f[0][2] == 2 && left_f[0][0] == 2 && left_f[0][1] == 2){
        // 4ª possibilidade
        printf("[I SHAPES 1º CASO (OLL)] [TESTE] 4ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }
     
    // 2º R' U² R² U R' U R U² x' U' R' U: R' U² R² U R' U R U² B' R' B
    if(top_f[0][1] == 2 && top_f[1][1] == 2 && top_f[2][1] == 2 && right_f[0][0] == 2 && right_f[0][1] == 2 && right_f[0][2] == 2 && left_f[0][0] == 2 && left_f[0][1] == 2 && left_f[0][2] == 2){
        // 1ª possibilidade
        printf("[I SHAPES 2º CASO (OLL)] [TESTE] 1ª possibilidade\n");
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[1][0] == 2 && top_f[1][1] == 2 && top_f[1][2] == 2 && front_f[0][0] == 2 && front_f[0][1] == 2 && front_f[0][2] == 2 && back_f[0][0] == 2 && back_f[0][1] == 2 && back_f[0][2] == 2){
        // 2ª possibilidade
        printf("[I SHAPES 2º CASO (OLL)] [TESTE] 2ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }
    
    // 3º (R U R' U) R d' R U' R' F': R U R' U R U' B U' B' R'
    if(top_f[0][1] == 2 && top_f[1][1] == 2 && top_f[2][1] == 2 && front_f[0][0] == 2 && right_f[0][0] == 2 && right_f[0][1] == 2 && right_f[0][2] == 2 && left_f[0][1] == 2 && back_f[0][0] == 2){
        // 1ª possibilidade
        printf("[I SHAPES 3º CASO (OLL)] [TESTE] 1ª possibilidade\n");
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[1][0] == 2 && top_f[1][1] == 2 && top_f[1][2] == 2 && front_f[0][0] == 2 && front_f[0][1] == 2 && front_f[0][2] == 2 && right_f[0][2] == 2 && left_f[0][0] == 2 && back_f[0][1] == 2){
        // 2ª possibilidade
        printf("[I SHAPES 3º CASO (OLL)] [TESTE] 2ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][1] == 2 && top_f[1][1] == 2 && top_f[2][1] == 2 && front_f[0][2] == 2 && right_f[0][1] == 2 && left_f[0][0] == 2 && left_f[0][1] == 2 && left_f[0][2] == 2 && back_f[0][2] == 2){
        // 3ª possibilidade
        printf("[I SHAPES 3º CASO (OLL)] [TESTE] 3ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[1][0] == 2 && top_f[1][1] == 2 && top_f[1][2] == 2 && front_f[0][1] == 2 && right_f[0][0] == 2 && left_f[0][2] == 2 && back_f[0][0] == 2 && back_f[0][1] == 2 && back_f[0][2] == 2){
        // 4ª possibilidade
        printf("[I SHAPES 3º CASO (OLL)] [TESTE] 4ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }
    
    
    // 4º F (R U R' U') R F' (r U R' U') r': F R U R' U' R F' L F R' F' L'
    if(top_f[1][0] == 2 && top_f[1][1] == 2 && top_f[1][2] == 2 && front_f[0][1] == 2 && right_f[0][0] == 2 && right_f[0][2] == 2 && left_f[0][0] == 2 && left_f[0][2] == 2 && back_f[0][1] == 2){
        // 1ª possibilidade
        printf("[I SHAPES 4º CASO (OLL)] [TESTE] 1ª possibilidade\n");
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][1] == 2 && top_f[1][1] == 2 && top_f[2][1] == 2 && front_f[0][0] == 2 && front_f[0][2] == 2 && right_f[0][1] == 2 && left_f[0][1] == 2 && back_f[0][0] == 2 && back_f[0][2] == 2){
        // 2ª possibilidade
        printf("[I SHAPES 4º CASO (OLL)] [TESTE] 2ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }
    
    // FIM do I SHAPES
    
    // KNIGHT MOVE SHAPES
    
    // 1º F U R U' R² F' R (U R U' R')
    if(top_f[1][0] == 2 && top_f[1][1] == 2 && top_f[1][2] == 2 && top_f[2][0] == 2 && front_f[0][1] == 2 && front_f[0][2] == 2 && right_f[0][2] == 2 && back_f[0][0] == 2 && back_f[0][1] == 2){
        // 1ª possibilidade
        printf("[KNIGHT MOVE SHAPES 1º CASO (OLL)] [TESTE] 1ª possibilidade\n");
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][0] == 2 && top_f[0][1] == 2 && top_f[1][1] == 2 && top_f[2][1] == 2 && front_f[0][2] == 2 && right_f[0][1] == 2 && right_f[0][2] == 2 && left_f[0][1] == 2 && left_f[0][2] == 2){
        // 2ª possibilidade
        printf("[KNIGHT MOVE SHAPES 1º CASO (OLL)] [TESTE] 2ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][2] == 2 && top_f[1][0] == 2 && top_f[1][1] == 2 && top_f[1][2] == 2 && front_f[0][1] == 2 && front_f[0][2] == 2 && left_f[0][2] == 2 && back_f[0][0] == 2 && back_f[0][1] == 2){
        // 3ª possibilidade
        printf("[KNIGHT MOVE SHAPES 1º CASO (OLL)] [TESTE] 3ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][1] == 2 && top_f[1][1] == 2 && top_f[2][1] == 2 && top_f[2][2] == 2 && right_f[0][1] == 2 && right_f[0][2] == 2 && left_f[0][1] == 2 && left_f[0][2] == 2 && back_f[0][0] == 2){
        // 4ª possibilidade
        printf("[KNIGHT MOVE SHAPES 1º CASO (OLL)] [TESTE] 4ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }
    
    // 2º (l' U' l) (L' U' L U) (l' U l): R' F' R L' U' L U R' F R
    if(top_f[0][0] == 2 && top_f[1][0] == 2 && top_f[1][1] == 2 && top_f[1][2] == 2 && front_f[0][1] == 2 && front_f[0][2] == 2 && right_f[0][2] == 2 && left_f[0][2] == 2 && back_f[0][1] == 2){
        // 1ª possibilidade
        printf("[KNIGHT MOVE SHAPES 2º CASO (OLL)] [TESTE] 1ª possibilidade\n");
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][1] == 2 && top_f[0][2] == 2 && top_f[1][1] == 2 && top_f[2][1] == 2 && front_f[0][2] == 2 && right_f[0][1] == 2 && left_f[0][2] == 2 && left_f[0][1] == 2 && back_f[0][0] == 2){
        // 2ª possibilidade
        printf("[KNIGHT MOVE SHAPES 2º CASO (OLL)] [TESTE] 2ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[1][0] == 2 && top_f[1][1] == 2 && top_f[1][2] == 2 && top_f[2][2] == 2 && front_f[0][1] == 2 && right_f[0][2] == 2 && left_f[0][2] == 2 && back_f[0][0] == 2 && back_f[0][1] == 2){
        // 3ª possibilidade
        printf("[KNIGHT MOVE SHAPES 2º CASO (OLL)] [TESTE] 3ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][1] == 2 && top_f[1][1] == 2 && top_f[2][0] == 2 && top_f[2][1] == 2 && front_f[0][2] == 2 && right_f[0][1] == 2 && right_f[0][2] == 2 && left_f[0][1] == 2 && back_f[0][0] == 2){
        // 4ª possibilidade
        printf("[KNIGHT MOVE SHAPES 2º CASO (OLL)] [TESTE] 4ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }
    
    // 3º R' F R U R' F' R y' R U' R': R' F R U R' F' R F U' F'
    if(top_f[1][0] == 2 && top_f[1][1] == 2 && top_f[1][2] == 2 && top_f[2][2] == 2 && front_f[0][0] == 2 && front_f[0][1] == 2 && left_f[0][0] == 2 && back_f[0][1] == 2 && back_f[0][2] == 2){
        // 1ª possibilidade
        printf("[KNIGHT MOVE SHAPES 3º CASO (OLL)] [TESTE] 1ª possibilidade\n");
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][1] == 2 && top_f[1][1] == 2 && top_f[2][0] == 2 && top_f[2][1] == 2 && right_f[0][0] == 2 && right_f[0][1] == 2 && back_f[0][2] == 2 && left_f[0][1] == 2 && left_f[0][0] == 2){
        // 2ª possibilidade
        printf("[KNIGHT MOVE SHAPES 3º CASO (OLL)] [TESTE] 2ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][0] == 2 && top_f[1][0] == 2 && top_f[1][1] == 2 && top_f[1][2] == 2 && front_f[0][0] == 2 && front_f[0][1] == 2 && right_f[0][0] == 2 && back_f[0][1] == 2 && back_f[0][2] == 2){
        // 3ª possibilidade
        printf("[KNIGHT MOVE SHAPES 3º CASO (OLL)] [TESTE] 3ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][1] == 2 && top_f[0][2] == 2 && top_f[1][1] == 2 && top_f[2][1] == 2 && front_f[0][0] == 2 && right_f[0][0] == 2 && right_f[0][1] == 2 && left_f[0][1] == 2 && left_f[0][0] == 2){
        // 4ª possibilidade
        printf("[KNIGHT MOVE SHAPES 3º CASO (OLL)] [TESTE] 4ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }
    
    // 4º (r U r') (R U R' U') (r U' r'): L F L' R U R' U' L F' L'
    if(top_f[0][2] == 2 && top_f[1][0] == 2 && top_f[1][1] == 2 && top_f[1][2] == 2 && front_f[0][0] == 2 && front_f[0][1] == 2 && right_f[0][0] == 2 && left_f[0][0] == 2 && back_f[0][1] == 2){
        // 1ª possibilidade
        printf("[KNIGHT MOVE SHAPES 4º CASO (OLL)] [TESTE] 1ª possibilidade\n");
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][1] == 2 && top_f[1][1] == 2 && top_f[2][1] == 2 && top_f[2][2] == 2 && front_f[0][0] == 2 && left_f[0][0] == 2 && left_f[0][1] == 2 && right_f[0][1] == 2 && back_f[0][2] == 2){
        // 2ª possibilidade
        printf("[KNIGHT MOVE SHAPES 4º CASO (OLL)] [TESTE] 2ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[1][0] == 2 && top_f[1][1] == 2 && top_f[1][2] == 2 && top_f[2][0] == 2 && front_f[0][1] == 2 && right_f[0][0] == 2 && left_f[0][0] == 2 && back_f[0][1] == 2 && back_f[0][2] == 2){
        // 3ª possibilidade
        printf("[KNIGHT MOVE SHAPES 4º CASO (OLL)] [TESTE] 3ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][0] == 2 && top_f[0][1] == 2 && top_f[1][1] == 2 && top_f[2][1] == 2 && front_f[0][0] == 2 && right_f[0][0] == 2 && right_f[0][1] == 2 && left_f[0][1] == 2 && back_f[0][2] == 2){
        // 4ª possibilidade
        printf("[KNIGHT MOVE SHAPES 4º CASO (OLL)] [TESTE] 4ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }
    
    // FIM do KNIGHT MOVE SHAPES
    
    // NO EDGES FLIPPED CORRECTLY
    
    // 1º R U² R² F R F' U² (R' F R F')
    if(top_f[1][1] == 2 && front_f[0][1] == 2 && back_f[0][1] == 2 && right_f[0][0] == 2 && right_f[0][1] == 2 && right_f[0][2] == 2 && left_f[0][0] == 2 && left_f[0][1] == 2 && left_f[0][2] == 2){
        // 1ª possibilidade
        printf("[NO EDGES FLIPPED CORRECTLY 1º CASO (OLL)] [TESTE] 1ª possibilidade\n");
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[1][1] == 2 && front_f[0][0] == 2 && front_f[0][1] == 2 && front_f[0][2] == 2 && back_f[0][0] == 2 && back_f[0][1] == 2 && back_f[0][2] == 2 && right_f[0][1] == 2 && left_f[0][1] == 2){
        // 2ª possibilidade
        printf("[NO EDGES FLIPPED CORRECTLY 1º CASO (OLL)] [TESTE] 2ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }
    
    // 2º [f (R U R' U') f'] U' [F (R U R' U') F']: B U L U' L' B' U' F R U R' U' F'
    if(top_f[1][1] == 2 && top_f[2][2] == 2 && front_f[0][1] == 2 && right_f[0][1] == 2 && right_f[0][2] == 2 && left_f[0][1] == 2 && left_f[0][2] == 2 && back_f[0][0] == 2 && back_f[0][1] == 2){
        // 1ª possibilidade
        printf("[NO EDGES FLIPPED CORRECTLY 2º CASO (OLL)] [TESTE] 1ª possibilidade\n");
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[1][1] == 2 && top_f[2][0] == 2 && front_f[0][1] == 2 && front_f[0][2] == 2 && right_f[0][1] == 2 && right_f[0][2] == 2 && left_f[0][1] == 2 && back_f[0][0] == 2 && back_f[0][1] == 2){
        // 2ª possibilidade
        printf("[NO EDGES FLIPPED CORRECTLY 2º CASO (OLL)] [TESTE] 2ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][0] == 2 && top_f[1][1] == 2 && front_f[0][1] == 2 && front_f[0][2] == 2 && right_f[0][1] == 2 && right_f[0][2] == 2 && left_f[0][1] == 2 && left_f[0][2] == 2 && back_f[0][1] == 2){
        // 3ª possibilidade
        printf("[NO EDGES FLIPPED CORRECTLY 2º CASO (OLL)] [TESTE] 3ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[1][1] == 2 && top_f[0][2] == 2 && front_f[0][1] == 2 && front_f[0][2] == 2 && right_f[0][1] == 2 && left_f[0][1] == 2 && left_f[0][2] == 2 && back_f[0][0] == 2 && back_f[0][1] == 2){
        // 4ª possibilidade
        printf("[NO EDGES FLIPPED CORRECTLY 2º CASO (OLL)] [TESTE] 4ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }
    
    // 3º [F (R U R' U) F'] y' U² (R' F R F'): F R U R' U F' U² F' L F L'
    if(top_f[1][1] == 2 && top_f[2][0] == 2 && top_f[2][2] == 2 && front_f[0][1] == 2 && right_f[0][1] == 2 && left_f[0][1] == 2 && back_f[0][0] == 2 && back_f[0][1] == 2 && back_f[0][2] ==  2){
        // 1ª possibilidade
        printf("[NO EDGES FLIPPED CORRECTLY 3º CASO (OLL)] [TESTE] 1ª possibilidade\n");
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][0] == 2 && top_f[1][1] == 2 && top_f[2][0] == 2 && front_f[0][1] == 2 && left_f[0][1] == 2 && back_f[0][1] == 2 && right_f[0][0] == 2 && right_f[0][1] == 2 && right_f[0][2] == 2){
        // 2ª possibilidade
        printf("[NO EDGES FLIPPED CORRECTLY 3º CASO (OLL)] [TESTE] 2ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][0] == 2 && top_f[0][2] == 2 && top_f[1][1] == 2 && front_f[0][0] == 2 && front_f[0][1] == 2 && front_f[0][2] == 2 && right_f[0][1] == 2 && back_f[0][1] == 2 && left_f[0][1] == 2){
        // 3ª possibilidade
        printf("[NO EDGES FLIPPED CORRECTLY 3º CASO (OLL)] [TESTE] 3ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][2] == 2 && top_f[1][1] == 2 && top_f[2][2] == 2 && front_f[0][1] == 2 && right_f[0][1] == 2 && back_f[0][1] == 2 && left_f[0][0] == 2 && left_f[0][1] == 2 && left_f[0][2] == 2){
        // 4ª possibilidade
        printf("[NO EDGES FLIPPED CORRECTLY 3º CASO (OLL)] [TESTE] 4ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }
    
    // 4º (R U R' U) (R' F R F') U² (R' F R F')
    if(top_f[0][0] == 2 && top_f[1][1] == 2 && top_f[2][2] == 2 && front_f[0][1] == 2 && right_f[0][1] == 2 && back_f[0][1] == 2 && back_f[0][2] == 2 && left_f[0][1] == 2 && left_f[0][2] == 2){
        // 1ª possibilidade
        printf("[NO EDGES FLIPPED CORRECTLY 4º CASO (OLL)] [TESTE] 1ª possibilidade\n");
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][2] == 2 && top_f[1][1] == 2 && top_f[2][0] == 2 && front_f[0][1] == 2 && right_f[0][0] == 2 && right_f[0][1] == 2 && back_f[0][0] == 2 && back_f[0][1] == 2 && left_f[0][1] == 2){
        // 2ª possibilidade
        printf("[NO EDGES FLIPPED CORRECTLY 4º CASO (OLL)] [TESTE] 2ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][0] == 2 && top_f[1][1] == 2 && top_f[2][2] == 2 && front_f[0][0] == 2 && front_f[0][1] == 2 && right_f[0][1] == 2 && right_f[0][2] == 2 && back_f[0][1] == 2 && left_f[0][1] == 2){
        // 3ª possibilidade
        printf("[NO EDGES FLIPPED CORRECTLY 4º CASO (OLL)] [TESTE] 3ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][2] == 2 && top_f[1][1] == 2 && top_f[2][0] == 2 && front_f[0][1] == 2 && front_f[0][2] == 2 && right_f[0][1] == 2 && left_f[0][0] == 2 && left_f[0][1] == 2 && back_f[0][1] == 2){
        // 4ª possibilidade
        printf("[NO EDGES FLIPPED CORRECTLY 4º CASO (OLL)] [TESTE] 4ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }
    
    // 5º [F (R U R' U') F'] [f (R U R' U') f']: F R U R' U' F' B U L U' L' B'
    if(top_f[1][1] == 2 && front_f[0][1] == 2 && front_f[0][2] == 2 && right_f[0][1] == 2 && left_f[0][0] == 2 && left_f[0][1] == 2 && left_f[0][2] == 2 && back_f[0][1] == 2 && back_f[0][2] == 2){
        // 1ª possibilidade
        printf("[NO EDGES FLIPPED CORRECTLY 5º CASO (OLL)] [TESTE] 1ª possibilidade\n");
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[1][1] == 2 && front_f[0][1] == 2 && right_f[0][0] == 2 && right_f[0][1] == 2 && left_f[0][1] == 2 && left_f[0][2] == 2 && back_f[0][0] == 2 && back_f[0][1] == 2 && back_f[0][2] == 2){
        // 2ª possibilidade
        printf("[NO EDGES FLIPPED CORRECTLY 5º CASO (OLL)] [TESTE] 2ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[1][1] == 2 && front_f[0][0] == 2 && front_f[0][1] == 2 && right_f[0][0] == 2 && right_f[0][1] == 2 && right_f[0][2] == 2 && left_f[0][1] == 2 && back_f[0][0] == 2 && back_f[0][1] == 2){
        // 3ª possibilidade
        printf("[NO EDGES FLIPPED CORRECTLY 5º CASO (OLL)] [TESTE] 3ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[1][1] == 2 && front_f[0][0] == 2 && front_f[0][1] == 2 && front_f[0][2] == 2 && right_f[0][1] == 2 && right_f[0][2] == 2 && left_f[0][0] == 2 && left_f[0][1] == 2 && back_f[0][1] == 2){
        // 4ª possibilidade
        printf("[NO EDGES FLIPPED CORRECTLY 5º CASO (OLL)] [TESTE] 4ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }
    
    // 6º [f (R U R' U') f'] U [F (R U R' U') F']: B U L U' L' B' U F R U R' U' F'
    if(top_f[1][1] == 2 && top_f[0][2] == 2 && front_f[0][0] == 2 && front_f[0][1] == 2 && right_f[0][0] == 2 && right_f[0][1] == 2 && left_f[0][0] == 2 && left_f[0][1] == 2 && back_f[0][1] == 2){
        // 1ª possibilidade
        printf("[NO EDGES FLIPPED CORRECTLY 6º CASO (OLL)] [TESTE] 1ª possibilidade\n");
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[1][1] == 2 && top_f[2][2] == 2 && front_f[0][0] == 2 && front_f[0][1] == 2 && right_f[0][1] == 2 && back_f[0][1] == 2 && back_f[0][2] == 2 && left_f[0][0] == 2 && left_f[0][1] == 2){
        // 2ª possibilidade
        printf("[NO EDGES FLIPPED CORRECTLY 6º CASO (OLL)] [TESTE] 2ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[1][1] == 2 && top_f[2][0] == 2 && front_f[0][1] == 2 && right_f[0][0] == 2 && right_f[0][1] == 2 && left_f[0][1] == 2 && left_f[0][0] == 2 && back_f[0][1] == 2 && back_f[0][2] == 2){
        // 3ª possibilidade
        printf("[NO EDGES FLIPPED CORRECTLY 6º CASO (OLL)] [TESTE] 3ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][0] == 2 && top_f[1][1] == 2 && front_f[0][0] == 2 && front_f[0][1] == 2 && right_f[0][0] == 2 && right_f[0][1] == 2 && left_f[0][1] == 2 && back_f[0][1] == 2 && back_f[0][2] == 2){
        // 4ª possibilidade
        printf("[NO EDGES FLIPPED CORRECTLY 6º CASO (OLL)] [TESTE] 4ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }
    
    // 7º M U (R U R' U') M' (R' F R F'): R L' B R B R' B' R' L R' F R F'
    if(top_f[0][0] == 2 && top_f[0][2] == 2 && top_f[1][1] == 2 && front_f[0][1] == 2 && right_f[0][0] == 2 && right_f[0][1] == 2 && left_f[0][1] == 2 && left_f[0][2] == 2 && back_f[0][1] == 2){
        // 1ª possibilidade
        printf("[NO EDGES FLIPPED CORRECTLY 7º CASO (OLL)] [TESTE] 1ª possibilidade\n");
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][2] == 2 && top_f[1][1] == 2 && top_f[2][2] == 2 && front_f[0][0] == 2 && front_f[0][1] == 2 && right_f[0][1] == 2 && left_f[0][1] == 2 && back_f[0][0] == 2 && back_f[0][1] == 2){
        // 2ª possibilidade
        printf("[NO EDGES FLIPPED CORRECTLY 7º CASO (OLL)] [TESTE] 2ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[1][1] == 2 && top_f[2][0] == 2 && top_f[2][2] == 2 && front_f[0][1] == 2 && right_f[0][1] == 2 && right_f[0][2] == 2 && left_f[0][0] == 2 && left_f[0][1] == 2 && back_f[0][1] == 2){
        // 3ª possibilidade
        printf("[NO EDGES FLIPPED CORRECTLY 7º CASO (OLL)] [TESTE] 3ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if(top_f[0][0] == 2 && top_f[1][1] == 2 && top_f[2][0] == 2 && front_f[0][1] == 2 && front_f[0][2] == 2 && right_f[0][1] == 2 && left_f[0][1] == 2 && back_f[0][1] == 2 && back_f[0][2] == 2){
        // 4ª possibilidade
        printf("[NO EDGES FLIPPED CORRECTLY 7º CASO (OLL)] [TESTE] 4ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }
    
    // 8º M U (R U R' U') M² (U R U' r'): R L' B R B R' B' R² L² F R F' L'
    if(top_f[0][0] == 2 && top_f[0][2] == 2 && top_f[1][1] == 2 && top_f[2][0] == 2 && top_f[2][2] == 2 && front_f[0][1] == 2 && right_f[0][1] == 2 && back_f[0][1] == 2 && left_f[0][1] == 2){
        // 1ª possibilidade
        printf("[NO EDGES FLIPPED CORRECTLY 8º CASO (OLL)] [TESTE] 1ª possibilidade\n");
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }
    
}   


void pll(int left_f[][3], int front_f[][3], int right_f[][3], int top_f[][3], int bottom_f[][3], int back_f[][3]) {
    
    // PERMUTATIONS OF EDGES OR CORNERS ONLY

    // 1º R² U (R U R' U')(R' U')(R' U R')
    if((back_f[0][0] == back_f[0][1] && back_f[0][1] == back_f[0][2]) && (right_f[0][2] == right_f[0][0] && right_f[0][0] == left_f[0][1]) && (front_f[0][0] == front_f[0][2] && front_f[0][2] == right_f[0][1]) && (left_f[0][0] == left_f[0][2] && left_f[0][2] == front_f[0][1])){
        // 1ª possibilidade
        printf("[PERMUTATIONS OF EDGES OR CORNERS ONLY 1º CASO (PLL)] [TESTE] 1ª possibilidade\n");
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if((right_f[0][0] == right_f[0][1] && right_f[0][1] == right_f[0][2]) && (front_f[0][0] == front_f[0][2] && front_f[0][2] == back_f[0][1]) && (front_f[0][1] == left_f[0][0] && left_f[0][0] == left_f[0][2]) && (back_f[0][2] == back_f[0][0] && back_f[0][0] == left_f[0][1])){
        // 2ª possibilidade
        printf("[PERMUTATIONS OF EDGES OR CORNERS ONLY 1º CASO (PLL)] [TESTE] 2ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if((front_f[0][0] == front_f[0][1] && front_f[0][1] == front_f[0][2]) && (right_f[0][0] == right_f[0][2] && right_f[0][2] == back_f[0][1]) && (right_f[0][1] == left_f[0][0] && left_f[0][0] == left_f[0][2]) && (back_f[0][0] == back_f[0][2] && back_f[0][2] == left_f[0][1])){
        // 3ª possibilidade
        printf("[PERMUTATIONS OF EDGES OR CORNERS ONLY 1º CASO (PLL)] [TESTE] 3ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if((left_f[0][0] == left_f[0][1] && left_f[0][1] == left_f[0][2]) && (front_f[0][0] == front_f[0][2] && front_f[0][2] == right_f[0][1]) && (front_f[0][1] == back_f[0][0] && back_f[0][0] == back_f[0][2]) && (right_f[0][0] == right_f[0][2] && right_f[0][2] == back_f[0][1])){
        // 4ª possibilidade
        printf("[PERMUTATIONS OF EDGES OR CORNERS ONLY 1º CASO (PLL)] [TESTE] 4ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }
    
    
    // 2º U² (R U R' U)(R' U' R' U)(R U' R' U') R² U R
    if((front_f[0][0] == front_f[0][2] && front_f[0][2] == right_f[0][1]) && (right_f[0][0] == right_f[0][2] && right_f[0][2] == front_f[0][1]) && (back_f[0][0] == back_f[0][2] && back_f[0][2] == left_f[0][1]) && (left_f[0][0] == left_f[0][2] && left_f[0][2] == back_f[0][1])){
        // 1ª possibilidade
        printf("[PERMUTATIONS OF EDGES OR CORNERS ONLY 2º CASO (PLL)] [TESTE] 1ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if((front_f[0][0] == front_f[0][2] && front_f[0][2] == left_f[0][1]) && (left_f[0][0] == left_f[0][2] && left_f[0][2] == front_f[0][1]) && (right_f[0][0] == right_f[0][2] && right_f[0][2] == back_f[0][1]) && (back_f[0][0] == back_f[0][2] && back_f[0][2] == right_f[0][1])){
        // 2ª possibilidade
        printf("[PERMUTATIONS OF EDGES OR CORNERS ONLY 2º CASO (PLL)] [TESTE] 2ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }
    
    // 3º x [(R' U R') D²][(R U' R') D²] R²: R' F R' B2 R F' R' B2 R2
    if((front_f[0][0] == front_f[0][1] && front_f[0][1] == right_f[0][2]) && (front_f[0][2] == back_f[0][1] && back_f[0][1] == left_f[0][0]) && (right_f[0][0] == left_f[0][1] && left_f[0][1] == left_f[0][2]) && (right_f[0][1] == back_f[0][0] && back_f[0][0] == back_f[0][2])){
        // 1ª possibilidade
        printf("[PERMUTATIONS OF EDGES OR CORNERS ONLY 3º CASO (PLL)] [TESTE] 1ª possibilidade\n");
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if((front_f[0][0] == back_f[0][0] && back_f[0][0] == back_f[0][1]) && (front_f[0][1] == right_f[0][0] && right_f[0][0] == right_f[0][2]) && (front_f[0][2] == left_f[0][0] && left_f[0][0] == left_f[0][1]) && (right_f[0][1] == left_f[0][2] && left_f[0][2] == back_f[0][2])){
        // 2ª possibilidade
        printf("[PERMUTATIONS OF EDGES OR CORNERS ONLY 3º CASO (PLL)] [TESTE] 2ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if((front_f[0][0] == front_f[0][2] && front_f[0][2] == left_f[0][1]) && (front_f[0][1] == right_f[0][0] && right_f[0][0] == back_f[0][0]) && (right_f[0][1] == right_f[0][2] && right_f[0][2] == left_f[0][0]) && (back_f[0][1] == back_f[0][2] && back_f[0][2] == left_f[0][2])){
        // 3ª possibilidade
        printf("[PERMUTATIONS OF EDGES OR CORNERS ONLY 3º CASO (PLL)] [TESTE] 3ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if((front_f[0][0] == right_f[0][2] && right_f[0][2] == left_f[0][1]) && (front_f[0][1] == front_f[0][2] && front_f[0][2] == back_f[0][2]) && (right_f[0][0] == right_f[0][1] && right_f[0][1] == back_f[0][0]) && (left_f[0][0] == left_f[0][2] && left_f[0][2] == back_f[0][1])){
        // 4ª possibilidade
        printf("[PERMUTATIONS OF EDGES OR CORNERS ONLY 3º CASO (PLL)] [TESTE] 4ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }
    
    // 4º x'[(R U' R') D (R U R')] D' [(R U R') D (R U' R')] D': R B' R' F R B R' F' R B R' F R B' R' F'
    if((front_f[0][0] == left_f[0][1] && left_f[0][1] == back_f[0][0]) && (front_f[0][1] == right_f[0][2] && right_f[0][2] == left_f[0][0]) && (front_f[0][2] == right_f[0][1] && right_f[0][1] == back_f[0][2]) && (right_f[0][0] == left_f[0][2] && left_f[0][2] == back_f[0][1])){
        // 1ª possibilidade
        printf("[PERMUTATIONS OF EDGES OR CORNERS ONLY 4º CASO (PLL)] [TESTE] 1ª possibilidade\n");
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if((front_f[0][0] == right_f[0][1] && right_f[0][1] == back_f[0][0]) && (front_f[0][1] == right_f[0][0] && right_f[0][0] == left_f[0][2]) && (front_f[0][2] == left_f[0][1] && left_f[0][1] == back_f[0][2]) && (right_f[0][2] == back_f[0][1] && back_f[0][1] == left_f[0][0])){
        // 2ª possibilidade
        printf("[PERMUTATIONS OF EDGES OR CORNERS ONLY 4º CASO (PLL)] [TESTE] 2ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }
    
    // 5º (R U')(R U)(R U)(R U') R' U' R²
    if((back_f[0][0] == back_f[0][1] && back_f[0][1] == back_f[0][2]) && (front_f[0][0] == front_f[0][2] && front_f[0][2] == left_f[0][1]) && (right_f[0][0] == right_f[0][2] && right_f[0][2] == front_f[0][1]) && (left_f[0][0] == left_f[0][2] && left_f[0][2] == right_f[0][1])){
        // 1ª possibilidade
        printf("[PERMUTATIONS OF EDGES OR CORNERS ONLY 5º CASO (PLL)] [TESTE] 1ª possibilidade\n");
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if((right_f[0][0] == right_f[0][1] && right_f[0][1] == right_f[0][2]) && (front_f[0][0] == front_f[0][2] && front_f[0][2] == left_f[0][1]) && (front_f[0][1] == back_f[0][0] && back_f[0][0] == back_f[0][2]) && (left_f[0][0] == left_f[0][2] && left_f[0][2] == back_f[0][1])){
        // 2ª possibilidade
        printf("[PERMUTATIONS OF EDGES OR CORNERS ONLY 5º CASO (PLL)] [TESTE] 2ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if((front_f[0][0] == front_f[0][1] && front_f[0][1] == front_f[0][2]) && (right_f[0][0] == right_f[0][2] && right_f[0][2] == left_f[0][1]) && (back_f[0][0] == back_f[0][2] && back_f[0][2] == right_f[0][1]) && (left_f[0][0] == left_f[0][2] && left_f[0][2] == back_f[0][1])){
        // 3ª possibilidade
        printf("[PERMUTATIONS OF EDGES OR CORNERS ONLY 5º CASO (PLL)] [TESTE] 3ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if((left_f[0][0] == left_f[0][1] && left_f[0][1] == left_f[0][2]) && (front_f[0][0] == front_f[0][2] && front_f[0][2] == back_f[0][1]) && (right_f[0][0] == right_f[0][2] && right_f[0][2] == front_f[0][1]) && (back_f[0][0] == back_f[0][2] && back_f[0][2] == right_f[0][1])){
        // 4ª possibilidade
        printf("[PERMUTATIONS OF EDGES OR CORNERS ONLY 5º CASO (PLL)] [TESTE] 4ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }
    
    
    // 6º M2 U M2 U2 M2 U M2: R2 U2 R2 U2 R2 U R2  U2  R2 U2 R2  U'
    if((front_f[0][0] == front_f[0][2] && front_f[0][2] == back_f[0][1]) && (back_f[0][0] == back_f[0][2] && back_f[0][2] == front_f[0][1]) && (right_f[0][0] == right_f[0][2] && right_f[0][2] == left_f[0][1]) && (left_f[0][0] == left_f[0][2] && left_f[0][2] == right_f[0][1])){
        // 1ª possibilidade
        printf("[PERMUTATIONS OF EDGES OR CORNERS ONLY 6º CASO (PLL)] [TESTE] 1ª possibilidade\n");
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }
    
    // 7º x' [(R U' R) D²][(R' U R) D²] R²: R² B² R F R' B² R F' R
    if((front_f[0][0] == front_f[0][1] && front_f[0][1] == back_f[0][0]) && (front_f[0][2] == right_f[0][1] && right_f[0][1] == left_f[0][0]) && (right_f[0][0] == right_f[0][2] && right_f[0][2] == back_f[0][1]) && (left_f[0][2] == left_f[0][1] && left_f[0][1] == back_f[0][2])){
        // 1ª possibilidade
        printf("[PERMUTATIONS OF EDGES OR CORNERS ONLY 7º CASO (PLL)] [TESTE] 1ª possibilidade\n");
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if((front_f[0][0] == front_f[0][2] && front_f[0][2] == right_f[0][1]) && (front_f[0][1] == back_f[0][2] && back_f[0][2] == left_f[0][2]) && (right_f[0][0] == back_f[0][0] && back_f[0][0] == back_f[0][1]) && (right_f[0][2] == left_f[0][0] && left_f[0][0] == left_f[0][1])){
        // 2ª possibilidade
        printf("[PERMUTATIONS OF EDGES OR CORNERS ONLY 7º CASO (PLL)] [TESTE] 2ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if((front_f[0][0] == right_f[0][1] && right_f[0][1] == right_f[0][2]) && (front_f[0][1] == left_f[0][0] && left_f[0][0] == left_f[0][2]) && (front_f[0][2] == back_f[0][1] && back_f[0][1] == back_f[0][2]) && (right_f[0][0] == back_f[0][0] && back_f[0][0] == left_f[0][1])){
        // 3ª possibilidade
        printf("[PERMUTATIONS OF EDGES OR CORNERS ONLY 7º CASO (PLL)] [TESTE] 3ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if((front_f[0][0] == right_f[0][2] && right_f[0][2] == back_f[0][1]) && (front_f[0][1] == front_f[0][2] && front_f[0][2] == left_f[0][0]) && (right_f[0][0] == right_f[0][1] && right_f[0][1] == left_f[0][2]) && (back_f[0][0] == back_f[0][2] && back_f[0][2] == left_f[0][1])){
        // 4ª possibilidade
        printf("[PERMUTATIONS OF EDGES OR CORNERS ONLY 7º CASO (PLL)] [TESTE] 4ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }
    
    // FIM do PERMUTATIONS OF EDGES OR CORNERS ONLY
    
    // SWAP ONE SET OF ADJACENT CORNERS
    
    // 1º (L U² L' U²)(L F')(L' U' L U)(L F) L² U
    if((front_f[0][0] == front_f[0][2] && front_f[0][2] == left_f[0][1]) && (front_f[0][1] == back_f[0][2] && back_f[0][2] == left_f[0][2]) && (right_f[0][0] == right_f[0][1] && right_f[0][1] == back_f[0][0]) && (right_f[0][2] == back_f[0][1] && back_f[0][1] == left_f[0][0])){
        // 1ª possibilidade
        printf("[SWAP ONE SET OF ADJACENT CORNERS 1º CASO (PLL)] [TESTE] 1ª possibilidade\n");
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if((front_f[0][0] == front_f[0][1] && front_f[0][1] == right_f[0][2]) && (front_f[0][2] == right_f[0][1] && right_f[0][1] == back_f[0][2]) && (right_f[0][0] == back_f[0][0] && back_f[0][0] == left_f[0][1]) && (back_f[0][1] == left_f[0][0] && left_f[0][0] == left_f[0][2])){
        // 2ª possibilidade
        printf("[SWAP ONE SET OF ADJACENT CORNERS 1º CASO (PLL)] [TESTE] 2ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if((front_f[0][0] == right_f[0][2] && right_f[0][2] == back_f[0][1]) && (front_f[0][1] == right_f[0][0] && right_f[0][0] == left_f[0][2]) && (front_f[0][2] == left_f[0][0] && left_f[0][0] == left_f[0][1]) && (right_f[0][1] == back_f[0][0] && back_f[0][0] == back_f[0][2])){
        // 3ª possibilidade
        printf("[SWAP ONE SET OF ADJACENT CORNERS 1º CASO (PLL)] [TESTE] 3ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if((front_f[0][0] == back_f[0][0] && back_f[0][0] == left_f[0][1]) && (front_f[0][1] == right_f[0][0] && right_f[0][0] == right_f[0][2]) && (front_f[0][2] == right_f[0][1] && right_f[0][1] == left_f[0][0]) && (back_f[0][1] == back_f[0][2] && back_f[0][2] == left_f[0][2])){
        // 4ª possibilidade
        printf("[SWAP ONE SET OF ADJACENT CORNERS 1º CASO (PLL)] [TESTE] 4ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }
    
    // 2º (R' U L')(U² R U' R' U²)(R L U')
    if((front_f[0][0] == front_f[0][1] && front_f[0][1] == front_f[0][2]) && (right_f[0][0] == right_f[0][1] && right_f[0][1] == back_f[0][0]) && (left_f[0][0] == left_f[0][1] && left_f[0][1] == right_f[0][2]) && (back_f[0][1] == back_f[0][2] && back_f[0][2] == left_f[0][2])){
        // 1ª possibilidade
        printf("[SWAP ONE SET OF ADJACENT CORNERS 2º CASO (PLL)] [TESTE] 1ª possibilidade\n");
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if((left_f[0][0] == left_f[0][1] && left_f[0][1] == left_f[0][2]) && (front_f[0][0] == front_f[0][1] && front_f[0][1] == right_f[0][2]) && (back_f[0][1] == back_f[0][2] && back_f[0][2] == front_f[0][2]) && (right_f[0][0] == right_f[0][1] && right_f[0][1] == back_f[0][0])){
        // 2ª possibilidade
        printf("[SWAP ONE SET OF ADJACENT CORNERS 2º CASO (PLL)] [TESTE] 2ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if((back_f[0][0] == back_f[0][1] && back_f[0][1] == back_f[0][2]) && (front_f[0][0] == front_f[0][1] && front_f[0][1] == right_f[0][2]) && (left_f[0][0] == left_f[0][1] && left_f[0][1] == front_f[0][2]) && (right_f[0][0] == right_f[0][1] && right_f[0][1] == left_f[0][2])){
        // 3ª possibilidade
        printf("[SWAP ONE SET OF ADJACENT CORNERS 2º CASO (PLL)] [TESTE] 3ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if((right_f[0][0] == right_f[0][1] && right_f[0][1] == right_f[0][2]) && (front_f[0][0] == front_f[0][1] && front_f[0][1] == back_f[0][0]) && (left_f[0][0] == left_f[0][1] && left_f[0][1] == front_f[0][2]) && (back_f[0][1] == back_f[0][2] && back_f[0][2] == left_f[0][2])){
        // 4ª possibilidade
        printf("[SWAP ONE SET OF ADJACENT CORNERS 2º CASO (PLL)] [TESTE] 4ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }
    
    // 3º (R U R' U')(R' F)(R² U' R') U' (R U R' F')
    if((front_f[0][0] == front_f[0][1] && front_f[0][1] == right_f[0][2]) && (front_f[0][2] == left_f[0][1] && left_f[0][1] == back_f[0][2]) && (back_f[0][0] == back_f[0][1] && back_f[0][1] == right_f[0][0]) && (left_f[0][0] == left_f[0][2] && left_f[0][2] == right_f[0][1])){
        // 1ª possibilidade
        printf("[SWAP ONE SET OF ADJACENT CORNERS 3º CASO (PLL)] [TESTE] 1ª possibilidade\n");
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if((front_f[0][0] == right_f[0][1] && right_f[0][1] == right_f[0][2]) && (front_f[0][1] == back_f[0][0] && back_f[0][0] == back_f[0][2]) && (front_f[0][2] == left_f[0][0] && left_f[0][0] == left_f[0][1]) && (right_f[0][0] == left_f[0][2] && left_f[0][2] == back_f[0][1])){
        // 2ª possibilidade
        printf("[SWAP ONE SET OF ADJACENT CORNERS 3º CASO (PLL)] [TESTE] 2ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if((front_f[0][0] == right_f[0][1] && right_f[0][1] == back_f[0][0]) && (front_f[0][1] == front_f[0][2] && front_f[0][2] == left_f[0][0]) && (right_f[0][0] == right_f[0][2] && right_f[0][2] == left_f[0][1]) && (back_f[0][1] == back_f[0][2] && back_f[0][2] == left_f[0][2])){
        // 3ª possibilidade
        printf("[SWAP ONE SET OF ADJACENT CORNERS 3º CASO (PLL)] [TESTE] 3ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if((front_f[0][0] == front_f[0][2] && front_f[0][2] == back_f[0][1]) && (front_f[0][1] == right_f[0][2] && right_f[0][2] == left_f[0][0]) && (right_f[0][0] == right_f[0][1] && right_f[0][1] == back_f[0][0]) && (left_f[0][1] == left_f[0][2] && left_f[0][2] == back_f[0][2])){
        // 4ª possibilidade
        printf("[SWAP ONE SET OF ADJACENT CORNERS 3º CASO (PLL)] [TESTE] 4ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }
    
    // 4º (R' U² R U²)(R' F)(R U R' U')(R' F') R² U'
    if((front_f[0][0] == front_f[0][2] && front_f[0][2] == right_f[0][1]) && (front_f[0][1] == right_f[0][0] && right_f[0][0] == back_f[0][0]) && (right_f[0][2] == back_f[0][1] && back_f[0][1] == left_f[0][0]) && (back_f[0][2] == left_f[0][1] && left_f[0][1] == left_f[0][2])){
        // 1ª possibilidade
        printf("[SWAP ONE SET OF ADJACENT CORNERS 4º CASO (PLL)] [TESTE] 1ª possibilidade\n");
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if((front_f[0][0] == right_f[0][2] && right_f[0][2] == left_f[0][1]) && (front_f[0][1] == left_f[0][0] && left_f[0][0] == left_f[0][2]) && (front_f[0][2] == right_f[0][1] && right_f[0][1] == back_f[0][2]) && (right_f[0][0] == back_f[0][0] && back_f[0][0] == back_f[0][1])){
        // 2ª possibilidade
        printf("[SWAP ONE SET OF ADJACENT CORNERS 4º CASO (PLL)] [TESTE] 2ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if((front_f[0][0] == right_f[0][1] && right_f[0][1] == right_f[0][2]) && (front_f[0][1] == right_f[0][0] && right_f[0][0] == left_f[0][2]) && (front_f[0][2] == back_f[0][1] && back_f[0][1] == left_f[0][0]) && (back_f[0][0] == back_f[0][2] &&  back_f[0][2] == left_f[0][1])){
        // 3ª possibilidade
        printf("[SWAP ONE SET OF ADJACENT CORNERS 4º CASO (PLL)] [TESTE] 3ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if((front_f[0][0] == back_f[0][0] && back_f[0][0] == left_f[0][1]) && (front_f[0][1] == front_f[0][2] && front_f[0][2] == left_f[0][0]) && (right_f[0][0] == right_f[0][2] && right_f[0][2] == back_f[0][1]) && (right_f[0][1] == back_f[0][2] && back_f[0][2] == left_f[0][2])){
        // 4ª possibilidade
        printf("[SWAP ONE SET OF ADJACENT CORNERS 4º CASO (PLL)] [TESTE] 4ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }
    
    // 5º (R U R' F')[(R U R' U')(R' F)(R² U' R') U']
    if((front_f[0][0] == right_f[0][1] && right_f[0][1] == right_f[0][2]) && (front_f[0][1] == front_f[0][2] && front_f[0][2] == back_f[0][2]) && (right_f[0][0] == back_f[0][0] && back_f[0][0] == back_f[0][1]) && (left_f[0][0] == left_f[0][1] && left_f[0][1] == left_f[0][2])){
        // 1ª possibilidade
        printf("[SWAP ONE SET OF ADJACENT CORNERS 5º CASO (PLL)] [TESTE] 1ª possibilidade\n");
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if((front_f[0][0] == right_f[0][1] && right_f[0][1] == right_f[0][2]) && (front_f[0][1] == front_f[0][2] && front_f[0][2] == left_f[0][0]) && (right_f[0][0] == left_f[0][1] && left_f[0][1] == left_f[0][2]) && (back_f[0][0] == back_f[0][1] && back_f[0][1] == back_f[0][2])){
        // 2ª possibilidade
        printf("[SWAP ONE SET OF ADJACENT CORNERS 5º CASO (PLL)] [TESTE] 2ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if((front_f[0][0] == back_f[0][0] && back_f[0][0] == back_f[0][1]) && (front_f[0][1] == front_f[0][2] && front_f[0][2] == left_f[0][0]) && (left_f[0][1] == left_f[0][2] && left_f[0][2] == back_f[0][2] && (right_f[0][0] == right_f[0][1] && right_f[0][1] == right_f[0][2]))){
        // 3ª possibilidade
        printf("[SWAP ONE SET OF ADJACENT CORNERS 5º CASO (PLL)] [TESTE] 3ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if((front_f[0][0] == front_f[0][1] && front_f[0][1] == front_f[0][2]) && (right_f[0][0] == back_f[0][0] && back_f[0][0] == back_f[0][1]) && (right_f[0][1] == right_f[0][2] && right_f[0][2] == left_f[0][0]) && (left_f[0][1] == left_f[0][2] && left_f[0][2] == back_f[0][2])){
        // 4ª possibilidade
        printf("[SWAP ONE SET OF ADJACENT CORNERS 5º CASO (PLL)] [TESTE] 4ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }
    
    // 6º (R' U² R' d')(R' F')(R² U' R' U)(R' F R U' F): (R' U' F')(R U R' U')(R' F)(R2 U')(R' U' R U) R' U R
    if((left_f[0][0] == left_f[0][1] && left_f[0][1] == left_f[0][2]) && (front_f[0][0] == right_f[0][2] && right_f[0][2] == back_f[0][1]) && (front_f[0][1] == right_f[0][0] && right_f[0][0] == back_f[0][0]) && (front_f[0][2] == right_f[0][1] && right_f[0][1] == back_f[0][2])){
        // 1ª possibilidade
        printf("[SWAP ONE SET OF ADJACENT CORNERS 6º CASO (PLL)] [TESTE] 1ª possibilidade\n");
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if((back_f[0][0] == back_f[0][1] && back_f[0][1] == back_f[0][2]) && (front_f[0][0] == right_f[0][2] && right_f[0][2] == left_f[0][1]) && (front_f[0][1] == right_f[0][0] && right_f[0][0] == left_f[0][2]) && (front_f[0][2] == right_f[0][1] && right_f[0][1] == left_f[0][0])){
        // 2ª possibilidade
        printf("[SWAP ONE SET OF ADJACENT CORNERS 6º CASO (PLL)] [TESTE] 2ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if((right_f[0][0] == right_f[0][1] && right_f[0][1] == right_f[0][2]) && (front_f[0][0] == left_f[0][1] && left_f[0][1] == back_f[0][0]) && (front_f[0][1] == left_f[0][2] && left_f[0][2] == back_f[0][2]) && (front_f[0][2] == left_f[0][0] && left_f[0][0] == back_f[0][1])){
        // 3ª possibilidade
        printf("[SWAP ONE SET OF ADJACENT CORNERS 6º CASO (PLL)] [TESTE] 3ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if((front_f[0][0] == front_f[0][1] && front_f[0][1] == front_f[0][2]) && (left_f[0][0] == back_f[0][1] && back_f[0][1] == right_f[0][2]) && (left_f[0][1] == back_f[0][0] && back_f[0][0] == right_f[0][0]) && (left_f[0][2] == back_f[0][2] && back_f[0][2] == right_f[0][1])){
        // 4ª possibilidade
        printf("[SWAP ONE SET OF ADJACENT CORNERS 6º CASO (PLL)] [TESTE] 4ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }
    
    // FIM do SWAP ONE SET OF ADJACENT CORNERS
    
    // SWAP ONE SET OF CORNERS DIAGONALLY
    
    // 1º (R' U R' d')(R' F')(R² U' R' U)(R' F R F): (R' U R' U') (B' R')(B2 U')(B' U B' R)(B R)
    if((front_f[0][0] == front_f[0][1] && front_f[0][1] == back_f[0][0]) && (front_f[0][2] == right_f[0][1] && right_f[0][1] == back_f[0][2]) && (right_f[0][0] == left_f[0][1] && left_f[0][1] == left_f[0][2]) && (right_f[0][2] == back_f[0][1] && back_f[0][1] == left_f[0][0])){
        // 1ª possibilidade
        printf("[SWAP ONE SET OF CORNERS DIAGONALLY 1º CASO (PLL)] [TESTE] 1ª possibilidade\n");
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if((front_f[0][0] == back_f[0][0] && back_f[0][0] == back_f[0][1]) && (front_f[0][1] == right_f[0][0] && right_f[0][0] == left_f[0][2]) && (front_f[0][2] == right_f[0][1] && right_f[0][1] == back_f[0][2]) && (right_f[0][2] == left_f[0][0] && left_f[0][0] == left_f[0][1])){
        // 2ª possibilidade
        printf("[SWAP ONE SET OF CORNERS DIAGONALLY 1º CASO (PLL)] [TESTE] 2ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if((front_f[0][0] == back_f[0][0] && back_f[0][0] == left_f[0][1]) && (front_f[0][1] == right_f[0][0] && right_f[0][0] == left_f[0][2]) && (front_f[0][2] == back_f[0][1] && back_f[0][1] == back_f[0][2]) && (right_f[0][1] == right_f[0][2] && right_f[0][2] == left_f[0][0])){
        // 3ª possibilidade
        printf("[SWAP ONE SET OF CORNERS DIAGONALLY 1º CASO (PLL)] [TESTE] 3ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if((front_f[0][0] == back_f[0][0] && back_f[0][0] == left_f[0][1]) && (front_f[0][1] == front_f[0][2] && front_f[0][2] == back_f[0][2]) && (right_f[0][0] == right_f[0][1] && right_f[0][1] == left_f[0][2]) && (right_f[0][2] == back_f[0][1] && back_f[0][1] == left_f[0][0])){
        // 4ª possibilidade
        printf("[SWAP ONE SET OF CORNERS DIAGONALLY 1º CASO (PLL)] [TESTE] 4ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }
    
    // 2º [(L U' R) U² (L' U R')][(L U' R) U² (L' U R')] U
    if((front_f[0][0] == back_f[0][0] && back_f[0][0] == back_f[0][1]) && (front_f[0][1] == front_f[0][2] && front_f[0][2] == back_f[0][2]) && (right_f[0][0] == left_f[0][1] && left_f[0][1] == left_f[0][2]) && (right_f[0][1] == right_f[0][2] && right_f[0][2] == left_f[0][0])){
        // 1ª possibilidade
        printf("[SWAP ONE SET OF CORNERS DIAGONALLY 2º CASO (PLL)] [TESTE] 1ª possibilidade\n");
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }
    
    // 3º F R U' R' U' (R U R' F')[(R U R' U')(R' F R F')]
    if((front_f[0][0] == front_f[0][1] && front_f[0][1] == back_f[0][0]) && (front_f[0][2] == back_f[0][2] && back_f[0][2] == left_f[0][1]) && (right_f[0][0] == left_f[0][2] && left_f[0][2] == back_f[0][1]) && (right_f[0][1] == right_f[0][2] && right_f[0][2] == left_f[0][0])){
        // 1ª possibilidade
        printf("[SWAP ONE SET OF CORNERS DIAGONALLY 3º CASO (PLL)] [TESTE] 1ª possibilidade\n");
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if((front_f[0][0] == right_f[0][1] && right_f[0][1] == back_f[0][0]) && (front_f[0][1] == front_f[0][2] && front_f[0][2] == back_f[0][2]) && (right_f[0][0] == back_f[0][1] && back_f[0][1] == left_f[0][2]) && (right_f[0][2] == left_f[0][0] && left_f[0][0] == left_f[0][1])){
        // 2ª possibilidade
        printf("[SWAP ONE SET OF CORNERS DIAGONALLY 3º CASO (PLL)] [TESTE] 2ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if((front_f[0][0] == right_f[0][1] && right_f[0][1] == back_f[0][0]) && (front_f[0][1] == right_f[0][2] && right_f[0][2] == left_f[0][0]) && (front_f[0][2] == back_f[0][1] && back_f[0][1] == back_f[0][2]) && (right_f[0][0] == left_f[0][1] && left_f[0][1] == left_f[0][2])){
        // 3ª possibilidade
        printf("[SWAP ONE SET OF CORNERS DIAGONALLY 3º CASO (PLL)] [TESTE] 3ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if((front_f[0][0] == back_f[0][0] && back_f[0][0] == back_f[0][1]) && (front_f[0][1] == right_f[0][2] && right_f[0][2] == left_f[0][0]) && (front_f[0][2] == back_f[0][2] && back_f[0][2] == left_f[0][1]) && (right_f[0][0] == right_f[0][1] && right_f[0][1] == left_f[0][2])){
        // 4ª possibilidade
        printf("[SWAP ONE SET OF CORNERS DIAGONALLY 3º CASO (PLL)] [TESTE] 4ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }
    
    // 4º [(R' U L') U² (R U' L)][(R' U L') U² (R U' L)] U'
    if((front_f[0][0] == front_f[0][1] && front_f[0][1] == back_f[0][0]) && (front_f[0][2] == back_f[0][1] && back_f[0][1] == back_f[0][2]) && (right_f[0][0] == right_f[0][1] && right_f[0][1] == left_f[0][2]) && (right_f[0][2] == left_f[0][0] && left_f[0][0] == left_f[0][1])){
        // 1ª possibilidade
        printf("[SWAP ONE SET OF CORNERS DIAGONALLY 4º CASO (PLL)] [TESTE] 1ª possibilidade\n");
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }
    
    // FIM do SWAP ONE SET OF CORNERS DIAGONALLY
    
    // DOUBLE SPINS
    
    // 1º R² u R' U R' U' R u' R² (y' R' U R): R2 U (R' U R' U' R) U' R2 D (U' R' U R) D' U
    if((front_f[0][0] == right_f[0][2] && right_f[0][2] == back_f[0][1]) && (front_f[0][1] == front_f[0][2] && front_f[0][2] == back_f[0][2]) && (right_f[0][0] == back_f[0][0] && back_f[0][0] == left_f[0][1]) && (right_f[0][1] == left_f[0][0] && left_f[0][0] == left_f[0][2])){
        // 1ª possibilidade
        printf("[DOUBLE SPINS 1º CASO (PLL)] [TESTE] 1ª possibilidade\n");
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        bottomClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        bottomIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if((front_f[0][0] == right_f[0][2] && right_f[0][2] == back_f[0][1]) && (front_f[0][1] == back_f[0][0] && back_f[0][0] == back_f[0][2]) && (front_f[0][2] == right_f[0][1] && right_f[0][1] == left_f[0][0]) && (right_f[0][0] == left_f[0][1] && left_f[0][1] == left_f[0][2])){
        // 2ª possibilidade
        printf("[DOUBLE SPINS 1º CASO (PLL)] [TESTE] 2ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        bottomClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        bottomIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if((front_f[0][0] == back_f[0][0] && back_f[0][0] == back_f[0][1]) && (front_f[0][1] == back_f[0][2] && back_f[0][2] == left_f[0][2]) && (front_f[0][2] == right_f[0][1] && right_f[0][1] == left_f[0][0]) && (right_f[0][0] == right_f[0][2] && right_f[0][2] == left_f[0][1])){
        // 3ª possibilidade
        printf("[DOUBLE SPINS 1º CASO (PLL)] [TESTE] 3ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        bottomClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        bottomIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if((front_f[0][0] == front_f[0][2] && front_f[0][2] == back_f[0][1]) && (front_f[0][1] == left_f[0][2] && left_f[0][2] == back_f[0][2]) && (right_f[0][0] == back_f[0][0] && back_f[0][0] == left_f[0][1]) && (right_f[0][1] == right_f[0][2] && right_f[0][2] == left_f[0][0])){
        // 4ª possibilidade
        printf("[DOUBLE SPINS 1º CASO (PLL)] [TESTE] 4ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        bottomClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        bottomIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }
    
    // 2º (R U R') y' R² u' R U' R' U R' u R²: (R U R') F2 D' L U' L' U L' D F2
    if((front_f[0][0] == right_f[0][2] && right_f[0][2] == back_f[0][1]) && (front_f[0][1] == left_f[0][0] && left_f[0][0] == left_f[0][2]) && (front_f[0][2] == back_f[0][2] && back_f[0][2] == left_f[0][1]) && (right_f[0][0] == right_f[0][1] && right_f[0][1] == back_f[0][0])){
        // 1ª possibilidade
        printf("[DOUBLE SPINS 2º CASO (PLL)] [TESTE] 1ª possibilidade\n");
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        bottomIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        bottomClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if((front_f[0][0] == front_f[0][1] && front_f[0][1] == right_f[0][2]) && (front_f[0][2] == right_f[0][1] && right_f[0][1] == left_f[0][0]) && (right_f[0][0] == back_f[0][1] && back_f[0][1] == left_f[0][2]) && (back_f[0][0] == back_f[0][2] && back_f[0][2] == left_f[0][1])){
        // 2ª possibilidade
        printf("[DOUBLE SPINS 2º CASO (PLL)] [TESTE] 2ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        bottomIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        bottomClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if((front_f[0][0] == right_f[0][1] && right_f[0][1] == back_f[0][0]) && (front_f[0][1] == back_f[0][2] && back_f[0][2] == left_f[0][2]) && (front_f[0][2] == left_f[0][0] && left_f[0][0] == left_f[0][1]) && (right_f[0][0] == right_f[0][2] && right_f[0][2] == back_f[0][1])){
        // 3ª possibilidade
        printf("[DOUBLE SPINS 2º CASO (PLL)] [TESTE] 3ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        bottomIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        bottomClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if((front_f[0][0] == front_f[0][2] && front_f[0][2] == right_f[0][1]) && (front_f[0][1] == right_f[0][2] && right_f[0][2] == left_f[0][0]) && (right_f[0][0] == back_f[0][0] && back_f[0][0] == left_f[0][1]) && (back_f[0][1] == back_f[0][2] && back_f[0][2] == left_f[0][2])){
        // 4ª possibilidade
        printf("[DOUBLE SPINS 2º CASO (PLL)] [TESTE] 4ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        bottomIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        bottomClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }
    
    // 3º R² u' R U' R U R' u R² (y R U' R'): U F2 R2 L2 U' L2 U L2 D' L2 D R2 F2 U'
    if((front_f[0][0] == right_f[0][2] && right_f[0][2] == left_f[0][1]) && (front_f[0][1] == right_f[0][0] && right_f[0][0] == back_f[0][0]) && (front_f[0][2] == back_f[0][1] && back_f[0][1] == back_f[0][2]) && (right_f[0][1] == left_f[0][0] && left_f[0][0] == left_f[0][2])){
        // 1ª possibilidade
        printf("[DOUBLE SPINS 3º CASO (PLL)] [TESTE] 1ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        bottomIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        bottomClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if((front_f[0][0] == right_f[0][2] && right_f[0][2] == left_f[0][1]) && (front_f[0][1] == back_f[0][0] && back_f[0][0] == back_f[0][2]) && (front_f[0][2] == back_f[0][1] && back_f[0][1] == left_f[0][0]) && (right_f[0][0] == right_f[0][1] && right_f[0][1] == left_f[0][2])){
        // 2ª possibilidade
        printf("[DOUBLE SPINS 3º CASO (PLL)] [TESTE] 2ª possibilidade\n");
        frontClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        bottomIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        bottomClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if((front_f[0][0] == front_f[0][1] && front_f[0][1] == back_f[0][0]) && (front_f[0][2] == back_f[0][1] && back_f[0][1] == left_f[0][0]) && (right_f[0][0] == right_f[0][2] && right_f[0][2] == left_f[0][1]) && (right_f[0][1] == back_f[0][2] && back_f[0][2] == left_f[0][2])){
        // 3ª possibilidade
        printf("[DOUBLE SPINS 3º CASO (PLL)] [TESTE] 3ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        bottomIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        bottomClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if((front_f[0][0] == front_f[0][2] && front_f[0][2] == back_f[0][1]) && (front_f[0][1] == right_f[0][0] && right_f[0][0] == back_f[0][0]) && (right_f[0][1] == back_f[0][2] && back_f[0][2] == left_f[0][2]) && (right_f[0][2] == left_f[0][0] && left_f[0][0] == left_f[0][1])){
        // 4ª possibilidade
        printf("[DOUBLE SPINS 3º CASO (PLL)] [TESTE] 4ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        bottomIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        bottomClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }
    
    
    // 4º (R' U' R) y R² u R' U R U' R u' R²: R' U' R B2 D (L' U L U' L) D' B2
    if((front_f[0][0] == right_f[0][1] && right_f[0][1] == right_f[0][2]) && (front_f[0][1] == right_f[0][0] && right_f[0][0] == back_f[0][0]) && (front_f[0][2] == back_f[0][2] && back_f[0][2] == left_f[0][1]) && (back_f[0][1] == left_f[0][0] && left_f[0][0] == left_f[0][2])){
        // 1ª possibilidade
        printf("[DOUBLE SPINS 4º CASO (PLL)] [TESTE] 1ª possibilidade\n");
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        bottomClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        bottomIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if((front_f[0][0] == right_f[0][2] && right_f[0][2] == left_f[0][1]) && (front_f[0][1] == front_f[0][2] && front_f[0][2] == left_f[0][0]) && (right_f[0][0] == back_f[0][1] && back_f[0][1] == left_f[0][2]) && (right_f[0][1] == back_f[0][0] && back_f[0][0] == back_f[0][2])){
        // 2ª possibilidade
        printf("[DOUBLE SPINS 4º CASO (PLL)] [TESTE] 2ª possibilidade\n");
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        bottomClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        bottomIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if((front_f[0][0] == right_f[0][1] && right_f[0][1] == back_f[0][0]) && (front_f[0][1] == right_f[0][0] && right_f[0][0] == right_f[0][2]) && (front_f[0][2] == back_f[0][1] && back_f[0][1] == left_f[0][0]) && (left_f[0][1] == left_f[0][2] && left_f[0][2] == back_f[0][2])){
        // 3ª possibilidade
        printf("[DOUBLE SPINS 4º CASO (PLL)] [TESTE] 3ª possibilidade\n");
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        bottomClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        bottomIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if((front_f[0][0] == front_f[0][2] && front_f[0][2] == left_f[0][1]) && (front_f[0][1] == right_f[0][2] && right_f[0][2] == left_f[0][0]) && (right_f[0][0] == back_f[0][0] && back_f[0][0] == back_f[0][1]) && (right_f[0][1] == back_f[0][2] && back_f[0][2] == left_f[0][2])){
        // 4ª possibilidade
        printf("[DOUBLE SPINS 4º CASO (PLL)] [TESTE] 4ª possibilidade\n");
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        bottomClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        bottomIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }
    
    
     //Mover o topo para "juntar" as cores certas

    if (front_f[1][1] == right_f[0][0]) {
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[1][1] == back_f[0][0]) {
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[1][1] == left_f[0][0]) {
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }
    
}


void imprimirCubo(struct Cubo cubo) {
    int i, j;
    int matriz_front[3][3];
    int matriz_left[3][3];
    int matriz_right[3][3];
    int matriz_top[3][3];
    int matriz_back[3][3];
    int matriz_bottom[3][3];

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            matriz_back[i][j] = cubo.back.face[i][j];
        }
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            matriz_front[i][j] = cubo.front.face[i][j];
        }
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            matriz_left[i][j] = cubo.left.face[i][j];
        }
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            matriz_right[i][j] = cubo.right.face[i][j];
        }
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            matriz_top[i][j] = cubo.top.face[i][j];
        }
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            matriz_bottom[i][j] = cubo.bottom.face[i][j];
        }
    }

    printf("        ");
    printf("%d %d %d\n", matriz_top[0][0], matriz_top[0][1], matriz_top[0][2]);
    printf("        ");
    printf("%d %d %d\n", matriz_top[1][0], matriz_top[1][1], matriz_top[1][2]);
    printf("        ");
    printf("%d %d %d\n", matriz_top[2][0], matriz_top[2][1], matriz_top[2][2]);
    printf("%d %d %d   %d %d %d   %d %d %d   %d %d %d\n", matriz_left[0][0], matriz_left[0][1], matriz_left[0][2], matriz_front[0][0], matriz_front[0][1], matriz_front[0][2], matriz_right[0][0], matriz_right[0][1], matriz_right[0][2], matriz_back[0][2], matriz_back[0][1], matriz_back[0][0]);
    printf("%d %d %d   %d %d %d   %d %d %d   %d %d %d\n", matriz_left[1][0], matriz_left[1][1], matriz_left[1][2], matriz_front[1][0], matriz_front[1][1], matriz_front[1][2], matriz_right[1][0], matriz_right[1][1], matriz_right[1][2], matriz_back[1][2], matriz_back[1][1], matriz_back[1][0]);
    printf("%d %d %d   %d %d %d   %d %d %d   %d %d %d\n", matriz_left[2][0], matriz_left[2][1], matriz_left[2][2], matriz_front[2][0], matriz_front[2][1], matriz_front[2][2], matriz_right[2][0], matriz_right[2][1], matriz_right[2][2], matriz_back[2][2], matriz_back[2][1], matriz_back[2][0]);
    printf("        ");
    printf("%d %d %d\n", matriz_bottom[0][0], matriz_bottom[0][1], matriz_bottom[0][2]);
    printf("        ");
    printf("%d %d %d\n", matriz_bottom[1][0], matriz_bottom[1][1], matriz_bottom[1][2]);
    printf("        ");
    printf("%d %d %d\n", matriz_bottom[2][0], matriz_bottom[2][1], matriz_bottom[2][2]);
}

int main(int argc, char** argv) {

    /*
       Branco(Bottom): 1
       Amarelo(Top): 2
       Verde(Front): 3
       Laranja(Right): 4
       Azul(Back): 5
       Vermelho(Left): 6
     */

    int i = 0, j = 0, cont = 0;
    struct Cubo cubo;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            cubo.bottom.face[i][j] = 1;
        }
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            cubo.top.face[i][j] = 2;
        }
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            cubo.front.face[i][j] = 3;
        }
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            cubo.right.face[i][j] = 4;
        }
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            cubo.back.face[i][j] = 5;
        }
    }


    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            cubo.left.face[i][j] = 6;
        }
    }


    topClock180(cubo.left.face, cubo.front.face, cubo.right.face, cubo.top.face, cubo.bottom.face, cubo.back.face);
    rightClock(cubo.left.face, cubo.front.face, cubo.right.face, cubo.top.face, cubo.bottom.face, cubo.back.face);
    bottomClock(cubo.left.face, cubo.front.face, cubo.right.face, cubo.top.face, cubo.bottom.face, cubo.back.face);
    rightIClock(cubo.left.face, cubo.front.face, cubo.right.face, cubo.top.face, cubo.bottom.face, cubo.back.face);
    frontClock(cubo.left.face, cubo.front.face, cubo.right.face, cubo.top.face, cubo.bottom.face, cubo.back.face);
    topIClock(cubo.left.face, cubo.front.face, cubo.right.face, cubo.top.face, cubo.bottom.face, cubo.back.face);
    rightIClock(cubo.left.face, cubo.front.face, cubo.right.face, cubo.top.face, cubo.bottom.face, cubo.back.face);
    bottomClock180(cubo.left.face, cubo.front.face, cubo.right.face, cubo.top.face, cubo.bottom.face, cubo.back.face);
    frontClock180(cubo.left.face, cubo.front.face, cubo.right.face, cubo.top.face, cubo.bottom.face, cubo.back.face);
    rightClock180(cubo.left.face, cubo.front.face, cubo.right.face, cubo.top.face, cubo.bottom.face, cubo.back.face);
    bottomIClock(cubo.left.face, cubo.front.face, cubo.right.face, cubo.top.face, cubo.bottom.face, cubo.back.face);
    
    
    montando = 1;

    imprimirCubo(cubo);

    printf("\n\n");



    //CHAMANDO A CRUZ
    cruz(cubo.left.face, cubo.front.face, cubo.right.face, cubo.top.face, cubo.bottom.face, cubo.back.face);

    // CHAMANDO F2L
    while (cont < 4) {
        f2l(cubo.left.face, cubo.front.face, cubo.right.face, cubo.top.face, cubo.bottom.face, cubo.back.face);
        cont++;
    }

    primeiraCamada(cubo.left.face, cubo.front.face, cubo.right.face, cubo.top.face, cubo.bottom.face, cubo.back.face);

    segundaCamada(cubo.left.face, cubo.front.face, cubo.right.face, cubo.top.face, cubo.bottom.face, cubo.back.face);

    oll(cubo.left.face, cubo.front.face, cubo.right.face, cubo.top.face, cubo.bottom.face, cubo.back.face);

    pll(cubo.left.face, cubo.front.face, cubo.right.face, cubo.top.face, cubo.bottom.face, cubo.back.face);

    imprimirCubo(cubo);

    printf("%s", historyMoviments);
    printf("\n\nQuantidade de movimentos: %d", contMovimentos);


    return 0;
}

