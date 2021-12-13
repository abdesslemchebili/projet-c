#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "crud.h"
#include "tree.h"
#include "foyer.h"
#include "reclam.h"
#include "fonction.h"
#include "fonction1.h"
#include "fonction2.h"
#include "stock.h"
int xg;
int tg[4]={0,0,0,0};
int xgg;
int tgg[4]={0,0,0,0};
int xy[]={0,0,0,0},sy;
int choix1;
int t[6]={0,0,0,0,0,0};
int s=1;
int s1=1 ; 
int testM=1;
int tn=0;
int tt=0;
int ts=0;
int tr=0;
int tu=0;
int tp=0;
int choix=0 ;
void sendmail(char body[])
{
        char cmd[1000];
        FILE *fp = fopen("mail.txt","w+"); // open it for writing.
        fprintf(fp,"%s\n",body);        // write body to it.
        fclose(fp);             // close it.

        sprintf(cmd,"curl smtps://smtp.gmail.com:465 -v --mail-from \"firaschalbi0007@gmail.com:fcbarcelona1999\" --mail-rcpt \"firas.chalbi@esprit.tn\" --ssl -u firaschalbi0007@gmail.com:fcbarcelona1999 -T mail.txt -k --anyauth"); // prepare command.
        system(cmd);     // execute it.
}
 
void on_button_ok_clicked                   (GtkWidget       *button,
                                        gpointer         user_data)
{

GtkWidget *Login,*psw,*windowESadmin,*fen,*window, *login;
char user1[20];
char pw[20];
Login=lookup_widget(button,"entry1_login");
psw =lookup_widget(button,"entry2_login");
strcpy(user1,gtk_entry_get_text(GTK_ENTRY(Login)));
strcpy(pw,gtk_entry_get_text(GTK_ENTRY(psw)));
/*
if (verifx(user,pw)==1)
{
	fen=lookup_widget(button,"LOGIN");
	gtk_widget_destroy(fen);
	windowESadmin=create_ADMIN();
	gtk_widget_show(windowESadmin);
}
*/
user u;
FILE *f = fopen("utilisateur.txt","r");
if(f){
while(fscanf(f,"%s %s %s %s %s %s %s\n",u.id,u.nom,u.login,u.pw,u.type,u.sexe,u.role)!=EOF)
{
if(strcmp(u.login,user1)==0&&strcmp(u.pw,pw)==0){
window=atoi(u.role)==1?create_ADMIN():atoi(u.role)==2?create_dashboard():atoi(u.role)==3?create_GestionFoyer():atoi(u.role)==4?create_gestion_Capteur():atoi(u.role)==5?create_afiicher_st():create_first();
login=lookup_widget(button,"LOGIN");
//gtk_widget_destroy(login);
gtk_widget_show(window);
}
}
fclose(f);
}
}

void on_button_gosupp_clicked               (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *fen_nv,*fen_act;
fen_act=lookup_widget(button,"ADMIN");
gtk_widget_destroy(fen_act);
fen_nv=create_SUPP();
gtk_widget_show(fen_nv);
}


void on_button_gomodif_clicked              (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *fen_nv,*fen_act;
fen_act=lookup_widget(button,"ADMIN");
gtk_widget_destroy(fen_act);
fen_nv=create_MODIF();
gtk_widget_show(fen_nv);
}


void on_button_gorech_clicked               (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *fen_nv,*fen_act;
fen_act=lookup_widget(button,"ADMIN");
gtk_widget_destroy(fen_act);
fen_nv=create_RECHERCHE();
gtk_widget_show(fen_nv);
}


void on_button_goajout_clicked              (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *fen_nv,*fen_act;
fen_act=lookup_widget(button,"ADMIN");
gtk_widget_destroy(fen_act);
fen_nv=create_AJOUT();
gtk_widget_show(fen_nv);
}


void on_button_affich_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
 GtkWidget *tv;
 tv=lookup_widget(button,"treeview1");
 afficher_user(tv);
}


void on_Home_ajout_clicked                  (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *fen_nv,*fen_act;
fen_act=lookup_widget(button,"AJOUT");
gtk_widget_destroy(fen_act);
fen_nv=create_ADMIN();
gtk_widget_show(fen_nv);
choix =0 ; 
}


void on_button_ajouter_clicked              (GtkWidget       *button,
                                        gpointer         user_data)
{

GtkWidget *login,*pw,*nom,*id,*Role,*type;
user u;
int role ;

nom=lookup_widget (button, "entry1_ajout");
id = lookup_widget (button, "entry2_ajout");
login = lookup_widget (button, "entry3_ajout");
pw = lookup_widget (button, "entry4_ajout");
type=lookup_widget(button,"combobox1_ajout");
Role=lookup_widget (button,"spinbutton1_ajout");
strcpy(u.login,gtk_entry_get_text(GTK_ENTRY(login)));
strcpy(u.pw,gtk_entry_get_text(GTK_ENTRY(pw)));
strcpy(u.id,gtk_entry_get_text(GTK_ENTRY(id)));
strcpy(u.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
role=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Role));
sprintf(u.role,"%d",role);
strcpy(u.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)));
if (s==1)
	strcpy(u.sexe,"Homme");
else if (s==2) 
	strcpy(u.sexe,"Femme");
if (choix == 1 ) 
{
ajouter_USER(u);
} 
}


void on_radiobutton1_ajout_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
s=1;
}


void on_radiobutton2_ajout_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
s=2;
}


void on_button_homesupp_clicked             (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *fen_nv,*fen_act;
fen_act=lookup_widget(button,"SUPP");
gtk_widget_destroy(fen_act);
fen_nv=create_ADMIN();
gtk_widget_show(fen_nv);
}


void on_button_supp_clicked                 (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *idd;
char U[20];
idd=lookup_widget(button,"entry1_supp");
strcpy(U,gtk_entry_get_text(GTK_ENTRY(idd)));
supprimer_user(U);
}


void on_button_homerech_clicked             (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *fen_nv,*fen_act;
fen_act=lookup_widget(button,"RECHERCHE");
gtk_widget_destroy(fen_act);
fen_nv=create_ADMIN();
gtk_widget_show(fen_nv);
}


