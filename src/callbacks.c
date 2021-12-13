#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "admin.h"
#include <string.h>
#include "stock.h"
#include "stock.c"

user uas;
int valeurAlarmes = 0;
int alarme = 0;
int jour = 1;
char filters[60]="*Filters: ";

void 
on_buttonLogin_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget 
*AdminDashboard,
*SignIN,
*treeview1,
*w1;
//Authentification
GtkWidget *CIN, *pass, *mess;
char cinEntry[40], passEntry[67];
CIN = lookup_widget(button,"entry1_cinEntry");
pass = lookup_widget(button,"entry2_passEntry");
//mess = lookup_widget(button,"label68");
strcpy(cinEntry,gtk_entry_get_text(GTK_ENTRY(CIN)));
strcpy(passEntry,gtk_entry_get_text(GTK_ENTRY(pass)));
int auth = authUser("user.txt",cinEntry,passEntry);
if(auth==1){
//Route vers AdminDashboard
SignIN = lookup_widget(button,"SignIN");
gtk_widget_destroy(SignIN);
AdminDashboard = create_home_in();
gtk_widget_show(AdminDashboard);
treeview1 = lookup_widget(AdminDashboard,"treeview1");
afficherListe("user.txt",treeview1);}
else{
w1 = lookup_widget(button,"SignIN");
gtk_widget_destroy(w1);
SignIN = create_SignIN();
gtk_widget_show(SignIN);
}
}


void
on_button6_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
//Ajout d'un Utilisateur
GtkWidget *CIN, *nom, *prenom, *pass, *role, *AddUser, *AdminDashboard, *treeview1;
user u;
CIN = lookup_widget(button,"entry4");
nom = lookup_widget(button,"entry8");
prenom = lookup_widget(button,"entry9");
pass = lookup_widget(button,"entry6");
role = lookup_widget(button,"combobox1_role");
strcpy(u.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(u.CIN,gtk_entry_get_text(GTK_ENTRY(CIN)));
strcpy(u.pass,gtk_entry_get_text(GTK_ENTRY(pass)));
strcpy(u.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));
strcpy(u.role,gtk_combo_box_get_active_text(GTK_COMBO_BOX(role)));
ajouterUtilisateur("user.txt",u);
//Retour vers le Dashboard
AddUser = lookup_widget(button,"AddUser");
gtk_widget_destroy(AddUser);
AdminDashboard = create_AdminDashboard();
gtk_widget_show(AdminDashboard);
treeview1 = lookup_widget(AdminDashboard,"treeview1");
afficherListe("user.txt",treeview1);
}


void
on_button8_ajoutUser_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
//Route a AddUser
GtkWidget *AddUser, *AdminDashboard;
AdminDashboard = lookup_widget(button,"AdminDashboard");
gtk_widget_destroy(AdminDashboard);
AddUser = create_AddUser();
gtk_widget_show(AddUser);
}


void
on_button10_deleteUser_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *DeleteUserPopup;
DeleteUserPopup = create_DeleteUserPopup();
gtk_widget_show(DeleteUserPopup);
}


void
on_button13_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
//Modification d'un Utilisateur
GtkWidget *nom, *prenom, *pass, *role, *ModifyUser, *AdminDashboard, *treeview1;
nom = lookup_widget(button,"entry11_nom");
prenom = lookup_widget(button,"entry10_prenom");
pass = lookup_widget(button,"entry12_pass");
role = lookup_widget(button,"combobox2_role");
//Copie Entry vers uas
strcpy(uas.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(uas.pass,gtk_entry_get_text(GTK_ENTRY(pass)));
strcpy(uas.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));
strcpy(uas.role,gtk_combo_box_get_active_text(GTK_COMBO_BOX(role)));
modifierUtilisateur("user.txt",uas);
//Retour vers le Dashboard
ModifyUser = lookup_widget(button,"ModifyUser");
gtk_widget_destroy(ModifyUser);
AdminDashboard = create_AdminDashboard();
gtk_widget_show(AdminDashboard);
treeview1 = lookup_widget(AdminDashboard,"treeview1");
afficherListe("user.txt",treeview1);
}


void
on_button11_confirmer_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *DeleteUserPopup, *treeview;
supprimerUtilisateur("user.txt",uas.CIN);
DeleteUserPopup = lookup_widget(button,"DeleteUserPopup");
gtk_widget_destroy(DeleteUserPopup);
}


void
on_button12_annuler_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *DeleteUserPopup;
DeleteUserPopup = lookup_widget(button,"DeleteUserPopup");
gtk_widget_destroy(DeleteUserPopup);
}




void
on_button14_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
//Boutton retour a Dashboard
GtkWidget *AddUser, *AdminDashboard, *treeview1;
AddUser = lookup_widget(button,"AddUser");
gtk_widget_destroy(AddUser);
AdminDashboard = create_AdminDashboard();
gtk_widget_show(AdminDashboard);
treeview1 = lookup_widget(AdminDashboard,"treeview1");
afficherListe("user.txt",treeview1);
}


void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar* CIN;
gchar* nom;
gchar* prenom;
gchar* pass;
gchar* role;
GtkTreeModel *model = gtk_tree_view_get_model(treeview);
if(gtk_tree_model_get_iter(model, &iter, path)){
gtk_tree_model_get(GTK_LIST_STORE(model), &iter, 0, &CIN, 1, &nom, 2, &prenom, 3, &pass, 4, &role, -1);
strcpy(uas.CIN,CIN); 
strcpy(uas.nom,nom); 
strcpy(uas.prenom,prenom); 
strcpy(uas.pass,pass); 
strcpy(uas.role,role); 
}
}


void
on_button7_actualiser_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *AdminDashboard, *w1;
GtkWidget *treeview1;
w1 = lookup_widget(button,"AdminDashboard");
AdminDashboard = create_AdminDashboard();
gtk_widget_show(AdminDashboard);
gtk_widget_hide(w1);
treeview1 = lookup_widget(AdminDashboard,"treeview1");
afficherListe("user.txt",treeview1);
}


void
on_button9_modifierUser_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
//Route a ModifyUser
GtkWidget *ModifyUser, *AdminDashboard, *nom, *prenom, *pass, *role;
AdminDashboard = lookup_widget(button,"AdminDashboard");
gtk_widget_destroy(AdminDashboard);
ModifyUser = create_ModifyUser();
gtk_widget_show(ModifyUser);
//Remplissage Entry a modifier

}


void
on_button15_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
//Boutton retour a Dashboard
GtkWidget *ModifyUser, *AdminDashboard, *treeview1;
ModifyUser = lookup_widget(button,"ModifyUser");
gtk_widget_destroy(ModifyUser);
AdminDashboard = create_AdminDashboard();
gtk_widget_show(AdminDashboard);
treeview1 = lookup_widget(AdminDashboard,"treeview1");
afficherListe("user.txt",treeview1);
}


void
on_button16_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{//Valeur spin
GtkWidget *spin;
spin = lookup_widget(button,"spinbutton1");
jour = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin));
//Actualiser treeview 2 et 3
GtkWidget *Alarmes, *w1;
GtkWidget *treeview3, *treeview4;
w1 = lookup_widget(button,"Alarmes");
Alarmes = create_Alarmes();
gtk_widget_show(Alarmes);
gtk_widget_hide(w1);
//Creation d'un fichier des alarmes
valeursAlarmes("fumee.txt", "fumeeAlarmes.txt");
valeursAlarmes("mouvement.txt", "mouvementAlarmes.txt");
//Filtration
if(valeurAlarmes == 0){
	if(alarme == 0){
	treeview3 = lookup_widget(Alarmes,"treeview3");
	afficherAlarmes("mouvement.txt",treeview3);
	treeview4 = lookup_widget(Alarmes,"treeview4");
	afficherAlarmes("fumee.txt",treeview4);
	}
	else if(alarme == 1){
	treeview3 = lookup_widget(Alarmes,"treeview3");
	afficherAlarmes("mouvementAlarmes.txt",treeview3);
	treeview4 = lookup_widget(Alarmes,"treeview4");
	afficherAlarmes("fumeeAlarmes.txt",treeview4);
	}
}
else if(valeurAlarmes == 1){
	treeview3 = lookup_widget(Alarmes,"treeview3");
	valeursFinales("mouvement.txt","mouvementfinales.txt",alarme);
	afficherAlarmes("mouvementfinales.txt",treeview3);
	treeview4 = lookup_widget(Alarmes,"treeview4");
	valeursFinales("fumee.txt","fumeefinales.txt",alarme);
	afficherAlarmes("fumeefinales.txt",treeview4);
}
else if(valeurAlarmes == 2){
	treeview3 = lookup_widget(Alarmes,"treeview3");
	valeursJour("mouvement.txt","mouvementAlarmes.txt","mouvementJour.txt",alarme,jour);
	afficherAlarmes("mouvementJour.txt",treeview3);
	treeview4 = lookup_widget(Alarmes,"treeview4");
	valeursJour("fumee.txt","fumeeAlarmes.txt","fumeeJour.txt",alarme,jour);
	afficherAlarmes("fumeeJour.txt",treeview4);
}
}



