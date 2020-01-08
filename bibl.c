#include <stdio.h>
#include <stdlib.h>
#include "bibl.h"


void wczytaj_do_tablicy(char *filename, int plansza[9][9])
{
    int pozycja;
    FILE *fin = fopen(filename, "r");
    for (int y = 0; y<9; y++)
    {
        for (int x = 0; x<9; x++)
        {
            fscanf(fin, "%1d", &pozycja);
            
            plansza[y][x] =  pozycja;
        }
    }
    fclose(fin); 
}


void wypisz(int plansza[9][9])
{
    for (int y = 0; y<9; y++)
    {
        if ((y % 3 == 0) && (y != 0))
                printf("- - - - - - - - - - - - - - - \n");
        for (int x = 0; x<9; x++)
        {
            if (x % 3 == 0 && (x != 0))
                printf("|");
            printf(" %d ", plansza[y][x]);
        }
    printf("\n");
    }
}


