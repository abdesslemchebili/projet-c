#include <gtk/gtk.h>

typedef struct capteur capteur;
struct capteur{
char ref[30];
char type[30];
char constructeur[30];
char dateAjout[30];
char bloc[30];
int valMax;
int valMin;
int valInit;
int etage;
};

typedef struct debit debit;
struct debit{
int jour;
int heure;
int numCapteu;
float valeurDebit;
};


typedef struct temp temp;
struct temp{
int jour;
int heure;
int numCapteu;
float valeurTemp;
};

typedef struct FUMEE FUMEE;
struct FUMEE{
int jour;
int heure;
int numCapteu;
int etatF;
};

int i,j,w,v,z;

GtkWidget *acceuil;
  GtkWidget *gestion_Capteur;
  GtkWidget *catalogue;
GtkWidget *etages_contenant_des_pannes;
GtkWidget *capteurs_defectueux;
GtkWidget *liste_des_alarmes;





void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_AcceuiCatalogue_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_catalogue_Acceuil_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_button2_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_AjouterCapteur_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_SupprimerCapteur_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_ModifierCapteur_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_button3_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_chercherCapteur_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton4_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button_pannes_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_alarmes_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_capteurs_defectueux_clicked  (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_capteurDef_acceuil_clicked   (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_etagePanne_acceuil_clicked   (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_alarmes_acceuil_clicked      (GtkButton       *button,
                                        gpointer         user_data);