/*
void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
//toute valeur
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))) valeurAlarmes = 0;
}





void
on_supprimer_hsm_clicked               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
//jour choisi
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))) valeurAlarmes = 2;
strcat(filters,"Jour ");
//SpinButton
}
*/

void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
//valeur alarmante
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))) alarme = 1;
strcat(filters,"Alarmes ");
}


void
on_checkbutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
//valeur alarmante
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))) alarme = 0;
}


void
on_entry12_pass_grab_focus             (GtkWidget       *widget,
                                        gpointer         user_data)
{GtkWidget *pass;
pass = lookup_widget(widget,"entry12_pass");
gtk_entry_set_text(GTK_ENTRY(pass),uas.pass);
GtkWidget *nom;
nom = lookup_widget(widget,"entry11_nom");
gtk_entry_set_text(GTK_ENTRY(nom),uas.nom);
GtkWidget *prenom;
prenom = lookup_widget(widget,"entry10_prenom");
gtk_entry_set_text(GTK_ENTRY(prenom),uas.prenom);
GtkWidget *role;
role = lookup_widget(widget,"combobox2_role");
gtk_combo_box_set_active(GTK_COMBO_BOX(role),2);
}



void
on_checkbutton2_grab_focus             (GtkWidget       *widget,
                                        gpointer         user_data)
{//Initialisation
GtkWidget *toggle, *toggle1, *R1, *R2, *R3, *output, *spin;
toggle = lookup_widget(widget,"checkbutton1");
toggle1 = lookup_widget(widget,"checkbutton2");
R1 = lookup_widget(widget,"radiobutton2");
R3 = lookup_widget(widget,"radiobutton3");
spin = lookup_widget(widget,"spinbutton1");
if (alarme==1) gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(toggle), TRUE);
else if (alarme==0) gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(toggle1), TRUE);
if (valeurAlarmes == 0) gtk_toggle_button_set_active(GTK_RADIO_BUTTON(R1), TRUE);
else if (valeurAlarmes == 2) gtk_toggle_button_set_active(GTK_RADIO_BUTTON(R3), TRUE);
gtk_spin_button_set_value(spin,jour);
}


void
on_button17_alarmes_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Alarmes,
	  *AdminDashboard;
AdminDashboard = lookup_widget(button,"AdminDashboard");
gtk_widget_destroy(AdminDashboard);
Alarmes = create_Alarmes ();
gtk_widget_show (Alarmes);
}


void
on_button17_retour_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Alarmes,
	  *AdminDashboard;
Alarmes = lookup_widget(button,"Alarmes");
gtk_widget_destroy(Alarmes);
AdminDashboard = create_AdminDashboard ();
gtk_widget_show (AdminDashboard);
}


void
on_button18_logout_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *SignIn,
	  *AdminDashboard;
AdminDashboard = lookup_widget(button,"AdminDashboard");
gtk_widget_destroy(AdminDashboard);
SignIn = create_SignIN ();
gtk_widget_show (SignIn);
}




// stock


produit o;
char tyy[20]="froid";
int choix=0;
char tyy1[20]="froid";
int x1=0;int x2=0;
void
on_modifier_st_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *afiicher_st;
afiicher_st=lookup_widget(button,"afiicher_st");
gtk_widget_destroy(afiicher_st);
produit p;
FILE *f;
f=fopen("produit.txt","r");
GtkWidget *modifier_st;
  modifier_st = create_modifier_st ();
  gtk_widget_show (modifier_st);
GtkWidget *Mref_st;
Mref_st = lookup_widget (modifier_st ,"Mref_st");
GtkWidget *Mnom_st,*combobox_entry;
Mnom_st = lookup_widget (modifier_st ,"Mnom_st");
GtkWidget *combobox2_st;
combobox2_st = lookup_widget (modifier_st ,"combobox2_st");
combobox_entry=GTK_COMBO(combobox2_st)->entry;
GtkWidget *spinbutton11_st;
spinbutton11_st = lookup_widget (modifier_st ,"spinbutton11_st");
GtkWidget *spinbutton22_st;
spinbutton22_st = lookup_widget (modifier_st ,"spinbutton22_st");

while(fscanf(f,"%s %s %s %d %s %s %d\n",p.ref,p.nom,p.categ,&p.quant,p.type,p.date,&p.poid)!=-1){
 if (strcmp(p.ref,o.ref)==0){
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(modifier_st,"Mref_st")),p.ref);
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(modifier_st,"Mnom_st")),p.nom);
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(modifier_st,"combobox2_st")),p.categ);
                gtk_range_set_value(GTK_ENTRY(lookup_widget(modifier_st,"spinbutton11_st")),p.quant);
                gtk_range_set_value(GTK_ENTRY(lookup_widget(modifier_st,"spinbutton22_st")),p.poid);
		gtk_entry_set_text(GTK_ENTRY(combobox_entry),p.categ);

}}
GtkWidget *erreur_nom2,*erreur_ref2,*erreur_conf2;

erreur_nom2=lookup_widget(modifier_st,"erreur_nom2");
erreur_ref2=lookup_widget(modifier_st,"erreur_ref2");
erreur_conf2=lookup_widget(modifier_st,"erreur_conf2");
 
gtk_widget_hide(erreur_nom2);  
gtk_widget_hide(erreur_ref2);  
gtk_widget_hide(erreur_conf2);
}


void
on_ajouter_st_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *afiicher_st;
afiicher_st=lookup_widget(button,"afiicher_st");
gtk_widget_destroy(afiicher_st);
GtkWidget *ajouter_st;
ajouter_st = create_ajouter_st ();
  gtk_widget_show (ajouter_st);


GtkWidget *erreur_nom1,*erreur_ref1,*erreur_categ1,*erreur_conf1;

erreur_nom1=lookup_widget(ajouter_st,"erreur_nom1");
erreur_ref1=lookup_widget(ajouter_st,"erreurref_1");
erreur_categ1=lookup_widget(ajouter_st,"erreur_categ1");
erreur_categ1=lookup_widget(ajouter_st,"erreur_conf1");

gtk_widget_hide(erreur_nom1);  
gtk_widget_hide(erreur_ref1);  
gtk_widget_hide(erreur_categ1);
gtk_widget_hide(erreur_conf1);



}


void
on_actualiser_st_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview1_st;
GtkWidget *afiicher_st;
afiicher_st=lookup_widget(button,"afiicher_st");
treeview1_st=lookup_widget(afiicher_st,"treeview1_st");
afficher_st(treeview1_st);


}


void
on_chercher_st_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *cherch;
char ch[20];
GtkWidget *treeview1_st;
GtkWidget *afiicher_st;
afiicher_st=lookup_widget(button,"afiicher_st");

treeview1_st=lookup_widget(afiicher_st,"treeview1_st");
cherch = lookup_widget (button ,"entre_rechercher_st");
strcpy(ch, gtk_entry_get_text(GTK_ENTRY(cherch)));
 chercher_st(treeview1_st,ch);
}


void
on_ajouterpr_st_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ref;
GtkWidget *nom;
GtkWidget *categ;
GtkWidget *quant;
GtkWidget *type;

GtkWidget *poid;
GtkWidget *ajouter_st;


produit p;
int aa,mm,jj;
char a[3];
char b[3];
char c[6];
char y[15]="";
int o=0;
ref = lookup_widget (button ,"entryref_st");
nom = lookup_widget (button ,"entrynom_st");
categ = lookup_widget (button ,"combobox1_categorie");
quant = lookup_widget (button ,"spinbutton1_qt_st");
type = lookup_widget (button ,"radiobutton1_fr");
poid = lookup_widget (button ,"spinbutton1_poid");


