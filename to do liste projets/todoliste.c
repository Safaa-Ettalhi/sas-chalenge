#include <stdio.h>
#include <string.h>
#include <time.h>

typedef struct {
    char Id[30];
    char titre[50];
    char description[80];
    char deadline[20];
    char statut[40];
    char dateCreation[20];
} Tache;

Tache taches[100];
int nbrtaches = 0;

typedef struct {
    char nom[20];
    char prenom[20];
    char email[30];
} Collaborateur;

char* obtenirDateActuelle() {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    static char dateActuelle[20];
    sprintf(dateActuelle, "%d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
    return dateActuelle;
}

int dateEnJours(const char* date) {
    int annee, mois, jour;
    sscanf(date, "%d-%d-%d", &annee, &mois, &jour);
    
    int jours = jour;
    for (int y = 1970; y < annee; y++) {
        jours += 365 + (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0));
    }
    for (int m = 1; m < mois; m++) {
        jours += 31;
        if (m == 4 || m == 6 || m == 9 || m == 11) jours -= 1;
        if (m == 2) jours -= 2;
    }
    return jours;
}

void afficherTachesUrgentes() {
    char* dateActuelle = obtenirDateActuelle();
    int deadlineLimite = dateEnJours(dateActuelle) + 3;

    printf("Tâches avec deadline dans 3 jours ou moins:\n");
    for (int i = 0; i < nbrtaches; i++) {
        int tacheDeadline = dateEnJours(taches[i].deadline);
        if (tacheDeadline <= deadlineLimite) {
            printf("Tâche %d\n\tID: %s | Titre: %s | Description: %s | Deadline: %s | Statut: %s\n", 
                   i + 1, taches[i].Id, taches[i].titre, taches[i].description, taches[i].deadline, taches[i].statut);
        }
    }
}

