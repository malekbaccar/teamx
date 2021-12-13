  #include "stock.h"
  #include <stdio.h>
#include <stdlib.h>
#include "string.h"
  void ajouter_produit( produit p){
FILE *f=NULL;
f=fopen("produit.txt","a+");//(+) creation du fichier sil nexsite pas
fprintf(f,"%s %s %s %d %s %s %d \n",p.ref,p.nom,p.categ,p.quant,p.type,p.date,p.poid);
fclose(f);
printf("ajouter avec succes \n");

}




void supprimer_st(char *ref){

FILE*f=NULL;
FILE*f1=NULL;
produit p ;
f=fopen("produit.txt","r");
f1=fopen("ancien.txt","w+");

while(fscanf(f,"%s %s %s %d %s %s %d\n",p.ref,p.nom,p.categ,&p.quant,p.type,p.date,&p.poid)!=-1){
if(strcmp(ref,p.ref)!=0)
    fprintf(f1,"%s %s %s %d %s %s %d\n",p.ref,p.nom,p.categ,p.quant,p.type,p.date,p.poid);
}
fclose(f);
fclose(f1);
remove("produit.txt");
rename("ancien.txt","produit.txt");
printf("suppeimer avec succes\n");
}




void modifier_stt(char ref[],produit r){
FILE*f=NULL;
FILE*f1=NULL;
produit p ;
f=fopen("produit.txt","r");

f1=fopen("ancien.txt","w+");

if ((f!=NULL)&&(f1!=NULL))
while(fscanf(f,"%s %s %s %d %s %s %d\n",p.ref,p.nom,p.categ,&p.quant,p.type,p.date,&p.poid)!=-1){
if( strcmp(p.ref,ref)==0    )
{
fprintf(f1,"%s %s %s %d %s %s %d\n",r.ref,r.nom,r.categ,r.quant,r.type,r.date,r.poid);
}
else
{
fprintf(f1,"%s %s %s %d %s %s %d \n",p.ref,p.nom,p.categ,p.quant,p.type,p.date,p.poid);
}

}
fclose(f);
fclose(f1);
remove("produit.txt");
rename("ancien.txt","produit.txt");
printf("modifier avec succes \n");
}

void afficher_st(GtkWidget *liste)
{
            GtkCellRenderer *renderer;
	    GtkTreeViewColumn *column;
 	    GtkTreeIter iter;
	    GtkListStore *store;
	    produit p;
            char ref[30];
	char nom[30];
	char categ[30];
	char type[30];
	char quant[30];
	char date[30];
	char poid[30];
	
	
	    store==NULL;
 	    
	    FILE *f;
	    
	    store=gtk_tree_view_get_model(liste);
	    if(store==NULL)
            {
            renderer = gtk_cell_renderer_text_new ();
	    column = gtk_tree_view_column_new_with_attributes("Reference",renderer ,"text",EREF, NULL);
	    gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	    
	    renderer = gtk_cell_renderer_text_new ();
	    column = gtk_tree_view_column_new_with_attributes("Nom",renderer ,"text",ENOM, NULL);
	    gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	    
	    renderer = gtk_cell_renderer_text_new ();
	    column = gtk_tree_view_column_new_with_attributes("Categorie",renderer ,"text",ECATEG, NULL);
	    gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	    
	    renderer = gtk_cell_renderer_text_new ();
	    column = gtk_tree_view_column_new_with_attributes("Quantite",renderer ,"text",EQUANT, NULL);
	    gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	    
	    renderer = gtk_cell_renderer_text_new ();
	    column = gtk_tree_view_column_new_with_attributes("type",renderer ,"text",ETYPE, NULL);
	    gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new ();
	    column = gtk_tree_view_column_new_with_attributes("Date",renderer ,"text",EDATE, NULL);
	    gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	    renderer = gtk_cell_renderer_text_new ();
	    column = gtk_tree_view_column_new_with_attributes("Poid",renderer ,"text",EPOID, NULL);
	    gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

}
	    store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

	    f=fopen("produit.txt","r");
	    if(f==NULL)
	    {
	          return;
	    }

	    else
	    {  
			f=fopen("produit.txt","a+");
			while(fscanf(f,"%s %s %s %s %s %s %s\n",ref,nom,categ,quant,type,date,poid)!=EOF)
			{
				gtk_list_store_append (store, &iter);
				gtk_list_store_set(store,&iter,EREF,ref,ENOM,nom,ECATEG,categ,EQUANT,quant,ETYPE,type,EDATE,date,EPOID,poid, -1);
			}
			fclose(f);
			gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
			g_object_unref (store);
	    }
}