GtkWidget *erreur_nom1,*erreur_ref1,*erreur_categ1,*erreur_conf1;
ajouter_st=lookup_widget(button,"ajouter_st");
erreur_nom1=lookup_widget(ajouter_st,"erreur_nom1");
erreur_ref1=lookup_widget(ajouter_st,"erreurref_1");
erreur_categ1=lookup_widget(ajouter_st,"erreur_catg1");
erreur_conf1=lookup_widget(ajouter_st,"erreur_conf1");
gtk_widget_hide(erreur_nom1);  
gtk_widget_hide(erreur_ref1);  
gtk_widget_hide(erreur_categ1);

gtk_widget_hide(erreur_conf1);





GtkWidget *calendar;
calendar=lookup_widget(button,"calendar1_st");
gtk_calendar_get_date (GTK_CALENDAR(calendar),
                       &aa,
                       &mm,
                       &jj);
mm=mm+1;


p.quant=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(quant));
p.poid=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(poid));

strcpy(p.ref, gtk_entry_get_text(GTK_ENTRY(ref)));
strcpy(p.nom, gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(p.categ, gtk_combo_box_get_active_text(GTK_COMBO_BOX(categ)));


sprintf(a,"%d",jj);sprintf(b,"%d",mm);sprintf(c,"%d",aa);
strcat(y,c);strcat(y,"-");strcat(y,b);strcat(y,"-");strcat(y,a);


strcpy(p.date,y);
strcpy(p.type,tyy);

if (strcmp(p.ref,"")==0)
{o=1;
gtk_widget_show(erreur_ref1);
}
else o=0;
 if (strcmp(p.nom,"")==0)
{o=1;
gtk_widget_show(erreur_nom1);
}
else o=0;

 if (x1==0)
{
gtk_widget_show(erreur_conf1);
}
if (strcmp(p.categ,"")==0)
{o=1;
gtk_widget_show(erreur_categ1);
}else o=0;



 if(o==0 && x1==1){
ajouter_produit(p);



gtk_widget_destroy(ajouter_st);
GtkWidget *afiicher_st;
afiicher_st = create_afiicher_st ();
  gtk_widget_show (afiicher_st);
x1=0;


}

}


void
on_anuulerajout_st_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ajouter_st;
ajouter_st=lookup_widget(button,"ajouter_st");
gtk_widget_destroy(ajouter_st);
GtkWidget *afiicher_st;
afiicher_st = create_afiicher_st ();
  gtk_widget_show (afiicher_st);
GtkWidget* resultat_st;

}


void
on_annulersupp_st_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *supprimer_st;
supprimer_st=lookup_widget(button,"supprimer_st");
gtk_widget_destroy(supprimer_st);
GtkWidget *afiicher_st;
afiicher_st=lookup_widget(button,"afiicher_st");
  gtk_widget_show (afiicher_st);



}


void
on_confirmersupp_st_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
 supprimer_st(o.ref);
GtkWidget *supprimer_st;
supprimer_st=lookup_widget(button,"supprimer_st");
gtk_widget_destroy(supprimer_st);
GtkWidget *afiicher_st;

  gtk_widget_show (afiicher_st);

}


void
on_treeview1_st_row_activated          (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
                                    
{GtkTreeIter iter;
	gchar* ref;
	gchar* nom;
	gchar* categ;
	gchar* type;
	gchar* quant;
	gchar* date;
	gchar* poid;
	

	GtkTreeModel *model =gtk_tree_view_get_model(treeview);

	if (gtk_tree_model_get_iter(model, &iter , path))
	{ 
	  gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0 , &ref, 1, &nom,2,&categ,3,&type,4,&quant,5,&date,6,&poid,-1);
	strcpy(o.ref,ref);
	o.quant=atoi(quant); 
	}

}


void
on_supprimer_st_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *afiicher_st;
afiicher_st=lookup_widget(button,"afiicher_st");

GtkWidget *supprimer_st;
supprimer_st = create_supprimer_st ();
  gtk_widget_show (supprimer_st);
}


void
on_annulerM_st_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *modifier_st;
modifier_st=lookup_widget(button,"modifier_st");
gtk_widget_destroy(modifier_st);
GtkWidget *afiicher_st;
afiicher_st = create_afiicher_st ();
  gtk_widget_show (afiicher_st);


}


void
on_modifier1_st_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ref;
GtkWidget *nom;
GtkWidget *categ;
GtkWidget *quant;
GtkWidget *type;

GtkWidget *poid;



produit p;
int aa,mm,jj;
char a[3];
char b[3];
char c[6];
char y[15]="";
int x=0;
GtkWidget *modifier_st;
modifier_st=lookup_widget(button,"modifier_st");
ref = lookup_widget (button ,"Mref_st");
nom = lookup_widget (button ,"Mnom_st");
categ = lookup_widget (button ,"combobox2_st");
quant = lookup_widget (button ,"spinbutton11_st");
type = lookup_widget (button ,"radiobutton11_st");
poid = lookup_widget (button ,"spinbutton22_st");

GtkWidget *erreur_nom2,*erreur_ref2,*erreur_conf2,*erreur_categ1;
erreur_categ1=lookup_widget(modifier_st,"erreur_catg2");
erreur_nom2=lookup_widget(modifier_st,"erreur_nom2");
erreur_ref2=lookup_widget(modifier_st,"erreur_ref2");
erreur_conf2=lookup_widget(modifier_st,"erreur_conf2");

 
gtk_widget_hide(erreur_nom2);  
gtk_widget_hide(erreur_ref2);  
gtk_widget_hide(erreur_conf2);
gtk_widget_hide(erreur_categ1);
GtkWidget *calendar;
calendar=lookup_widget(button,"calendar1_dateM");
gtk_calendar_get_date (GTK_CALENDAR(calendar),
                       &aa,
                       &mm,
                       &jj);
mm=mm+1;


p.quant=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(quant));
p.poid=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(poid));

strcpy(p.ref, gtk_entry_get_text(GTK_ENTRY(ref)));
strcpy(p.nom, gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(p.categ, gtk_combo_box_get_active_text(GTK_COMBO_BOX(categ)));


sprintf(a,"%d",jj);sprintf(b,"%d",mm);sprintf(c,"%d",aa);
strcat(y,c);strcat(y,"-");strcat(y,b);strcat(y,"-");strcat(y,a);


strcpy(p.date,y);
strcpy(p.type,tyy1);
if (strcmp(p.ref,"")==0)
{x=1;
gtk_widget_show(erreur_ref2);
}else x=0;
 if (strcmp(p.nom,"")==0)
{x=1;
gtk_widget_show(erreur_nom2);
}else x=0;
if (strcmp(p.categ,"")==0)
{x=1;
gtk_widget_show(erreur_categ1);
}else x=0;

 if (x2==0)
{
gtk_widget_show(erreur_conf2);
}

 if(x==0 && x2 ==1){
modifier_stt(o.ref,p);

gtk_widget_destroy(modifier_st);
GtkWidget *afiicher_st;
afiicher_st = create_afiicher_st ();
  gtk_widget_show (afiicher_st);
x2=0;
}}


void
on_radiobutton1_fr_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
strcpy(tyy,"froid");
}


void
on_radiobutton2_nr_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
strcpy(tyy,"normal");
}


void
on_radiobutton11_st_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
strcpy(tyy1,"froid");
}


void
on_radiobutton22_st_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
strcpy(tyy1,"normal");
}


void
on_checkbutton1_st_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
x1=1;
}


void
on_checkbutton11_st_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
x2=1;
}


void
on_retire_st_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *afiicher_st;
afiicher_st=lookup_widget(button,"tache2");

GtkWidget *tache2;
tache2 = create_tache2 ();
  gtk_widget_show (tache2);
}


void
on_treeview2_st_row_activated          (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_afficher_tache2_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *spinbutton1_mn;
spinbutton1_mn = lookup_widget (button ,"spinbutton1_mn");
int mn=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton1_mn));
int aa,mm,jj;
char a[3];
char b[3];
char c[6];
char y[15]="";
GtkWidget *calendar;
calendar=lookup_widget(button,"calendar3_st");
gtk_calendar_get_date (GTK_CALENDAR(calendar),
                       &aa,
                       &mm,
                       &jj);
mm=mm+1;

sprintf(a,"%d",jj);sprintf(b,"%d",mm);sprintf(c,"%d",aa);
strcat(y,c);strcat(y,"-");strcat(y,b);strcat(y,"-");strcat(y,a);

