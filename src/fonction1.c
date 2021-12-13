#include<stdio.h>
#include"fonction1.h"
#include<string.h>
#include<gtk/gtk.h>

enum{
id,
date,
type,
desert,
repas,
COLUMNS2
};

void ajoutermenu(char id[],char date[],char type[],char desert[],char repas[])
{
FILE* f;
f=fopen("menu.txt","a+");
fprintf(f,"%s %s %s %s %s\n",id,date,type,desert,repas);
fclose(f);
}


dechet plat1 (int z){
FILE *f;
dechet x;
dechet y;
int s1,s2;
if (z==1){s1=1; s2=7;}
if (z==2){s1=8; s2=14;}
if (z==3){s1=15; s2=21;}
if (z==4){s1=22; s2=29;}

float ddd=100.000000;
f=fopen("dechets.txt","r");


while(fscanf(f,"%d %d %f \n",&x.x1,&x.x2,&x.x3)!=-1){
if(x.x2==1 && x.x1>=s1 && x.x1<=s2){
	if (x.x3<ddd){

ddd=x.x3;

y.x1=x.x1;
y.x2=x.x2;
y.x3=x.x3;

}
}
    

}  return y;}


dechet plat2 (int z){
FILE *f;
dechet x;
dechet y;
float ddd=100.00;
int s1,s2;
if (z==1){s1=1; s2=7;}
if (z==2){s1=8; s2=14;}
if (z==3){s1=15; s2=21;}
if (z==4){s1=22; s2=29;}
f=fopen("dechets.txt","r");


while(fscanf(f, "%d %d %f \n",&x.x1,&x.x2,&x.x3)!=EOF){
if(x.x2==2  && x.x1>=s1 && x.x1<=s2){
	if (x.x3<ddd){
ddd=x.x3;
y.x1=x.x1;
y.x2=x.x2;
y.x3=x.x3;
}

    
}
}

return y;}



dechet plat3 (int z){
FILE *f;
dechet x;
dechet y;
float ddd=100.0;
int s1,s2;
if (z==1){s1=1; s2=7;}
if (z==2){s1=8; s2=14;}
if (z==3){s1=15; s2=21;}
if (z==4){s1=22; s2=29;}
f=fopen("dechets.txt","r");


while(fscanf(f, "%d %d %f \n",&x.x1,&x.x2,&x.x3)!=EOF){
if(x.x2==3  && x.x1>=s1 && x.x1<=s2){
	if (x.x3<ddd){
ddd=x.x3;
y.x1=x.x1;
y.x2=x.x2;
y.x3=x.x3;
}

    
}
} return y;}


void affichermenu(GtkWidget *liste)
{

menu p;
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
column=gtk_tree_view_column_new_with_attributes("id",renderer,"text",id,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("date",renderer,"text",date,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("type",renderer,"text",type,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("desert",renderer,"text",desert,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("repas",renderer,"text",repas,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


}
store=gtk_list_store_new(COLUMNS2,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f=fopen("menu.txt","r");

char id1[30];
char date1[30];
char type1[30];
char desert1[30];
char repas1[30];

{
f=fopen("menu.txt","a+");
	while(fscanf(f, "%s %s %s %s %s \n",id1,date1,type1,desert1,repas1)!=EOF)
	{
gtk_list_store_append(store,&iter);
	gtk_list_store_set(store,&iter,id,id1,date,date1,type,type1,desert,desert1,repas,repas1,-1);
	}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}
}

void modifiermenu(char id[],menu r){
char id1[30];
char date1[30];
char type1[30];
char desert1[30];
char repas1[30];
FILE*f=NULL;
FILE*f1=NULL;
menu p ;
f=fopen("menu.txt","r");
f1=fopen("ancien.txt","w+");

while(fscanf(f, "%s %s %s %s %s \n",id1,date1,type1,desert1,repas1)!=EOF){
if(strcmp(id,id1)==0){
fprintf(f1, "%s %s %s %s %s \n",id1,r.date,r.type,r.desert,r.repas);
}
else
{
fprintf(f1,"%s %s %s %s %s \n",id1,date1,type1,desert1,repas1);
}

}
fclose(f);
fclose(f1);
remove("menu.txt");
rename("ancien.txt","menu.txt");
printf("modifier avec succes \n");
}



void supprimermenu (char id[]){

menu p ;
char id1[30];
char date1[30];
char type1[30];
char desert1[30];
char repas1[30];
FILE*f=NULL;
FILE*f1=NULL;

f=fopen("menu.txt","r");
f1=fopen("ancien.txt","w+");

while(fscanf(f, "%s %s %s %s %s \n",id1,date1,type1,desert1,repas1)!=EOF){
if(strcmp(id,id1)!=0){
    fprintf(f1,"%s %s %s %s %s \n",id1,date1,type1,desert1,repas1);
}}
fclose(f);
fclose(f1);
remove("menu.txt");
rename("ancien.txt","menu.txt");
printf("supprimer avec succes\n");
}


