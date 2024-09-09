// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>
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

    }

    printf("Tâche modifié:\n\tID: %s | Description: %s | Statut: %s | Deadline: %s\n", taches[i].Id, taches[i].description, taches[i].statut, taches[i].deadline);
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
    char Idrech[20];
    printf("Entrez lid de taches a suprimer : ");
    scanf("%[^\n]",Idrech);
   

    for (int i = 0; i < nbrtaches; i++) {
        if (strcmp(taches[i].Id, Idrech) == 0) {
            printf("tach exicte !\n");
            printf("id : %s \n", taches[i].Id);
            printf("Titre : %s \n", taches[i].titre);
            printf("description : %s \n", taches[i].description);
            printf("Deadline :%s\n",taches[i].deadline);
            printf("Statut :%s \n ",taches[i].statut);
            
            return;
        }
    }

    printf("Aucune tache trouve avec ce id.\n");
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
                 printf("    Entrez votre choix : ");
                  printf("1.rechercher par id");
                  printf("1.rechercher par titre");
                  scanf("%d", &choixrech);
                  getchar();
                  switch(choix){
                      case 1:
                        rechId();
                      break;
                      case 2:
                        rechTitre();
                      break;
                      default:
                printf("Choix invalide. Veuillez réessayer.\n");
                break;
                  }
                break;
            case 7:
               
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
                break;
        }
    }while(choix!=7);
     
    return 0;
}