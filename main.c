#include <stdio.h>
#include <stdlib.h>
#include "bibl.h"


int main()
{
    int plansza[9][9];
    wczytaj_do_tablicy("plansza.txt", plansza);
    wypisz(plansza);
    return 0;
}