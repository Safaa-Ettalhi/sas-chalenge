#include<stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    int numero;
    char nom[50];
    char prenom[50];
    char date_naissance[11];
    char departement[30];
    float note_generale;
} Etudiant;
Etudiant etudiants[10000];
int nbretudiant=0;
void ajouter(){
    if (nbretudiant >= 10000) {
        printf("Universite pleine.\n");
        return;
    }
    printf("entrer les informations d'etudiant \n");
    printf("\tLe nemero d'etudiant : %d \n", nbretudiant+1);
    etudiants[nbretudiant].numero = nbretudiant + 1;
    printf("Entrez le nom : ");
    scanf("%[^\n]", etudiants[nbretudiant].nom);
    getchar();
    printf("Entrez le prenom : ");
    scanf("%[^\n]", etudiants[nbretudiant].prenom);
    getchar();
    printf("Entrez la date de naissance : ");
    scanf("%[^\n]", etudiants[nbretudiant].date_naissance);
    getchar();
    printf("Entrez le departement : ");
    scanf("%[^\n]", etudiants[nbretudiant].departement);
    getchar();
    printf("Entrez la note general : ");
    scanf("%f", &etudiants[nbretudiant].note_generale);
    getchar();
    nbretudiant++;
    
    printf("Ajoutee avec succes.\n");
}
void afficher() {
    if (nbretudiant == 0) {
        printf("Aucun etudiant trouve.\n");
        return;
    }
    for (int i = 0; i < nbretudiant; i++) {
        printf("\n Etudiant %d :\n", etudiants[i].numero);
        printf("               Nom : %s\n", etudiants[i].nom);
        printf("               Prenom : %s\n", etudiants[i].prenom);
        printf("               Date de naissance : %s\n", etudiants[i].date_naissance);
        printf("               Departement : %s \n", etudiants[i].departement);
        printf("               Note generale : %.2f \n", etudiants[i].note_generale);
    }
}
void modifier() {
    int numero , exict=0;
    printf("entrer le numero detudaint rechercher");
    scanf("%d",&numero);
    getchar();
    for (int i = 0; i < nbretudiant; i++) {
        if (etudiants[i].numero == numero) {
            exict = 1;
            printf("Modifier le nom %s : ", etudiants[i].nom);
            scanf("%[^\n]", etudiants[i].nom);
            getchar();
            printf("Modifier le prenom %s : ", etudiants[i].prenom);
            scanf("%[^\n]", etudiants[i].prenom);
            getchar();
            printf("Modifier la date de naissance %s : ", etudiants[i].date_naissance);
            scanf("%[^\n]", etudiants[i].date_naissance);
            getchar();
            printf("Modifier le departement %s : ", etudiants[i].departement);
            scanf("%[^\n]", etudiants[i].departement);
            getchar();
            printf("Modifier la note generale %.2f : ", etudiants[i].note_generale);
            scanf("%f", &etudiants[i].note_generale);
            getchar();
            printf("Modification  avec succes.\n");
            break;
        }
    }
    if(!exict)
        printf("Etudiant non trouve.\n");
   
}
void supprimer() {
    int exict = 0;
    int numero;
    int confirmation;
    printf("entrer le numero detudaint que vous voulez supprimer :\n");
    scanf("%d",&numero);
    getchar();
    for (int i = 0; i < nbretudiant; i++) {
        if (etudiants[i].numero == numero) {
            exict= 1;
            printf("Êtes-vous sûr de vouloir supprimer (1.oui et 2.non) : \n");
            scanf("%d",&confirmation);
            getchar();
        switch (confirmation){
            case 1:
            for (int j = i; j < nbretudiant - 1; j++) {
                etudiants[j] = etudiants[j + 1];
            }
            nbretudiant--;
            printf("Etudiant supprime avec succes.\n");
            break;
            case 2:
              printf("Suppression annulée.\n");
              break;
              default:
                printf("Choix invalide. Veuillez réessayer.\n");
                break;
        }
            
            
        }
    }
    if (!exict) {
        printf("Etudiant non trouve.\n");
    }
}
void calculerMoyenne_Departement() {
    if (nbretudiant == 0) {
        printf("Aucun etudiant trouve.\n");
        return;
    }

    float sommeGenerale = 0;
    int totalEtudiants = 0;
    char departements[100][30];
    int nbDepartements = 0;

    for (int i = 0; i < nbretudiant; i++) {
        int existe = 0;
        for (int j = 0; j < nbDepartements; j++) {
            if (strcmp(etudiants[i].departement, departements[j]) == 0) {
                existe = 1;
                break;
            }
        }
        if (!existe) {
            strcpy(departements[nbDepartements], etudiants[i].departement);
            nbDepartements++;
        }
    }

    for (int i = 0; i < nbDepartements; i++) {
        float sommeDepartement = 0;
        int nbEtudiantsDepartement = 0;
        for (int j = 0; j < nbretudiant; j++) {
            if (strcmp(etudiants[j].departement, departements[i]) == 0) {
                sommeDepartement += etudiants[j].note_generale;
                nbEtudiantsDepartement++;
            }
        }
        if (nbEtudiantsDepartement > 0) {
            float moyenne = sommeDepartement / nbEtudiantsDepartement;
            printf("Moyenne du departement %s : %.2f\n", departements[i], moyenne);
        }

        sommeGenerale += sommeDepartement;
        totalEtudiants += nbEtudiantsDepartement;
    }

    if (totalEtudiants > 0) {
        float moyenneGeneraleUniversite = sommeGenerale / totalEtudiants;
        printf("Moyenne generale de l'universite : %.2f\n", moyenneGeneraleUniversite);
    }
}
void rechercher_Nom() {
    char nomRech[50];
    int exist = 0;

    printf("Entrez le nom que vous recherchez : ");
    scanf("%[^\n]", nomRech);
    getchar();

    for (int i = 0; i < nbretudiant; i++) {
        if (strcmp(etudiants[i].nom, nomRech) == 0) {
            printf("Etudiant %d :\n", etudiants[i].numero);
            printf("              Nom : %s\n", etudiants[i].nom);
            printf("              Prenom : %s\n", etudiants[i].prenom);
            printf("              Date de naissance : %s\n", etudiants[i].date_naissance);
            printf("              Departement : %s\n", etudiants[i].departement);
            printf("              Note generale : %.2f\n", etudiants[i].note_generale);
            exist = 1;
        }
    }
    if (!exist) {
        printf("Aucun etudiant trouve avec ce nom ");
    }
}
void afficher_Departement() {
    char depRechercher[30];
    int exist = 0;

    printf("Entrez le nom du departement rechercher : ");
    scanf("%[^\n]", depRechercher);
    getchar();

    for (int i = 0; i < nbretudiant; i++) {
        if (strcmp(etudiants[i].departement, depRechercher) == 0) {
            printf("Etudiant %d :\n", etudiants[i].numero);
            printf("             Nom : %s\n", etudiants[i].nom);
            printf("             Prenom : %s\n", etudiants[i].prenom);
            printf("             Date de naissance : %s\n", etudiants[i].date_naissance);
            printf("             Note generale : %.2f\n", etudiants[i].note_generale);
            exist = 1;
        }
    }
    if (!exist) {
        printf("Aucun etudiant trouve dans ce departement ");
    }
}
void trie_nom() {
    for (int i = 0; i < nbretudiant - 1; i++) {
        for (int j = i + 1; j < nbretudiant; j++) {
            int comparaison = strcmp(etudiants[i].nom, etudiants[j].nom);
            
                Etudiant temp = etudiants[i];
                etudiants[i] = etudiants[j];
                etudiants[j] = temp;
            
        }
    }
    printf("Etudiants triés par nom.\n");
    afficher(); 
}
void trie_Moyenne() {
    for (int i = 0; i < nbretudiant - 1; i++) {
        for (int j = i + 1; j < nbretudiant; j++) {
            
                Etudiant temp = etudiants[i];
                etudiants[i] = etudiants[j];
                etudiants[j] = temp;
           
        }
    }
    printf("Etudiants tries par moyenne .\n");
    afficher(); 
}
void trier_Statut() {
    for (int i = 0; i < nbretudiant - 1; i++) {
        for (int j = i + 1; j < nbretudiant; j++) {
            int reussiI, reussiJ;

            if (etudiants[i].note_generale >= 10) {
                reussiI = 1;
            } else {
                reussiI = 0;
            }

            if (etudiants[j].note_generale >= 10) {
                reussiJ = 1;
            } else {
                reussiJ = 0;
            }
            
                Etudiant temp = etudiants[i];
                etudiants[i] = etudiants[j];
                etudiants[j] = temp;
           
        }
    }
    printf("Etudiants triés par statut.\n");
    afficher(); 
}

