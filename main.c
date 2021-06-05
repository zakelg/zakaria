#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h>



typedef struct datac
{
	char nom[20];
	 char prenom[20];
	 char adresse[20];
	 long tel;
	 long cin;
	 long idclien;
}datac;
typedef struct client
{
	datac clients;
	struct client *suivant;
}client;
typedef client *listec;


typedef struct datav
{
	 char marque[20];
	 char color[20];
	 char type[20];
	 long idvoiture;
	 long prix;
	 int enlocation;
}datav;
 typedef struct voitures
{
	datav voitures;
	struct voiture *suivant;
}voitures;
typedef voitures *listev;







void affiche_client(listec l)
{
	listec p;
	p=l;
	int i;
	i=1;
while(p!=NULL)
{
printf("\n\n");
printf("\t\tClient %d \n",i);
printf("\n\tNOM:                              ");
puts(p->clients.nom);
printf("\n\tPRENOM:                           ");
puts(p->clients.prenom);
printf("\n\tTEL:                              %ld\n",p->clients.tel);
printf("\n\tNum Carte Identite:               %ld\n",p->clients.cin);
printf("\n\t id client:        %ld\n",p->clients.idclien);
printf("\n\tAdresse:                          ");
puts(p->clients.adresse);
printf("--------------------------------------------------------------");
p=p->suivant;
i++;
getch();
}

}
void afficher_un_client(listec l,int x)
{
	listec p;
	int i=1;
	p=l;


	while (i<x)
	{
		p=p->suivant;
	   i++;
	}

	printf("\n\tNom:                                  ");
	puts(p->clients.nom);

	printf("\n\tPrenom:                               ");
	puts(p->clients.prenom);

printf("\n\tNum Carte Identite:                  %ld\n",p->clients.cin);
printf("\n\tTEL:                                 %ld\n",p->clients.tel);

printf("\n\tNumero Permis de conduire:           %ld\n",p->clients.idclien);

	printf("\n\tAdresse:                            ");
	puts(p->clients.adresse);




}
void affiche_voiture(listev l)
{
	listev p2;
	p2=l;
while(p2!=NULL)
{
printf("\n\n");

printf("\tMARQUE:                                  ");
puts(p2->voitures.marque);
printf("\n");
printf("\tCOULEURS:                                ");
puts(p2->voitures.color);
printf("\n");

printf("\tCode Agence:                          %ld\n",p2->voitures.idvoiture);
printf("\n");

printf("\tTYPE:                                 ");
puts(p2->voitures.type);
printf("\n\tKilometage:                         %ld\n",p2->voitures.prix);
if(p2->voitures.enlocation==1)
		printf("\n\tEtat voiture:                    Disponible\n");
	else
		printf("\n\tEtat voiture:                  Indisponible\n");
	printf("--------------------------------------------------------------");
p2=p2->suivant;
getch();}


}

			    listec charger_client(listec l)
{
	FILE *fichier_client;
	client c;

	client *nc,*p;
	p=l;

	fichier_client=fopen("tab_client.txt","r");
	if(fichier_client==NULL)
		{
		fichier_client=fopen("tab_client.txt","wb+");
	}
	else
	{


		while(fread(&c,sizeof(client),1,fichier_client))
		{


				nc=(listec)malloc(sizeof(client));
				strcpy(nc->clients.nom,c.clients.nom);
				strcpy(nc->clients.prenom,c.clients.prenom);
				nc->clients.tel=c.clients.tel;
				nc->clients.cin=c.clients.cin;
				nc->clients.idclien=c.clients.idclien;
				strcpy(nc->clients.adresse,c.clients.adresse);
				nc->suivant=NULL;

				if(l==NULL)
				{
					l=nc;
					p=nc;
				}
				else
				{
					p->suivant=nc;
					p=nc;
				}

	}}

	fclose(fichier_client);
	return(l);
}


listev charger_voiture(listev l)
{
	FILE *fichier_voiture;
	voitures v;

	voitures *nc,*p;
	nc=l;

	fichier_voiture=fopen("tab_voiture.txt","r");
if(fichier_voiture==NULL)
		{
		fichier_voiture=fopen("tab_voiture.txt","wb+");
		fclose(fichier_voiture);
	}
	else
	{

				while(fread(&v,sizeof(voitures),1,fichier_voiture))
		{
				nc=(listev)malloc(sizeof(voitures));
				strcpy(nc->voitures.marque,v.voitures.marque);
			    strcpy(nc->voitures.type,v.voitures.type);
			    nc->voitures.enlocation=v.voitures.enlocation;
			    nc->voitures.idvoiture=v.voitures.idvoiture;
			    nc->voitures.prix=v.voitures.prix;
			    strcpy(nc->voitures.color,v.voitures.color);
				nc->suivant=NULL;

				if(l==NULL)

					l=nc;


				else
				{
				p=l;

				while(p->suivant!=NULL)
			p=p->suivant;

		p->suivant=nc;
	}



	}}
	fclose(fichier_voiture);
	return(l);
}