GtkWidget *treeview2_st;
GtkWidget *afiicher_st;
afiicher_st=lookup_widget(button,"afiicher_st");
treeview2_st=lookup_widget(afiicher_st,"treeview2_st");
stoq_ep(treeview2_st,y,mn,choix);
}


void
on_confirme_ut_st_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *quant1;
GtkWidget *tache2;
GtkWidget *erreur_qnt;
int x;
int y=0;
int bb=0;
quant1 = lookup_widget (button ,"spinbutton111_st");

tache2=lookup_widget(button,"tache2");

erreur_qnt=lookup_widget(tache2,"erreur_qnt");
y=0;
 
gtk_widget_hide(erreur_qnt);  


x=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(quant1));



bb = ret_qp( o);

if (x >bb)
{y=1;
gtk_widget_show(erreur_qnt);
}
if (x <= bb){
utiliser_stt(o.ref,x);

gtk_widget_destroy(tache2);
GtkWidget *afiicher_st;
afiicher_st = create_afiicher_st ();
  gtk_widget_show (afiicher_st);
}



}


void
on_annuler_ut_st_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *tache2;
tache2=lookup_widget(button,"tache2");
gtk_widget_destroy(tache2);
GtkWidget *afiicher_st;
afiicher_st=lookup_widget(button,"afiicher_st");
  gtk_widget_show (afiicher_st);
}


void
on_Date_expir___toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
choix=1;
}

void
on_date_exx_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
choix=1;
}


void
on_Stock_epuis___toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
choix=0;
}


void
on_button_gestion_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Acceuil_stock;
Acceuil_stock=lookup_widget(button,"Acceuil_stock");
gtk_widget_destroy(Acceuil_stock);
GtkWidget *afiicher_st;
afiicher_st = create_afiicher_st ();
  gtk_widget_show (afiicher_st);
GtkWidget* resultat_st;
}


void
on_button_rupture1_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Acceuil_stock;
Acceuil_stock=lookup_widget(button,"Acceuil_stock");
gtk_widget_destroy(Acceuil_stock);
GtkWidget *tache2;
tache2 = create_tache2 ();
  gtk_widget_show (tache2);
}


void
on_radiobutton222_nr_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
strcpy(tyy,"normal");
}


void
on_radiobutton2222_nr_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
strcpy(tyy1,"normal");
}




// capteurs



#include "fonction.c"

int t=0;
int tp=0;
void
on_button10_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *acceuil;
acceuil=lookup_widget(button,"acceuil");
gtk_widget_destroy(acceuil);
GtkWidget *ajouter;
ajouter = create_ajouter ();
  gtk_widget_show (ajouter);
}


void
on_button11_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *acceuil;
acceuil=lookup_widget(objet,"acceuil");
gtk_widget_destroy(acceuil);
GtkWidget *mod;
mod = create_modifier ();
  gtk_widget_show (mod);
}


void
on_button12_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkTreeModel *model;
GtkTreeSelection *selection;
GtkTreeIter iter;
GtkWidget *p;
GtkWidget *label;
gchar *id;
p=lookup_widget(objet,"treeview1");
selection=gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
if(gtk_tree_selection_get_selected(selection,&model,&iter))
{gtk_tree_model_get(model,&iter,0,&id,-1);
gtk_list_store_remove(GTK_LIST_STORE(model),&iter);}
supp_id(id);
afficher(p);
}





void
on_button14c_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *des;
des=lookup_widget(objet,"acceuil");
gtk_widget_destroy(des);
GtkWidget *aff;
aff= create_Home ();
  gtk_widget_show (aff);
}


void
on_button3_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{capteur c;
                             
GtkWidget* input1;
GtkWidget *radio1,*radio2,*radio3;
GtkWidget*radio4;
GtkWidget* spin1,*spin2, *spin3,*spin4,*spin5;
GtkWidget* combo1;
GtkWidget* combo2;


input1 = lookup_widget(objet,"stentry4");
strcpy(c.id,gtk_entry_get_text(GTK_ENTRY(input1)));

radio1 = lookup_widget(objet,"radiobutton1");
radio2 = lookup_widget(objet,"radiobutton2");
radio3 = lookup_widget(objet,"radiobutton3");
radio4 = lookup_widget(objet,"radiobutton4");
if(t==0)
strcpy(c.type,"temperature");
else if(t==1)
strcpy(c.type,"debit");
else if(t==2)
strcpy(c.type,"fumee");
else
strcpy(c.type,"mouvement");

spin1=lookup_widget(objet,"spinbutton1ccc");
spin2=lookup_widget(objet,"spinbutton2ccc");
spin3=lookup_widget(objet,"spinbutton3ccc");
spin4=lookup_widget(objet,"spinbutton9cc");
spin5=lookup_widget(objet,"spinbutton10cc");

c.captj=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin1));
c.captm=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin2));
c.capta=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin3));

c.vmax=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin5));
c.vmin=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin4));

combo1=lookup_widget(objet,"stcombobox1");
combo2=lookup_widget(objet,"stcombobox2");
strcpy(c.zone,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combo1)));
strcpy(c.etage,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combo2)));
if(c.vmin<10 ||c.vmax>30)
{
add(c);
add_def(c);
}
else 
add(c);
}



void
on_button5_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *add;
add=lookup_widget(objet,"ajouter");
gtk_widget_destroy(add);
GtkWidget *aff;
aff = create_acceuil ();
  gtk_widget_show (aff);
}


void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
t=0;
}


void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
t=1;
}


void
on_radiobutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
t=2;
}


void
on_radiobutton4_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
t=3;
}


void
on_button6c_clicked                     (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *id,*type1,*type2,*type3,*type4,*type,*vmax,*vmin,*zone,*etage,*rech,*captj,*captm,*capta;

capteur p;
char reche[200];

id=lookup_widget(objet,"entry6c");


captj=lookup_widget(objet,"spinbutton4c");
captm=lookup_widget(objet,"spinbutton5c");
capta=lookup_widget(objet,"spinbutton6c");

vmax=lookup_widget(objet,"spinbutton7c");
vmin=lookup_widget(objet,"spinbutton8c");

zone=lookup_widget(objet,"comboboxentry7c");
etage=lookup_widget(objet,"comboboxentry8c");

rech=lookup_widget(objet,"entrychercher");


strcpy(reche,gtk_entry_get_text(GTK_ENTRY(rech)));

strcpy(p.id,gtk_entry_get_text(GTK_ENTRY(id)));

p.captj=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(captj));
p.captm=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(captm));
p.capta=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(capta));

p.vmax=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(vmax));
p.vmin=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(vmin));




if(tp==0)
{
strcpy(p.type,"temperatur");
}
else if(tp==1)
{
strcpy(p.type,"debit");
}
else if(tp==2)
{
strcpy(p.type,"fumee");
}
else if(tp==3)
{
strcpy(p.type,"mouvement");
}

zone=lookup_widget(objet,"comboboxentry7c");
strcpy(p.zone,gtk_combo_box_get_active_text(GTK_COMBO_BOX(zone)));

etage=lookup_widget(objet,"comboboxentry8c");
strcpy(p.etage,gtk_combo_box_get_active_text(GTK_COMBO_BOX(etage)));


supp_id(reche);
add(p);

}



void
on_button7_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *mod;
mod=lookup_widget(objet,"modifier");
gtk_widget_destroy(mod);
GtkWidget *acceuil;
acceuil= create_acceuil ();
  gtk_widget_show (acceuil);
}




void
on_button16_hany_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *tree;
GtkWidget *aff;
aff=lookup_widget(objet,"acceuil");
tree=lookup_widget(aff,"treeview1");
afficher(tree);
}


void
on_radiobutton5_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
tp=0;
}


void
on_radiobutton6_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
tp=1;
}


void
on_radiobutton7_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
tp=2;
}


void
on_radiobutton8_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
tp=3;
}


