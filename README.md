Niniejszy program jest implementacją mrówki Langtona w języku C.

Podczas wywoływania programu należy przekazać następujące dane wejściowe poprzedzone odpowiednią literą zamieszczoną w nawiasie:

a) szerokość pola w którym porusza się mrówka (w) np. w10

b) wysokość pola w którym porusza się mrówka (h) np. h10
c) liczbę iteracji (i) np. i5

d) przedrostek plików wynikowych (p) np. pm

e) kierunek początkowy mrówki (d + liczba z przedziału od 0 do 3; patrz poniżej) np. d3

f) ścieżkę do pliku zawierającego mapę z naniesionymi już "czarnymi" polami i aktualną pozycją mrówki (e)

g) procent czarnych pól (c) np. c50

SPOSÓB OKREŚLANIA KIERUNKU MRÓWKI:

Góra /\ to 0, prawo -> to 1, dół \/ to 2, lewo <- to 3