void enregistrer_client(listec l)
{
FILE *fichier_client;
	client c,*p;

	p=l;
	fichier_client=fopen("tab_client.txt","wb+");//ouverture du fichier en mode lecture/้criture (destruction ancienne version si elle existe)

	if(fichier_client==NULL)//echec en cas de ne pas trouver le fichier
		printf("IMPOSSIBLE D'OUVRIR LE FICHIER\n");
	else
	{

		while(p!=NULL)
		{
			strcpy(c.clients.nom,p->clients.nom);
			strcpy(c.clients.prenom,p->clients.prenom);
			c.clients.tel=p->clients.tel;
			c.clients.cin=p->clients.cin;
			c.clients.idclien=p->clients.idclien;
			strcpy(c.clients.adresse,p->clients.adresse);
			fwrite(&c,sizeof(client),1,fichier_client);//ecrire dans le fichier toute la structure
			p=p->suivant;

		}
	}
	fclose(fichier_client);
}
void enregistrer_voiture(listev l)
{
FILE *fichier_voiture;
	voitures v,*p;

	p=l;
	fichier_voiture=fopen("tab_voiture.txt","wb+");//ouverture du fichier en mode lecture/้criture (destruction ancienne version si elle existe)
                                                   /*lecture/้criture (destruction ancienne version si elle existe)*/
	if(fichier_voiture==NULL)
		printf("IMPOSSIBLE D'OUVRIR LE FICHIER\n");
	else
	{

		while(p!=NULL)
		{
			strcpy(v.voitures.marque,p->voitures.marque);
			strcpy(v.voitures.type,p->voitures.type);
			v.voitures.enlocation=p->voitures.enlocation;
			v.voitures.idvoiture=p->voitures.idvoiture;
			v.voitures.prix=p->voitures.prix;
			strcpy(v.voitures.color,p->voitures.color);
			fwrite(&v,sizeof(voitures),1,fichier_voiture);
			p=p->suivant;

		}
	}
	fclose(fichier_voiture);
}

	int rechercher_client(listec l,long x);
int rechercher_voiture(listev l,long x);


int trouvev=0;
int trouvec=0;
int i=1;
listec p;
listev p1;






void afficher_un_client(listec l,int x);
int rechercher_client(listec l,long x);
listec modifier_client(listec l)
{   long ci;
int trouver=1,i=1,t=0;char d;
listec p;
p=l;
printf("\n                 Modification                               \n");
    printf("**************************************************************");

	printf("\ndonner le numero de C.I.N du Client a modifier:\t");
		scanf("%ld",&ci);
	trouver=rechercher_client(l,ci);
	if(trouver==-1)
	{
		printf("\n\n\t\tERROR Client inexistant\a");
		getchar();
		//getchar();
	}
	else
	{
		printf("\n\tInforamtion actuelle :\n");
		printf("\n\t-----------------------\n");
		afficher_un_client(l,trouver);
		printf("\n\tLes nouvelles informations :\n");
		printf("\n\t-----------------------------\n");

		while (i<trouver)
		{
			p=p->suivant;
			i++;
		}

		if(p!=NULL)
		{
			while((p!=NULL)&&(t==0))
			{
				if(p->clients.cin==ci)
				{
					printf("\n\n\tDonner le nom du client                       : ");
					scanf("%s",&p->clients.nom);

					printf("\n\n\tDonner le prenom du client                    : ");
					scanf("%s",&p->clients.prenom);

					/*printf("\n\n\tDonner le numero du carte d'identite du client: ");
					scanf("%ld",&p->clients.nci);
					getchar();*/
					//p->clients.nci=

					printf("\n\n\tNumero Telephone                              : ");
	                scanf("%ld",&p->clients.tel);

				//	printf("\n\n\tDonner le numero du permis du client          : ");
				//	scanf("%ld",&p->clients.npc);
gets(&d);
					printf("\n\n\tDonner l'adresse du client                    : ");
					gets(p->clients.adresse);t=1;

				}

				p=p->suivant;
			}
		}

	}
	return(l);
}
void afficher_une_voiture(listev l,int x);
int rechercher_voiture(listev l,long x);

