#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include"tree.h"
#include"crud.h"




void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{


 	gchar *ref; //gchar* type gtk ==> chaine en c car la fonction gtk_tree_model_get naccepte que gchar*
        gchar *type;
	gchar *constructeur;
        gchar *dateAjout;
	gchar *bloc;
	gint valMax;
	gint valMin;
	gint etage;
        

        int x;
        GtkTreeModel     *model;
        GtkTreeIter iter;
        GtkWidget *p=lookup_widget(gestion_Capteur,"treeview1");
        GtkTreeSelection *selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
	
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {
                gtk_tree_model_get (model,&iter,0,&ref,1,&type,2,&constructeur,3,&dateAjout,4,&valMax,5,&valMin,6,&etage,7,&bloc,-1);//recuperer les information de la ligne selectionneé

                gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestion_Capteur,"entry2")),dateAjout);
		gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestion_Capteur,"entry12")),constructeur);
		gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestion_Capteur,"entry13")),bloc);
		
                
		gtk_spin_button_set_value (GTK_SPIN_BUTTON(lookup_widget(gestion_Capteur,"spinbutton7")),valMax);
		gtk_spin_button_set_value (GTK_SPIN_BUTTON(lookup_widget(gestion_Capteur,"spinbutton8")),valMin);
                gtk_spin_button_set_value (GTK_SPIN_BUTTON(lookup_widget(gestion_Capteur,"spinbutton4")),etage);
                

                if(strcmp(type,"Temperature")==0) x=0;
                if(strcmp(type,"Debit")==0) x=1;
		if(strcmp(type,"Fumee")==0) x=2;
		if(strcmp(type,"Dechets")==0) x=3;
		if(strcmp(type,"Mouvement")==0) x=4;




                gtk_combo_box_set_active(GTK_COMBO_BOX(lookup_widget(gestion_Capteur,"combobox2")),x);
		GtkWidget* msg=lookup_widget(gestion_Capteur,"label25");
                gtk_label_set_text(GTK_LABEL(msg),ref);
		


                gtk_widget_show(lookup_widget(gestion_Capteur,"button7"));//afficher le bouton modifier
        GtkWidget* msg1=lookup_widget(gestion_Capteur,"label27");
        gtk_widget_hide(msg1);

}



}




int choix[] = {0,0,0}; 
int choix1[] = {0,0,0,0};






void
on_catalogue_Acceuil_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_widget_show (acceuil);
 gtk_widget_destroy (catalogue);


        
        
    
}


void
on_button2_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
/*preparation du treeView*/
GtkWidget *p;
GtkWidget *p1;
FILE*f1=NULL;
capteur c;
gtk_widget_hide (acceuil);
gestion_Capteur = create_gestion_Capteur ();
p=lookup_widget(gestion_Capteur,"treeview1");
p1=lookup_widget(gestion_Capteur,"treeview3");
i=0;
Capteurtree(p,"capteurs.txt");

i=0;
Capteurtree(p1,"capteurs.txt");

gtk_widget_show (gestion_Capteur);
}


////////////////////////  Ajouter   ////////////////////////////

void
on_AjouterCapteur_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *cal1;
GtkWidget *combobox;
GtkWidget *labelNom;
GtkWidget *labelsuccess;
GtkWidget *labelCombo;
GtkWidget *labelExist;
FILE*f=NULL;
capteur c;
int jj1,mm1,aa1,b=1;

labelNom=lookup_widget(gestion_Capteur,"label9");
labelCombo=lookup_widget(gestion_Capteur,"label15");
labelExist=lookup_widget(gestion_Capteur,"label8");
labelsuccess=lookup_widget(gestion_Capteur,"label10");
combobox=lookup_widget(gestion_Capteur,"combobox1");
cal1=lookup_widget(gestion_Capteur,"calendar1");
           gtk_widget_hide (labelsuccess);

strcpy(c.ref,gtk_entry_get_text(GTK_ENTRY(lookup_widget(gestion_Capteur,"entry1"))));


