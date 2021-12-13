
#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif
#include <stdlib.h>
#include <gtk/gtk.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "foyer.h"
#include <stdio.h>
#include <string.h>
#include <time.h>







GtkListStore *adstore;/*creation du modele de type liste*/
GtkTreeViewColumn *adcolumn;/*visualisation des colonnes*/
GtkCellRenderer *cellad;/*afficheur de cellule(text,image..)*/
FILE *F;

void affi_ch(GtkWidget* treeview1,char*l)
{

char id[20];
char NOM[20];
char Prenom[20];
char sexe[20];
char jour[20];
char chambre[20];
char niveau[20];
char CIN[20];
char mois[20];
char annee[20];


        /* Creation du modele */
        adstore = gtk_list_store_new(10,
				     G_TYPE_STRING,
				     G_TYPE_STRING,
				     G_TYPE_STRING,			
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING);
        /* Insertion des elements */
        F=fopen(l,"r");
while(fscanf(F,"%s %s %s %s %s %s %s %s %s %s \n",id,NOM,Prenom,sexe,CIN,chambre,jour,mois,annee,niveau)!= EOF)
        {GtkTreeIter pIter;

         /* Creation de la nouvelle ligne */
         gtk_list_store_append(adstore, &pIter);
         /* Mise a jour des donnees */
         gtk_list_store_set(adstore, &pIter,
                            0,id,
                            1,NOM,
			    2,Prenom,	
                            3,sexe,
                            4,CIN,
                            5,chambre,
                            6,jour,
                            7,mois,
                            8,annee,
                            9,niveau,
                            -1);}
        fclose(F);

	/* Creation de la 1ere colonne */
if(m==0)
	{cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("ID",
                                                            cellad,
                                                            "text", 0,
                                                            NULL);


        /* Ajouter la 1er colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


	/* Creation de la 2eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("NOM",
                                                            cellad,
                                                            "text", 1,
                                                            NULL);
	/* Ajouter la 2emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 3eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("PRENOM",
                                                            cellad,
                                                            "text", 2,
                                                            NULL);
	/* Ajouter la 3emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);
       

       /* Creation de la 4eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("SEXE",
                                                            cellad,
                                                            "text", 3,
                                                            NULL);
	/* Ajouter la 4emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


            /* Creation de la 5eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("niveau",
                                                            cellad,
                                                            "text", 4,
                                                            NULL);
	/* Ajouter la 5emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);



           /* Creation de la 6eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("NUMTL",
                                                            cellad,
                                                            "text", 5,
                                                            NULL);
	/* Ajouter la 6emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 7eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("JOUR",
                                                            cellad,
                                                            "text", 6,
                                                            NULL);
	/* Ajouter la 7emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 8eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("MOIS",
                                                            cellad,
                                                            "text", 7,
                                                            NULL);
	/* Ajouter la 8emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


        /* Creation de la 8eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("ANNEE",
                                                            cellad,
                                                            "text", 8,
                                                            NULL);
	/* Ajouter la 8emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

        /* Creation de la 9eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("chambre",
                                                            cellad,
                                                            "text", 9,
                                                            NULL);
	/* Ajouter la 9emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


	m++;}


 	gtk_tree_view_set_model ( GTK_TREE_VIEW (treeview1),
                                  GTK_TREE_MODEL(adstore)  );

}








void Ajouter_ch(foyer o)
{
    FILE *F=NULL;

F=fopen("foyer.txt","a");
if(F!=NULL)
{

    fprintf(F,"%s %s %s %s %s %s %d %d %d %s \n",o.id,o.NOM,o.Prenom,o.sexe,o.CIN,o.chambre,o.dt_ns.jour,o.dt_ns.mois,o.dt_ns.annee,o.niveau);
    fclose(F);
    

}
}
void supp_ch(char id[])
{

   FILE *F,*FW;
  foyer o;
  
F = fopen ("foyer.txt", "r");
FW = fopen ("or.txt", "w");

  if ((F!=NULL)&&(FW!=NULL))
 {
  while (fscanf (F,"%s %s %s %s %s %s %d %d %d %s \n",o.id,o.NOM,o.Prenom,o.sexe,o.CIN,o.chambre,&o.dt_ns.jour,&o.dt_ns.mois,&o.dt_ns.annee,o.niveau) != EOF)
    if (strcmp (o.id,id) != 0)
      fprintf (FW,"%s %s %s %s %s %s %d %d %d %s \n",o.id,o.NOM,o.Prenom,o.sexe,o.CIN,o.chambre,o.dt_ns.jour,o.dt_ns.mois,o.dt_ns.annee,   o.niveau);
  fclose (F);
  fclose (FW);
remove("foyer.txt");
rename("or.txt", "foyer.txt");
}


}

void modi_ch(char id[],foyer o)
{


  foyer c;
  
   FILE *F, *FW;
  
  
F = fopen ("foyer.txt", "r");
FW = fopen ("or.txt", "w");

  if ((F!=NULL)&&(FW!=NULL))
 {


  while (fscanf (F, "%s %s %s %s %s %s %d %d %d %s\n",c.id,c.NOM,c.Prenom,c.sexe,c.CIN,c.chambre,&c.dt_ns.jour,&c.dt_ns.mois,&c.dt_ns.annee, c.niveau)!=EOF)
    if (strcmp (c.id, id) == 0)
     {
fprintf (FW, "%s %s %s %s %s %s %d %d %d %s\n",id,o.NOM,o.Prenom,o.sexe,o.CIN,o.chambre,o.dt_ns.jour,o.dt_ns.mois,o.dt_ns.annee,o.niveau);

     }
     else
     {
       fprintf (FW, "%s %s %s %s %s %s %d %d %d %s\n", c.id,c.NOM,c.Prenom,c.sexe,c.CIN,c.chambre,c.dt_ns.jour,c.dt_ns.mois,c.dt_ns.annee,c.niveau);
     }
     

     
     

  fclose (F);
  fclose (FW);
remove("foyer.txt");
rename("or.txt", "foyer.txt");

}


}







foyer rechercher_foyer(char id[])
{

FILE *F;
  foyer q;
  foyer o;
F = fopen ("foyer.txt", "r");


  if (F!=NULL)
 {


    while (fscanf (F, "%s %s %s %s %s %s %d %d %d %s \n",q.id,q.NOM,q.Prenom,q.sexe,q.CIN,q.chambre,&o.dt_ns.jour,&o.dt_ns.mois,&o.dt_ns.annee, q.niveau)!=EOF)
    if (strcmp (q.id, id) == 0)
	{
        
	strcpy(o.NOM,q.NOM);
        strcpy(o.Prenom,q.Prenom);
        strcpy(o.sexe,q.sexe);
	strcpy(o.CIN,q.CIN);
	strcpy(o.niveau,q.niveau);
	strcpy(o.chambre,q.chambre);
        
    }
    
      return(o);

  fclose (F);
 }
}





void affi_ad_ch(GtkWidget* treeview6,char*l)
{

char niveau[20];
char nb[20];




        /* Creation du modele */
        adstore = gtk_list_store_new(2,
				     G_TYPE_STRING,
				     G_TYPE_STRING);
        /* Insertion des elements */
        F=fopen(l,"r");
while(fscanf(F,"%s %s  \n",niveau,nb)!= EOF)
        {GtkTreeIter pIter;

         /* Creation de la nouvelle ligne */
         gtk_list_store_append(adstore, &pIter);
         /* Mise a jour des donnees */
         gtk_list_store_set(adstore, &pIter,
                            0,niveau,
                            1,nb,
			    -1);}
        fclose(F);

	/* Creation de la 1ere colonne */
if(k==0)
	{cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("niveau",
                                                            cellad,
                                                            "text", 0,
                                                            NULL);


        /* Ajouter la 1er colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview6), adcolumn);


	/* Creation de la 2eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("NB",
                                                            cellad,
                                                            "text", 1,
                                                            NULL);
        /* Ajouter la 1er colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview6), adcolumn);
	
	k++;}


 	gtk_tree_view_set_model ( GTK_TREE_VIEW (treeview6),
                                  GTK_TREE_MODEL(adstore)  );

}


