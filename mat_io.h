#ifndef _MAT_IO_H
#define _MAT_IO_H

typedef struct _Matrix
{
    int r, c, x, y, dir;
    int **data;
} Matrix;

/**
 * Zwraca 0 - udalo sie wczytac
 * Zwraca 1 - podczas wczytywania wystapil blad
 */
Matrix *readFromFile(char *fname);
void print(Matrix *mat, char* prefix, int x);
Matrix *fresh_Matrix(int covered, int width, int height, int x, int y, int dir);
Matrix *createMatrix(int r, int c, int x, int y, int dir);
void freeMatrix(Matrix *mat);

#endif
