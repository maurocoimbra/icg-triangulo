#ifndef _MYGL_H_
#define _MYGL_H_
#endif

#include "definitions.h"

//-----------------------------------------------------------------------------
void MyGlDraw(void);

struct Pxl {
    int x;
    int y;
    Pxl(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};

//*****************************************************************************
// Defina aqui as suas funções gráficas
//*****************************************************************************

void PutPixel(int x, int y, int r, int g, int b);
void DrawLine(int xi, int yi, int xf, int yf);
void DrawTriangle(Pxl v1, Pxl v2, Pxl v3);