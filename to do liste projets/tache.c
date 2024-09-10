#include <stdio.h>
#include <string.h>
#include <time.h>
typedef struct{
  char Id[30];  
  char titre[50];
  char description[80];
  char deadline[20];
  char statut[40];
  char dateCreation[20]; 
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
   time_t t = time(NULL);
   struct tm tm = *localtime(&t);
    sprintf(taches[nbrtaches].dateCreation, "%d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
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
void afficherTachesUrgentes(char date1[], char date2[], char date3[]) {
    printf("Tâches avec deadline dans 3 jours ou moins:\n");
    for (int i = 0; i < nbrtaches; i++) {
        if (strcmp(taches[i].deadline, date1) == 0 ||
            strcmp(taches[i].deadline, date2) == 0 ||
            strcmp(taches[i].deadline, date3) == 0) {
            printf("Tache %d\n\tID: %s | Titre: %s | Description: %s | Deadline: %s | Statut: %s\n", 
                   i+1, taches[i].Id, taches[i].titre, taches[i].description, taches[i].deadline, taches[i].statut);
        }
    }
}
void AfficherListe() {
    int choix;

    printf("Choisissez l'option convenable\n");
    printf("1. Afficher la liste de toutes les tâches.\n");
    printf("2. Afficher la liste de toutes les tâches par deadline.\n");
    printf("3. Afficher la liste de toutes les tâches par ordre alphabétique.\n");
  printf("4. Afficher les tâches avec deadline dans 3 jours ou moins.\n");

    printf("Entrer votre choix: ");
    scanf("%d", &choix);
    getchar();

    printf("Liste des tâches:\n");

    switch (choix) {
        case 1:
    
            for (int i = 0; i < nbrtaches; i++) 
                printf("Tache %d\n\tID: %s | Titre: %s | Description: %s | Deadline: %s | Statut: %s\n", i+1, taches[i].Id, taches[i].titre, taches[i].description, taches[i].deadline, taches[i].statut);
            break;

        case 2:
        
            for (int i = 0; i < nbrtaches - 1; i++) {
                for (int j = 0; j < nbrtaches - i - 1; j++) {
                    if (strcmp(taches[j].deadline, taches[j + 1].deadline) > 0) {
                        Tache tmp = taches[j];
                        taches[j] = taches[j + 1];
                        taches[j + 1] = tmp;
                    }
                }
            }
            for (int i = 0; i < nbrtaches; i++) 
                printf("Tache %d\n\tID: %s | Titre: %s | Description: %s | Deadline: %s | Statut: %s\n", i+1, taches[i].Id, taches[i].titre, taches[i].description, taches[i].deadline, taches[i].statut);
            break;

        case 3:
           
            for (int i = 0; i < nbrtaches - 1; i++) {
                for (int j = 0; j < nbrtaches - i - 1; j++) {
                    if (strcmp(taches[j].titre, taches[j+1].titre) > 0) {
                        Tache tmp = taches[j];
                        taches[j] = taches[j+1];
                        taches[j+1] = tmp;
                    }
                }
            }
          
            for (int i = 0; i < nbrtaches; i++) 
                printf("Tache %d\n\tID: %s | Titre: %s | Description: %s | Deadline: %s | Statut: %s\n", i+1, taches[i].Id, taches[i].titre, taches[i].description, taches[i].deadline, taches[i].statut);
            break;

        case 4:
           
            char date1[20], date2[20], date3[20];
            printf("Entrer la date d'aujourd'hui (format YYYY-MM-DD): ");
            scanf("%s", date1);
            printf("Entrer la date de demain (format YYYY-MM-DD): ");
            scanf("%s", date2);
            printf("Entrer la date après-demain (format YYYY-MM-DD): ");
            scanf("%s", date3);

            afficherTachesUrgentes(date1, date2, date3);
            break;
        default:
            printf("Choix invalide.\n");
            break;
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
   printf("Tâche modifié:\n\tID: %s | Description: %s | Statut: %s | Deadline: %s\n", taches[i].Id, taches[i].description, taches[i].statut, taches[i].deadline);
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
void rechercher(){

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
int calculerJoursRestants(const char* dateActuelle, const char* deadline) {
    int anneeActuelle, moisActuel, jourActuel;
    int anneeDeadline, moisDeadline, jourDeadline;
    sscanf(dateActuelle, "%d-%d-%d", &anneeActuelle, &moisActuel, &jourActuel);
    sscanf(deadline, "%d-%d-%d", &anneeDeadline, &moisDeadline, &jourDeadline);
    int joursRestants = (anneeDeadline - anneeActuelle) * 365 + (moisDeadline - moisActuel) * 30 + (jourDeadline - jourActuel);

    return joursRestants;
}

void afficherStatistiques() {
    int totalTaches = nbrtaches;
    int tachesCompletes = 0;
    int tachesIncompletes = 0;
      char dateActuelle[20];
    printf("Entrer la date actuelle (format YYYY-MM-DD) : ");
    scanf("%s", dateActuelle);
    for (int i = 0; i < nbrtaches; i++) {
        if (strcmp(taches[i].statut, "finalisée") == 0) {
            tachesCompletes++;
        } else {
            tachesIncompletes++;
        }
    }
    printf("Nombre total de tAches : %d\n", totalTaches);
    printf("Nombre de taches completes : %d\n", tachesCompletes);
    printf("Nombre de taches incompletes : %d\n", tachesIncompletes);
    printf("\nJours restants jusqu'au deadline pour chaque tâche :\n");
     for (int i = 0; i < nbrtaches; i++) {
        int joursRestants = calculerJoursRestants(dateActuelle, taches[i].deadline);
        printf("Tache %d (%s) - Jours restants : %d jours\n", i+1, taches[i].titre, joursRestants);
    }
}
int main() {
    int choix,choixrech;
    do{
        printf("\n ------------GESTIONS DE TACHES-----------\n");
        printf("    1. Ajouter une taches\n");
        printf("    2. Ajouter pleusieurs taches\n");
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
               AfficherListe();
                break;
            case 4:
                 ModifierTache();
                break;
            case 5:
                supprimer_Id();
                break;
            case 6:
                 
                rechercher();
                break;
            case 7:
               afficherStatistiques();
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
                break;
        }
    }while(choix!=7);
     
    return 0;
}