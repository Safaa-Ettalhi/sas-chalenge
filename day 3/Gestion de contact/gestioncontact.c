#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include <time.h>
typedef struct{
  char Id[30];  
  char titre[50];
  char description[80];
  char deadline[20];
  char statut[40];
}Tache;
Tache taches[100];
int nbrtaches=0;
typedef struct{
    char nom[20];
    char prenom[20];
    char email[30];
}collaborateur;
void ajouter(){
    char id[30];
    int id_unique;
     if (nbrtaches >= 100) {
        printf("pas despaces.\n");
        return;
    }
    while (1) {
        printf("Entrez l'identifiant : ");
        scanf("%[^\n]",id);
        getchar();
        id_unique = 1;

        for (int i = 0; i < nbrtaches; i++) {
            if (strcmp(taches[i].Id, id) == 0) {
                id_unique = 0; 
                printf("ID déjà utilisé. Veuillez entrer un autre ID.\n");
                break;
            }
        }

        if (id_unique) {
            strcpy(taches[nbrtaches].Id, id);
            break; 
        }
    }

   printf("entrer le titre");
   scanf("%[^\n]",taches[nbrtaches].titre);
   getchar();
   printf("entrer le description");
   scanf("%[^\n]",taches[nbrtaches].description);
   getchar();
   printf("entrer le deadline (format YYYY-MM-DD)");
   scanf("%[^\n]",taches[nbrtaches].deadline);
   getchar();
   printf("entrer la statut statut (à réaliser, en cours de réalisation, finalisée)");
   scanf("%[^\n]",taches[nbrtaches].statut);
   getchar();
   nbrtaches++;
   printf("Ajoutee avec succes.\n");
}
void ajouterpleusieur(){
    int n;
    printf("entrer le nbr de tache a ajouter");
    scanf("%d",&n);
    getchar();
     if (n >= 100) {
        printf("pas despaces.\n");
        return;
    }
    else{
        for (int i = 0; i < n; i++){
            ajouter();
        }
        }    
}
void ModifierTache() {
    char idnew[30], descnew[200], statutnew[30], deadlinenew[30];
    int choix;

    printf("Entrer l'id de la tache que vous voulez modifier: ");
    scanf("%s", idnew);
    getchar();

    printf("Choisissez l'option convenable\n");
    printf("1. Modifier la description d'une tâche.\n");
    printf("2. Modifier le statut d'une tâche.\n");
    printf("3. Modifier le deadline d'une tâche.\n");

    printf("Entrer votre choix: ");
    scanf("%d", &choix);
    getchar();
int i;
    for ( i = 0; i < nbrtaches; i++) {
        if (strcmp(taches[i].Id, idnew) == 0) {
            switch (choix) {
                case 1:
                    printf("Entrer la nouvelle description: ");
                    scanf("%[^\n]", descnew);
                    strcpy(taches[i].description, descnew);
                    break;
                case 2:
                    printf("Entrer le nouveau statut: ");
                    scanf("%[^\n]", statutnew);
                    strcpy(taches[i].statut, statutnew);
                    break;
                case 3:
                    printf("Entrer le nouveau deadline: ");
                    scanf("%[^\n]", deadlinenew);
                    strcpy(taches[i].deadline, deadlinenew);
                    break;
                default:
                    printf("Choix invalide");
                    break;
            }
        }
           printf("Tâche modifiée :\n");
            printf("ID : %s\n", taches[i].Id);
            printf("Titre : %s\n", taches[i].titre);
            printf("Description : %s\n", taches[i].description);
            printf("Deadline : %s\n", taches[i].deadline);
            printf("Statut : %s\n", taches[i].statut);
            break;

    }

  
}
void supprimer_Id() {
    char IdReche[30];
    printf("Entrez lid de taches a suprimer : ");
    scanf("%[^\n]", IdReche);
    getchar();

    for (int i = 0; i < nbrtaches; i++) {
        if (strcmp(taches[i].Id, IdReche) == 0) {
           
            for (int j = i; j < nbrtaches - 1; j++) {
                taches[j] = taches[j + 1];
            }
            nbrtaches--;
            printf("tache supprime avec succes.\n");
            return;
        }
    }

    printf("Aucun tache trouve avec ce id.\n");
}
void rechId(){

    int choix,i;
    printf("Choisissez l'option convenable\n");
    printf("1. Rechercher une tâche par son Identifiant.\n");
    printf("2. Rechercher une tâche par son Titre.\n");
    printf("Entrer votre choix: ");
    scanf("%d", &choix);
    getchar();
    switch (choix)
    {
    case 1:
           char idrech[30];
             printf("Entrer l'id de la tache rechercher: ");
             scanf("%s", idrech);
            
            for ( i = 0; i < nbrtaches; i++) {
            if (strcmp(taches[i].Id, idrech) == 0) {
            printf("ID : %s\n", taches[i].Id);
            printf("Titre : %s\n", taches[i].titre);
            printf("Description : %s\n", taches[i].description);
            printf("Deadline : %s\n", taches[i].deadline);
            printf("Statut : %s\n", taches[i].statut);
             break;
        }
         printf("Aucune tache trouve avec ce id.\n");
}
    

        break;
        case 2:
             char titrerech[30];
             printf("Entrer le titre de la tache rechercher: ");
             scanf("%s", titrerech);
        
            for ( i = 0; i < nbrtaches; i++) {
            if (strcmp(taches[i].titre, titrerech) == 0) {
            printf("ID : %s\n", taches[i].Id);
            printf("Titre : %s\n", taches[i].titre);
            printf("Description : %s\n", taches[i].description);
            printf("Deadline : %s\n", taches[i].deadline);
            printf("Statut : %s\n", taches[i].statut);
             break;
        }
         printf("Aucune tache trouve avec ce titre.\n");
}
    

        break;
    default:
         printf("Choix invalide. Veuillez réessayer.\n");
        break;
    }
}
void Statistiques(){
    int complete, incomplete;

    printf("Le nombre total des taches est %d\n", nbrtaches);

    for (int i = 0; i < nbrtaches; i++) {
        if (strcmp(taches[i].statut, "finalisée") == 0) 
            complete++;

        else
            incomplete++;
    }
    printf("Le nombre de taches finies est %d\nLe nombre de taches non finies est %d\n", complete, incomplete);

    printf("Le nombre de jours restants jusqu'au délai pour chaque tache:\n");




    int jourActuel, moisActuel, anneeActuelle;
    time_t now = time(NULL);
    struct tm *tm_now = localtime(&now);
    jourActuel = tm_now->tm_mday;
    moisActuel = tm_now->tm_mon + 1;
    anneeActuelle = tm_now->tm_year + 1900;

    for (int i = 0; i < nbrtaches; i++) {
        int jour, mois, annee;

        sscanf(taches[i].deadline, "%d-%d-%d", &jour, &mois, &annee);

        int joursDeadline = dateEnJours(jour, mois, annee);
        int joursActuel = dateEnJours(jourActuel, moisActuel, anneeActuelle);

        int restants = jour - joursActuel;
        printf("ID: %s | Titre: %s | Jours restants: %d\n", taches[i].Id, taches[i].titre, restants);
    }
}
int main() {
    int choix,choixrech;
    do{
        printf("\n ------------GESTIONS DE TACHES-----------\n");
        printf("    1. Ajouter une taches\n");
        printf("    2. Afficher pleusieurs taches\n");
        printf("    3. Afficher la liste de toutes les tâches \n");
        printf("    4. Modifier une tâche\n");
        printf("    5. Supprimer une tâche\n");
        printf("    6. Rechercher les Tâches\n");
        printf("    7. Statistiques\n");
         printf(" -------------------------------------------\n");
        printf("    Entrez votre choix : ");
        scanf("%d", &choix);
        getchar();
        switch (choix) {
            case 1:
                ajouter();
                break;
            case 2:
                ajouterpleusieur();
                break;
            case 3:
                
                break;
            case 4:
                 ModifierTache();
                break;
            case 5:
                supprimer_Id();
                break;
            case 6:
                 rechId();
                break;
                  
            case 7:
                 Statistiques();
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
                break;
        }
    }while(choix!=7);
     
    return 0;
}