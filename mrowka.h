#ifndef _MROWKA_H
#define _MROWKA_H
#include "mat_io.h"
typedef struct _ant
{
    int direction;
    int position_x;
    int position_y;
} ant;
ant *create(int dir, int * polozenie); //polozenie[0] odcieta, polozenie[1] rzedna
int move(ant *ant, Matrix *plansza, int szerokosc, int wysokosc);
#endif
