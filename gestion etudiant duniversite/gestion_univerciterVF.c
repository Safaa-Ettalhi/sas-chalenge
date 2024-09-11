
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

char departements[10][30]={"Physique","Chimie","Biologie","Géologie","Économie","Informatique","Design","Finance","Logistique","Ressources Humaines"};
int nbrDepartements = 10;

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
    printf("Choisissez un département  :\n");
    for (int i = 0; i <nbrDepartements; i++) {
        printf("%d. %s\n", i + 1, departements[i]);
    }
    int choixDepartement;
    printf("Entrez le numero convenable : ");
    scanf("%d", &choixDepartement);
    getchar();
   while(choixDepartement < 1 || choixDepartement > nbrDepartements){
       printf("Choix invalide saisie une autre fois: ");
       scanf("%d", &choixDepartement);
        getchar();
        
   }
   strcpy(etudiants[nbretudiant].departement, departements[choixDepartement - 1]);
    
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
          printf("Choisissez un département  :\n");
            for (int i = 0; i <nbrDepartements; i++) {
                printf("%d. %s\n", i + 1, departements[i]);
            }
            int choixDepartement;
            printf("Entrez le numero convenable : ");
            scanf("%d", &choixDepartement);
            getchar();
            while(choixDepartement < 1 || choixDepartement > nbrDepartements){
               printf("Choix invalide saisie une autre fois: ");
               scanf("%d", &choixDepartement);
                getchar();
                
           }
           strcpy(etudiants[nbretudiant].departement, departements[choixDepartement - 1]);
            
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
    
    for (int i = 0; i < nbrDepartements; i++) {
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
    if (nbretudiant == 0) {
        printf("aucun etudiant trouve.\n");
        return;
    }
    int ordre;
    printf("Choisissez l'ordre de tri par nom :\n");
    printf("1. A à Z\n");
    printf("2. Z à A\n");
    printf("Entrez votre choix : ");
    scanf("%d", &ordre);
    getchar();

    for (int i = 0; i < nbretudiant - 1; i++) {
        for (int j = i + 1; j < nbretudiant; j++) {
            int comparer = 0;

            if (ordre== 1) { //sghir lkbir
                comparer = strcmp(etudiants[i].nom, etudiants[j].nom) > 0;
            } else if (ordre == 2) { //kbir lsghir
                comparer = strcmp(etudiants[i].nom, etudiants[j].nom) < 0;
            } else {
                printf("Choix invalide.\n");
                return;
            }

            if (comparer) {
                Etudiant temp = etudiants[i];
                etudiants[i] = etudiants[j];
                etudiants[j] = temp;
            }
        }
    }

    printf("Étudiants triés par nom.\n");
       afficher();
}
void trie_Moyenne() {
     int ordre;
    printf("Choisissez l'ordre de tri  :\n");
    printf("1. plus faible au plus élevé\n");
    printf("2. plus élevé au plus faible\n");
    printf("Entrez votre choix : ");
    scanf("%d", &ordre);
    getchar();
    
    for (int i = 0; i < nbretudiant - 1; i++) {
        for (int j = i + 1; j < nbretudiant; j++) {
            int comparer = 0;
            if (ordre == 1) { 
                comparer = etudiants[i].note_generale > etudiants[j].note_generale;
            } else if (ordre== 2) { 
                comparer = etudiants[i].note_generale < etudiants[j].note_generale;
            } else {
                printf("Choix invalide.\n");
                return;
            }

            if (comparer) {
                Etudiant temp = etudiants[i];
                etudiants[i] = etudiants[j];
                etudiants[j] = temp;
            }
        }
    } 
     printf("Étudiants triés par Moyenne.\n");
       afficher();
}
void trier_Statut() {
     if (nbretudiant == 0) {
        printf("Aucun étudiant trouvé.\n");
        return;
    }

    int admis= 0;

    for (int i = 0; i < nbretudiant; i++) {
        if (etudiants[i].note_generale >= 10) {
            printf("Étudiant %d :\n", etudiants[i].numero);
            printf("            Nom : %s\n", etudiants[i].nom);
            printf("            Prénom : %s\n", etudiants[i].prenom);
            printf("            Date de naissance : %s\n", etudiants[i].date_naissance);
            printf("            Département : %s\n", etudiants[i].departement);
            printf("            Note générale : %.2f\n", etudiants[i].note_generale);
        
            if (etudiants[i].note_generale >= 16) {
                printf("    Mention : Très Bien\n");
            } else if (etudiants[i].note_generale >= 14) {
                printf("    Mention : Bien\n");
            } else if (etudiants[i].note_generale >= 12) {
                printf("    Mention : Assez Bien\n");
            } else {
                printf("    Mention : Passable\n");
            }

            admis = 1;
        }
    }

    if (!admis) {
        printf("Aucun étudiant admis trouvé.\n");
    }
}

void nbrtotaletud(){
    
        printf("le nombre total des etudiants c'est:%d",nbretudiant);
 
}
void nbretud_dep() {
    if (nbretudiant == 0) {
        printf("Aucun étudiant trouvé.\n");
        return;
    }

    int nbretuddepar[10] = {0}; 
    for (int i = 0; i < nbretudiant; i++) {
        for (int j = 0; j < nbrDepartements; j++) {
            if (strcmp(etudiants[i].departement, departements[j]) == 0) {
                nbretuddepar[j]++;
                break;
            }
        }
    }
    for (int i = 0; i < nbrDepartements; i++) {
        printf("Nombre d'etudiants dedepartement %s : %d\n", departements[i], nbretuddepar[i]);
    }
}

