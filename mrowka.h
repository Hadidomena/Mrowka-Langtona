#ifndef _MROWKA_H
#define _MROWKA_H

typedef struct _ant {
				int direction;
				int position_x;
                int position_y;
} ant;

ant * create(int dir, int width, int height );
int move(ant *ant, Matrix * plansza);
#endif
