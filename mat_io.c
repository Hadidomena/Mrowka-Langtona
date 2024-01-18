#include "mat_io.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>

#define LINE_VERTICAL L'│'
#define LINE_HORIZONTAL L'─'
#define LINE_DOWN_RIGHT L'┌'
#define LINE_DOWN_LEFT L'┐'
#define LINE_UP_RIGHT L'└'
#define LINE_UP_LEFT L'┘'
#define SQUARE_WHITE L' '
#define SQUARE_BLACK L'█'
#define ARROW_NORTH_WHITE L'△'
#define ARROW_NORTH_BLACK L'▲'
#define ARROW_EAST_WHITE L'▷'
#define ARROW_EAST_BLACK L'▶'
#define ARROW_SOUTH_WHITE L'▽'
#define ARROW_SOUTH_BLACK L'▼'
#define ARROW_WEST_WHITE L'◁'
#define ARROW_WEST_BLACK L'◀'

Matrix *readFromFile(char *fname)
{
    int r, c, x, y, dir;
    int ir, ic;
    FILE *fin = fopen(fname, "r");
    Matrix *mat = NULL;
    if (fin != NULL)
    {
        fscanf(fin, "%d %d %d %d %d", &r, &c, &x, &y, &dir);
        mat = createMatrix(r, c, x, y, dir);
        if (mat != NULL)
        {
            for (ir = 0; ir < r; ir++)
                for (ic = 0; ic < c; ic++)
                    fscanf(fin, "%d", &(mat->data[ir][ic]));
        }
        else
        {
            fprintf(stderr, "Wystąpił problem podczas tworzenia macierzy o rozmiarach %d x %d dla danych z pliku: %s\n", r, c,
                    fname);
        }

        fclose(fin);
    }
    else
    {
        fprintf(stderr, "Nie mogę otworzyć pliku o nazwie: %s\n", fname);
    }

    return mat;
}

