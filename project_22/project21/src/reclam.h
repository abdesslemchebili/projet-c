#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>

typedef struct reclam
{
    int id;
    char prenom[20];
    char nom[20];
    char classe[10];
    int service;
    char desc[500];
}reclam;


void ajouter1(reclam u, char *fname);
void supprimer1x(reclam u, char *fname);
void modifier1(reclam u, char *fname);
void afficher1(GtkWidget *liste, char *fname);
char* plus_reclame(char *fname);

