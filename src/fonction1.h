#include<gtk/gtk.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct 
{
int x1;
int x2;
float x3;

}dechet;

typedef struct menu{
    char id[20];
    char date[20];
    char type[20] ;
    char desert[20];
    char repas [20];
}menu;

/*
dechet plat1 (int z);
dechet plat2 (int z);
dechet plat3 (int z);

void ajoutermenu(char id[],char date[],char type[],char desert[],char repas[]);
void supprimermenu(char id[]);
void modifiermenu(char id[],menu r);
*/
