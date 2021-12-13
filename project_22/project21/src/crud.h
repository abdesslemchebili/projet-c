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

void ajout( capteur c);
int exist(char*ref);
void supp(char*ref);



/************************/