int main() {
    int choix;
    do{
        printf("\n ------------GESTIONS D'ETUDIANTS DANS UNE UNIVERSITE-----------\n");
        printf("    1. Ajouter un etudiant\n");
        printf("    2. modifier un etudiant\n");
        printf("    3. supprimer un etudiant \n");
        printf("    4. Afficher les details d'etudiants\n");
        printf("    5. calcule de moyenne genarale\n");
        printf("    6. Statistiques\n");
        printf("    7. rechercher un etudiant\n");
        printf("    8.triages \n");
        printf(" -------------------------------------------\n");
        printf("    Entrez votre choix : ");
        scanf("%d", &choix);
        getchar();
        switch (choix) {
            case 1:
                 ajouter();
                break;
            case 2:
               modifier();
                break;
            case 3:
              supprimer();
                break;
            case 4:
                 afficher();
                break;
            case 5:
                 calculerMoyenne_Departement();
                break;
            case 6:
            
                break; 
            case 7:
                 int rechChoix;
                printf("\n ----- RECHERCHER-----\n");
                printf("    1. Rechercher par nom\n");
                printf("    2. Afficher les etudiants par departement\n");
                printf(" -----------------------------------\n");
                printf("    Entrez votre choix : ");
                scanf("%d", &rechChoix);
                getchar();
                switch (rechChoix) {
                    case 1:
                        rechercher_Nom();
                        break;
                    case 2:
                        afficher_Departement();
                        break;
                    default:
                        printf("Choix nexiste pas . Veuillez reessayer.\n");
                        break;
                }
                break;
            case 8:
            int trieChoix, ordreChoix;
                printf("\n ----- TRIE DES ETUDIANTS -----\n");
                printf("    1. Trier par nom \n");
                printf("    2. Trier par moyenne generale\n");
                printf("    3. Trier par statut e\n");
                printf(" --------------------------------\n");
                printf("    Entrez votre choix : ");
                scanf("%d", &trieChoix);
                getchar();
                switch (trieChoix) {
                    case 1:
                        trie_nom();
                        break;
                    case 2:
                        trie_Moyenne();
                        break;
                    case 3:
                        trier_Statut();
                        break;
                    default:
                        printf("Choix invalide. Veuillez réessayer.\n");
                        break;
                }
                break;
           
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
                break;
        }    
    }while(choix!=9);
     
    return 0;
}