listev modifier_voiture(listev l)
{   long mat;
int trouver=1,i=1,t=0;
listev p;
p=l;
printf("\n                 Modification                               \n");
    printf("**************************************************************");
	printf("\ndonner le Code Agence de la voiture a modifier:\t");
		scanf("%ld",&mat);
	trouver=rechercher_voiture(l,mat);
	if(trouver==-1)
	{
		printf("\n\tERROR Voiture inexistante");
		getchar();

	}
	else
	{
		printf("\n\tInforamtion actuelle :\n");
		printf("\n\t-----------------------\n");
		printf("\n\tLes nouvelles informations :\n");
		printf("\n\t-----------------------------\n");

		while (i<trouver)
		{
			p=p->suivant;
			i++;
		}

		if(p!=NULL)
		{
			while((p!=NULL)&&(t==0))
			{
				if(p->voitures.prix==mat)
				{
	printf("\n\n\tentrer la marque:      ");
	scanf("%s",&p->voitures.marque);
	printf("\n\n\tentrer la couleur:     ");
	scanf("%s",&p->voitures.color);
	printf("\n\n\tCode Agence:           ");
	scanf("%ld",&p->voitures.prix);
	printf("\n\n\tTYPE:                  ");
	scanf("%s",&p->voitures.type);
	printf("\n\n\tKILOMETRAGE:           ");
	scanf("%ld",&p->voitures.idvoiture);
					t=1;

				}

				p=p->suivant;
			}
		}

	}
	return(l);
}
int rechercher_client(listec l,long x)
{
	client *p;//definir pointeur sur cellule client
	p=l;
	int pos=1;//pos ce definit comme un compteur

	if(p!=NULL)
	{
		while((p!=NULL))
		{
			if(p->clients.cin==x)
				return(pos);
			pos++;//incrementer pour definir le nbre de deplacement
			p=p->suivant;//deplacement du pointeur
		}
	}
	return(-1);//en cas d'echec de la recheche
}

int rechercher_voiture(listev l,long x)
{
	voitures *p;
	p=l;
	int pos=1;//compteur

	if(p!=NULL)
	{
		while((p!=NULL))
		{
			if(p->voitures.prix==x)
				return(pos);//retourne la position exacte de la cellule recherch้e
			pos++;
			p=p->suivant;//parcours de la liste
		}
	}
	return(-1);//en cas d'erreur
}


int rechercher_voiture(listev l,long x);





int rechercher_voiture(listev l,long x);
listev saisiev(listev l)
{ listev nc,p;char f;
int h;
long b;
nc=(listev)malloc(sizeof(voitures));//allocation de la nouvelle cellule
printf("\n                 Ajout Voiture                                  \n");
    printf("**************************************************************");
	printf("\n\n entrer la marque:       ");
	scanf("%s",&nc->voitures.marque);
	gets(&f);
	printf("\n\n entrer la couleur:      ");
	gets(nc->voitures.color);
	do//boule pour savoir si le code agence est deja utilise ou non
	{//la saise ne peut ontinuer que si le ode de lq voite n'est pas utilis้e
	printf("\n\n Code Agence:            ");
	scanf("%ld",&b);
	h=rechercher_voiture(l,b);
	if(h!=-1)
		printf("\n\tCode Agence existe deja");
	}while(h!=-1);
	nc->voitures.prix=b;


	printf("\n\n TYPE:                   ");
	scanf("%s",&nc->voitures.type);
	printf("\n\n KILOMETRAGE:            ");
	scanf("%ld",&nc->voitures.idvoiture);
	nc->voitures.enlocation=1;


nc->suivant=NULL;

	if(l==NULL)//si la liste est vide
		l=nc;//la tete de la liste recoit la nouvelle cellule
	else
	{
		p=l;

		while(p->suivant!=NULL)  /* faire le parcour de la liste*/
			p=p->suivant;        /*  le pointeur p se deplace et */
		                           /*  s'arrete avant la fin de la liste)*/

		p->suivant=nc;
	}
	return(l);
}



	listec saisiec(listec l);
listev saisiev(listev l);

void affiche_client(listec l);
void affiche_voiture(listev l);

int rechercher_client(listec l,long x);
int rechercher_voiture(listev l,long x);


void afficher_un_client(listec l,int x);
void afficher_une_voiture(listev l,int x);



//modification
listev modifier_voiture(listev l);
listec modifier_client(listec l);

//enregistrement dans des fihiers
void enregistrer_client(listec l);
void enregistrer_voiture(listev l);

//chargement a partir des fichiers
listec charger_client(listec l);
listev charger_voiture(listev l);

listev suuprimer_voiture(listev l);//appel a la fonction pour supprimer la voiture