void ajouter() {
    char id[30];
    int id_unique;
    if (nbrtaches >= 100) {
        printf("Pas d'espace.\n");
        return;
    }
    while (1) {
        printf("Entrez l'identifiant : ");
        scanf("%[^\n]", id);
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

    printf("Entrez le titre : ");
    scanf("%[^\n]", taches[nbrtaches].titre);
    getchar();
    printf("Entrez la description : ");
    scanf("%[^\n]", taches[nbrtaches].description);
    getchar();
    printf("Entrez le deadline (format YYYY-MM-DD) : ");
    scanf("%[^\n]", taches[nbrtaches].deadline);
    getchar();
    printf("Entrez le statut (à réaliser, en cours de réalisation, finalisée) : ");
    scanf("%[^\n]", taches[nbrtaches].statut);
    getchar();
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(taches[nbrtaches].dateCreation, "%d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
    nbrtaches++;
    printf("Ajoutée avec succès.\n");
}

void ajouterpleusieur() {
    int n;
    printf("Entrez le nombre de tâches à ajouter : ");
    scanf("%d", &n);
    getchar();
    if (n + nbrtaches > 100) {
        printf("Pas assez d'espace.\n");
        return;
    } else {
        for (int i = 0; i < n; i++) {
            ajouter();
        }
    }
}

void AfficherListe() {
    int choix;

    printf("Choisissez l'option convenable\n");
    printf("1. Afficher la liste de toutes les taches.\n");
    printf("2. Afficher la liste de toutes les taches par deadline.\n");
    printf("3. Afficher la liste de toutes les taches par ordre alphabetique.\n");
    printf("4. Afficher les taches avec deadline dans 3 jours ou moins.\n");

    printf("Entrer votre choix : ");
    scanf("%d", &choix);
    getchar();

    printf("Liste des taches:\n");

    switch (choix) {
        case 1:
            for (int i = 0; i < nbrtaches; i++) 
                printf("Tache %d\n\tID: %s | Titre: %s | Description: %s | Deadline: %s | Statut: %s\n", 
                       i + 1, taches[i].Id, taches[i].titre, taches[i].description, taches[i].deadline, taches[i].statut);
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
                printf("Tache %d\n\tID: %s | Titre: %s | Description: %s | Deadline: %s | Statut: %s\n", 
                       i + 1, taches[i].Id, taches[i].titre, taches[i].description, taches[i].deadline, taches[i].statut);
            break;
        case 3:
            for (int i = 0; i < nbrtaches - 1; i++) {
                for (int j = 0; j < nbrtaches - i - 1; j++) {
                    if (strcmp(taches[j].titre, taches[j + 1].titre) > 0) {
                        Tache tmp = taches[j];
                        taches[j] = taches[j + 1];
                        taches[j + 1] = tmp;
                    }
                }
            }
            for (int i = 0; i < nbrtaches; i++) 
                printf("Tache %d\n\tID: %s | Titre: %s | Description: %s | Deadline: %s | Statut: %s\n", 
                       i + 1, taches[i].Id, taches[i].titre, taches[i].description, taches[i].deadline, taches[i].statut);
            break;
        case 4:
            afficherTachesUrgentes();
            break;
        default:
            printf("Choix invalide.\n");
            break;
    }
}

void ModifierTache() {
    char idnew[30], descnew[200], statutnew[30], deadlinenew[30];
    int choix;

    printf("Entrez l'ID de la tache que vous voulez modifier : ");
    scanf("%s", idnew);
    getchar();

    printf("Choisissez l'option convenable\n");
    printf("1. Modifier la description d'une tache.\n");
    printf("2. Modifier le statut d'une tache.\n");
    printf("3. Modifier le deadline d'une tache.\n");

    printf("Entrer votre choix : ");
    scanf("%d", &choix);
    getchar();

    int i;
    for (i = 0; i < nbrtaches; i++) {
        if (strcmp(taches[i].Id, idnew) == 0) {
            switch (choix) {
                case 1:
                    printf("Entrer la nouvelle description : ");
                    scanf("%[^\n]", descnew);
                    strcpy(taches[i].description, descnew);
                    break;
                case 2:
                    printf("Entrer le nouveau statut : ");
                    scanf("%[^\n]", statutnew);
                    strcpy(taches[i].statut, statutnew);
                    break;
                case 3:
                    printf("Entrer le nouveau deadline : ");
                    scanf("%[^\n]", deadlinenew);
                    strcpy(taches[i].deadline, deadlinenew);
                    break;
                default:
                    printf("Choix invalide\n");
                    break;
            }
            printf("Tache modifiee :\n\tID: %s | Description: %s | Statut: %s | Deadline: %s\n", 
                   taches[i].Id, taches[i].description, taches[i].statut, taches[i].deadline);
            return;
        }
    }
    printf("Tache non trouvee.\n");
}

void supprimer_Id() {
    char IdReche[30];
    printf("Entrez l'ID de la tache à supprimer : ");
    scanf("%[^\n]", IdReche);
    getchar();

    for (int i = 0; i < nbrtaches; i++) {
        if (strcmp(taches[i].Id, IdReche) == 0) {
            for (int j = i; j < nbrtaches - 1; j++) {
                taches[j] = taches[j + 1];
            }
            nbrtaches--;
            printf("Tache supprimee avec succes.\n");
            return;
        }
    }

    printf("Aucune tache trouvee avec cet ID.\n");
}

void rechercher() {
    int choix;
    printf("Choisissez l'option convenable\n");
    printf("1. Rechercher une tache par son Identifiant.\n");
    printf("2. Rechercher une tache par son Titre.\n");
    printf("Entrer votre choix : ");
    scanf("%d", &choix);
    getchar();

    switch (choix) {
        case 1: {
            char idrech[30];
            printf("Entrer l'ID de la tache recherchee : ");
            scanf("%s", idrech);
            for (int i = 0; i < nbrtaches; i++) {
                if (strcmp(taches[i].Id, idrech) == 0) {
                    printf("ID : %s\n", taches[i].Id);
                    printf("Titre : %s\n", taches[i].titre);
                    printf("Description : %s\n", taches[i].description);
                    printf("Deadline : %s\n", taches[i].deadline);
                    printf("Statut : %s\n", taches[i].statut);
                    return;
                }
            }
            printf("Aucune tache trouvee avec cet ID.\n");
            break;
        }
        case 2: {
            char titrerech[30];
            printf("Entrer le titre de la tache recherchee : ");
            scanf("%s", titrerech);
            for (int i = 0; i < nbrtaches; i++) {
                if (strcmp(taches[i].titre, titrerech) == 0) {
                    printf("ID : %s\n", taches[i].Id);
                    printf("Titre : %s\n", taches[i].titre);
                    printf("Description : %s\n", taches[i].description);
                    printf("Deadline : %s\n", taches[i].deadline);
                    printf("Statut : %s\n", taches[i].statut);
                    return;
                }
            }
            printf("Aucune tache trouvee avec ce titre.\n");
            break;
        }
        default:
            printf("Choix invalide. Veuillez reessayer.\n");
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
    printf("Nombre total de taches : %d\n", totalTaches);
    printf("Nombre de taches completes : %d\n", tachesCompletes);
    printf("Nombre de taches incomplètes : %d\n", tachesIncompletes);
    printf("\nJours restants jusqu'au deadline pour chaque tache :\n");
    for (int i = 0; i < nbrtaches; i++) {
        int joursRestants = calculerJoursRestants(dateActuelle, taches[i].deadline);
        printf("Tache %d (%s) - Jours restants : %d jours\n", i + 1, taches[i].titre, joursRestants);
    }
}

int main() {
    int choix;
    do {
        printf("\n ------------GESTION DES TACHES-----------\n");
        printf("    1. Ajouter une tache\n");
        printf("    2. Ajouter plusieurs taches\n");
        printf("    3. Afficher la liste de toutes les taches\n");
        printf("    4. Modifier une tache\n");
        printf("     5. Supprimer une tache\n");
        printf("    6. Rechercher les taches\n");
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
                printf("Choix invalide. Veuillez ressayer.\n");
                break;
        }
    } while (choix != 7);

    return 0;
}