void on_button_aff_clicked                  (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *id,*outputr;
GtkWidget *output1,*output2,*output3,*output4,*output5,*output6;
GtkWidget *output11,*output22,*output33,*output44,*output55,*output66;
int test;
char p[20];
char nom[20];
char t[20];
char sx[20];
char log[20];
char pw[20];
char r[20];

//////////////////////////////////////////////////////////////

output1=lookup_widget(button,"aa1");
 gtk_label_set_text(GTK_LABEL(output1),"");
output2=lookup_widget(button,"aa2");
 gtk_label_set_text(GTK_LABEL(output2),"");
output3=lookup_widget(button,"aa3");
 gtk_label_set_text(GTK_LABEL(output3),"");
output4=lookup_widget(button,"aa4");
 gtk_label_set_text(GTK_LABEL(output4),"");
output5=lookup_widget(button,"aa5");
 gtk_label_set_text(GTK_LABEL(output5),"");
output6=lookup_widget(button,"aa6");
 gtk_label_set_text(GTK_LABEL(output6),"");
output11=lookup_widget(button,"nom");
 gtk_label_set_text(GTK_LABEL(output11),"");
output22=lookup_widget(button,"type");
 gtk_label_set_text(GTK_LABEL(output22),"");
output33=lookup_widget(button,"sexe");
 gtk_label_set_text(GTK_LABEL(output33),"");
output44=lookup_widget(button,"role");
 gtk_label_set_text(GTK_LABEL(output44),"");
output55=lookup_widget(button,"username");
 gtk_label_set_text(GTK_LABEL(output55),"");
output66=lookup_widget(button,"pw");
 gtk_label_set_text(GTK_LABEL(output66),"");

////////////////////////////////////////////////////////////////////////////////
id=lookup_widget(button,"entry_rech");
strcpy(p,gtk_entry_get_text(GTK_ENTRY(id)));
test=cherche_user(p,nom,t,sx,log,pw,r);
if (test==1)
{
output1=lookup_widget(button,"aa1");
 gtk_label_set_text(GTK_LABEL(output1),"nom-->");
output2=lookup_widget(button,"aa2");
 gtk_label_set_text(GTK_LABEL(output2),"type-->");
output3=lookup_widget(button,"aa3");
 gtk_label_set_text(GTK_LABEL(output3),"sexe-->");
output4=lookup_widget(button,"aa4");
 gtk_label_set_text(GTK_LABEL(output4),"role-->");
output5=lookup_widget(button,"aa5");
 gtk_label_set_text(GTK_LABEL(output5),"user_name-->");
output6=lookup_widget(button,"aa6");
 gtk_label_set_text(GTK_LABEL(output6),"pw -->");
output11=lookup_widget(button,"nom");
 gtk_label_set_text(GTK_LABEL(output11),nom);
output22=lookup_widget(button,"type");
 gtk_label_set_text(GTK_LABEL(output22),t);
output33=lookup_widget(button,"sexe");
 gtk_label_set_text(GTK_LABEL(output33),sx);
output44=lookup_widget(button,"role");
 gtk_label_set_text(GTK_LABEL(output44),r);
output55=lookup_widget(button,"username");
 gtk_label_set_text(GTK_LABEL(output55),log);
output66=lookup_widget(button,"pw");
 gtk_label_set_text(GTK_LABEL(output66),pw);
}
else
{
 outputr=lookup_widget(button,"notrecherche");
 gtk_label_set_text(GTK_LABEL(outputr),"n existe pas");

}
}


void on_button_homemodif_clicked            (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *fen_nv,*fen_act;
fen_act=lookup_widget(button,"RECHERCHE");
gtk_widget_destroy(fen_act);
fen_nv=create_ADMIN();
gtk_widget_show(fen_nv);
}





void on_checkbutton_n_toggled               (GtkToggleButton *togglebutton,
                                             gpointer         user_data)
{
tn=1;
}


void on_checkbutton_t_toggled               (GtkToggleButton *togglebutton,
                                             gpointer         user_data)
{
tt=1;
}


void on_checkbutton_s_toggled               (GtkToggleButton *togglebutton,
                                      	     gpointer         user_data)
{
ts=1;
}


void on_checkbutton_r_toggled               (GtkToggleButton *togglebutton,
                                             gpointer         user_data)
{
tr=1;
}


void on_checkbutton_u_toggled               (GtkToggleButton *togglebutton,
                                             gpointer         user_data)
{
tu=1;
}


void on_checkbutton_p_toggled               (GtkToggleButton *togglebutton,
                                             gpointer         user_data)
{
tp=1;
}


void on_radiobutton_modifF_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
testM=1;
}


void on_radiobutton_modifH_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
testM=2;
}


void
on_button_modif_clicked               (GtkWidget       *button,
                                        gpointer         user_data)
{
{
user x;
GtkWidget *idd,*nom,*type,*sexe,*role,*user,*pw ;
int Ri;
idd=lookup_widget(button,"entry_modif");
nom=lookup_widget(button,"entry1");
type=lookup_widget(button,"combobox_modif");
role=lookup_widget(button,"spinbutton_modif");
user=lookup_widget(button,"entry5");
pw=lookup_widget(button,"entry6");
strcpy(x.id,gtk_entry_get_text(GTK_ENTRY(idd)));
strcpy(x.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(x.login,gtk_entry_get_text(GTK_ENTRY(user)));
strcpy(x.pw,gtk_entry_get_text(GTK_ENTRY(pw)));
strcpy(x.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)));
Ri=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(role));
sprintf(x.role,"%d",Ri);
if (testM==1)
	strcpy(x.sexe,"Homme");
else if (testM==2) 
	strcpy(x.sexe,"Femme");

modifier_user(x,tn,tt,ts,tr,tu,tp);

}

}


void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{
choix =1 ; 
}else 
choix =0 ; 
}

//
//
//

void
on_button_modif1_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
 GtkWidget *first, *modifier;
first=lookup_widget(objet,"first");  
gtk_widget_destroy(first);
modifier=create_modifier();
gtk_widget_show(modifier);

}