void chercher_st(GtkWidget *liste, char ch[30])
{
            GtkCellRenderer *renderer;
	    GtkTreeViewColumn *column;
 	    GtkTreeIter iter;
	    GtkListStore *store;
	    produit p;
            char ref[30];
	char nom[30];
	char categ[30];
	char type[30];
	char quant[30];
	char date[30];
	char poid[30];
	
	
	    store==NULL;
 	    
	    FILE *f;
	    
	    store=gtk_tree_view_get_model(liste);
	    if(store==NULL)
            {
            renderer = gtk_cell_renderer_text_new ();
	    column = gtk_tree_view_column_new_with_attributes("Reference",renderer ,"text",EREF, NULL);
	    gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	    
	    renderer = gtk_cell_renderer_text_new ();
	    column = gtk_tree_view_column_new_with_attributes("Nom",renderer ,"text",ENOM, NULL);
	    gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	    
	    renderer = gtk_cell_renderer_text_new ();
	    column = gtk_tree_view_column_new_with_attributes("Categorie",renderer ,"text",ECATEG, NULL);
	    gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	    
	    renderer = gtk_cell_renderer_text_new ();
	    column = gtk_tree_view_column_new_with_attributes("Quantite",renderer ,"text",EQUANT, NULL);
	    gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	    
	    renderer = gtk_cell_renderer_text_new ();
	    column = gtk_tree_view_column_new_with_attributes("type",renderer ,"text",ETYPE, NULL);
	    gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new ();
	    column = gtk_tree_view_column_new_with_attributes("Date",renderer ,"text",EDATE, NULL);
	    gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	    renderer = gtk_cell_renderer_text_new ();
	    column = gtk_tree_view_column_new_with_attributes("Poid",renderer ,"text",EPOID, NULL);
	    gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

}
	    store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

	    f=fopen("produit.txt","r");
	    if(f==NULL)
	    {
	          return;
	    }

	    else
	    {  
			f=fopen("produit.txt","a+");
			while(fscanf(f,"%s %s %s %s %s %s %s\n",ref,nom,categ,quant,type,date,poid)!=EOF)
			{if (strcmp(nom,ch)==0){
				gtk_list_store_append (store, &iter);
				gtk_list_store_set(store,&iter,EREF,ref,ENOM,nom,ECATEG,categ,EQUANT,quant,ETYPE,type,EDATE,date,EPOID,poid, -1);
			}}
			fclose(f);
			gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
			g_object_unref (store);
	    }
}


void cherche_produit(char ref[]){
FILE*f=NULL;
 produit p;
f=fopen("produit.txt","r");
while(fscanf(f,"%s %s %s %d %s %s\n",p.ref,p.nom,p.categ,&p.quant,p.type,p.date)!=-1){
if(strcmp(p.ref,ref)==0)
     printf("%s %s %s %d %s %s\n",p.ref,p.nom,p.categ,p.quant,p.type,p.date);
}
fclose(f);

}