void
on_button16chercher_clicked            (GtkWidget      *objet,
                                        gpointer         user_data)
{

GtkWidget *id,*type1,*type2,*type3,*type4,*type,*vmax,*vmin,*zone,*etage,*rech,*captj,*captm,*capta;
capteur c;
capteur p;
char nmch[30];
char reche[200];
int i=0;
int j=0;
char matrice[6][30]={"1","2","3","4","5","6","7","8","9"};
id=lookup_widget(objet,"entry6");
type1=lookup_widget(objet,"radiobutton5");
type2=lookup_widget(objet,"radiobutton6");
type3=lookup_widget(objet,"radiobutton7");
type4=lookup_widget(objet,"radiobutton8");

captj=lookup_widget(objet,"spinbutton4");
captm=lookup_widget(objet,"spinbutton5");
capta=lookup_widget(objet,"spinbutton6");

vmax=lookup_widget(objet,"spinbutton7");
vmin=lookup_widget(objet,"spinbutton8");

zone=lookup_widget(objet,"comboboxentry7");
etage=lookup_widget(objet,"comboboxentry8");


rech=lookup_widget(objet,"entrychercher");


strcpy(reche,gtk_entry_get_text(GTK_ENTRY(rech)));
//printf("hello world");
FILE *f=NULL;
int v=1;
f=fopen("capt.txt","r");
while(fscanf(f,"%s %s %d %d %s %s %d %d %d \n",c.id,c.type,&c.vmax,&c.vmin,c.zone,c.etage,&c.captj,&c.captm,&c.captj)!=EOF)
        {
	if( strcmp(reche,c.id)==0){
			
			v=0;
			strcpy(p.id,c.id);
			strcpy(p.type,c.type);
			strcpy(p.zone,c.zone);
			strcpy(p.etage,c.etage);
			p.vmax=c.vmax;
			p.vmin=c.vmin;
			p.captj=c.captj;
			p.captm=c.captm;
			p.capta=c.capta;
			
			
			
	}
	else 
		{//gtk_widget_show (message);
		//gtk_label_set_text(GTK_LABEL(message),"ce cin n'existe pas");
		gtk_entry_set_text (id,"");
		gtk_entry_set_text (type,"");
		gtk_entry_set_text (captj,"");
		gtk_entry_set_text (captm,"");
		gtk_entry_set_text (capta,"");
		gtk_entry_set_text (vmax,"");
		gtk_entry_set_text (vmin,"");
		gtk_entry_set_text (zone,"");
		gtk_entry_set_text (etage,"");

}
}
if(v==0)
{
	gtk_entry_set_text (id,p.id);
	
	if(strcmp(p.type,"temperature")==0)
	{
	gtk_toggle_button_set_active(GTK_RADIO_BUTTON (type1),TRUE);
	}
	else if(strcmp(p.type,"debit")==0)
	{
	gtk_toggle_button_set_active(GTK_RADIO_BUTTON (type2),TRUE);
	}
	else if(strcmp(p.type,"fumee")==0)
	{
	gtk_toggle_button_set_active(GTK_RADIO_BUTTON (type3),TRUE);
	}
	else if(strcmp(p.type,"mouvement")==0)
	{
	gtk_toggle_button_set_active(GTK_RADIO_BUTTON (type4),TRUE);
	}
	i=0;
	while(i<10 && strcmp(matrice[i],p.zone)!=0)
	{
	i++;}
	gtk_combo_box_set_active(GTK_COMBO_BOX(zone),i);
	j=0;
	while(j<10 && strcmp(matrice[j],p.etage)!=0)
	{
	j++;}
	gtk_combo_box_set_active(GTK_COMBO_BOX(etage),j);
	
	gtk_spin_button_set_value(vmax,p.vmax);
	gtk_spin_button_set_value(vmin,p.vmin);
	gtk_spin_button_set_value(captj,p.captj);
	gtk_spin_button_set_value(captm,p.captm);
	gtk_spin_button_set_value(capta,p.capta);
	
}

}


void
on_def_aff_clicked                     (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *tree;
GtkWidget *aff;
aff=lookup_widget(objet,"liste_des_capteurs");
tree=lookup_widget(aff,"def_treeview");
afficherdef(tree);
}


void
on_button_capteur_def_clicked          (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *des;
des=lookup_widget(objet,"Home");
gtk_widget_destroy(des);
GtkWidget *aff;
aff= create_liste_des_capteurs ();
  gtk_widget_show (aff);
}


void
on_buttonhome_exit_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *home_in;
home_in=lookup_widget(objet,"Home");
gtk_widget_destroy(home_in);
GtkWidget *afiicher_st;
afiicher_st=lookup_widget(objet,"afiicher_st");
afiicher_st=create_home_in();
  gtk_widget_show (afiicher_st);
}


void
on_buttonhome_acceuil_clicked          (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *des;
des=lookup_widget(objet,"Home");
gtk_widget_destroy(des);
GtkWidget *aff;
aff= create_acceuil ();
  gtk_widget_show (aff);
}


void
on_button15_retour_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *des;
des=lookup_widget(objet,"liste_des_capteurs");
gtk_widget_destroy(des);
GtkWidget *aff;
aff= create_Home ();
  gtk_widget_show (aff);
}








void
on_radiobutton9n_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
t=3;
}


void
on_radiobutton8n_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
tp=2;
}


void
on_radiobutton14_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
tp=1;
}


void
on_radiobutton12n_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
tp=2;
}


void
on_radiobutton11n_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
tp=1;
}


void
on_radiobutton19n_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
tp=3;
}


void
on_radiobutton16n_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
t=2;
}


void
on_radiobutton15n_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
t=1;
}

// menu



#include "fonction1.c"
char id111[9];
int typeh =0 ;
int sele =0 ;

void
on_afficher_hsm_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{


menu p;

GtkWidget *id,*date,*comboboxentry2,*entry4,*entry9;

id=lookup_widget(button,"entry14_hsm");
date=lookup_widget(button,"entry15_hsm");
comboboxentry2=lookup_widget(button,"comboboxentry2");

strcpy(p.repas,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxentry2)));
strcpy(id111,gtk_entry_get_text(GTK_ENTRY(id)));
strcpy(p.date,gtk_entry_get_text(GTK_ENTRY(date)));
if (typeh==1) strcpy(p.type,"autres");
else strcpy(p.type,"vegetarien");

if (sele==1) strcpy(p.desert,"avec_desert");
else strcpy(p.desert,"sans_desert");
modifiermenu(id111,p);

GtkWidget *modifiermenu;
modifiermenu=lookup_widget(button,"modifiermenu");
gtk_widget_destroy(modifiermenu);
GtkWidget *affichermenu;
affichermenu = create_affichermenu ();
gtk_widget_show (affichermenu);
}


void
on_radiobutton2_hsm_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
typeh=1;
}


void
on_choix1_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
sele=1;
}


void
on_choix2_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
sele =0 ;
}


void
on_ajout_hsm_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
menu m;

GtkWidget *input1,*input2,*comboboxentry1_hsm;
GtkWidget *ajout_hsm;
ajout_hsm=lookup_widget(button,"ajout_hsm");

GtkComboBoxEntry *comboboxentry1;
GtkRadioButton *radiobutton1_hsm , *radiobutton2_hsm;
GtkCheckButton *choix1 , *choix2 ;
input1=lookup_widget(button,"entry4h");
input2=lookup_widget(button,"entry9h");

comboboxentry1_hsm=lookup_widget(button,"comboboxentry1h");
strcpy(m.id,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(m.date,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(m.repas,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxentry1_hsm)));
if (typeh==1) strcpy(m.type,"autres");
else strcpy(m.type,"vegetarien");

if (sele==1) strcpy(m.desert,"avec_desert");
else strcpy(m.desert,"sans_desert");

ajoutermenu(m.id,m.date,m.type,m.desert,m.repas);
GtkWidget *des ,*windowmenu_hsm;
des=lookup_widget(button,"menu_hsm");
gtk_widget_destroy(des);
}


void
on_vegetarien_toggled                  (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
typeh =0 ;
}


void
on_chercher_hsm_clicked                (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *affichermenu;
affichermenu=lookup_widget(objet,"affichermenu");
gtk_widget_destroy(affichermenu);
GtkWidget *bienvenue ;
bienvenue=create_bienvenue();
gtk_widget_show(bienvenue);
}


void
on_modifier_hsm_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *affichermenu;
affichermenu=lookup_widget(button,"affichermenu");
gtk_widget_destroy(affichermenu);
menu p;
char id1[30];
char date1[30];
char type1[30];
char desert1[30];
char repas1[30];
FILE *f;

f=fopen("menu.txt","r");
GtkWidget *modifier_menu_hsm;
  modifier_menu_hsm = create_modifier_menu_hsm ();
  gtk_widget_show (modifier_menu_hsm);
