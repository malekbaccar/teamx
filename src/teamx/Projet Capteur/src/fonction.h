#include <stdio.h>
#include <stdlib.h>

typedef struct
 {
char id[20];
char type[20];
int vmax;
int vmin;
char zone[20];
char etage[20];
int captj;
int captm;
int capta;
}capteur;



void add(capteur C);
void afficher(GtkWidget *liste );
void supp_id(char id[]);
void add_def(capteur C);

