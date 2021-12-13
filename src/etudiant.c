#include "etudiant.h"
#include "callbacks.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <gtk/gtk.h>

enum{
IDe,
NOM,
PRENOM,
CIN,
SEXE,
DATE_NAISSANCE,
GSM,
NIVEAUX,
USERNAME,
PASSWORD,
ETAGEe,
CHAMBRE,
TYPEe,
/*NIVEAU,*/
COLUMNSe
};

int verif_pass(char log[], char pw[])
{
int trouve=-1;
FILE *f=NULL;
char ch1[20];
char ch2[20];
f=fopen("utilisateur.txt","r");
if (f!=NULL){
while (fscanf(f,"%s %s ",ch1,ch2)!=EOF)
{if( (strcmp(ch1,log)==0) && (strcmp(ch2,pw)==0)){
trouve=1;}
}
fclose(f);
}
return trouve;
}

void ajouter_et(Etudiant p)

{

FILE *f;
f=fopen("etudiant.txt","a+");
if (f!=NULL)
{
fprintf(f, "%s %s %s %s %s %s %s %s %s %d %d %s %s \n",p.id,p.nom,p.prenom,p.cin,p.sexe,p.date_naissance,p.gsm,p.username,p.password,p.num_etage,p.num_ch,p.type_ch,p.niveaux);

fclose(f);
}}

void afficher_ett(GtkWidget *liste )

