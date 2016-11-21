/* 
 * File:   b_face.h
 * Author: Camila Jordana Ribeiro Teixeira
 *
 * Última modificação: 20/11/2016
 */

#ifndef B_FACE_H
#define	B_FACE_H


void turnClock(int face[][3]);
void turnClock180(int face[][3]);
void turnIClock(int face[][3]);
void getTop(int face[][3], int v);
void getTopI(int face[][3], int v);
void setTop(int face[][3], int t[]);
void getBottom(int face[][3], int v);
void getBottomI(int face[][3], int v);
void setBottom(int face[][3], int b[]);
void getLeft(int face[][3], int v);
void getLeftI(int face[][3], int v);
void setLeft(int face[][3], int l[]);
void getRight(int face[][3], int v);
void getRightI(int face[][3], int v);
void setRight(int face[][3], int r[]);


#endif	/* B_FACE_H */

