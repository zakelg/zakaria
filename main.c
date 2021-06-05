#include <stdio.h>
#include <stdlib.h>


struct date
{
 int   jour,mois,annee;
};


typedef struct Voiture
{  int idVoiture;
char marque[15];
char nomVoiture[15];
char couleur[7];
int nbplaces;
int prixJour;
char EnLocation[4];
struct voiture *suivant;
 } voiture;
 typedef voiture *listev;

 typedef struct contratLocation
 {  float numContrat;
   int idVoiture;
   int idClient;
   struct date debut;
   struct   date fin;
    int cout;
} contrat;

 typedef struct Client
 {
    int idClient;
    char nom[20];
    char prenom[20];
    int cin;
    char adresse[15];
    int telephone;
}client;

listev ajoutvoitur()
{
    listev nc;
    voiture v,*p;
    nc=(listev)malloc(sizeof(voiture));
    printf("------ajout voiture-------\n");

    printf("enrer id voitur \n");
    scanf("%d",&nc->idVoiture);

     printf("enrer la marque de voitur \n");
    scanf("%s",&nc->marque);

     printf("enrer le nom de voitur \n");
    scanf("%s",&nc->nomVoiture);

     printf("enrer la color de voitur \n");
    scanf("%s",&nc->couleur);

     printf("enrer le nbr de place \n");
    scanf("%d",&nc->nbplaces);

     printf("enrer le prix jour \n");
    scanf("%d",&nc->prixJour);

     printf("en location \n");
    scanf("%s",&nc->EnLocation);

    nc->suivant=NULL;


FILE *ptr;
p=nc;
ptr=fopen("voiture.txt","wb+");
if(ptr==NULL){

    printf("impossible ovrire le fichier\n");

}
else
{
    strcpy(v.idVoiture,p->idVoiture);
    strcpy(v.marque,p->marque);
    strcpy(v.nomVoiture,p->nomVoiture);
    strcpy(v.couleur,p->couleur);
    strcpy(v.nbplaces,p->nbplaces);
    strcpy(v.prixJour,p->prixJour);
    strcpy(v.EnLocation,p->EnLocation);
    fwrite(&v,sizeof(voiture),100,ptr);
    p->suivant;
     }
 fclose("ptr");

 return(1);
}
void listevoiture()
{
FILE *za;

za=fopen("voiture.txt",)
    printf("------lest de voitur-------\n");

    printf(" id voitur \n");
    printf("%d",v->idVoiture);

     printf("la marque de voitur \n");
     puts(p2->marque);

     printf(" le nom de voitur \n");
    puts(p2->nomVoiture);

     printf("la color de voitur \n");
    puts(p2->couleur);

     printf(" le nbr de place \n");
    puts(p2->nbplaces);

     printf(" le prix jour \n");
    puts(p2->prixJour);

     printf("en location \n");
    puts(p2->EnLocation);

    p2=p2->suivant;
getch();}



int main()
{
printf("fcsdcvsdvsvsvfv\n");
ajoutvoitur();
listevoiture();
return 0;
}