void utiliser_stt(char ref[],int x){
FILE*f=NULL;
FILE*f1=NULL;
produit p ;
f=fopen("produit.txt","r");

f1=fopen("ancien.txt","w+");

if ((f!=NULL)&&(f1!=NULL))
while(fscanf(f,"%s %s %s %d %s %s %d\n",p.ref,p.nom,p.categ,&p.quant,p.type,p.date,&p.poid)!=-1){
if( strcmp(p.ref,ref)==0    )
{
fprintf(f1,"%s %s %s %d %s %s %d\n",p.ref,p.nom,p.categ,(p.quant-x),p.type,p.date,p.poid);
}
else
{
fprintf(f1,"%s %s %s %d %s %s %d\n",p.ref,p.nom,p.categ,p.quant,p.type,p.date,p.poid);
}

}
fclose(f);
fclose(f1);
remove("produit.txt");
rename("ancien.txt","produit.txt");
printf("modifier avec succes \n");
}




int ret_qp(produit o){
FILE*f=NULL;
int bb;
produit p ;
f=fopen("produit.txt","r");

while(fscanf(f,"%s %s %s %d %s %s %d\n",p.ref,p.nom,p.categ,&p.quant,p.type,p.date,&p.poid)!=-1){
if(strcmp(o.ref,p.ref)==0){
  bb = p.quant;   
}}

return bb;}



void stoq_ep(GtkWidget *liste,char y[],int mn,int choix)
{
            GtkCellRenderer *renderer;
	    GtkTreeViewColumn *column;
 	    GtkTreeIter iter;
	    GtkListStore *store;
	    produit p;
            char ref[30];
	char nom[30];
	char categ[30];
	char type[30];
	char quant[30];
	char date[30];
	char poid[30];
	
	
	    store==NULL;
 	    
	    FILE *f;
	    
	    store=gtk_tree_view_get_model(liste);
	    if(store==NULL)
            {
            renderer = gtk_cell_renderer_text_new ();
	    column = gtk_tree_view_column_new_with_attributes("Reference",renderer ,"text",EREF, NULL);
	    gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	    
	    renderer = gtk_cell_renderer_text_new ();
	    column = gtk_tree_view_column_new_with_attributes("Nom",renderer ,"text",ENOM, NULL);
	    gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	    
	    renderer = gtk_cell_renderer_text_new ();
	    column = gtk_tree_view_column_new_with_attributes("Categorie",renderer ,"text",ECATEG, NULL);
	    gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	    
	    renderer = gtk_cell_renderer_text_new ();
	    column = gtk_tree_view_column_new_with_attributes("Quantite",renderer ,"text",EQUANT, NULL);
	    gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	    
	    renderer = gtk_cell_renderer_text_new ();
	    column = gtk_tree_view_column_new_with_attributes("type",renderer ,"text",ETYPE, NULL);
	    gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new ();
	    column = gtk_tree_view_column_new_with_attributes("Date",renderer ,"text",EDATE, NULL);
	    gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	    renderer = gtk_cell_renderer_text_new ();
	    column = gtk_tree_view_column_new_with_attributes("Etat",renderer ,"text",EPOID, NULL);
	    gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

}
	    store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

	    f=fopen("produit.txt","r");
	    if(f==NULL)
	    {
	          return;
	    }

	    else
	    {  
			f=fopen("produit.txt","a+");
			while(fscanf(f,"%s %s %s %s %s %s %s\n",ref,nom,categ,quant,type,date,poid)!=EOF)
			{if (atoi(quant)<=mn && choix == 0){ strcpy(poid,"Stock épuise");
				gtk_list_store_append (store, &iter);
				gtk_list_store_set(store,&iter,EREF,ref,ENOM,nom,ECATEG,categ,EQUANT,quant,ETYPE,type,EDATE,date,EPOID,poid, -1);
			}
			if ((strcmp(y,date)>0) && choix == 1 ){ strcpy(poid,"Date épuise");
				gtk_list_store_append (store, &iter);
				gtk_list_store_set(store,&iter,EREF,ref,ENOM,nom,ECATEG,categ,EQUANT,quant,ETYPE,type,EDATE,date,EPOID,poid, -1);
			}}
			fclose(f);
			gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
			g_object_unref (store);
	    }
}



