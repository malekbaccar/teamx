#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
//#include "fonction.h"
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
on_button16_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_button14_clicked                    (GtkWidget       *objet,
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

spin1=lookup_widget(objet,"spinbutton1");
spin2=lookup_widget(objet,"spinbutton2");
spin3=lookup_widget(objet,"spinbutton3");
spin4=lookup_widget(objet,"spinbutton9");
spin5=lookup_widget(objet,"spinbutton10");

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
on_button6_clicked                     (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *id,*type1,*type2,*type3,*type4,*type,*vmax,*vmin,*zone,*etage,*rech,*captj,*captm,*capta;

capteur p;
char reche[200];

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

strcpy(p.id,gtk_entry_get_text(GTK_ENTRY(id)));

p.captj=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(captj));
p.captm=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(captm));
p.capta=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(capta));

p.vmax=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(vmax));
p.vmin=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(vmin));

type1=lookup_widget(objet,"radiobutton5");
type2=lookup_widget(objet,"radiobutton6");
type3=lookup_widget(objet,"radiobutton7");
type4=lookup_widget(objet,"radiobutton8");


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

zone=lookup_widget(objet,"comboboxentry7");
strcpy(p.zone,gtk_combo_box_get_active_text(GTK_COMBO_BOX(zone)));

etage=lookup_widget(objet,"comboboxentry8");
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
on_button15_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

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