GtkWidget *entry14_hsm;
entry14_hsm = lookup_widget (modifier_menu_hsm ,"entry14_hsm");
GtkWidget *entry15_hsm;
entry15_hsm = lookup_widget (modifier_menu_hsm ,"entry15_hsm");

GtkRadioButton *radiobutton22_hsm , *radiobutton200_hsm;
GtkCheckButton *checkbutton10_hsm , *checkbutton200_hsm ;

if (typeh==1) strcpy(p.type,"autres");
else strcpy(p.type,"vegetarien");

if (sele==1) strcpy(p.desert,"avec_desert");
else strcpy(p.desert,"sans_desert");

GtkWidget *comboboxentry2;
comboboxentry2 = lookup_widget (modifier_menu_hsm ,"comboboxentry2");

while(fscanf(f, "%s %s %s %s %s \n",id1,date1,type1,desert1,repas1)!=EOF){
 if (strcmp(id111,id1)==0){
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(modifier_menu_hsm,"entry14_hsm")),id1);
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(modifier_menu_hsm,"entry15_hsm")),date1);
                
		gtk_entry_set_text(GTK_ENTRY(lookup_widget(modifier_menu_hsm,"comboboxentry2")),repas1);

}}
}


void
on_ajouter_hsm_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowajoutermenu ,*windowbienvenue;
windowajoutermenu=create_ajoutermenu();
gtk_widget_show(windowajoutermenu);

GtkWidget *des;
des=lookup_widget(button,"affichermenu");
gtk_widget_destroy(des);
}


void
on_Menu_hsm_clicked                    (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowaffichermenu ;
windowaffichermenu=create_affichermenu();
gtk_widget_show(windowaffichermenu);
GtkWidget *des ;
des=lookup_widget(objet,"bienvenue");
gtk_widget_destroy(des);
}


void
on_Meilleur_hsm_clicked                (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowmeilleur_menu_hsm ;
windowmeilleur_menu_hsm=create_meilleur_menu_hsm();
gtk_widget_show(windowmeilleur_menu_hsm);
GtkWidget *des , *windowbienvenue;
des=lookup_widget(objet,"bienvenue");
gtk_widget_destroy(des);
}


void
on_statistique_plat_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
char a3[10];
char b3[10];
char c3[10];
char y3[40]="le jour : ";


char a1[10];
char b1[10];
char c1[10];
char y1[40]="le jour : ";

char a2[10];
char b2[10];
char c2[10];
char y2[40]="le jour : ";

char num[3];

GtkWidget *spinbutton1_semaine;

spinbutton1_semaine = lookup_widget(button,"spinbutton100");

int z=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton1_semaine));

sprintf(num,"%d",z);

GtkWidget *num_semaine;
num_semaine = lookup_widget(button,"num_semaine");
gtk_label_set_text(GTK_LABEL(num_semaine),num);

dechet pl1 = plat1(z);
dechet pl2 = plat2(z);
dechet pl3 = plat3(z);

sprintf(a1,"%d",pl1.x1);sprintf(b1,"%d",pl1.x2);sprintf(c1,"%f",pl1.x3);
strcat(y1,a1);strcat(y1," qui contient ");strcat(y1,c1);(y1," de dechets");strcat(y1," %");

sprintf(a2,"%d",pl2.x1);sprintf(b2,"%d",pl2.x2);sprintf(c2,"%f",pl2.x3);
strcat(y2,a2);strcat(y2," qui contient ");strcat(y2,c2);(y2," de dechets");strcat(y2," %");

sprintf(a3,"%d",pl3.x1);sprintf(b3,"%d",pl3.x2);sprintf(c3,"%f",pl3.x3);
strcat(y3,a3);strcat(y3," qui contient ");strcat(y3,c3);(y3," de dechets");strcat(y3," %");


GtkWidget *plat1;
plat1 = lookup_widget(button,"plat1");
gtk_label_set_text(GTK_LABEL(plat1),y1);
GtkWidget *plat2;
plat2 = lookup_widget(button,"plat2");
gtk_label_set_text(GTK_LABEL(plat2),y2);
GtkWidget *plat3;
plat3 = lookup_widget(button,"plat3");
gtk_label_set_text(GTK_LABEL(plat3),y3);
}




void
on_actualiser_user_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview1;
GtkWidget *affichermen;
affichermen=lookup_widget(button,"affichermenu");
treeview1=lookup_widget(affichermen,"treeview1h");
affichermenu(treeview1);
}


void
on_retour_meilleur_clicked             (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowbienvenue ;
GtkWidget *des ;
des=lookup_widget(objet,"meilleur_menu_hsm");
gtk_widget_destroy(des);
windowbienvenue=create_bienvenue();
gtk_widget_show(windowbienvenue);


}




void
on_retour_modifier_hsm_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *mod;
mod=lookup_widget(button,"modifier_menu_hsm");
gtk_widget_destroy(mod);
GtkWidget *acceuil;
acceuil= create_affichermenu ();
  gtk_widget_show (acceuil);
}


void
on_retour_ajouter_hsm_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *mod;
mod=lookup_widget(button,"ajoutermenu");
gtk_widget_destroy(mod);
GtkWidget *acceuil;
acceuil= create_affichermenu ();
  gtk_widget_show (acceuil);
}




void
on_treeview1h_row_activated            (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar* id;
gchar* date;
gchar* type;
gchar* desert;
gchar* repas;
menu p;

GtkTreeModel *model = gtk_tree_view_get_model(treeview);

if(gtk_tree_model_get_iter(model , &iter , path)){
gtk_tree_model_get (GTK_LIST_STORE(model),&iter,0,&id,1,&date,2,&type,3,&desert,4,&repas,5,-1);}

strcpy(p.id,id);
strcpy(p.date,date);
strcpy(p.type,type);
strcpy(p.desert,desert);
strcpy(p.repas,repas);
supprimermenu(id);
affichermenu(treeview);
}


void
on_autres_hsm_toggled                  (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
typeh=1;
}






void
on_dec_homes_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *home_in;
home_in=lookup_widget(button,"home_in");
gtk_widget_destroy(home_in);
GtkWidget *afiicher_st;
afiicher_st=lookup_widget(button,"afiicher_st");
afiicher_st=create_SignIN();
  gtk_widget_show (afiicher_st);
}


void
on_go_stg_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *home_in;
home_in=lookup_widget(button,"home_in");
gtk_widget_destroy(home_in);
GtkWidget *afiicher_st;
afiicher_st=lookup_widget(button,"afiicher_st");
afiicher_st=create_Acceuil_stock();
  gtk_widget_show (afiicher_st);
}


void
on_go_capptg_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *home_in;
home_in=lookup_widget(button,"home_in");
gtk_widget_destroy(home_in);
GtkWidget *afiicher_st;
afiicher_st=lookup_widget(button,"afiicher_st");
afiicher_st=create_Home();
  gtk_widget_show (afiicher_st);
}


void
on_go_mmenug_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *home_in;
home_in=lookup_widget(button,"home_in");
gtk_widget_destroy(home_in);
GtkWidget *afiicher_st;
afiicher_st=lookup_widget(button,"afiicher_st");
afiicher_st=create_bienvenue();
  gtk_widget_show (afiicher_st);
}


void
on_go_etudg_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *home_in,*treeview1;
home_in=lookup_widget(button,"home_in");
gtk_widget_destroy(home_in);
GtkWidget *afiicher_st;
afiicher_st=lookup_widget(button,"afiicher_st");
afiicher_st=create_accuile_et();
  gtk_widget_show (afiicher_st);
treeview1 = lookup_widget(afiicher_st,"treeview1");
afficherListe("user.txt",treeview1);
}


void
on_go_adming_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *home_in,*treeview1;
home_in=lookup_widget(button,"home_in");
gtk_widget_destroy(home_in);
GtkWidget *afiicher_st;
afiicher_st=lookup_widget(button,"afiicher_st");
afiicher_st=create_AdminDashboard();
  gtk_widget_show (afiicher_st);
treeview1 = lookup_widget(afiicher_st,"treeview1");
afficherListe("user.txt",treeview1);

}


void
on_retour_st_tohome_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *home_in;
home_in=lookup_widget(button,"afiicher_st");
gtk_widget_destroy(home_in);
GtkWidget *afiicher_st;
afiicher_st=lookup_widget(button,"afiicher_st");
afiicher_st=create_Acceuil_stock();
  gtk_widget_show (afiicher_st);
}