{


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
column=gtk_tree_view_column_new_with_attributes("ID",renderer,"text",IDe,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("nom",renderer,"text",NOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",PRENOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("cin",renderer,"text",CIN,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("sexe",renderer,"text",SEXE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("dns",renderer,"text",DATE_NAISSANCE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("gsm",renderer,"text",GSM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);



renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("niveaux",renderer,"text",NIVEAUX,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("username",renderer,"text",USERNAME,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("password",renderer,"text",PASSWORD,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("etage",renderer,"text",ETAGEe,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("chambre",renderer,"text",CHAMBRE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("type",renderer,"text",TYPEe,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


}
store=gtk_list_store_new(COLUMNSe,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f=fopen("util.txt","r");

 char nom[40];
    char prenom[40];
    char sexe[40];
    char date_naissance[40];
    char cin[40];
    char gsm[40];
 char niveaux[40];
    char id[40];
    char username[40];
    char password[40];
    char num_etage[40];
	char num_ch[40];
	char type_ch[40];


{
f=fopen("etudiant.txt","a+");
	while(fscanf(f, "%s %s %s %s %s %s %s %s %s %s %s %s %s \n",id,nom,prenom,cin,sexe,date_naissance,gsm,username,password,num_etage,num_ch,type_ch,niveaux)!=EOF)
	{
gtk_list_store_append(store,&iter);
	gtk_list_store_set(store,&iter,IDe,id,NOM,nom,PRENOM,prenom,CIN,cin,SEXE,sexe,DATE_NAISSANCE,date_naissance,GSM,gsm
,NIVEAUX,niveaux,USERNAME,username,PASSWORD,password,ETAGEe,num_etage,CHAMBRE,num_ch,TYPEe,type_ch,-1);
	}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}
}




void rechercher_ett(GtkWidget *liste,char ch[30] )

{


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
column=gtk_tree_view_column_new_with_attributes("ID",renderer,"text",IDe,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("nom",renderer,"text",NOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",PRENOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("cin",renderer,"text",CIN,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("sexe",renderer,"text",SEXE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("dns",renderer,"text",DATE_NAISSANCE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("gsm",renderer,"text",GSM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);



renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("niveaux",renderer,"text",NIVEAUX,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("username",renderer,"text",USERNAME,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("password",renderer,"text",PASSWORD,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("etage",renderer,"text",ETAGEe,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("chambre",renderer,"text",CHAMBRE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("type",renderer,"text",TYPEe,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


}
store=gtk_list_store_new(COLUMNSe,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f=fopen("util.txt","r");

 char nom[40];
    char prenom[40];
    char sexe[40];
    char date_naissance[40];
    char cin[40];
    char gsm[40];
 char niveaux[40];
    char id[40];
    char username[40];
    char password[40];
    char num_etage[40];
	char num_ch[40];
	char type_ch[40];


{
f=fopen("etudiant.txt","a+");
	while(fscanf(f, "%s %s %s %s %s %s %s %s %s %s %s %s %s \n",id,nom,prenom,cin,sexe,date_naissance,gsm,username,password,num_etage,num_ch,type_ch,niveaux)!=EOF)
	{if (strcmp(ch,nom)==0){
gtk_list_store_append(store,&iter);
	gtk_list_store_set(store,&iter,IDe,id,NOM,nom,PRENOM,prenom,CIN,cin,SEXE,sexe,DATE_NAISSANCE,date_naissance,GSM,gsm
,NIVEAUX,niveaux,USERNAME,username,PASSWORD,password,ETAGEe,num_etage,CHAMBRE,num_ch,TYPEe,type_ch,-1);
	}}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}
}


void supprimer_ett (char id1[20])
{
char nom[40];
    char prenom[40];
    char sexe[40];
    char date_naissance[40];
    char cin[40];
    char gsm[40];
 char niveaux[40];
    char id[40];
    char username[40];
    char password[40];
    char num_etage[40];
	char num_ch[40];
	char type_ch[40];
FILE*f=NULL;
FILE*f1=NULL;

f=fopen("etudiant.txt","r");
f1=fopen("ancien.txt","w+");

while(fscanf(f, "%s %s %s %s %s %s %s %s %s %s %s %s %s \n",id,nom,prenom,cin,sexe,date_naissance,gsm,username,password,num_etage,num_ch,type_ch,niveaux)!=EOF){
if(strcmp(id,id1)!=0){
fprintf(f1, "%s %s %s %s %s %s %s %s %s %s %s %s %s \n",id,nom,prenom,cin,sexe,date_naissance,gsm,username,password,num_etage,num_ch,type_ch,niveaux);
}


}

fclose(f);
fclose(f1);
remove("etudiant.txt");
rename("ancien.txt","etudiant.txt");
printf("supprimer avec succes \n");
}



void modifier_ett(char id1[],Etudiant r){
char nom[40];
    char prenom[40];
    char sexe[40];
    char date_naissance[40];
    char cin[40];
    char gsm[40];
 char niveaux[40];
    char id[40];
    char username[40];
    char password[40];
    char num_etage[40];
	char num_ch[40];
	char type_ch[40];
FILE*f=NULL;
FILE*f1=NULL;

f=fopen("etudiant.txt","r");
f1=fopen("ancien.txt","w+");

while(fscanf(f, "%s %s %s %s %s %s %s %s %s %s %s %s %s \n",id,nom,prenom,cin,sexe,date_naissance,gsm,username,password,num_etage,num_ch,type_ch,niveaux)!=EOF){
if(strcmp(id,id1)==0){
fprintf(f1, "%s %s %s %s %s %s %s %s %s %s %s %s %s \n",id,r.nom,r.prenom,r.cin,sexe,date_naissance,r.gsm,r.username,r.password,num_etage,num_ch,type_ch,niveaux);
}
else
{
fprintf(f1,"%s %s %s %s %s %s %s %s %s %s %s %s %s \n",id,nom,prenom,cin,sexe,date_naissance,gsm,username,password,num_etage,num_ch,type_ch,niveaux);
}

}

fclose(f);
fclose(f1);
remove("etudiant.txt");
rename("ancien.txt","etudiant.txt");
printf("modifier avec succes \n");
}


int stat (char niv[20])
{int s=0;
char nom[40];
    char prenom[40];
    char sexe[40];
    char date_naissance[40];
    char cin[40];
    char gsm[40];
 char niveaux[40];
    char id[40];
    char username[40];
    char password[40];
    char num_etage[40];
	char num_ch[40];
	char type_ch[40];
FILE*f=NULL;
FILE*f1=NULL;

f=fopen("etudiant.txt","r");


while(fscanf(f, "%s %s %s %s %s %s %s %s %s %s %s %s %s \n",id,nom,prenom,cin,sexe,date_naissance,gsm,username,password,num_etage,num_ch,type_ch,niveaux)!=EOF){
if(strcmp(niveaux,niv)==0){
s=s+1;
}


}

return s;
}

