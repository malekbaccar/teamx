#include "admin.h"
#include <stdio.h>
#include <string.h>
#include <gtk/gtk.h>

enum{
	CIN,
	NOM,
	PRENOM,
	PASS,
	ROLE,
	COLUMNS
};

enum{
	JOUR,
	HEURE,
	ID,
	VALEUR,
	COLUMNS1
};


//Fonctions ADMIN
//AJOUT
void ajouterUtilisateur(char fichier[],user u){
	FILE* f;
	f = fopen(fichier,"a");
	if(f!=NULL){
		fprintf(f,"%s %s %s %s %s\n",u.CIN,u.nom,u.prenom,u.pass,u.role);	
	};
	fclose(f);
};
//SUPPRESSION
void supprimerUtilisateur(char fichier[],char CIN[]){
	FILE* f;
	user n[1000];
	int i = 0;
	f = fopen(fichier,"r");
	//Ecriture du fichier dans un tableau
	if(f!=NULL){
		while(fscanf(f,"%s %s %s %s %s",n[i].CIN,n[i].nom,n[i].prenom,n[i].pass,n[i].role) != EOF){
			i++;
		};
	};
	fclose(f);
	
	//Suppression de l'element choisi
	for(int j=0;j<i;j++){
		if(strcmp(n[j].CIN,CIN)==0) {
			
			for(int k=j;k<i;k++) {
				n[k]=n[k+1];
			};
			i--;
			break;
		};
	};
	f = fopen(fichier,"w");
	//Ecriture du nouveau tableau dans le fichier reintialise
	if(f!=NULL){
		for(int j=0;j<i;j++) {
			fprintf(f,"%s %s %s %s %s\n",n[j].CIN,n[j].nom,n[j].prenom,n[j].pass,n[j].role);
		}
	};
	fclose(f);
};	

//MODIFIER
void modifierUtilisateur(char fichier[], user u){
	FILE* f;
	char cin[8];
	user n[1000];
	int i = 0;
	f = fopen(fichier,"r");
	//Ecriture du fichier dans un tableau
	if(f!=NULL){
		while(fscanf(f,"%s %s %s %s %s",n[i].CIN,n[i].nom,n[i].prenom,n[i].pass,n[i].role) != EOF){
			i++;
		};
	};
	fclose(f);
	//Modification de l'utilisateur
	for(int j=0;j<i;j++){
		if(strcmp(n[j].CIN,u.CIN)==0) {
			n[j]=u;
		};
	};
	f = fopen(fichier,"w");
	//Ecriture du nouveau tableau dans le fichier reintialise
	if(f!=NULL){
		for(int j=0;j<i;j++) {
			fprintf(f,"%s %s %s %s %s\n",n[j].CIN,n[j].nom,n[j].prenom,n[j].pass,n[j].role);
		}
	};
	fclose(f);
}


//CHERCHER
user chercherUtilisateur(char fichier[], char CIN[]){
	FILE* f;
	f = fopen(fichier,"r");
	user u;
	strcpy(u.CIN,"-1");
	char n[30];
	if(f!=NULL){
		while(fscanf(f,"%s %s %s %s %s",u.CIN,u.nom,u.prenom,u.pass,u.role) != EOF){
			if(strcmp(u.CIN,CIN)==0) break;
		}
	}
	fclose(f);
	return u;
}

//3 derniers capteurs
signalCapteur derniersCapteurs(char signal[]){
	FILE* f;
	signalCapteur C;
	f = fopen(signal,"r");
	if(f!=NULL){while(
fscanf(f,"%d %d %d %d",&C.cap1.jour,&C.cap1.heure,&C.cap1.capteur1,&C.cap1.valeur)!=EOF){	fscanf(f,"%d %d %d %d",&C.cap2.jour,&C.cap2.heure,&C.cap2.capteur1,&C.cap2.valeur);
fscanf(f,"%d %d %d %d",&C.cap3.jour,&C.cap3.heure,&C.cap3.capteur1,&C.cap3.valeur);
		}
	}
	return C;
}

