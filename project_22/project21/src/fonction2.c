#include <stdio.h>
#include "fonction2.h"
#include <string.h>
#include <gtk/gtk.h>
enum
{
TYPE,
DATEV,
DATEA,
NOMBRE,
REF,
COLUMNS
};
int verif(char log[],char pw[])
{ 
int trouve=-1;
FILE *f=NULL;
char ch1[20];
char ch2[20];
f=fopen("utilisateur.txt","r");
if(f!=NULL)
{
while(fscanf(f,"%s %s",ch1,ch2)!=EOF)
{
if((strcmp(ch1,log)==0) && (strcmp(ch2,pw)==0))
trouve=1;
}
fclose(f);
}
return (trouve);
}

void ajouter(stock ingred)
{ 
FILE *f;
f=fopen("stock.txt","a+");
if (f!=NULL)
{

fprintf(f,"%s %s %s %s %s \n",ingred.type_ingred,ingred.date_ajout,ingred.date_valid,ingred.refer,ingred.Nomb_ingred);
fclose(f);
}

}




char chercher(char ref,stock ingred)
{ FILE *f;
 char type_ingred[50]; 
char Nomb_ingred[10];
char date_valid[50];
char date_ajout[50];
char refer[10];
char Nul="reference invalide";
char x[20];
int tr=0;
  
  f=fopen("stock.txt","r");

  if(f!=NULL)
            {while(fscanf(f,"%s %s %s %s %s",type_ingred,date_ajout,date_valid,refer,Nomb_ingred)!=EOF);
	     {
if (strcmp(ingred.type_ingred,type_ingred)!=0 || strcmp(ingred.date_ajout,date_ajout)!=0 || strcmp(ingred.date_valid,date_valid)!=0 || strcmp(ingred.refer,ref)!=0 || strcmp(Nomb_ingred,Nomb_ingred)!=0)
	{

strcpy(x,ingred.refer);

tr=1;
}
else
strcpy(x,Nul);

  
            }

  }
fclose(f);

return x;



}
void modifier(char refer,stock p)
{

FILE *l=fopen("stock.txt","r");
FILE *t=fopen("tamp.txt","a+");
stock s;
if (l!=NULL) 
	{ 
	while(fscanf(l,"%s %s %s %s %s",s.type_ingred,s.date_ajout,s.date_valid,s.refer,s.Nomb_ingred)!=EOF)
		{
		if (strcmp(refer,s.refer)!=0)
		fprintf(t,"%s %s %s %s %s \n",s.type_ingred,s.date_ajout,s.date_valid,s.refer,s.Nomb_ingred);
		else 
		fprintf(t,"%s %s %s %s %s \n",p.type_ingred,p.date_ajout,p.date_valid,p.refer,p.Nomb_ingred);
		}
	}
fclose(l);
fclose(t);
remove("stock.txt");
rename("tamp.txt","stock.txt");
}


 void supprimer(stock ingred)
{ char type_ingred[50]; 
char Nomb_ingred[10];
char date_valid[50];
char date_ajout[50];
char refer[10];
FILE *f, *l;

f=fopen("stock.txt","r");
l=fopen("tmp.txt","w");
if(f==NULL || l==NULL )
{
return;
}
else
{
while(fscanf(f,"%s %s %s %s %s",type_ingred,date_ajout,date_valid,refer,Nomb_ingred)!=EOF)
{ 
if (strcmp(ingred.type_ingred,type_ingred)!=0 || strcmp(ingred.date_ajout,date_ajout)!=0 || strcmp(ingred.date_valid,date_valid)!=0 || strcmp(ingred.refer,refer)!=0 || strcmp(ingred.Nomb_ingred,Nomb_ingred)!=0)
fprintf(l,"%s %s %s %s %s \n",type_ingred,date_ajout,date_valid,refer,Nomb_ingred);

}
fclose(f);
fclose(l);
remove("stock.txt");
rename("tmp.txt","stock.txt");

}
}

 void supprimer1(char id[])
{ char type_ingred[50]; 
char Nomb_ingred[10];
char date_valid[50];
char date_ajout[50];
char refer[10];
FILE *f, *l;

f=fopen("stock.txt","r");
l=fopen("tmp.txt","w");
if(f==NULL || l==NULL )
{
return;
}
else
{
while(fscanf(f,"%s %s %s %s %s",type_ingred,date_ajout,date_valid,refer,Nomb_ingred)!=EOF)
{ 
if ( strcmp(id,refer)!=0)
fprintf(l,"%s %s %s %s %s \n",type_ingred,date_ajout,date_valid,refer,Nomb_ingred);

}
fclose(f);
fclose(l);
remove("stock.txt");
rename("tmp.txt","stock.txt");

}
}

void afficher(GtkWidget *liste)
{ 
	GtkCellRenderer *renderer;

	GtkTreeViewColumn *column;

	GtkTreeIter iter;
	        
	GtkListStore *store;

	char type_ingred[50]; 
	char Nomb_ingred[10];
	char date_valid[50];
	char date_ajout[50];
	char refer[10];
	store=NULL;

	FILE *f;

	store=gtk_tree_view_get_model(liste);
	if(store == NULL)
	{
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" type_ingred",renderer,"text",TYPE,NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" date_valid",renderer,"text",DATEV,NULL);	
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes(" date_ajout",renderer,"text",DATEA,NULL);	
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes(" Nomb_ingred",renderer,"text",NOMBRE,NULL);	
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes(" refer",renderer,"text",REF,NULL);	
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
f=fopen("stock.txt","r");
if(f==NULL)
{
return;
}
else
{
f=fopen("stock.txt","a+");
do
{
gtk_list_store_append (store, &iter);
gtk_list_store_set (store, &iter,TYPE,type_ingred,DATEV,date_valid,DATEA,date_ajout,NOMBRE,Nomb_ingred,REF,refer,-1); 
}while(fscanf(f,"%s %s %s %s %s\n",type_ingred,date_ajout,date_valid,refer,Nomb_ingred)!=EOF);
fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
g_object_unref (store);
}
}
}

stock XX(char ref[])
{
stock p,s ;
FILE* f=fopen ("stock.txt" , "r");
if (f!=NULL) 
	{ 
	while (fscanf(f,"%s %s %s %s %s \n",p.type_ingred,p.date_ajout,p.date_valid,p.refer,p.Nomb_ingred)!=EOF)
		{ 
		if (strcmp(ref,p.refer)==0)
			{
			s=p;		
			}
		}
	}
fclose(f);
return s;
}
