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

int znajdz_puste(int plansza[9][9], int wspolrzedne[2])
{
    for (int y = 0; y<9; y++)
    {
       for (int x = 0; x<9; x++)
       {
           if (plansza[y][x] == 0)
           {
               wspolrzedne[0] = y;
               wspolrzedne[1] = x;
               return 1;
            }
       } 
    }
return 0;
} 

int is_valid(int plansza[9][9], int wspolrzedne[2], int liczba)
{
    //row
    for (int x = 0; x<9; x++)
    {
        if ((plansza[wspolrzedne[0]][x] == liczba) && (x != wspolrzedne[1]))
            return 0;
    }
    
    //col
    for (int y = 0; y<9; y++)
    {
        if ((plansza[wspolrzedne[1]][y] == liczba) && (y != wspolrzedne[0]))
            return 0;
    }

    //box
    int box_x = wspolrzedne[1] / 3;
    int box_y = wspolrzedne[0] / 3;

    for (int y = box_y*3; y<(box_y*3 + 3); y++)
        for (int x = box_x*3; x<(box_x*3 + 3); x++)
        {
            if ((plansza[y][x] == liczba) && (y != wspolrzedne[0])  && (x != wspolrzedne[1]))
                return 0;
        }
    return 1;
}


int backtracking(int plansza[9][9])
{
    int wspolrzedne[2];
    if ((znajdz_puste(plansza, wspolrzedne)) == 0)
    {
        return 1;
    }
    else
    {
        znajdz_puste(plansza, wspolrzedne);
    }
    

    for (int i = 1; i<10; i++)
    {
        if (is_valid(plansza, wspolrzedne, i))
        {
            plansza[wspolrzedne[0]][wspolrzedne[1]] = i;
            if ((backtracking(plansza)) == 1)
                return 1;
            plansza[wspolrzedne[0]][wspolrzedne[1]] = 0;
            printf("plansza o wspolrzednych to %d", plansza[wspolrzedne[0]][wspolrzedne[1]] = 0);
        }
    }
    return 0;
}

