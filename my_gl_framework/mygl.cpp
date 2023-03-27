#include "definitions.h"
#include <iostream>
#include <cmath>
#include <stdio.h>

using namespace std;

//-----------------------------------------------------------------------------
void MyGlDraw(void)
{
    srand(time(NULL));

    int r = rand()%256, g = rand()%256, b = rand()%256;
    Pxl v1(rand()%IMAGE_WIDTH, rand()%IMAGE_WIDTH, r, g, b);
    Pxl v2(rand()%IMAGE_WIDTH, rand()%IMAGE_WIDTH, r, g, b);
    Pxl v3(rand()%IMAGE_WIDTH, rand()%IMAGE_WIDTH, r, g, b);
    DrawTriangle(v1, v2, v3);
}

void PutPixel(Pxl p) {
    // Escreve um pixel de cor (r,g,b) na posicao (x,y) da tela:
    FBptr[4*IMAGE_WIDTH*p.y + 4*p.x] = p.r; // componente R
    FBptr[4*IMAGE_WIDTH*p.y + 4*p.x + 1] = p.g;   // componente G
    FBptr[4*IMAGE_WIDTH*p.y + 4*p.x + 2] = p.b;   // componente B
    FBptr[4*IMAGE_WIDTH*p.y + 4*p.x + 3] = 255; // componente A
}

void DrawLine(Pxl pi, Pxl pf) {

    int dx, dy, x, y, t, e, incrementX, incrementY;
    int r = pi.r, g = pi.g, b = pi.b;

    x = pi.x;
    y = pi.y;

    dy = abs(pf.y - pi.y);
    dx = abs(pf.x - pi.x);
    incrementX = pi.x > pf.x ? -1 : 1;
    incrementY = pi.y > pf.y ? -1 : 1;
    
    e = 0;

    if (dx > dy){
        while (x != pf.x) {
                PutPixel(Pxl(x, y, r, g, b));
                x += incrementX;
                e += 2*dy;
                if (e >= dx) {
                    y += incrementY;
                    e += -2*dx;
                }
            }
    }
    else {
        while (y != pf.y) {
            PutPixel(Pxl(x, y, r, g, b));
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
    DrawLine(v1, v2);
    DrawLine(v1, v3);
    DrawLine(v2, v3);
}