#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonction.h"


enum{
ID,
TYPE,
VALEUR_MAX,
VALEUR_MIN,


ZONE,
ETAGE,
JOUR,
MOIS,
ANNEE,
COLUMNS1
};
void add(capteur C)
{
FILE *f=NULL;
f=fopen("capt.txt","a+") ;
if(f!=NULL)
{
fprintf(f,"%s %s %d %d %s %s %d %d %d\n" , C.id,
C.type,C.vmin,C.vmax,C.zone,C.etage,C.captj,C.captm,C.capta);
fclose(f);
}

}
//////////////////////////////////////////////////////////////////////////////////////////////////////

void add_def(capteur C)
{
FILE *f1=NULL;
f1=fopen("captdef.txt","a+");
if(f1!=NULL)
{

fprintf(f1,"%s %s %d %d %s %s %d %d %d \n" , C.id,
C.type,C.vmin,C.vmax,C.zone,C.etage,C.captj,C.captm,C.capta);
fclose(f1);
}

}



void afficher(GtkWidget *liste )

{

capteur p;
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;


store=NULL;
FILE *f;
store=gtk_tree_view_get_model(liste);
if (store==NULL)
{
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("ID",renderer,"text",ID,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("type",renderer,"text",TYPE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Valeur min",renderer,"text",VALEUR_MIN,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("valeur max",renderer,"text",VALEUR_MAX,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Zone",renderer,"text",ZONE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Etage",renderer,"text",ETAGE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Jour d'chat",renderer,"text",JOUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Mois d'achat",renderer,"text",MOIS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Annee d'achat",renderer,"text",ANNEE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


}
store=gtk_list_store_new(COLUMNS1,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT);
f=fopen("capt.txt","r");

char id1[30];
char type1[30];
int vmax1;
int vmin1;
char zone1[30];
char etage1[30];
int j1;
int m1;
int a1;


{
f=fopen("capt.txt","r");
	while(fscanf(f, "%s %s %d %d %s %s %d %d %d \n",id1,type1,&vmin1,&vmax1,zone1,etage1,&j1,&m1,&a1)!=EOF)
	{
gtk_list_store_append(store,&iter);
	gtk_list_store_set(store,&iter,ID,id1,TYPE,type1,VALEUR_MAX,vmax1,VALEUR_MIN,vmin1,ZONE,zone1,ETAGE,etage1,JOUR,j1,MOIS,m1,ANNEE,a1,-1);
	}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}
}


void supp_id(char id[])
{
FILE *f;
    FILE *f1=NULL;
    capteur c;
    f=fopen("capt.txt","r");
    f1=fopen("tmp.txt","w");
    if(f!=NULL)
    {
        
        while(fscanf(f,"%s %s %d %d %s %s %d %d %d\n ",c.id,c.type,&c.vmax,&c.vmin,c.zone,c.etage,&c.captj,&c.captm,&c.capta)!=EOF)
        {
            if(strcmp(c.id,id)!=0)
		   
	    {

                fprintf(f1,"%s %s %d %d %s %s %d %d %d\n ",c.id,c.type,c.vmax,c.vmin,c.zone,c.etage,c.captj,c.captm,c.captj);
            }
                

            }
        fclose(f);
        fclose(f1);

        }

    remove ("capt.txt");
    rename ("tmp.txt","capt.txt");

}






/////////////
void afficherdef(GtkWidget *liste )

{

capteur p;
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;


store=NULL;
FILE *f;
store=gtk_tree_view_get_model(liste);
if (store==NULL)
{
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("ID",renderer,"text",ID,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("type",renderer,"text",TYPE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Valeur min",renderer,"text",VALEUR_MIN,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("valeur max",renderer,"text",VALEUR_MAX,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Zone",renderer,"text",ZONE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Etage",renderer,"text",ETAGE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Jour d'chat",renderer,"text",JOUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Mois d'achat",renderer,"text",MOIS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Annee d'achat",renderer,"text",ANNEE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


}
store=gtk_list_store_new(COLUMNS1,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT);
f=fopen("captdef.txt","r");

char id1[30];
char type1[30];
int vmax1;
int vmin1;
char zone1[30];
char etage1[30];
int j1;
int m1;
int a1;


{
f=fopen("captdef.txt","r");
	while(fscanf(f, "%s %s %d %d %s %s %d %d %d \n",id1,type1,&vmin1,&vmax1,zone1,etage1,&j1,&m1,&a1)!=EOF)
	{
gtk_list_store_append(store,&iter);
	gtk_list_store_set(store,&iter,ID,id1,TYPE,type1,VALEUR_MAX,vmax1,VALEUR_MIN,vmin1,ZONE,zone1,ETAGE,etage1,JOUR,j1,MOIS,m1,ANNEE,a1,-1);
	}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}
}
