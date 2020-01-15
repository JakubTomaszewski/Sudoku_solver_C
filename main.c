#include <stdio.h>
#include <stdlib.h>
#include "bibl.h"


int main()
{
    int plansza[9][9];
    printf("Plansza przed:\n");
    wczytaj_do_tablicy("plansza.txt", plansza);
    wypisz(plansza);
    
    if (poprawna_plansza(plansza))
        {
            backtracking(plansza);
            printf("\nPlansza po:\n");
            wypisz(plansza);
        }
    //printf("\nx = %d\n", wspolrzedne[1]);
    //printf("y = %d\n", wspolrzedne[0]);

    return 0;
}