void affichetudSeuil() {
    float seuil;
    printf("Entrez le seuil de note : ");
    scanf("%f", &seuil);
    getchar();
    int exict = 0;
    printf("Etudiants ayant une moyenne superieure à %.2f :\n", seuil);
    for (int i = 0; i < nbretudiant; i++) {
        if (etudiants[i].note_generale > seuil) {
            exict = 1;
            printf("Numero : %d, Nom : %s, Prenom : %s, Note Generale : %.2f\n", 
                   etudiants[i].numero, etudiants[i].nom, etudiants[i].prenom, etudiants[i].note_generale);
        }
    }
    if (exict == 0) {
        printf("Aucun étudiant n'a une note supérieure à %.2f.\n", seuil);
    }
}

void affich3etudtop() {
    if (nbretudiant == 0) {
        printf("Aucun etudiant trouve.\n");
        return;
    }
    for (int i = 0; i < nbretudiant - 1; i++) {
        for (int j = i + 1; j < nbretudiant; j++) {
            if (etudiants[i].note_generale < etudiants[j].note_generale) {
                Etudiant temp = etudiants[i];
                etudiants[i] = etudiants[j];
                etudiants[j] = temp;
            }
        }
    }

    printf("3 meilleurs etudiants sont :\n");
    for (int i = 0; i < 3 && i < nbretudiant; i++) {
        printf("Numero : %d, Nom : %s, Prenom : %s, Note Generale : %.2f\n",
               etudiants[i].numero, etudiants[i].nom, etudiants[i].prenom, etudiants[i].note_generale);
    }
}
void affichnbrreussdep() {
    if (nbretudiant == 0) {
        printf("Aucun etudiant trouve.\n");
        return;
    }
    int nbretuddepar[10] = {0};
      for (int i = 0; i < nbretudiant; i++) {
        if (etudiants[i].note_generale >= 10) {
            for (int j = 0; j < nbrDepartements; j++) {
                if (strcmp(etudiants[i].departement, departements[j]) == 0) {
                    nbretuddepar[j]++;
                    break;
                }
            }
        }
    }

    for (int i = 0; i < nbrDepartements; i++) {
        printf("Nombre d'etudiant reussi dans le département %s : %d\n", departements[i], nbretuddepar[i]);
    }
}
void ajouterMultiplesEtudiants() {
     char noms[10][50] = {"El Amrani", "Belkadi", "Bouzid", "El Ghazi", "Fassi", "Haddad", "Idrissi", "Jaziri", "Kabbaj", "Malki"};
    char prenoms[10][50] = {"Ahmed", "Fatima", "Hassan", "Khadija", "Mohamed", "Rachid", "Samira", "Tariq", "Youssef", "Zineb"};
    char dates_naissance[10][11] = {"2000-01-01", "1999-05-15", "2001-12-30", "2000-03-21", "1998-07-12", "2002-11-25", "1999-08-19", "2001-04-16", "2000-10-09", "1999-02-20"};
    char departements[10][30] = {"Physique", "Chimie", "Biologie", "Géologie", "Économie", "Informatique", "Design", "Finance", "Logistique", "Ressources Humaines"};
    float notes_generales[10] = {12.5, 15.0, 9.0, 13.0, 17.0, 10.0, 14.5, 11.0, 8.0, 16.5};

    for (int i = 0; i < 10; i++) {
        if (nbretudiant >= 10000) {
            printf("Université pleine.\n");
            return;
        }
        etudiants[nbretudiant].numero = nbretudiant + 1;
        strcpy(etudiants[nbretudiant].nom, noms[i]);
        strcpy(etudiants[nbretudiant].prenom, prenoms[i]);
        strcpy(etudiants[nbretudiant].date_naissance, dates_naissance[i]);
        strcpy(etudiants[nbretudiant].departement, departements[i]);
        etudiants[nbretudiant].note_generale = notes_generales[i];
        nbretudiant++;
    }
    printf("10 étudiants ajoutés avec succès.\n");
}

int main() {
    int choix;
    ajouterMultiplesEtudiants();
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
            case 6:{
                 
                int choixStatistique;
                printf("\n --------------------- STATISTIQUES -------------------------------\n");
                printf("    1. Afficher le nombre total d'etudiants\n");
                printf("    2. Afficher le nombre d'etudiants par departement\n");
                printf("    3. Afficher les etudiants ayant une note superieure a un seuil\n");
                printf("    4. Afficher les 3 meilleurs etudiants\n");
                printf("    5. Afficher le nombre d'etudiants reussis par departement\n");
                printf(" ------------------------------------------------------------------\n");
                printf("    Entrez votre choix : ");
                scanf("%d", &choixStatistique);
                getchar();
                switch (choixStatistique) {
                     case 1:
                          nbrtotaletud();
                            break;
                     case 2:
                            nbretud_dep();
                            break;
                     case 3: {
                           
                           affichetudSeuil();
                            break;
                                        }
                     case 4:
                          affich3etudtop();
                            break;
                     case 5:
                            affichnbrreussdep();
                            break;
                    default:
                            printf("Choix invalide. Veuillez réessayer.\n");
                            break;
                        }
                             break;
                        }
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
                printf("\n ----- TRIE DES ETUDIANTS ------\n");
                printf("    1. Trier par nom \n");
                printf("    2. Trier par moyenne generale\n");
                printf("    3. Trier par statut \n");
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