void
on_button_ajout_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *first, *ajout;
first=lookup_widget(objet,"first");  //first --> ajout
gtk_widget_destroy(first);
ajout=create_ajout();
gtk_widget_show(ajout);
}


void
on_button_sup_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
  GtkWidget *first, *sup;
first=lookup_widget(objet,"first"); 
gtk_widget_destroy(first);
sup=create_sup();
gtk_widget_show(sup);                                    
}                                     


void
on_button_app_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)


{
/*GtkWidget *entry_idmod;
GtkWidget *modifier;
menu m
char ch1;
char txt[30];
char txt1[30];
modifier=lookup_widget(objet,"modifier");
strcpy(ch1,gtk_entry_get_text(GTK_ENTRY(entry_idmod)));

if(choix==0)
strcpy(txt,petit_dejeuner);
else 
if(choix==1)
strcpy(txt,dejeuner);
else
if(choix==2)
strcpy(txt,diner);
if (t[0]==1)
strcat(txt1,"\t lait");
else 
if (t[2]==1)
strcat(txt1,"\t jus");
else 
if (t[3]==1)
strcat(txt1,"\t viande");
else 
if (t[4]==1)
strcat(txt1,"\t céreale");
else 
if (t[5]==1)
strcat(txt1,"\t fruit");
modifier_menu(m);*/

}


void
on_button_suppx_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *entry3;
menu m;
char ch1[20];
entry3=lookup_widget(objet,"entry3");
strcpy(ch1,gtk_entry_get_text(GTK_ENTRY(entry3)));
suprimer_menu(m,ch1);
}


void
on_treeview11_row_activated             (GtkTreeView     *treeview11,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar* id;
gchar* type;
gchar* ingred;
gchar* etat; 
gchar* qut;
//char  ch1[200];
menu m;
GtkTreeModel *model = gtk_tree_view_get_model(treeview11);
if (gtk_tree_model_get_iter(model,&iter,path))
{
gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&id,1,&type,2,&ingred,3,&etat,4,&qut,-1);
strcpy(m.id,id);
strcpy(m.type,type);
strcpy(m.ingred,ingred);
strcpy(m.etat,etat);
strcpy(m.qut,qut);
//suprimer_menu(m,ch1);
affiche_menu(treeview11);
} 

}




void
on_affiche_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *first; 
GtkWidget *treeview1;
first=lookup_widget(objet,"first");
treeview1=lookup_widget(first,"treeview11");
affiche_menu(treeview1);
}


void
on_button_ret_aff_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *first, *affichage;
affichage=lookup_widget(objet,"affichage");
gtk_widget_destroy(affichage);
first=create_first();
gtk_widget_show(first);
}


void
on_ret_ajout_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *first, *ajout;
ajout=lookup_widget(objet,"ajout");  
gtk_widget_destroy(ajout);
first=create_first();
gtk_widget_show(first);
}


void
on_ret_mod_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *first, *modifier;
modifier=lookup_widget(objet,"modifier");  
gtk_widget_destroy(modifier);
first=create_first();
gtk_widget_show(first);
}


void
on_ret_sup_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *first, *sup;
sup=lookup_widget(objet,"sup");  
gtk_widget_destroy(sup);
first=create_first();
gtk_widget_show(first);
}


void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choix1=0;
}


void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choix1=1;
}


void
on_radiobutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choix1=2;
}



