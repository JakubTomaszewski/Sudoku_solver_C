#include <stdio.h>
#include <stdlib.h>
#include "bibl.h"


int main()
{
    int plansza[9][9];
    int wspolrzedne[2];
    wczytaj_do_tablicy("plansza.txt", plansza);
    wypisz(plansza);
    znajdz_puste(plansza, wspolrzedne);
    printf("\nx = %d\n", wspolrzedne[1]);
    printf("y = %d\n", wspolrzedne[0]);

    return 0;
}