//Treeview pour les utilisateurs
void afficherListe(char fichier[],GtkWidget *Liste){
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
user uaf;
FILE *f;

store = gtk_tree_view_get_model(Liste);
if(store == NULL){
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("	CIN",renderer,"text",CIN,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(Liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("	NOM",renderer,"text",NOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(Liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("	PRENOM",renderer,"text",PRENOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(Liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("	PASS",renderer,"text",PASS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(Liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("	ROLE",renderer,"text",ROLE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(Liste),column);

store = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

f = fopen(fichier,"r");
if(f!=NULL){
f = fopen(fichier,"a+");
while(fscanf(f,"%s %s %s %s %s \n",uaf.CIN,uaf.nom,uaf.prenom,uaf.pass,uaf.role)!=EOF){
gtk_list_store_append(store,&iter);
gtk_list_store_set(store, &iter, CIN, uaf.CIN, NOM, uaf.nom, PRENOM, uaf.prenom, PASS, uaf.pass, ROLE, uaf.role, -1);
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(Liste), GTK_TREE_MODEL(store));
g_object_unref(store);
}
}
}

//Treeview pour les capteurs
void afficherAlarmes(char fichier[],GtkWidget *Liste){
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
capteur1 uaf;
FILE *f;

store = gtk_tree_view_get_model(Liste);
if(store == NULL){
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("JOUR",renderer,"text",CIN,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(Liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("HEURE",renderer,"text",NOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(Liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("ID",renderer,"text",PRENOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(Liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("VALEUR",renderer,"text",PASS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(Liste),column);


store = gtk_list_store_new(COLUMNS1, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

f = fopen(fichier,"r");
if(f!=NULL){
f = fopen(fichier,"a+");
while(fscanf(f,"%s %s %s %s \n",uaf.jour,uaf.heure,uaf.capteur1,uaf.valeur)!=EOF){
gtk_list_store_append(store,&iter);
gtk_list_store_set(store, &iter, JOUR, uaf.jour, HEURE, uaf.heure, ID, uaf.capteur1, VALEUR, uaf.valeur, -1);
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(Liste), GTK_TREE_MODEL(store));
g_object_unref(store);
}
}
}

//Ecriture des valeurs de 1 a un fichier Alarmes
void valeursAlarmes(char fichier[], char fichier1[]){
FILE *f,*f1;
capteur1 c;
f = fopen(fichier,"r");
f1 = fopen(fichier1,"w");
if((f!=NULL)&&(f1!=NULL)){
while(fscanf(f,"%s %s %s %s",c.jour,c.heure,c.capteur1,c.valeur)!=EOF){
if(strcmp(c.valeur,"1")==0) fprintf(f1,"%s %s %s %s \n",c.jour,c.heure,c.capteur1,c.valeur);	
}
};
fclose(f);
fclose(f1);
}

//Ecriture des valeurs des capteurs d'un jour donne
void valeursJour(char fichier[], char fichier1[], char fichier2[], int alarme, int jour){
FILE *f,*f1;
capteur1 c;
char jour1[3],fich[40];
itoa(jour,jour1,10);
if (alarme == 0) strcpy(fich,fichier);
else strcpy(fich,fichier1);
f = fopen(fich,"r");
f1 = fopen(fichier2,"w");
if((f!=NULL)&&(f1!=NULL)){
while(fscanf(f,"%s %s %s %s",c.jour,c.heure,c.capteur1,c.valeur)!=EOF){
if(strcmp(c.jour,jour1)==0) fprintf(f1,"%s %s %s %s \n",c.jour,c.heure,c.capteur1,c.valeur);	
}
};
fclose(f);
fclose(f1);
}

//Ecriture d'un fichier contenant les dernieres valeurs
void valeursFinales(char fichier[], char fichier1[], int alarme){
FILE *f;
capteur1 c;
signalCapteur cap;
char fich[40];
if (alarme == 0) {
cap = derniersCapteurs(fichier);
f = fopen(fichier1,"w");
if(f!=NULL){
fprintf(f,"%s %s %s %s \n",cap.cap1.jour,cap.cap1.heure,cap.cap1.capteur1,cap.cap1.valeur);
fprintf(f,"%s %s %s %s \n",cap.cap2.jour,cap.cap2.heure,cap.cap2.capteur1,cap.cap2.valeur);	
fprintf(f,"%s %s %s %s \n",cap.cap3.jour,cap.cap3.heure,cap.cap3.capteur1,cap.cap3.valeur);	
};
fclose(f);
}
else{
cap = derniersCapteurs(fichier);
f = fopen(fichier1,"w");
if(f!=NULL){
if(strcmp(cap.cap1.valeur,"1")==0) fprintf(f,"%s %s %s %s \n",cap.cap1.jour,cap.cap1.heure,cap.cap1.capteur1,cap.cap1.valeur);
if(strcmp(cap.cap2.valeur,"1")==0) fprintf(f,"%s %s %s %s \n",cap.cap2.jour,cap.cap2.heure,cap.cap2.capteur1,cap.cap2.valeur);	
if(strcmp(cap.cap3.valeur,"1")==0) fprintf(f,"%s %s %s %s \n",cap.cap3.jour,cap.cap3.heure,cap.cap3.capteur1,cap.cap3.valeur);	
}
fclose(f);
}
}

//Conversion int => str
char* itoa(int value, char* result, int base) {
    // check that the base if valid
    if (base < 2 || base > 36) { *result = '\0'; return result; }

    char* ptr = result, *ptr1 = result, tmp_char;
    int tmp_value;

    do {
        tmp_value = value;
        value /= base;
        *ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value - value * base)];
    } while ( value );

    // Apply negative sign
    if (tmp_value < 0) *ptr++ = '-';
    *ptr-- = '\0';
    while(ptr1 < ptr) {
        tmp_char = *ptr;
        *ptr--= *ptr1;
        *ptr1++ = tmp_char;
    }
    return result;
}



//Authentification
int authUser(char fichier[], char CIN[], char pass[]){
int auth = 0;
user loginEntry;
FILE *f;
f = fopen(fichier,"r");
if(f!=NULL){
while(fscanf(f,"%s %s %s %s %s",loginEntry.CIN,loginEntry.nom,loginEntry.prenom,loginEntry.pass,loginEntry.role) != EOF){
if(strcmp(CIN,loginEntry.CIN)==0) if(strcmp(pass,loginEntry.pass)==0) auth = 1;
}
}
fclose(f);
return auth;
}