void
on_button_appajout_clicked             (GtkWidget      *objet,
                                        gpointer         user_data)
{
menu m;
GtkWidget *input1,*input2,*input3,*input4,*input5;
GtkWidget *ajout;
ajout=lookup_widget(objet,"ajout");
input1=lookup_widget(objet,"input1");
input2=lookup_widget(objet,"input2");
input3=lookup_widget(objet,"input3");
input4=lookup_widget(objet,"input4");
input5=lookup_widget(objet,"input5");
strcpy(m.id,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(m.type,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(m.ingred,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(m.etat,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(m.qut,gtk_entry_get_text(GTK_ENTRY(input5)));
ajout_menu(m);
}


void
on_recherche_clicked                   (GtkWidget        *objet,
                                        gpointer         user_data)
{
char ch1[30];
menu m;
GtkWidget *output1;
GtkWidget *output2;
GtkWidget *output3;
GtkWidget *output4;
output1=lookup_widget(objet,"type");
output2=lookup_widget(objet,"ingred");
output3=lookup_widget(objet,"etat");
output4=lookup_widget(objet,"qut");
GtkWidget *entry_recherche;
entry_recherche=lookup_widget(objet,"entry_recherche");
strcpy(ch1,gtk_entry_get_text(GTK_ENTRY(entry_recherche)));
m=chercher_menu (ch1);

gtk_label_set_text(GTK_LABEL(output1),m.type);
gtk_label_set_text(GTK_LABEL(output2),m.ingred);
gtk_label_set_text(GTK_LABEL(output3),m.etat);
gtk_label_set_text(GTK_LABEL(output4),m.qut);

}


void
on_button1_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_ajou_ch_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget*No,*Pr,*Am,*Ac,*ci,*Nt,*windowsup,*se,*jour,*mois,*annee,*labelnom,*labelprenom,*labelsexe,*labelcin,*labelnt,*labelniveau;
foyer o ; 


int i=0, longueurChaine = 0;
char chaine[] = "a1b2c3d4e5f6g7h8i9j0klmnpqrstuvwxyz";
int b=1;
No = lookup_widget (objet,"entry10");
Pr = lookup_widget (objet,"entry11");
ci = lookup_widget (objet,"entry12");
Am = lookup_widget (objet,"entry14");
Nt = lookup_widget (objet,"entry13");
jour = lookup_widget (objet,"spinbutton2");
mois = lookup_widget (objet,"spinbutton3");
annee = lookup_widget (objet,"spinbutton4");
se = lookup_widget (objet,"combobox6");




strcpy(o.NOM,gtk_entry_get_text(GTK_ENTRY(No)));
strcpy(o.Prenom,gtk_entry_get_text(GTK_ENTRY(Pr)));
strcpy(o.CIN,gtk_entry_get_text(GTK_ENTRY(ci)));
strcpy(o.niveau,gtk_entry_get_text(GTK_ENTRY(Am)));
strcpy(o.chambre,gtk_entry_get_text(GTK_ENTRY(Nt)));
o.dt_ns.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
o.dt_ns.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
o.dt_ns.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
strcpy(o.sexe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(se)));



 
    longueurChaine = strlen(chaine);
 
    srand(time(NULL));
 
    for(i=0; i < 4; i++)
        {
            o.id[i] = chaine[rand()%longueurChaine];
        }
labelnom=lookup_widget(objet,"label69");
labelprenom=lookup_widget(objet,"label72");
labelsexe=lookup_widget(objet,"label76");
labelcin=lookup_widget(objet,"label336");
labelnt=lookup_widget(objet,"label337");
labelniveau=lookup_widget(objet,"label75");




// controle saisie
if(strcmp(o.NOM,"")==0){
		 
          gtk_label_set_text(GTK_LABEL(labelnom),"saisir NOM !");
b=0;
}
else {
		  
          gtk_label_set_text(GTK_LABEL(labelnom),"");
}

if(strcmp(o.Prenom,"")==0){
		  
          gtk_label_set_text(GTK_LABEL(labelprenom),"saisir prénom !");
b=0;
}
else {
		  
          gtk_label_set_text(GTK_LABEL(labelprenom),"");
}


if(strcmp(o.sexe,"")==0){
		  
          gtk_label_set_text(GTK_LABEL(labelsexe),"saisir sexe !");
b=0;
}
else {
		  
          gtk_label_set_text(GTK_LABEL(labelsexe),"");
}

if(strcmp(o.CIN,"")==0){
		  
          gtk_label_set_text(GTK_LABEL(labelcin),"saisir CIN !");
b=0;
}
else {
		  
          gtk_label_set_text(GTK_LABEL(labelcin),"");
}

if((strcmp(o.chambre,"")==0)||(strlen(o.chambre)!=8)){
		  
          gtk_label_set_text(GTK_LABEL(labelnt),"saisir numéro de téléphone !");
b=0;
}
else {
		  
          gtk_label_set_text(GTK_LABEL(labelnt),"");
}


if(strlen(o.chambre)!=8){
		  
          gtk_label_set_text(GTK_LABEL(labelnt),"saisir numéro de téléphone de 8 number !");
b=0;
}
else {
		  
          gtk_label_set_text(GTK_LABEL(labelnt),"");
}



if(strcmp(o.niveau,"")==0){
		  
          gtk_label_set_text(GTK_LABEL(labelniveau),"saisir chambre !");
b=0;
}
else {
		  
          gtk_label_set_text(GTK_LABEL(labelniveau),"");
}
if(b==1){
Ajouter_ch(o);
}

//mise a jour treeview
 GtkWidget* p=lookup_widget(objet,"treeview5");
affi_ch(p,"foyer.txt");


sendmail("Un etudiant a ete ajoute avec succes.");
}


void
on_supp_ch_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{


GtkWidget *dd,*lb;

char idd[20];
FILE *F;
int x=-1;
char NOM[20];
char sexe[20];
char Prenom[20];
char CIN[20];
char id[20];
char jour[20];
char mois[20];
char annee[20];
char chambre[20];
char niveau[20];
lb = lookup_widget (objet,"label332");
dd = lookup_widget (objet,"entry15");
strcpy(idd,gtk_entry_get_text(GTK_ENTRY(dd)));

F = fopen ("foyer.txt", "r");


  if (F!=NULL)
 {
  while (fscanf (F,"%s %s %s %s %s %s %s %s %s %s \n",id,NOM,Prenom,sexe,CIN,chambre,jour,mois,annee,niveau) != EOF)
  {
  
    if (strcmp (idd,id) == 0)
      {
      x=1;
      } 
     } 
    
     fclose (F);
  }

if(x==-1)
{
gtk_label_set_text(GTK_LABEL(lb),"l'id n'existe pas ");
}else
{
    supp_ch(idd);
    gtk_label_set_text(GTK_LABEL(lb),"supprimer avec succes");/* code */
}

//mise a jour treeview
 GtkWidget* p=lookup_widget(objet,"treeview5");
affi_ch(p,"foyer.txt");
}


void
on_rech_ch_clicked                     (GtkWidget       *button,
                                        gpointer         user_data)
{


GtkWidget *dd,*Nm,*Pnom,*cin,*SEXE,*Jour,*Mois,*Num,*Annee,*niveau1,*lb;

char id[20];
char NOM[20];
char Prenom[20];
char sexe[20];
char CIN[20];
char chambre[20];
char jour[20];
char mois[20];
char annee[20];
char niveau[20];
char idd[20];
foyer o ;
int x=-1;
FILE *F;

dd = lookup_widget (button,"entry16");
Nm = lookup_widget(button, "entry17");
Pnom = lookup_widget(button, "entry18");
SEXE = lookup_widget(button, "label355");
cin = lookup_widget (button,"entry19");
Num = lookup_widget(button, "entry20");
Jour = lookup_widget(button, "spinbutton5");
Mois = lookup_widget(button, "spinbutton6");
Annee = lookup_widget(button, "spinbutton7");
niveau1 = lookup_widget(button, "entry21");
lb = lookup_widget(button, "label354");

strcpy(idd,gtk_entry_get_text(GTK_ENTRY(dd)));

F = fopen ("foyer.txt", "r");


  if (F!=NULL)
 {
  while (fscanf (F,"%s %s %s %s %s %s %s %s %s %s\n",id,NOM,Prenom,sexe,CIN,chambre,jour,mois,annee,niveau) != EOF)
  {
  
    if (strcmp (idd,id) == 0)
      {
      x=1;
      } 
     } 
    
     fclose (F);
  }

if(x==-1)
{
gtk_label_set_text(GTK_LABEL(lb),"l'id n'existe pas ");
gtk_entry_set_text(GTK_LABEL(Nm),"");
gtk_entry_set_text(GTK_LABEL(Pnom),"");
gtk_label_set_text(GTK_LABEL(SEXE),"");
gtk_entry_set_text(GTK_LABEL(cin),"");
gtk_entry_set_text(GTK_LABEL(Num),"");
gtk_entry_set_text(GTK_LABEL(niveau1),"");
}else
{
    foyer o = rechercher_foyer(idd);
    gtk_label_set_text(GTK_LABEL(lb),"avec succées");/* code */


gtk_entry_set_text(GTK_LABEL(Nm),o.NOM);
gtk_entry_set_text(GTK_LABEL(Pnom),o.Prenom);
gtk_label_set_text(GTK_LABEL(SEXE),o.sexe);
gtk_entry_set_text(GTK_LABEL(cin),o.CIN);
gtk_entry_set_text(GTK_LABEL(Num),o.chambre);
gtk_entry_set_text(GTK_LABEL(niveau1),o.niveau);
//gtk_spin_button_set_value(GTK_SPIN_BUTTON(Jour),jour);
//gtk_spin_button_set_value(GTK_SPIN_BUTTON(Mois),mois);
//gtk_spin_button_set_value(GTK_SPIN_BUTTON(Annee),annee);

}

}


void
on_modi_ch_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *no,*pr,*ci,*nt,*am,*se,*jour,*mois,*annee,*dd;
foyer o;
char id[20];


dd = lookup_widget (objet_graphique,"entry16");
no = lookup_widget (objet_graphique,"entry17");
pr = lookup_widget (objet_graphique,"entry18");
se = lookup_widget (objet_graphique,"combobox7");
ci = lookup_widget (objet_graphique,"entry19");
nt = lookup_widget (objet_graphique,"entry20");
jour = lookup_widget (objet_graphique,"spinbutton5");
mois = lookup_widget (objet_graphique,"spinbutton6");
annee = lookup_widget (objet_graphique,"spinbutton7");
am = lookup_widget (objet_graphique,"entry21");


strcpy(id,gtk_entry_get_text(GTK_ENTRY(dd)));

strcpy(o.NOM,gtk_entry_get_text(GTK_ENTRY(no)));
strcpy(o.Prenom,gtk_entry_get_text(GTK_ENTRY(pr)));
strcpy(o.sexe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(se)));
strcpy(o.CIN,gtk_entry_get_text(GTK_ENTRY(ci)));
strcpy(o.chambre,gtk_entry_get_text(GTK_ENTRY(nt)));
o.dt_ns.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
o.dt_ns.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
o.dt_ns.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
strcpy(o.niveau,gtk_entry_get_text(GTK_ENTRY(am)));
modi_ch(id,o);

//mise a jour treeview
 GtkWidget* p=lookup_widget(objet_graphique,"treeview5");
affi_ch(p,"foyer.txt");
}


