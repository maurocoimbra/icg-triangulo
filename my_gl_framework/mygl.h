#ifndef _MYGL_H_
#define _MYGL_H_
#endif

#include "definitions.h"

//-----------------------------------------------------------------------------
void MyGlDraw(void);

struct Pxl {
    int x, y; // coordenadas
    int r, g, b; // cor

    Pxl(int x, int y) // caso não especificada, a cor do pixel será branca
    {
        this->x = x;
        this->y = y;
        r = 255;
        g = 255;
        b = 255;
    }
    Pxl(int x, int y, int r, int g, int b)
    {
        this->x = x;
        this->y = y;
        this->r = r;
        this->g = g;
        this->b = b;
    }
};

//*****************************************************************************
// Defina aqui as suas funções gráficas
//*****************************************************************************

void PutPixel(Pxl p);
void DrawLine(Pxl pi, Pxl pf);
void DrawTriangle(Pxl v1, Pxl v2, Pxl v3);