#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mat_io.h"
#include "mrowka.h"
int main(int argc, char* argv[]) {
    int c;
    int polozenie[2] = {-1, -1}; //polozenie[] = {x, y}
    int width = -1;
    int height = -1;
    int iterations = -1;
    char * prefix = "";
    int direction = -1;
    char * existing = "abcdefghijklmnoprstuwxyz";
    int covered = 0;

    while ( (c = getopt (argc, argv, "w:h:i:p:d:e:c:x:y:")) != -1 ) {
      switch( c )
      {
        case 'w':
          width = atoi(optarg);
          break;
        case 'h':
          height = atoi(optarg);
          break;
        case 'i':
          iterations = atoi(optarg);
          break;
        case 'p':
          prefix = optarg;
          break;
        case 'd':
          direction = atoi(optarg);
          break;
        case 'e':
          existing = optarg;
          break;
        case 'c':
          covered = atoi(optarg);
          break;
        case 'x':
          polozenie[0] = atoi(optarg);
          if (polozenie[0] >= width || polozenie[0] < 0) // mechanizm do ponownego sprawdzenia jeszcze
          {
            polozenie[0] = width / 2 + 1;
            printf("Wprowadziles niepoprawne polozenie x. Ustawiam standardowe polozenie. \n");
          }
          break;
        case 'y':
          polozenie[1] = atoi(optarg);
          if (polozenie[1] >= height || polozenie[1] < 0) // mechanizm do ponownego sprawdzenia jeszcze
          {
            polozenie[1] = height / 2 + 1;
            printf("Wprowadziles niepoprawne polozenie y. Ustawiam standardowe polozenie. \n");
          }
          break;
      }
    }

    if (polozenie[1] >= height || polozenie[1] < 0 ||
    polozenie[0] >= width || polozenie[0] < 0) // tak zmienilem ustawianie jak nie ma x i y, bo pdw czemu ale nie dziala mi NULL
    {
      polozenie[1] = height / 2;
      polozenie[0] = width / 2 - 1;
    }

    if ( width <= 0 || height <= 0 || iterations <= 0 ||
    direction < 0 || direction > 3 ||
    covered < 0 || covered > 100 )
    {
      printf("Dane wejsciowe zawieraja blad, liczba iteracji, wysokosc i szerokosc planszy musza byc >= 0, natomiast kierunek musi znajdowac sie w przedziale <0, 3>,\na procent zakrytych pol miedzy 0%% a 100%%\n");
      return 1;
    }

    ant * mrowka = create(direction, polozenie);
    Matrix *A = strcmp(existing, "abcdefghijklmnoprstuwxyz") != 0 ? readFromFile(existing): fresh_Matrix(covered, width, height,
    mrowka->position_x, mrowka->position_y, mrowka->direction);
    if (strcmp(existing, "abcdefghijklmnoprstuwxyz") != 0) {
        mrowka->direction = A->dir;
        mrowka->position_x = A->x;
        mrowka->position_y = A->y;
    }
    if (A == NULL) {
      return -1;
    }

    int x = 0;
    int check;

    while(iterations-->0) {

      print(A, prefix, x++);

      check = move(mrowka, A, width, height);

      if (check == 1) {
        return 2;
      }

      A->x = mrowka->position_x;
      A->y = mrowka->position_y;
      A->dir = mrowka->direction;

    }
    return 0;
}