void
on_treeview5_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_actua_ch_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{ 

GtkTreeModel     *model,*labe;
        GtkTreeSelection *selection;
        GtkTreeIter iter;
        GtkWidget* p=lookup_widget(objet_graphique,"treeview5");
	gchar *CIN;
        gchar *NOM;
        gchar *Prenom;
        gchar *niveau;
        gchar *chambre;
        gchar *jour;
	gchar *mois;
	gchar *annee;
	gchar *sexe;


        gchar *id;//gchar* type gtk ==> chaine en c car la fonction gtk_tree_model_get naccepte que gchar*
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))//test sur la ligne selectionnée
        {  gtk_tree_model_get (model,&iter,0,&id,1,&NOM,2,&Prenom,3,&sexe,4,&CIN,5,&chambre,6,&jour,7,&mois,8,&annee,9,&niveau,-1);
 gtk_entry_set_text(GTK_ENTRY(lookup_widget(objet_graphique,"entry16")),id);
 gtk_entry_set_text(GTK_ENTRY(lookup_widget(objet_graphique,"entry17")),NOM);
 gtk_entry_set_text(GTK_ENTRY(lookup_widget(objet_graphique,"entry18")),Prenom);
 gtk_entry_set_text(GTK_ENTRY(lookup_widget(objet_graphique,"entry19")),CIN);
 gtk_entry_set_text(GTK_ENTRY(lookup_widget(objet_graphique,"entry20")),chambre);
 gtk_entry_set_text(GTK_ENTRY(lookup_widget(objet_graphique,"entry21")),niveau);

		//gtk_widget_show(lookup_widget(objet,"modifier_ch"));//afficher le bouton modifier
                gtk_notebook_prev_page(GTK_NOTEBOOK(lookup_widget(objet_graphique,"notebook3")));//redirection vers la page precedente



labe = lookup_widget(objet_graphique, "label355");
gtk_label_set_text(GTK_LABEL(labe),sexe);




         
}
//mise a jour treeview

affi_ch(p,"foyer.txt");
}







void
on_supp_tree_ch_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{  GtkTreeModel     *model;
        GtkTreeSelection *selection;
        GtkTreeIter iter;
        GtkWidget* p=lookup_widget(objet,"treeview5");;
        
        gchar *id;//gchar* type gtk ==> chaine en c car la fonction gtk_tree_model_get naccepte que gchar*
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))//test sur la ligne selectionnée
        {  gtk_tree_model_get (model,&iter,0,&id,-1);
           gtk_list_store_remove(GTK_LIST_STORE(model),&iter);//supprimer la ligne du treeView

            supp_ch( id);// supprimer la ligne du fichier
}

}
int x1;
int tx[2]={0,0};

void
on_radiobutton11_poste_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

 if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
 {x1=1;} 

}


void
on_radiobutton12_poste_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

 if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton))) 
{x1=2;} 


}


void
on_checkbutton14_groupe_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{


 if (gtk_toggle_button_get_active(togglebutton)) 

   {tx[1]=1;}    

}


void
on_checkbutton15_groupe_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

 if (gtk_toggle_button_get_active(togglebutton)) 
  {tx[0]=1;}  

}


void
on_button5_ok__clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *output;
char ch1[200]=" Affecté ";
char ch2[200]=" ";
char ch3[200]=" ";
if (x==1) 
strcpy(ch2,"Bloc Fille ");
 else  