//--------------------------------------------------------------------------
void main()
{   int w,a,s,trouve;
    char save;
    long c;

	listec liste_client;
	listev liste_voiture;
	liste_client=NULL;
    liste_voiture=NULL;
	liste_client=charger_client(liste_client);
	liste_voiture=charger_voiture(liste_voiture);




        printf("                       developpee par:EL GHALI ZAKARIA // FSA AGADIR                      \n\n\n");



	printf("\n\n");
	printf("\n\n\n\t\t\t GESTION LOCATION DE VOITURE V2.1\n\n");


		printf("      ษอออออออออออออออออออออออออMENUอออออออออออออออออออออออออออออป\n");
		printf("      บ   -----------------------------------------------------  บ\n");
		printf("      บ  (  | 1 | location) บ\n");
        printf("      บ                                                          บ\n");
        printf("      บ  (  | 2 | gestion voiture                            ) บ\n");
        printf("      บ                                                          บ\n");
        printf("      บ  (  | 3 | gestion  Clients                         ) บ\n");
        printf("      บ                                                          บ\n");
        printf("      บ  (  | 4 | quitter                       ) บ\n");

		printf("      ษอออออออออออออออออออออออออMENUอออออออออออออออออออออออออออออป\n");
      printf("enter votre chois\n");
      scanf("%d",&a);
   if(a==1){

   }

	 if(a==2){
            printf("      บ  (  | 1 | Ajouter Voiture                              ) บ\n");
            printf("      บ  (  | 2 | Afficher les Voitures                        ) บ\n");
		    printf("      บ  (  | 3 | Modifier Voiture                             ) บ\n");
            printf("      บ  (  | 4| Supprimer Voiture                            ) บ\n");
            printf("enter votre chois\n");
            scanf("%d",&s);

            if(s==1)
		{system("cls");//effacer l'ecran

		liste_voiture=saisiev(liste_voiture);
		system("cls");}
				if(s==2)
		{system("cls");
		if(liste_voiture==NULL)
		{system("COLOR 0c");printf("\n\n\tERROR liste voiture vide\a");Sleep(1000);}
		else
		affiche_voiture(liste_voiture);
		getchar();
	   system("cls");}
	   if(s==3)
		{system("cls");
		if(liste_voiture==NULL)
		{system("COLOR 0c");printf("\n\tERROR liste de voitures vide\a");Sleep(1000);}

		else
			liste_voiture=modifier_voiture(liste_voiture);
		getchar();system("cls");
		}
		if(s==4)
{
	system("cls");
getchar();
system("cls");
}


   }

 if(a==3){
           printf("      บ  (  | 1 | Ajouter Client                               ) บ\n");
           printf("      บ  (  | 3 | Afficher les Clients                         ) บ\n");
           printf("      บ  (  | 5| Modifier Client                              ) บ\n");
           printf("      บ  (  | 7| Rentree Voiture                              ) บ\n");
            printf("      *        Entrer Votre Choix                    *\t");
    scanf("%d",&w);
	if(w==1)
		{ system("cls");
		system("cls");
	}
	if(w==2)
		{
			system("cls");

			if(liste_client==NULL)
			{system("COLOR 0c");printf("\n\n\t\tERROR liste de clients vide\a");Sleep(1000);}
			else
	   affiche_client(liste_client);
			getchar();system("cls");}



		if(w==3)
		{system("cls");
		if(liste_client==NULL)
			{system("COLOR 0c");
		printf("\n\n\t\tERROR liste de clients vide\a");Sleep(1000);}

		else
			liste_client=modifier_client(liste_client);
		getchar();system("cls");
		}

		if(w==4)
		{system("cls");
		if((liste_client==NULL)||(liste_voiture==NULL))
		{system("COLOR 0c");printf("\n\n\t\tERROR liste Client ou Voiture vide\a");Sleep(1000);}
else
getchar();
         system("cls");
		}



	if(w==4)
	{system("cls");


getchar();
         system("cls");
		}


   }
    if(a==4){
system("COLOR 0c");
printf("\n\n\tsi vous voulez sauvegarder les donnees taper 1\n\t");
save=getch();
if(save=='1')
{
enregistrer_client(liste_client);
enregistrer_voiture(liste_voiture);

for(int k=0; k<4; k++)
	{
		system("cls");
		Sleep(300);



		for(int t=0; t<11; t++)
			printf("\n");

        //printf("              ษอออออออออออออออออออออออออออออออออออออออออออออออออออป\n");
	 	//printf("              บ                                                   บ\n");
	   	printf("                           Sauvegarde des donnees                    ");
	 	//printf("              บ                                                   บ\n");
	 	//printf("              ศอออออออออออออออออออออออออออออออออออออออออออออออออออผ");

		Sleep(500);
	}
}
else
{ printf("\n\n\t\tfermeture\n\n");}


system("cls");}
   }












