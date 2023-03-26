#include "definitions.h"
#include <iostream>
#include <cmath>
#include <stdio.h>

using namespace std;

//-----------------------------------------------------------------------------
void MyGlDraw(void)
{
    //*************************************************************************
    // Chame aqui as funções do mygl.h
    //*************************************************************************
    // PutPixel();
    
    // DrawLine(100, 0, 0, 100);
    // DrawLine(100, 100, 0, 0);
    // DrawLine(, 100, 0, 0);
    Pxl v1(100, 100);
    Pxl v2(100, 200);
    Pxl v3(300, 400);
    DrawTriangle(v1, v2, v3);
}

void PutPixel(int x, int y, int r = 255, int g = 255, int b = 255) {
    // Escreve um pixel de cor (r,g,b) na posicao (x,y) da tela:
    FBptr[4*IMAGE_WIDTH*y + 4*x] = r; // componente R
    FBptr[4*IMAGE_WIDTH*y + 4*x + 1] = g;   // componente G
    FBptr[4*IMAGE_WIDTH*y + 4*x + 2] = b;   // componente B
    FBptr[4*IMAGE_WIDTH*y + 4*x + 3] = 255; // componente A
}

void DrawLine(int xi, int yi, int xf, int yf) {

    int dx, dy, x, y, t, e, incrementX, incrementY;
    
    x = xi;
    y = yi;

    dy = abs(yf - yi);
    dx = abs(xf - xi);
    incrementX = xi > xf ? -1 : 1;
    incrementY = yi > yf ? -1 : 1;
    
    e = 0;

    if (dx > dy){
        while (x != xf) {
                PutPixel(x, y);
                x += incrementX;
                e += 2*dy;
                if (e >= dx) {
                    y += incrementY;
                    e += -2*dx;
                }
            }
    }
    else {
        while (y != yf) {
            PutPixel(x, y);
            y += incrementY;
            e += 2*dx;
            if (e >= dy) {
                x += incrementX;
                e += -2*dy;
            }
        }
    }
}

void DrawTriangle(Pxl v1, Pxl v2, Pxl v3) {
    DrawLine(v1.x, v1.y, v2.x, v2.y);
    DrawLine(v1.x, v1.y, v3.x, v3.y);
    DrawLine(v2.x, v2.y, v3.x, v3.y);
}