void print(Matrix *mat, char* prefix, int x)
{
  	setlocale(LC_ALL, "C.UTF-8");
       	if (strcmp(prefix, "") == 0) {
        wprintf(L"%i %i %i %i %i\n", mat->r, mat->c, mat->x, mat->y, mat->dir);
        int i, j;
        wprintf(L"%lc", LINE_DOWN_RIGHT);
        for (int x = 0; x < mat->c; x++) {
            wprintf(L"%lc", LINE_HORIZONTAL);
        }
        wprintf(L"%lc\n", LINE_DOWN_LEFT);
        for (i = 0; i < mat->r; i++)
        {
            wprintf(L"%lc", LINE_VERTICAL);
            for (j = 0; j < mat->c; j++)
            {
                if (i == mat->y && j == mat->x) {
                    switch (100 + mat->dir * 10 + mat->data[i][j]) {
			case 100:
			    wprintf(L"%lc", ARROW_NORTH_WHITE);
			  	break;

			case 110:
			  	wprintf(L"%lc", ARROW_EAST_WHITE);
				break;

			case 120:
				wprintf(L"%lc", ARROW_SOUTH_WHITE);
				break;

			case 130:
				wprintf(L"%lc", ARROW_WEST_WHITE);
				break;

			case 101:
				wprintf(L"%lc", ARROW_NORTH_BLACK);
				break;

			case 111:
				wprintf(L"%lc", ARROW_EAST_BLACK);
				break;

			case 121:
				wprintf(L"%lc", ARROW_SOUTH_BLACK);
				break;

			case 131:
				wprintf(L"%lc", ARROW_WEST_BLACK);
                break;

			}
                } else if (mat->data[i][j] == 0) {
                    wprintf(L"%lc", SQUARE_WHITE);
                } else {
			wprintf(L"%lc", SQUARE_BLACK);
		}
            }
            wprintf(L"%lc", LINE_VERTICAL);
            wprintf(L"\n");
        }

        wprintf(L"%lc", LINE_UP_RIGHT);
        for (int x = 0; x < mat->c; x++) {
            wprintf(L"%lc", LINE_HORIZONTAL);
        }
        wprintf(L"%lc\n", LINE_UP_LEFT);
    } else {
        char file[1000];
        snprintf(file, 1000, "%s_%d", prefix, x + 1);
        FILE *out = fopen( file, "w" );

        fwprintf(out, L"%i %i %i %i %i\n", mat->r, mat->c, mat->x, mat->y, mat->dir);
        fwprintf(out, L"%lc", LINE_DOWN_RIGHT);
        for (int x = 0; x < mat->c; x++) {
            fwprintf(out, L"%lc", LINE_HORIZONTAL);
        }
        fwprintf(out, L"%lc\n", LINE_DOWN_LEFT);
        int i, j;
        for (i = 0; i < mat->r; i++)
        {
            fwprintf(out, L"%lc", LINE_VERTICAL);
            for (j = 0; j < mat->c; j++)
            {
                if (i == mat->y && j == mat->x) {
                    switch (100 + mat->dir * 10 + mat->data[i][j]) {
			            case 100:
			                fwprintf(out, L"%lc", ARROW_NORTH_WHITE);
			  	            break;
			            case 110:
			  	            fwprintf(out, L"%lc", ARROW_EAST_WHITE);
				            break;
			            case 120:
				            fwprintf(out, L"%lc", ARROW_SOUTH_WHITE);
				            break;
			            case 130:
				            fwprintf(out, L"%lc", ARROW_EAST_WHITE);
				            break;
			            case 101:
				            fwprintf(out, L"%lc", ARROW_NORTH_BLACK);
				            break;
			            case 111:
				            fwprintf(out, L"%lc", ARROW_EAST_BLACK);
				            break;
			            case 121:
				            fwprintf(out, L"%lc", ARROW_SOUTH_BLACK);
				            break;
			            case 131:
				            fwprintf(out, L"%lc", ARROW_WEST_BLACK);
                            break;
			}
        } else if (mat->data[i][j] == 0) {
            fwprintf(out, L"%lc", SQUARE_WHITE);
        } else {
			fwprintf(out, L"%lc", SQUARE_BLACK);
		}
        }
        fwprintf(out, L"%lc", LINE_VERTICAL);
	    fwprintf(out, L"\n");
    	}

        fwprintf(out, L"%lc", LINE_UP_RIGHT);
        for (int x = 0; x < mat->c; x++) {
            fwprintf(out, L"%lc", LINE_HORIZONTAL);
        }
        fwprintf(out, L"%lc\n", LINE_UP_LEFT);
    }
}

Matrix *createMatrix(int r, int c, int x, int y, int dir)
{
    int i;
    Matrix *mat = (Matrix *) malloc(sizeof(Matrix));
    if (mat != NULL)
    {
        mat->r = r;
        mat->c = c;
        mat->x = x;
        mat->y = y;
        mat->dir = dir;
        mat->data = (int **) malloc(sizeof(int *) * r);
        for (i = 0; i < r; i++)
        {
            mat->data[i] = (int *) malloc(sizeof(int) * c);
        }
    }

    return mat;
}
Matrix *fresh_Matrix(int covered, int width, int height, int x, int y, int dir)
{
    Matrix *mat = createMatrix(height, width, x, y, dir);

    int percentage = (covered) * (width * height) / 100;
    int positions_x[percentage];
    int positions_y[percentage];
    int current = 0;
    srand(time(NULL));

    for (int x = 0; x < percentage; x++)
    {
        int is_in = 0;
        int a = rand() % width;
        int b = rand() % height;
        for (int y = 0; y < current; y++)
        {
            if (positions_x[y] == a && positions_y[y] == b)
            {
                is_in = 1;
                break;
            }
        }
        if (is_in == 0)
        {
            positions_x[current] = a;
            positions_y[current] = b;
            current++;
        }
        else
        {
            x--;
        }
    }
    for (int x = 0; x < height; x++)
    {
        for (int y = 0; y < width; y++)
        {
            mat->data[x][y] = 0;
        }
    }
    for (int x = 0; x < percentage; x++)
    {
        mat->data[positions_y[x]][positions_x[x]] = 1;
    }
    return mat;
}

void freeMatrix(Matrix *mat)
{
    int i;
    for (i = 0; i < mat->r; i++)
    {
        free(mat->data[i]);
    }
    free(mat->data);
    free(mat);
}
