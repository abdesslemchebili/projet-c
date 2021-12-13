#include <gtk/gtk.h>
typedef struct {
char type_ingred[50]; //liquide ou solide, viande ou vegetaux etc
char Nomb_ingred[10];
char date_valid[50];
char date_ajout[50];
char refer[10];
}stock;

int verif(char log[],char pw[]);
void ajouter_utilisateur(char login1[],char passw[],char nom[],char prenom[],int role);


void ajouter(stock ingred);
void modifier(char refer,stock p);
void supprimer(stock ingred);
void supprimer1(char id[]);

void afficher(GtkWidget *liste);
char chercher(char refer,stock ingred);
void rupture(stock ingred);
stock XX(char ref[]);