strcpy(ch2,"Bloc Homme ");
 if (tx[0]==1)
 strcat(ch3,"Groupe B "); 
if(tx[1]==1)
 strcat (ch3,"Groupe A ");
strcat(ch3,ch1);
strcat(ch3,ch2);
output = lookup_widget(objet, "label105");

gtk_label_set_text(GTK_LABEL(output),ch3);





}








void
on_buttonINST_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
system("firefox https://www.instagram.com/");
}


void
on_buttonFB_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
system("firefox https://www.facebook.com/");
}


void
on_treeview6_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_button56_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *ty,*nb;


char id[20];
char NOM[20];
char Prenom[20];
char sexe[20];
char CIN[20];
char chambre[20];
char jour[20];
char mois[20];
char annee[20];
char niveau[20];

char niveauComb[20];

ty = lookup_widget(objet_graphique,"entry22");
nb = lookup_widget(objet_graphique, "spinbutton8");

strcpy(niveauComb,gtk_entry_get_text(GTK_ENTRY(ty)));
 FILE* F;


int nb1=0;


F=fopen("foyer.txt","r");
if(F!=NULL)
{
    
while (fscanf (F,"%s %s %s %s %s %s %s %s %s %s \n",id,NOM,Prenom,CIN,niveau,chambre,jour,mois,annee,sexe) != EOF)
    {
      if(strcmp(niveau,niveauComb)==0)
      nb1++;
    }
fclose(F); 
}

gtk_spin_button_set_value(GTK_SPIN_BUTTON(nb),nb1);


}



void
on_button57_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
	  GtkWidget *Gestion_foyer;

Gestion_foyer=lookup_widget(button,"GestionFoyer");
gtk_widget_destroy(Gestion_foyer);

}

void
on_button1111_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkWidget *aj, *dashboard;
dashboard=lookup_widget(objet,"dashboard");
aj=lookup_widget(objet,"aj");
aj=create_aj();
gtk_widget_show(aj);


}


void
on_button2222_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *mod, *dashboard;
dashboard=lookup_widget(objet,"dashboard");
mod=lookup_widget(objet,"mod");
mod=create_mod();
gtk_widget_show(mod);
}


void
on_button3_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeview, *af;
af=lookup_widget(objet,"af");
af=create_af();
gtk_widget_show(af);
treeview=lookup_widget(af,"treeview");
afficher1(treeview,"reclamations.txt");
}


void
on_button4_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *pInfo;
char str[1000], ch[1000]="";
strcpy(ch,plus_reclame("reclamations.txt"));
sprintf(str,"%s",ch);
pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,str);
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
}


void
on_button_mod_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkWidget *mod1, *mod2, *mod3, *pInfo, *mod4, *r1, *r2, *r3, *r4, *r5, *r6;
reclam u;
mod1=lookup_widget(objet,"mod1");
mod2=lookup_widget(objet,"mod2");
mod3=lookup_widget(objet,"mod3");
mod4=lookup_widget(objet,"mod4");
r1=lookup_widget(objet,"r1");
r2=lookup_widget(objet,"r2");
r3=lookup_widget(objet,"r3");
r4=lookup_widget(objet,"r4");
r5=lookup_widget(objet,"r5");
r6=lookup_widget(objet,"r6");
u.id=atoi(gtk_entry_get_text(GTK_ENTRY(mod1)));
strcpy(u.prenom,gtk_entry_get_text(GTK_ENTRY(mod2)));
strcpy(u.nom,gtk_entry_get_text(GTK_ENTRY(mod3)));
strcpy(u.classe,gtk_entry_get_text(GTK_ENTRY(mod4)));
u.service=gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(r1))?0:gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(r2))?1:gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(r3))?2:gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(r4))?3:gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(r5))?4:5;
modifier1(u,"reclamations.txt");
pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Réclamation modifiée avec succès");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}

}


void
on_check_id_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *mod1, *mod2, *mod3, *pInfo, *mod4, *r1, *r2, *r3, *r4, *r5, *r6;
reclam p;
int a=0, id;
FILE *f;
mod1=lookup_widget(objet,"mod1");
mod2=lookup_widget(objet,"mod2");
mod3=lookup_widget(objet,"mod3");
mod4=lookup_widget(objet,"mod4");
r1=lookup_widget(objet,"r1");
r2=lookup_widget(objet,"r2");
r3=lookup_widget(objet,"r3");
r4=lookup_widget(objet,"r4");
r5=lookup_widget(objet,"r5");
r6=lookup_widget(objet,"r6");
id = atoi(gtk_entry_get_text(GTK_ENTRY(mod1)));
f = fopen("reclamations.txt","r");
if(f!=NULL){
while(fscanf(f,"%d %s %s %s %d\n",&(p.id),p.prenom,p.nom,p.classe,&(p.service))!=EOF)
	{
		if(p.id==id){
			a=1;
			break;
                 }
	}
fclose(f);
}
if(a==1){
gtk_entry_set_text(GTK_ENTRY(mod2),p.prenom);
gtk_entry_set_text(GTK_ENTRY(mod3),p.nom);
gtk_entry_set_text(GTK_ENTRY(mod4),p.classe);
p.service==0?gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(r1),TRUE):p.service==1?gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(r2),TRUE):p.service==2?gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(r3),TRUE):p.service==3?gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(r4),TRUE):p.service==4?gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(r5),TRUE):gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(r6),TRUE);
}
else{
pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_ERROR,GTK_BUTTONS_OK,"Réclamation introuvable");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
}
}


void
on_button_af_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeview, *af;
af=lookup_widget(objet,"af");
gtk_widget_destroy(af);
af=lookup_widget(objet,"af");
af=create_af();
gtk_widget_show(af);
treeview=lookup_widget(af,"treeview");
afficher1(treeview,"reclamations.txt");
}


