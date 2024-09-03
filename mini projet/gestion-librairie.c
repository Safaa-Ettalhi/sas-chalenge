#include <stdlib.h>
#include <stdio.h>
#include <string.h>
 char Titre[80][50];
 char Auteur[80][50];
 float Prix[50];
 int Quantite[50];
 int nbrlivre=0;
 void ajouter(){
    printf("entrer le titre de livre");
    scanf("%s",&Titre[nbrlivre]);
    printf("entrer l'auteur de l'LIVRE");
    scanf("%s",&Auteur[nbrlivre]);
    printf("entrer le prix");
    scanf("%f",&Prix);
    printf("entrer la quantite");
    scanf("%d",&Quantite);
    nbrlivre++;
    printf("ajouter avec succes");

 }
 void afficher() {
    int i;
    printf("Les détails des livres : \n");
    for (i = 0; i < nbrlivre; i++) {
        printf("\nLivre num : %d\n", i + 1);
        printf("\tTitre : %s - Auteur : %s - Prix : %.2f dhs - Quantité : %d\n",
               Titre[i], Auteur[i], Prix[i], Quantite[i]);
    }
}

void modifier(){
    char titre_rech[50];
    int quantite_nouvelle;
    printf("entrer le titre rechercher");
    scanf("%s",&titre_rech);
    for(int i=0;i<nbrlivre;i++){
        if(strcmp(Titre[i],titre_rech)==0){
            printf("entrer le nouvelle quantites");
            scanf("%d",&quantite_nouvelle); 
            Quantite[i]=quantite_nouvelle;
            printf("mise ajr avec succes");
        }
    }
}
void supprimer() {
    char titre_supp[50];
    int id_supp = -1;

    printf("Entrer le titre du livre à supprimer : ");
    scanf("%s", titre_supp);

    for (int i = 0; i < nbrlivre; i++) {
        if (strcmp(Titre[i], titre_supp) == 0) {
            id_supp = i;
            break;
        }
    }

    if (id_supp == -1) {
        printf("Aucun livre trouvé avec ce titre.\n");
    } else {
        // je déplacer les livres pour combiler l'espace
        for (int i = id_supp; i < nbrlivre - 1; i++) {
            strcpy(Titre[i], Titre[i + 1]);
            strcpy(Auteur[i], Auteur[i + 1]);
            Prix[i] = Prix[i + 1];
            Quantite[i] = Quantite[i + 1];
        }
        nbrlivre--;
        printf("Livre supprimé avec succès.\n");
    }
}

void nbrtotal(){
    int total=0;
    for(int i=0;i<nbrlivre;i++){
        total+=Quantite[i];
    }
    printf("le Nombre Total de Livres en Stocke est :%d",total);
}
int main(){
   
    int choix;

    do {
        printf("\n  1. pour ajouter un livres");
        printf("\n  2. pour Afficher tous les livres disponibles");
        printf("\n  3. pour Mettre à jour la quantité d'un livre.");
        printf("\n  4. pour Supprimer un livre du stock.");
        printf("\n  5. pour Afficher le nombre total de livres en stock.");
        printf("\n  6. pour quitter");
        printf("\nEntrez votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajouter();
                break;
            case 2:
                afficher();
                break;
            case 3:
                  modifier();
                break;
            case 4:
                supprimer();
                break;
            case 5:
                nbrtotal();
                break;
           
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
                printf("Choix invalide. Veuillez réessayer.\n");
                break;
        }
    } while (choix != 6);
}