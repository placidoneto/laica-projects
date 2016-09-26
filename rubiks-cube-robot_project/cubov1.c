#include <stdio.h>

int aux1;
int aux2;

struct Face{
	int face[3][3];
};

void turnClock(){
	struct Face f;
        //girando os elementos das pontas
        aux1 = f.face[0][0];
        aux2 = f.face[0][2];
        f.face[0][2] = aux1;
        aux1 = f.face[2][2];
        f.face[2][2] = aux2;
        aux2 = f.face[2][0];
        f.face[2][0] = aux1;
        f.face[0][0] = aux2;

        //girando os elementos do meio
        aux1 = f.face[0][1];
        aux2 = f.face[1][2];
        f.face[1][2] = aux1;
        aux1 = f.face[2][1];
        f.face[2][1] = aux2;
        aux2 = f.face[1][0];
        f.face[1][0] = aux1;
        f.face[0][1] = aux2;
}

void turnClock180() {
        turnClock();
        turnClock();
}

void turnIClock(){
        turnClock();
        turnClock();
        turnClock();
}

int* getTop() {
	struct Face f;
        int top[] = {f.face[0][0], f.face[0][1], f.face[0][2]};
        return top;
}

int* getTopI() {
	struct Face f;
        int top[] = {f.face[0][2], f.face[0][1], f.face[0][0]};
        return top;
}

void setTop(int *top) {
	struct Face f;
        f.face[0][0] = top[0];
        f.face[0][1] = top[1];
        f.face[0][2] = top[2];
}

int* getBottom() {
	struct Face f;
        int bottom[] = {f.face[2][0], f.face[2][1], f.face[2][2]};
        return bottom;
}

int* getBottomI() {
	struct Face f;
        int bottom[] = {f.face[2][2], f.face[2][1], f.face[2][0]};
        return bottom;
}

void setBottom(int *bottom) {
	struct Face f;
        f.face[2][0] = bottom[0];
        f.face[2][1] = bottom[1];
        f.face[2][2] = bottom[2];
}

int* getCenterH() {
	struct Face f;
        int centerH[] = {f.face[1][0], f.face[1][1], f.face[1][2]};
        return centerH;
}

void setCenterH(int *centerH) {
	struct Face f;
        f.face[1][0] = centerH[0];
        f.face[1][1] = centerH[1];
        f.face[1][2] = centerH[2];
}

int* getLeft() {
	struct Face f;
        int left[] = {f.face[0][0], f.face[1][0], f.face[2][0]};
        return left;
}

int* getLeftI() {
	struct Face f;
        int left[] = {f.face[2][0], f.face[1][0], f.face[0][0]};
        return left;
}

void setLeft(int *left) {
	struct Face f;
        face[0][0] = left[0];
        face[1][0] = left[1];
        face[2][0] = left[2];
}

int* getRight() {
	struct Face f;
        int right[] = {f.face[0][2], f.face[1][2], f.face[2][2]};
        return right;
}

int* getRightI() {
	struct Face f;
        int right[] = {f.face[2][2], f.face[1][2], f.face[0][2]};
        return right;
}

void setRight(int *right) {
	struct Face f;
	f.face[0][2] = right[0];
        f.face[1][2] = right[1];
        f.face[2][2] = right[2];
}

int* getCenterV() {
	struct Face f;
        int centerV[] = {f.face[0][1], f.face[1][1], f.face[2][1]};
        return centerV;
}

void setCenterV(int *centerV) {
	struct Face f;
        f.face[0][1] = centerV[0];
        f.face[1][1] = centerV[1];
        f.face[2][1] = centerV[2];
}

int main(int argc, char **argv){

	

	return 0;
}
