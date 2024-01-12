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
    int width = -1;
    int height = -1;
    int iterations = -1;
    char * prefix = "";
    int direction = -1;
    char * existing = "abcdefghijklmnoprstuwxyz";
    int covered = 0;

    while ( (c = getopt (argc, argv, "w:h:i:p:d:e:c:")) != -1 ) {
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
      }
    }

    if ( width <= 0 || height <= 0 || iterations <= 0 ||
    direction < 0 || direction > 3 ||
    covered < 0 || covered > 100 )
    {
      printf("Dane wejsciowe zawieraja blad, liczba iteracji, wysokosc i szerokosc planszy musza byc >= 0, natomiast kierunek musi znajdowac sie w przedziale <0, 3>,\na procent zakrytych pol miedzy 0%% a 100%%\n");
      return 1;
    }

    ant * mrowka = create(direction, width, height);
    Matrix *A = strcmp(existing, "abcdefghijklmnoprstuwxyz") != 0 ? readFromFile(existing): fresh_Matrix(covered, width, height,
    mrowka->position_x, mrowka->position_y, mrowka->direction);

    if (A == NULL) {
      return -1;
    }
    int x = 0;]
    while(iterations-->0) {
      move(mrowka, A);
      print(A, prefix, x++);
    }
    return 0;
}
