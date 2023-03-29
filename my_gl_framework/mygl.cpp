#include "definitions.h"
#include <iostream>
#include <cmath>
#include <stdio.h>
#include<unistd.h>

using namespace std;

//-----------------------------------------------------------------------------
void MyGlDraw(void)
{
    srand(time(NULL));

    // for(int i =0; i < 200; i++){
    //     int r = rand()%256, g = rand()%256, b = rand()%256;
    //     Pxl p1(rand()%IMAGE_WIDTH, rand()%IMAGE_WIDTH, r, g, b);
    //     PutPixel(p1);
    // }

    // for(int i =0; i < 15; i++){
    //     int r = rand()%256, g = rand()%256, b = rand()%256;
    //     Pxl p2(rand()%IMAGE_WIDTH, rand()%IMAGE_WIDTH, r, g, b);
    //     Pxl p3(rand()%IMAGE_WIDTH, rand()%IMAGE_WIDTH, r, g, b);
    //     DrawLine(p2, p3);
    // }

    // Pxl v1(250, 150);
    // Pxl v2(150, 350);
    // Pxl v3(350, 350);
    // DrawTriangle(v1, v2, v3);

    // for(int i = 0; i < 5; i ++){
    //     int r = rand()%256, g = rand()%256, b = rand()%256;
    //     Pxl v1(rand()%IMAGE_WIDTH, rand()%IMAGE_WIDTH, r, g, b);
    //     Pxl v2(rand()%IMAGE_WIDTH, rand()%IMAGE_WIDTH, r, g, b);
    //     Pxl v3(rand()%IMAGE_WIDTH, rand()%IMAGE_WIDTH, r, g, b);
    //     DrawTriangle(v1, v2, v3);
    // }

    Pxl p1(IMAGE_WIDTH/2, IMAGE_WIDTH/2, rand()%256, rand()%256, rand()%256);
    Pxl p2(IMAGE_WIDTH, IMAGE_WIDTH/4, rand()%256, rand()%256, rand()%256);
    Pxl p3(IMAGE_WIDTH, 0, rand()%256, rand()%256, rand()%256);
    Pxl p4(3*IMAGE_WIDTH/4, 0, rand()%256, rand()%256, rand()%256);
    Pxl p5(IMAGE_WIDTH/2, 0, rand()%256, rand()%256, rand()%256);
    Pxl p6(IMAGE_WIDTH/4, 0, rand()%256, rand()%256, rand()%256);
    Pxl p7(0, 0, rand()%256, rand()%256, rand()%256);
    Pxl p8(0, IMAGE_WIDTH/4, rand()%256, rand()%256, rand()%256);
    Pxl p9(0, IMAGE_WIDTH/2, rand()%256, rand()%256, rand()%256);
    Pxl p10(0, 3*IMAGE_WIDTH/4, rand()%256, rand()%256, rand()%256);
    Pxl p11(0, IMAGE_WIDTH, rand()%256, rand()%256, rand()%256);
    Pxl p12(IMAGE_WIDTH/4, IMAGE_WIDTH, rand()%256, rand()%256, rand()%256);
    Pxl p13(IMAGE_WIDTH/2, IMAGE_WIDTH, rand()%256, rand()%256, rand()%256);
    Pxl p14(3*IMAGE_WIDTH/4, IMAGE_WIDTH, rand()%256, rand()%256, rand()%256);
    Pxl p15(IMAGE_WIDTH, IMAGE_WIDTH, rand()%256, rand()%256, rand()%256);
    Pxl p16(IMAGE_WIDTH, 3*IMAGE_WIDTH/4, rand()%256, rand()%256, rand()%256);
    Pxl p17(IMAGE_WIDTH, IMAGE_WIDTH/2, rand()%256, rand()%256, rand()%256);

    DrawLine(p2, p1);
    DrawLine(p3, p1);
    DrawLine(p4, p1);
    DrawLine(p5, p1);
    DrawLine(p6, p1);
    DrawLine(p7, p1);
    DrawLine(p8, p1);
    DrawLine(p9, p1);
    DrawLine(p10, p1);
    DrawLine(p11, p1);
    DrawLine(p12, p1);
    DrawLine(p13, p1);
    DrawLine(p14, p1);
    DrawLine(p15, p1);
    DrawLine(p16, p1);
    DrawLine(p17, p1);

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