#include "mrowka.h"

#define CZARNY 1	//jaka dana reprezentuje czarny kolor planszy
#define BIALY 0		//jaka dana reprezentuje bialy kolor planszy

ant * create(int dir, int width, int height ) {
/*funkcja porzadkujaca poczatkowe parametry: kierunek, szerokosc planszy, wysokosc planszy w strukture typu ant*/

	ant * akt_parametry = (ant *) malloc(sizeof(ant));
	akt_parametry->direction = dir;
	akt_parametry->position_x = width/2 +1;	/*do rozwazenia czy w przypadku parzystego wymiaru chcemy, aby mrowka
						  pojawiala sie po prawej czy lewej stronie od srodka*/
	akt_parametry->position_y = height/2 +1;/*to co wyzej*/

	return akt_parametry;

}
int move(ant *akt_parametry, Matrix * plansza, int szerokosc, int wysokosc) {
    /* Przesuwa mrowke zgodnie z jej kierunkiem, sprawdza czy nie "przechodzi" przez sciane,
       zmienia kolor pola, obraca mrowke
       Jesli mrowka przechodzi przez sciane zwroca 1, jesli nie 0 */

	if ( plansza->data[akt_parametry->position_y][akt_parametry->position_x] == CZARNY)
	{
		if(akt_parametry->direction > 0) //zmiana kierunku
			--(akt_parametry->direction) %= 4;
		else
		{
			(akt_parametry->direction) += 4;
			--(akt_parametry->direction) %= 4;
		}

		plansza->data[akt_parametry->position_y][akt_parametry->position_x] = BIALY; //zmiana koloru pola

		if (akt_parametry->direction == 0) //ruch mrowki
			(akt_parametry->position_y)--;

		else if (akt_parametry->direction == 1)
			(akt_parametry->position_x)++;

		else if (akt_parametry->direction == 2)
			(akt_parametry->position_y)++;

		else if (akt_parametry->direction == 3)
			(akt_parametry->position_x)--;

		if (akt_parametry->position_x < 0 ||			//sprawdzenie czy mrowka nie wyszla poza plansze
		    akt_parametry->position_x >= szerokosc ||
		    akt_parametry->position_y < 0 ||
		    akt_parametry->position_y >= wysokosc)
			return 1;
	}
	else if ( plansza->data[akt_parametry->position_y][akt_parametry->position_x] == BIALY)
	{
		if(akt_parametry->direction > 0) //zmiana kierunku
			++(akt_parametry->direction) %= 4;
		else
		{
			(akt_parametry->direction) += 4;
			++(akt_parametry->direction) %= 4;
		}

		plansza->data[akt_parametry->position_y][akt_parametry->position_x] = CZARNY; //zmiana koloru pola

		if (akt_parametry->direction == 0) //ruch mrowki
			(akt_parametry->position_y)--;

		else if (akt_parametry->direction == 1)
			(akt_parametry->position_x)++;

		else if (akt_parametry->direction == 2)
			(akt_parametry->position_y)++;

		else if (akt_parametry->direction == 3)
			(akt_parametry->position_x)--;

		if (akt_parametry->position_x < 0 ||			//sprawdzenie czy mrowka nie wyszla poza plansze
		    akt_parametry->position_x >= szerokosc ||
		    akt_parametry->position_y < 0 ||
		    akt_parametry->position_y >= wysokosc)
			return 1;
	}

	return 0;
	
}

