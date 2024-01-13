#include "mat_io.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>

#define LINE_VERTICAL │
#define LINE_HORIZONTAL ─
#define LINE_DOWN_RIGHT ┌
#define LINE_DOWN_LEFT ┐
#define LINE_UP_RIGHT └
#define LINE_UP_LEFT ┘
#define SQUARE_WHITE
#define SQUARE_BLACK █
#define ARROW_NORTH_WHITE L△
#define ARROW_NORTH_BLACK ▲
#define ARROW_EAST_WHITE ▷
#define ARROW_EAST_BLACK ▶
#define ARROW_SOUTH_WHITE ▽
#define ARROW_SOUTH_BLACK ▼
#define ARROW_WEST_WHITE ◁
#define ARROW_WEST_BLACK ◀

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
    if (strcmp(prefix, "") == 0) {
        printf("%i %i %i %i %i\n", mat->r, mat->c, mat->x, mat->y, mat->dir);
        int i, j;
        printf("┌");
        for (int x = 0; x < mat->c; x++) {
            printf("─");
        }
        printf("┐\n");
        for (i = 0; i < mat->r; i++)
        {
            printf("│");
            for (j = 0; j < mat->c; j++)
            {
                if (i == mat->y && j == mat->x) {
                    switch (100 + mat->dir * 10 + mat->data[i][j]) {
			case 100:
			    printf("△");
			  	break;

			case 110:
			  	printf("▷");
				break;

			case 120:
				printf("▽");
				break;

			case 130:
				printf("◁");
				break;

			case 101:
				printf("▲");
				break;

			case 111:
				printf("▶");
				break;

			case 121:
				printf("▼");
				break;

			case 131:
				printf("◀");
                break;

			}
                } else if (mat->data[i][j] == 0) {
                    printf(" ");
                } else {
			printf("█");
		}
            }
            printf("│");
            printf("\n");
        }

        printf("└");
        for (int x = 0; x < mat->c; x++) {
            printf("─");
        }
        printf("┘\n");
    } else {
        char file[1000];
        snprintf(file, 1000, "%s_%d", prefix, x + 1);
        FILE *out = fopen( file, "w" );

        fprintf(out, "%i %i %i %i %i\n", mat->r, mat->c, mat->x, mat->y, mat->dir);
        fprintf(out, "┌");
        for (int x = 0; x < mat->c; x++) {
            fprintf(out, "─");
        }
        fprintf(out, "┐\n");
        int i, j;
        for (i = 0; i < mat->r; i++)
        {
            fprintf(out, "│");
            for (j = 0; j < mat->c; j++)
            {
                if (i == mat->y && j == mat->x) {
                    switch (100 + mat->dir * 10 + mat->data[i][j]) {
			            case 100:
			                fprintf(out, "△");
			  	            break;
			            case 110:
			  	            fprintf(out, "▷");
				            break;
			            case 120:
				            fprintf(out, "▽");
				            break;
			            case 130:
				            fprintf(out, "◁");
				            break;
			            case 101:
				            fprintf(out, "▲");
				            break;
			            case 111:
				            fprintf(out, "▶");
				            break;
			            case 121:
				            fprintf(out, "▼");
				            break;
			            case 131:
				            fprintf(out, "◀");
                            break;
			}
        } else if (mat->data[i][j] == 0) {
            fprintf(out, " ");
        } else {
			fprintf(out, "█");
		}
        }
        fprintf(out, "│");
	    fprintf(out, "\n");
    	}

        fprintf(out, "└");
        for (int x = 0; x < mat->c; x++) {
            fprintf(out, "─");
        }
        fprintf(out, "┘\n");
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
