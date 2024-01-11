#include "mrowka.h"

ant * create(int dir, int width, int height ) {
    // trzeba przypisac wartosci dla 3 parametrow struktury ant
    // imo mozna ja zawsze ustawiac na srodku planszy, wiec uzyc jej wymiarow do przypisania pozycji x i y mrowki
}
int move(ant *ant, Matrix * plansza) {
    // przesuwa mrowke zgodnie z jej kierunkiem, oraz sprawdza czy nie "przechodzi" ona przez sciane
    // trzeba zmienic jej kierunek potem, moja propozycja to np wzor (direction + 4) % 4 zeby nie zaleznie czy skreca
    // w lewo czy prawo zawsze byla liczba z zakresu <0, 3>
    // i niech przy przechodzeniu przez sciane zwroci 1, jesli nie ma problemow 0
    // nie widze wiecej potencjalu na bledy, ale jakby cos bylo to tez mozesz dodac
}

