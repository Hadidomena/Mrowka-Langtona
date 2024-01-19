Niniejszy program jest implementacją mrówki Langtona w języku C.

Podczas wywoływania programu należy przekazać następujące dane wejściowe poprzedzone odpowiednią literą zamieszczoną w nawiasie:

a) szerokość pola w którym porusza się mrówka (-w) np. -w 10

b) wysokość pola w którym porusza się mrówka (-h) np. -h 10

c) liczbę iteracji (-i) np. -i 5

d) przedrostek plików wynikowych (-p) np. -p Mrowa

e) kierunek początkowy mrówki (-d + liczba z przedziału od 0 do 3; patrz poniżej) np. -d 3

f) ścieżkę do pliku zawierającego mapę z naniesionymi już "czarnymi" polami i aktualną pozycją mrówki (-e)

g) procent czarnych pól (-c) np. -c 50

e) polozenie w poziomie (-x) np. -x 5

e) polozenie w pionie (-y) np. -y 5

SPOSÓB OKREŚLANIA KIERUNKU MRÓWKI:

Góra /\ to 0, prawo -> to 1, dół \/ to 2, lewo <- to 3