void
on_button_aj_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *aj1, *aj2, *aj3, *aj4, *aj5, *aj6;
reclam u;
aj1=lookup_widget(objet,"aj1");
aj2=lookup_widget(objet,"aj2");
aj3=lookup_widget(objet,"aj3");
aj4=lookup_widget(objet,"aj4");
aj5=lookup_widget(objet,"aj5");
aj6=lookup_widget(objet,"aj6");
u.id=atoi(gtk_entry_get_text(GTK_ENTRY(aj1)));
strcpy(u.prenom,gtk_entry_get_text(GTK_ENTRY(aj2)));
strcpy(u.nom,gtk_entry_get_text(GTK_ENTRY(aj3)));
strcpy(u.classe,gtk_entry_get_text(GTK_ENTRY(aj4)));
u.service=gtk_combo_box_get_active(GTK_COMBO_BOX(aj5));
strcpy(u.desc,gtk_entry_get_text(GTK_ENTRY(aj6)));
ajouter1(u,"reclamations.txt");
}


void
on_treeview_row_activated              (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	GtkTreeIter iter;
	gint id;
	reclam u;
	char str[100];
	GtkWidget *pInfo;
	GtkTreeModel *model=gtk_tree_view_get_model(treeview);
	if(gtk_tree_model_get_iter(model,&iter,path)){
	gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&id,-1);
	u.id=id;
	pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_QUESTION,GTK_BUTTONS_YES_NO,"Voulez-vous vraiment\nsupprimer cette réclamation?");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_YES:
	gtk_widget_destroy(pInfo);
	supprimer1x(u,"reclamations.txt");
	sprintf(str,"%d.txt",u.id);
	remove(str);
	break;
	case GTK_RESPONSE_NO:
	gtk_widget_destroy(pInfo);
	break;
}	
}
}

void
on_treeview1x_row_activated             (GtkTreeView     *treeview,
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
        GtkWidget *p=lookup_widget(gestion_Capteur,"treeview1x");
        GtkTreeSelection *selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
	
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {
                gtk_tree_model_get (model,&iter,0,&ref,1,&type,2,&constructeur,3,&dateAjout,4,&valMax,5,&valMin,6,&etage,7,&bloc,-1);//recuperer les information de la ligne selectionneé

                gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestion_Capteur,"entry2x")),dateAjout);
		gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestion_Capteur,"entry12x")),constructeur);
		gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestion_Capteur,"entry13x")),bloc);
		
                
		gtk_spin_button_set_value (GTK_SPIN_BUTTON(lookup_widget(gestion_Capteur,"spinbutton7x")),valMax);
		gtk_spin_button_set_value (GTK_SPIN_BUTTON(lookup_widget(gestion_Capteur,"spinbutton8x")),valMin);
                gtk_spin_button_set_value (GTK_SPIN_BUTTON(lookup_widget(gestion_Capteur,"spinbutton4x")),etage);
                

                if(strcmp(type,"Temperature")==0) x=0;
                if(strcmp(type,"Debit")==0) x=1;
		if(strcmp(type,"Fumee")==0) x=2;
		if(strcmp(type,"Dechets")==0) x=3;
		if(strcmp(type,"Mouvement")==0) x=4;




                gtk_combo_box_set_active(GTK_COMBO_BOX(lookup_widget(gestion_Capteur,"combobox2x")),x);
		GtkWidget* msg=lookup_widget(gestion_Capteur,"label25x");
                gtk_label_set_text(GTK_LABEL(msg),ref);
		


                gtk_widget_show(lookup_widget(gestion_Capteur,"button7"));//afficher le bouton modifier
        GtkWidget* msg1=lookup_widget(gestion_Capteur,"label27x");
        gtk_widget_hide(msg1);

}



}




int choixx[] = {0,0,0}; 
int choix1x[] = {0,0,0,0};






void
on_catalogue_Acceuil_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_widget_show (acceuil);
 gtk_widget_destroy (catalogue);


        
        
    
}


void
on_button22222_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
/*preparation du treeView*/
GtkWidget *p;
GtkWidget *p1;
FILE*f1=NULL;
capteur c;
gtk_widget_hide (acceuil);
gestion_Capteur = create_gestion_Capteur ();
p=lookup_widget(gestion_Capteur,"treeview1x");
p1=lookup_widget(gestion_Capteur,"treeview3x");
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

labelNom=lookup_widget(gestion_Capteur,"label9x");
labelCombo=lookup_widget(gestion_Capteur,"label115x");
labelExist=lookup_widget(gestion_Capteur,"label8x");
labelsuccess=lookup_widget(gestion_Capteur,"label10x");
combobox=lookup_widget(gestion_Capteur,"combobox1x");
cal1=lookup_widget(gestion_Capteur,"calendar1x");
           gtk_widget_hide (labelsuccess);

strcpy(c.ref,gtk_entry_get_text(GTK_ENTRY(lookup_widget(gestion_Capteur,"entry1x"))));


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

if (choix1x[0]==1)
strcpy(c.constructeur,"Hitech");
else if (choix1x[1]==1)
strcpy(c.constructeur,"ABB Automation");
else if (choix1x[2]==1)
strcpy(c.constructeur,"NEXT");
else if (choix1x[3]==1)
strcpy(c.constructeur,"TOMRA");

if (choixx[0]==1)
strcpy(c.bloc,"A");
else if (choixx[1]==1)
strcpy(c.bloc,"B");
else if (choixx[2]==1)
strcpy(c.bloc,"C");


c.valMax =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(gestion_Capteur,"spinbutton5x")));
c.valMin =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(gestion_Capteur,"spinbutton6x")));
c.etage =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(gestion_Capteur,"spinbutton2x")));
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
p=lookup_widget(gestion_Capteur,"treeview1x");
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
        label=lookup_widget(gestion_Capteur,"label27x");
        p=lookup_widget(gestion_Capteur,"treeview1x");
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
        strcpy(c.ref,gtk_label_get_text(GTK_LABEL(lookup_widget(gestion_Capteur,"label25x"))));
        strcpy(c.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(lookup_widget(gestion_Capteur,"combobox2x"))));
        strcpy(c.dateAjout,gtk_entry_get_text(GTK_ENTRY(lookup_widget(gestion_Capteur,"entry2x"))));
	strcpy(c.constructeur,gtk_entry_get_text(GTK_ENTRY(lookup_widget(gestion_Capteur,"entry12x"))));
	strcpy(c.bloc,gtk_entry_get_text(GTK_ENTRY(lookup_widget(gestion_Capteur,"entry13x"))));
	
	c.valMax =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(gestion_Capteur,"spinbutton7x")));
	c.valMin =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(gestion_Capteur,"spinbutton8x")));
        c.etage =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(gestion_Capteur,"spinbutton4x")));

        supp(c.ref);
        ajout(c);
        Capteurtree(lookup_widget(gestion_Capteur,"treeview1x"),"capteurs.txt");
        GtkWidget* msg=lookup_widget(gestion_Capteur,"label26x");
        gtk_widget_show(msg);

}


