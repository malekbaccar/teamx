#include <gtk/gtk.h>
//Type user
typedef struct{
	char CIN[100];
	char nom[100];
	char prenom[100];
	char pass[100];
	char role[20];
}user;

//Type capteur
typedef struct{
	char jour[5];
	char heure[5];
	char capteur1[5];
	char valeur[5];
}capteur1;

typedef struct{
	capteur1 cap1;
	capteur1 cap2;
	capteur1 cap3;
}signalCapteur;


int authUser(char fichier[], char CIN[], char pass[]);

//Fonctions ADMIN
void ajouterUtilisateur(char fichier[], user u);
void supprimerUtilisateur(char fichier[],char CIN[]); 
void modifierUtilisateur(char fichier[], user u);
user chercherUtilisateur(char fichier[], char CIN[]);
void afficherListe(char fichier[], GtkWidget* Liste);
void afficherAlarmes(char fichier[],GtkWidget *Liste);
char* itoa(int value, char* result, int base);
void valeursAlarmes(char fichier[], char fichier1[]);
void valeursJour(char fichier[], char fichier1[], char fichier2[], int alarme, int jour);
void valeursFinales(char fichier[], char fichier1[], int alarme);

//Fonctions du Test
void afficherUtilisateur(user u);
void afficherTout(char fichier[]);

//Fonctions Dashboard
signalCapteur derniersCapteurs(char fumee[]);