void
on_button3_quitterstock_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *home_in;
home_in=lookup_widget(button,"Acceuil_stock");
gtk_widget_destroy(home_in);
GtkWidget *afiicher_st;
afiicher_st=lookup_widget(button,"afiicher_st");
afiicher_st=create_home_in();
  gtk_widget_show (afiicher_st);
}


void
on_rtt_mn_hom_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *home_in;
home_in=lookup_widget(button,"bienvenue");
gtk_widget_destroy(home_in);
GtkWidget *afiicher_st;
afiicher_st=lookup_widget(button,"afiicher_st");
afiicher_st=create_home_in();
  gtk_widget_show (afiicher_st);
}




// etudiants


#include "etudiant.c"

Etudiant oo;
char sexe1[10]="Homme";
char zz[10]="";
int conf1=0;



void
on_go_ajouter_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *afficher_et;
afficher_et=lookup_widget(button,"afficher_et");
gtk_widget_destroy(afficher_et);
GtkWidget *ajouter_et;
ajouter_et = create_ajouter_et ();
  gtk_widget_show (ajouter_et);
}


void
on_go_supprimer_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *afficher_et;
afficher_et=lookup_widget(button,"afficher_et");

GtkWidget *supprimer_et;
supprimer_et = create_supprimer_et ();
  gtk_widget_show (supprimer_et);
}


void
on_go_modifier_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *afficher_et;
afficher_et=lookup_widget(button,"afficher_et");
gtk_widget_destroy(afficher_et);

 char nom[40];
    char prenom[40];
    char sexe[40];
    char date_naissance[40];
    char cin[40];
    char gsm[40];
 char niveaux[40];
    char id[10];
    char username[40];
    char password[40];
    char num_etage[40];
	char num_ch[40];
	char type_ch[40];
FILE *f;

f=fopen("etudiant.txt","r");
GtkWidget *Modifier_et;
  Modifier_et = create_Modifier_et ();
  gtk_widget_show (Modifier_et);

GtkWidget *nom_et1;
nom_et1 = lookup_widget (Modifier_et ,"nom_et1");
GtkWidget *prenom_et1;
prenom_et1 = lookup_widget (Modifier_et ,"prenom_et1");
GtkWidget *cin_et1;
cin_et1 = lookup_widget (Modifier_et ,"cin_et1");
GtkWidget *tel_et1;
tel_et1 = lookup_widget (Modifier_et ,"tel_et1");
GtkWidget *username_et1;
username_et1 = lookup_widget (Modifier_et ,"username_et1");
GtkWidget *password_et1;
password_et1 = lookup_widget (Modifier_et ,"password_et1");

while(fscanf(f, "%s %s %s %s %s %s %s %s %s %s %s %s %s \n",id,nom,prenom,cin,sexe,date_naissance,gsm,username,password,num_etage,num_ch,type_ch,niveaux)!=EOF){
 if (strcmp(oo.id,id)==0){
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(Modifier_et,"nom_et1")),nom);
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(Modifier_et,"prenom_et1")),prenom);
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(Modifier_et,"cin_et1")),cin);
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(Modifier_et,"tel_et1")),gsm);
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(Modifier_et,"username_et1")),username);
		gtk_entry_set_text(GTK_ENTRY(lookup_widget(Modifier_et,"password_et1")),password);

}}
}


void
on_actualiser_et_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview1_et;
GtkWidget *afficher_et;
afficher_et=lookup_widget(button,"afficher_et");
treeview1_et=lookup_widget(afficher_et,"treeview1_et");


afficher_ett(treeview1_et);
}






void
on_deconn_user_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *afficher_et;
afficher_et=lookup_widget(button,"afficher_et");
gtk_widget_destroy(afficher_et);
GtkWidget *window1;

  gtk_widget_show (window1);
}


void
on_treeview1_et_row_activated          (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
	gchar* id;
	gchar* nom;
	gchar* prenom;
	gchar* cin;
	gchar* sexe;
	gchar* dns;
	gchar* gsm;
	gchar* niv;
	gchar* username;
	gchar* password;
	gchar* etage;
	gchar* chambre;
	gchar* type;
	

	GtkTreeModel *model =gtk_tree_view_get_model(treeview);

	if (gtk_tree_model_get_iter(model, &iter , path))
	{ 
	  gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0 , &id, 1, &nom,2,&prenom,3,&cin,4,&sexe,5,&dns,6,&gsm,7,&niv,8,&username,9,&password,10,&etage,11,&chambre,12,&type,-1);
	strcpy(oo.id,id);strcpy(zz,id);
	
	}
}


void
on_chercher_et_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *cherch;
char ch[20];
GtkWidget *treeview1_user;
GtkWidget *afficher_et;
afficher_et=lookup_widget(button,"afficher_et");

treeview1_user=lookup_widget(afficher_et,"treeview1_et");
cherch = lookup_widget (button ,"entry1_chercher");
strcpy(ch, gtk_entry_get_text(GTK_ENTRY(cherch)));
 rechercher_ett(treeview1_user,ch);
}


void
on_ajouter_et_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
int aa,mm,jj;
char a[3];
char b[3];
char c[6];
char y[15]="";

int x=0;
Etudiant p;
GtkWidget *calendar1_et;
GtkWidget *id_et,*nom_et,*prenom_et,*cin_et,*tel_et,*comboboxentry1_et,*comboboxentry2_et;
GtkWidget *spinbutton1_et;
GtkWidget *username_et,*password_et,*cin_user,*num_etage,*num_ch;

calendar1_et=lookup_widget(button,"calendar1_et");

nom_et=lookup_widget(button,"entre_nomet");
prenom_et=lookup_widget(button,"entre_prenom_et");
cin_et=lookup_widget(button,"entre_cinet");
tel_et=lookup_widget(button,"entre_telet");
password_et=lookup_widget(button,"entre_passwordet");
username_et=lookup_widget(button,"entre_usernameet");


comboboxentry1_et=lookup_widget(button,"comboboxentry1_et");
comboboxentry2_et=lookup_widget(button,"comboboxentry2_et");
id_et=lookup_widget(button,"entre_id");
num_etage=lookup_widget(button,"spinbutton2_et");
num_ch=lookup_widget(button,"spinbutton3_et");




GtkWidget *e_id;
e_id = lookup_widget (button ,"e_id");
GtkWidget *e_nom;
e_nom = lookup_widget (button ,"e_nom");
GtkWidget *e_prenom;
e_prenom = lookup_widget (button ,"e_prenom");
GtkWidget *e_cin;
e_cin = lookup_widget (button ,"e_cin");
GtkWidget *e_num;
e_num = lookup_widget (button ,"e_num");
GtkWidget *e_username;
e_username = lookup_widget (button ,"e_username");
GtkWidget *e_password;
e_password = lookup_widget (button ,"e_password");
GtkWidget *e_niveaux;
e_niveaux = lookup_widget (button ,"e_niveaux");
GtkWidget *e_typeet;
e_typeet = lookup_widget (button ,"e_typeet");
GtkWidget *e_confet;
e_confet = lookup_widget (button ,"e_confet");


int bbb=0;
gtk_calendar_get_date (GTK_CALENDAR(calendar1_et),
                       &aa,
                       &mm,
                       &jj);

mm=mm+1;

sprintf(a,"%d",jj);sprintf(b,"%d",mm);sprintf(c,"%d",aa);
strcat(y,a);strcat(y,"-");strcat(y,b);strcat(y,"-");strcat(y,c);


p.num_etage=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(num_etage));
p.num_ch=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(num_ch));

strcpy(p.id,gtk_entry_get_text(GTK_ENTRY(id_et)));
strcpy(p.nom,gtk_entry_get_text(GTK_ENTRY(nom_et)));
strcpy(p.prenom,gtk_entry_get_text(GTK_ENTRY(prenom_et)));
strcpy(p.cin,gtk_entry_get_text(GTK_ENTRY(cin_et)));
strcpy(p.gsm,gtk_entry_get_text(GTK_ENTRY(tel_et)));
strcpy(p.username,gtk_entry_get_text(GTK_ENTRY(username_et)));
strcpy(p.password,gtk_entry_get_text(GTK_ENTRY(password_et)));



strcpy(p.date_naissance,y);
strcpy(p.niveaux,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxentry1_et)));
strcpy(p.type_ch,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxentry2_et)));

strcpy(p.sexe,sexe1);