// saisie controlé
if(strcmp(c.ref,"")==0){
                gtk_widget_show (labelNom);
b=0;

}else
{
           gtk_widget_hide (labelNom);
}

if(gtk_combo_box_get_active (GTK_COMBO_BOX(combobox))==-1){
                gtk_widget_show (labelCombo);
b=0;
}
else{

           gtk_widget_hide (labelCombo);
}
if(b==1){

if (choix1[0]==1)
strcpy(c.constructeur,"Hitech");
else if (choix1[1]==1)
strcpy(c.constructeur,"ABB Automation");
else if (choix1[2]==1)
strcpy(c.constructeur,"NEXT");
else if (choix1[3]==1)
strcpy(c.constructeur,"TOMRA");

if (choix[0]==1)
strcpy(c.bloc,"A");
else if (choix[1]==1)
strcpy(c.bloc,"B");
else if (choix[2]==1)
strcpy(c.bloc,"C");


c.valMax =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(gestion_Capteur,"spinbutton5")));
c.valMin =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(gestion_Capteur,"spinbutton6")));
c.etage =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(gestion_Capteur,"spinbutton2")));
strcpy(c.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)));
//recuperer la date du calendrier jour,mois,annee
gtk_calendar_get_date (GTK_CALENDAR(cal1),
                       &aa1,
                       &mm1,
                       &jj1);

if(exist(c.ref)==1) {

                gtk_widget_show (labelExist);

}
else{
           gtk_widget_hide (labelExist);
f=fopen("capteurs.txt","a+");
fprintf(f,"%s %s %s %d/%d/%d  %d %d %d %s\n",c.ref,c.type,c.constructeur,jj1,mm1+1,aa1,c.valMax,c.valMin,c.etage,c.bloc);
fclose(f);
                gtk_widget_show (labelsuccess);


/*mise a jour du treeView*/
GtkWidget *p;
p=lookup_widget(gestion_Capteur,"treeview1");
Capteurtree(p,"capteurs.txt");



}
}

}

////////////////////////  supprimer   ////////////////////////////

void
on_SupprimerCapteur_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkTreeSelection *selection;
        GtkTreeModel     *model;
        GtkTreeIter iter;
        GtkWidget* p;
        GtkWidget *label;
        gchar* ref;
        label=lookup_widget(gestion_Capteur,"label27");
        p=lookup_widget(gestion_Capteur,"treeview1");
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {  gtk_tree_model_get (model,&iter,0,&ref,-1);
           gtk_list_store_remove(GTK_LIST_STORE(model),&iter);//supprimer la ligne du treeView

           supp(ref);// supprimer la ligne du fichier

           gtk_widget_hide (label);}else{
                gtk_widget_show (label);
        }

}


////////////////////////  Modifier   ////////////////////////////

void
on_ModifierCapteur_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
capteur c;
        strcpy(c.ref,gtk_label_get_text(GTK_LABEL(lookup_widget(gestion_Capteur,"label25"))));
        strcpy(c.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(lookup_widget(gestion_Capteur,"combobox2"))));
        strcpy(c.dateAjout,gtk_entry_get_text(GTK_ENTRY(lookup_widget(gestion_Capteur,"entry2"))));
	strcpy(c.constructeur,gtk_entry_get_text(GTK_ENTRY(lookup_widget(gestion_Capteur,"entry12"))));
	strcpy(c.bloc,gtk_entry_get_text(GTK_ENTRY(lookup_widget(gestion_Capteur,"entry13"))));
	
	c.valMax =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(gestion_Capteur,"spinbutton7")));
	c.valMin =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(gestion_Capteur,"spinbutton8")));
        c.etage =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(gestion_Capteur,"spinbutton4")));

        supp(c.ref);
        ajout(c);
        Capteurtree(lookup_widget(gestion_Capteur,"treeview1"),"capteurs.txt");
        GtkWidget* msg=lookup_widget(gestion_Capteur,"label26");
        gtk_widget_show(msg);

}


