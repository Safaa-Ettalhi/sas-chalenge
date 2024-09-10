#include <stdlib.h>
#include <stdio.h>
#include <string.h>
 char Titre[80][50];
 char Auteur[80][50];
 float Prix[50];
 int Quantite[50];
 int nbrlivre=0;
 void ajouter() {
    printf("entrer le titre de livre: ");
    scanf("%s", Titre[nbrlivre]); 
    printf("entrer l'auteur de livre: ");
    scanf("%s", Auteur[nbrlivre]); 
    printf("entrer le prix: ");
    scanf("%f", &Prix[nbrlivre]);
    printf("entrer la quantite: ");
    scanf("%d", &Quantite[nbrlivre]);
    nbrlivre++;
    printf("ajouté avec succes\n");
}
 void afficher() {
    int i;
    printf("Les détails des livres : \n");
    for (i = 0; i < nbrlivre; i++) {
        printf("\nLivre num : %d\n", i + 1);
        printf("\t Titre : %s - Auteur : %s - Prix : %.2f dhs - Quantite : %d\n",
               Titre[i], Auteur[i], Prix[i], Quantite[i]);
    }
}
void rechercher(){
     char titre_rech[50];
      printf("entrer le titre rechercher");
      scanf("%s",&titre_rech);
       for(int i=0;i<nbrlivre;i++){
        if(strcmp(Titre[i],titre_rech)==0){
            printf("le livre recherchee a etee trouver par succes \n");
             printf("\t Titre : %s - Auteur : %s - Prix : %.2f dhs - Quantite : %d\n",
               Titre[i], Auteur[i], Prix[i], Quantite[i]);
                break;
        }
        else
            printf("Livre non trouvé");
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
            break;
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
        //  combiler l'espace
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
        printf("\n               gestion de biblioteque                           ");
        printf("\n  1. pour ajouter un livres");
        printf("\n  2. pour Afficher tous les livres disponibles");
        printf("\n  3. Rechercher un livre par son titre.");
        printf("\n  4. pour Mettre à jour la quantité d'un livre.");
        printf("\n  5. pour Supprimer un livre du stock.");
        printf("\n  6. pour Afficher le nombre total de livres en stock.");
        printf("\n  7. pour quitter");
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
                  rechercher();
                break;
            case 4:
                  modifier();
                break;
            case 5:
                supprimer();
                break;
            case 6:
                nbrtotal();
                break;
            case 7:
                exit(0);
            default:
                
                printf("Choix invalide. Veuillez ressayer.\n");
                break;
        }
    } while (choix != 7);
}