if (strcmp(p.id,"")==0)
{x=1;
gtk_widget_show(e_id);
}
else {x=0;
gtk_widget_hide(e_id);
}
if (strcmp(p.nom,"")==0)
{x=1;
gtk_widget_show(e_nom);
}
else {x=0;
gtk_widget_hide(e_nom);
}
if (strcmp(p.prenom,"")==0)
{x=1;
gtk_widget_show(e_prenom);
}
else {x=0;
gtk_widget_hide(e_prenom);
}
if (strcmp(p.cin,"")==0)
{x=1;
gtk_widget_show(e_cin);
}
else {x=0;
gtk_widget_hide(e_cin);
}
if (strcmp(p.gsm,"")==0)
{x=1;
gtk_widget_show(e_num);
}
else {x=0;
gtk_widget_hide(e_num);
}
if (strcmp(p.username,"")==0)
{x=1;
gtk_widget_show(e_username);
}
else {x=0;
gtk_widget_hide(e_username);
}
if (strcmp(p.password,"")==0)
{x=1;
gtk_widget_show(e_password);
}
else {x=0;
gtk_widget_hide(e_password);
}
if (strcmp(p.niveaux,"")==0)
{x=1;
gtk_widget_show(e_niveaux);
}
else {x=0;
gtk_widget_hide(e_niveaux);
}
if (strcmp(p.type_ch,"")==0)
{x=1;
gtk_widget_show(e_typeet);
}
else {x=0;
gtk_widget_hide(e_typeet);
}
if (conf1==0)
{x=1;
gtk_widget_show(e_confet);
}
else {
gtk_widget_hide(e_confet);
}


if(x==0){
ajouter_et(p);
GtkWidget *ajouter_et;
ajouter_et=lookup_widget(button,"ajouter_et");
gtk_widget_destroy(ajouter_et);
GtkWidget *afficher_et;
afficher_et = create_afficher_et ();
  gtk_widget_show (afficher_et);
}}




void
on_modifier_et_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{


Etudiant p;


GtkWidget *nom_et1;
nom_et1 = lookup_widget (button ,"nom_et1");
GtkWidget *prenom_et1;
prenom_et1 = lookup_widget (button ,"prenom_et1");
GtkWidget *cin_et1;
cin_et1 = lookup_widget (button ,"cin_et1");
GtkWidget *tel_et1;
tel_et1 = lookup_widget (button ,"tel_et1");
GtkWidget *username_et1;
username_et1 = lookup_widget (button ,"username_et1");
GtkWidget *password_et1;
password_et1 = lookup_widget (button ,"password_et1");





GtkWidget *e_nom;
e_nom = lookup_widget (button ,"e_nom1");
GtkWidget *e_prenom;
e_prenom = lookup_widget (button ,"e_prenom1");
GtkWidget *e_cin;
e_cin = lookup_widget (button ,"e_cin1");
GtkWidget *e_num;
e_num = lookup_widget (button ,"e_tel1");
GtkWidget *e_username;
e_username = lookup_widget (button ,"e_username1");
GtkWidget *e_password;
e_password = lookup_widget (button ,"e_password1");




int x=0;






strcpy(p.nom,gtk_entry_get_text(GTK_ENTRY(nom_et1)));
strcpy(p.prenom,gtk_entry_get_text(GTK_ENTRY(prenom_et1)));
strcpy(p.cin,gtk_entry_get_text(GTK_ENTRY(cin_et1)));
strcpy(p.gsm,gtk_entry_get_text(GTK_ENTRY(tel_et1)));
strcpy(p.username,gtk_entry_get_text(GTK_ENTRY(username_et1)));
strcpy(p.password,gtk_entry_get_text(GTK_ENTRY(password_et1)));
if (strcmp(p.nom,"")==0)
{x=1;
gtk_widget_show(e_nom);
}
else {x=0;
gtk_widget_hide(e_nom);
}
if (strcmp(p.prenom,"")==0)
{x=1;
gtk_widget_show(e_prenom);
}
else {x=0;
gtk_widget_hide(e_prenom);
}
if (strcmp(p.cin,"")==0)
{x=1;
gtk_widget_show(e_cin);
}
else {x=0;
gtk_widget_hide(e_cin);
}
if (strcmp(p.gsm,"")==0)
{x=1;
gtk_widget_show(e_num);
}
else {x=0;
gtk_widget_hide(e_num);
}
if (strcmp(p.username,"")==0)
{x=1;
gtk_widget_show(e_username);
}
else {x=0;
gtk_widget_hide(e_username);
}
if (strcmp(p.password,"")==0)
{x=1;
gtk_widget_show(e_password);
}
else {x=0;
gtk_widget_hide(e_password);
}


if (x==0){

 modifier_ett(oo.id,p);
GtkWidget *Modifier_et;
Modifier_et=lookup_widget(button,"Modifier_et");
gtk_widget_destroy(Modifier_et);
GtkWidget *afficher_et;
afficher_et = create_afficher_et ();
  gtk_widget_show (afficher_et);

}}


void
on_retour_ajouteret_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ajouter_et;
ajouter_et=lookup_widget(button,"ajouter_et");
gtk_widget_destroy(ajouter_et);
GtkWidget *afficher_et;
afficher_et = create_afficher_et ();
  gtk_widget_show (afficher_et);
}


void
on_retour_modifier_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Modifier_et;
Modifier_et=lookup_widget(button,"Modifier_et");
gtk_widget_destroy(Modifier_et);
GtkWidget *afficher_et;
afficher_et = create_afficher_et ();
  gtk_widget_show (afficher_et);
}


void
on_annuler_supp_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *supprimer_et;
supprimer_et=lookup_widget(button,"supprimer_et");
gtk_widget_destroy(supprimer_et);
GtkWidget *afficher_et;

  gtk_widget_show (afficher_et);
}


void
on_conf_supp_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
supprimer_ett(oo.id);
GtkWidget *supprimer_et;
supprimer_et=lookup_widget(button,"supprimer_et");
gtk_widget_destroy(supprimer_et);
GtkWidget *afficher_et;

  gtk_widget_show (afficher_et);
}


void
on_radiobutton1_et_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
strcpy(sexe1,"Homme");
}


void
on_radiobutton2_et_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
strcpy(sexe1,"Femme");
}


void
on_checkbutton1_et_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
conf1=1;
}








void
on_calculer2222_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
char nnn[20];
char a[20];
int s;
GtkWidget *comboboxentry3_et;
comboboxentry3_et=lookup_widget(button,"comboboxentry4_et");

GtkWidget *nbr_ettt;
nbr_ettt=lookup_widget(button,"nbr_ettt1");

strcpy(nnn,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxentry3_et)));
s = stat(nnn);
sprintf(a,"%d",s);
gtk_label_set_text(GTK_LABEL(nbr_ettt),a);
}


void
on_Go_afficger_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *accuile_et;
accuile_et=lookup_widget(button,"accuile_et");
gtk_widget_destroy(accuile_et);
GtkWidget *afficher_et;
afficher_et = create_afficher_et ();
  gtk_widget_show (afficher_et);
}


void
on_go_tach22_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *tach2;
tach2=lookup_widget(button,"accuile_et");
gtk_widget_destroy(tach2);
GtkWidget *afficher_et;
afficher_et = create_tache22 ();
  gtk_widget_show (afficher_et);
}


void
on_home_ett_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *tach2;
tach2=lookup_widget(button,"afficher_et");
gtk_widget_destroy(tach2);
GtkWidget *afficher_et;
afficher_et = create_accuile_et ();
  gtk_widget_show (afficher_et);
}



void
on_radiobutton17_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
strcpy(sexe1,"Femme");
}


void
on_radiobutton16_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
strcpy(sexe1,"Homme");
}








void
on_retttt_2_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *tach2;
tach2=lookup_widget(button,"tache22");
gtk_widget_destroy(tach2);
GtkWidget *afficher_et;
afficher_et = create_accuile_et ();
  gtk_widget_show (afficher_et);
}


void
on_ret_mn_22_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *tach2;
tach2=lookup_widget(button,"accuile_et");
gtk_widget_destroy(tach2);
GtkWidget *afficher_et;
afficher_et = create_home_in ();
  gtk_widget_show (afficher_et);
}


void
on_radiobutton2H_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
//toute valeur
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))) valeurAlarmes = 0;
}


void
on_radiobutton3H_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
//toute valeur
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))) valeurAlarmes = 2;
}