void
on_button3_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_widget_show (acceuil);
        gtk_widget_destroy (gestion_Capteur);
}

 

////////////////////////  RECHERCHE   ////////////////////////////
void
on_chercherCapteur_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *p1;
GtkWidget *entry;
GtkWidget *labelType;
GtkWidget *nbResultat;
GtkWidget *message;
char type[30];
char chnb[30];
int b=0,nb;
entry=lookup_widget(gestion_Capteur,"entry7");
labelType=lookup_widget(gestion_Capteur,"label64");
p1=lookup_widget(gestion_Capteur,"treeview3");

strcpy(type,gtk_entry_get_text(GTK_ENTRY(entry)));
if(strcmp(type,"")==0){
  gtk_widget_show (labelType);b=0;
}else{
b=1;
gtk_widget_hide (labelType);}

if(b==0){return;}else{

nb=ChercherCapteurTree(p1,"capteurs.txt",type);//type entry ecrie par lutilisateur
/* afficher le nombre de resultats obtenue par la recherche */
sprintf(chnb,"%d",nb);
nbResultat=lookup_widget(gestion_Capteur,"label66");
message=lookup_widget(gestion_Capteur,"label65");
gtk_label_set_text(GTK_LABEL(nbResultat),chnb);//set_text n'accepte que chaine de caractere 

gtk_widget_show (nbResultat);
gtk_widget_show (message);




}

}

 // bouton radio

void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choix1[1] = 1;
else
choix1[1] = 0;
}


void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choix1[0] = 1;
else
choix1[0] = 0;
}


void
on_radiobutton4_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choix1[3] = 1;
else
choix1[3] = 0;
}


void
on_radiobutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choix1[2] = 1;
else
choix1[2] = 0;
}
// case a cocher

void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choix[0] = 1;
else
choix[0] = 0;
}
  

void
on_checkbutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choix[1] = 1;
else
choix[1] = 0;
}


void
on_checkbutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choix[2] = 1;
else
choix[2] = 0;
}


void
on_button_pannes_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
/*preparation du treeView*/
GtkWidget *p2;
FILE*f1=NULL;
debit d;
gtk_widget_hide (acceuil);
etages_contenant_des_pannes = create_etages_contenant_des_pannes ();
p2=lookup_widget(etages_contenant_des_pannes,"treeview8");

i=0;
Debittree(p2,"debit.txt");


gtk_widget_show (etages_contenant_des_pannes);
}


void
on_button_alarmes_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
/*preparation du treeView*/
GtkWidget *p4;
FILE*f1=NULL;
//temp t;
FUMEE F;
gtk_widget_hide (acceuil);
liste_des_alarmes = create_liste_des_alarmes ();
p4=lookup_widget(liste_des_alarmes,"treeview9");

v=0;
/*Temptree(p3,"temperature.txt");*/
Fumeetree(p4,"fumee.txt");


gtk_widget_show (liste_des_alarmes);
}


void
on_button_capteurs_defectueux_clicked  (GtkButton       *button,
                                        gpointer         user_data)
{
/*preparation du treeView*/
GtkWidget *p3;
FILE*f1=NULL;
temp t;

gtk_widget_hide (acceuil);
capteurs_defectueux = create_capteurs_defectueux ();
p3=lookup_widget(capteurs_defectueux,"treeview7");

v=0;
Temptree(p3,"temperature.txt");



gtk_widget_show (capteurs_defectueux);
}


void
on_button_capteurDef_acceuil_clicked   (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_widget_show (acceuil);
        gtk_widget_destroy (capteurs_defectueux);
}


void
on_button_etagePanne_acceuil_clicked   (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_widget_show (acceuil);
        gtk_widget_destroy (etages_contenant_des_pannes);
}


void
on_button_alarmes_acceuil_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_widget_show (acceuil);
        gtk_widget_destroy (liste_des_alarmes);
}