void
on_button33333_clicked                     (GtkButton       *button,
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
entry=lookup_widget(gestion_Capteur,"entry7x");
labelType=lookup_widget(gestion_Capteur,"label6x4");
p1=lookup_widget(gestion_Capteur,"treeview3x");

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
nbResultat=lookup_widget(gestion_Capteur,"label66x");
message=lookup_widget(gestion_Capteur,"label65x");
gtk_label_set_text(GTK_LABEL(nbResultat),chnb);//set_text n'accepte que chaine de caractere 

gtk_widget_show (nbResultat);
gtk_widget_show (message);




}

}

 // bouton radio

void
on_radiobutton2x_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choix1x[1] = 1;
else
choix1x[1] = 0;
}


void
on_radiobutton1x_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choix1x[0] = 1;
else
choix1x[0] = 0;
}


void
on_radiobutton4x_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choix1x[3] = 1;
else
choix1x[3] = 0;
}


void
on_radiobutton3x_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choix1x[2] = 1;
else
choix1x[2] = 0;
}
// case a cocher

void
on_checkbutton1x_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choixx[0] = 1;
else
choixx[0] = 0;
}
  

void
on_checkbutton2x_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choixx[1] = 1;
else
choixx[1] = 0;
}


void
on_checkbutton3x_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choixx[2] = 1;
else
choixx[2] = 0;
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
p2=lookup_widget(etages_contenant_des_pannes,"treeview8x");

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
p4=lookup_widget(liste_des_alarmes,"treeview9x");

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
p3=lookup_widget(capteurs_defectueux,"treeview7x");

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

void
on_button2223_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
window=create_GestionFoyer();
gtk_widget_show(window);

}

void
on_button2224_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
window=create_dashboard();
gtk_widget_show(window);
}

void
on_button2225_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
window=create_acceuil();
gtk_widget_show(window);
}

void
on_button2226_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
window=create_LOGIN();
gtk_widget_show(window);
}

void
on_button2227_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
window=create_first();
gtk_widget_show(window);
}

void
on_button2228_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
window=create_afiicher_st();
gtk_widget_show(window);
}


produit o;
char tyy[20]="";
char tyy1[20]="";
int x1d=0;int x2=0;
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
GtkWidget *Mnom_st;
Mnom_st = lookup_widget (modifier_st ,"Mnom_st");
GtkWidget *combobox2_st;
combobox2_st = lookup_widget (modifier_st ,"combobox2_st");
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
erreur_categ1=lookup_widget(ajouter_st,"erreur_categ1");
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
strcat(y,a);strcat(y,"-");strcat(y,b);strcat(y,"-");strcat(y,c);

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

 if (x1d==0)
{
gtk_widget_show(erreur_conf1);
}


 if(o==0 && x1d==1){
ajouter_produit(p);



gtk_widget_destroy(ajouter_st);
GtkWidget *afiicher_st;
afiicher_st = create_afiicher_st ();
  gtk_widget_show (afiicher_st);
x1d=0;


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
GtkWidget *supprimer_stt;
supprimer_stt=lookup_widget(button,"supprimer_st");
gtk_widget_destroy(supprimer_stt);
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

GtkWidget *erreur_nom2,*erreur_ref2,*erreur_conf2;

erreur_nom2=lookup_widget(modifier_st,"erreur_nom2");
erreur_ref2=lookup_widget(modifier_st,"erreur_ref2");
erreur_conf2=lookup_widget(modifier_st,"erreur_conf2");

 
gtk_widget_hide(erreur_nom2);  
gtk_widget_hide(erreur_ref2);  
gtk_widget_hide(erreur_conf2);

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
strcat(y,a);strcat(y,"-");strcat(y,b);strcat(y,"-");strcat(y,c);

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


 if (x1d==0)
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
x1d=1;
}


void
on_checkbutton11_st_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
x2=1;
}



void
on_button_create_acc_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;

window=create_window1();
 
gtk_widget_show(window);

}


void
on_button_ajoutcc_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *login,*pw,*nom,*id,*Role,*type;
user u;
int role ;

nom=lookup_widget (button, "entry_nomcc");
id = lookup_widget (button, "entry_idcc");
login = lookup_widget (button, "entry_usercc");
pw = lookup_widget (button, "entry_mdpcc");
type=lookup_widget(button,"combobox_typcc");
Role=lookup_widget (button,"spinbutton_cc");
strcpy(u.login,gtk_entry_get_text(GTK_ENTRY(login)));
strcpy(u.pw,gtk_entry_get_text(GTK_ENTRY(pw)));
strcpy(u.id,gtk_entry_get_text(GTK_ENTRY(id)));
strcpy(u.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
role=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Role));
sprintf(u.role,"%d",role);
strcpy(u.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)));
if (s1==1)
	strcpy(u.sexe,"Homme");
else if (s1==2) 
	strcpy(u.sexe,"Femme");
if (choix == 1 ) 
{
ajouter_USER(u);

} 
}




void
on_checkbutton_cc_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{
choix =1 ; 
}else 
choix =0 ;
}


void
on_radiobutton4_cc_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
s1=1;
}


void
on_radiobutton5_ccf_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
s1=1;
}


void
on_button_home_cc_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
GtkWidget *window1; 
window=create_LOGIN();
window1=create_window1();
gtk_widget_show(window);
gtk_widget_destroy(window1);

}

