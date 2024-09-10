#include <stdio.h>
#include <string.h>
#include <stdlib.h> //pour exit
typedef struct {
    char nom[20];
    char telephone[20];
    char email[50];
} Contact;

Contact contacts[1000];
int nbrContacts = 0;

void ajouterContact() {
    if (nbrContacts >= 1000) {
        printf("Le carnet plein.\n");
        return;
    }

    printf("Entrez le nom du contact : ");
    scanf("%s", contacts[nbrContacts].nom);
    printf("Entrez le numéro de téléphone : ");
    scanf("%s", contacts[nbrContacts].telephone);
    printf("Entrez l'adresse e-mail : ");
    scanf("%s", contacts[nbrContacts].email);

    nbrContacts++;
    printf("Ajoutee avec succes.\n");
}

void afficherContacts() {
    if (nbrContacts == 0) {
        printf("Aucun contact a afficher.\n");
    }

    printf("Liste des contacts :\n");
    
    for (int i = 0; i < nbrContacts; i++) {
        printf("Contacts %d:\n",i+1);
        printf("Nom : %s \n", contacts[i].nom);
        printf("Telephone : %s \n", contacts[i].telephone);
        printf("Email : %s\n", contacts[i].email);
        printf("\n");
    }
}

void rechercherContact() {
    char nomReche[20];
    printf("Entrez le nom que vous recherchier : ");
    scanf("%s", nomReche);

    for (int i = 0; i < nbrContacts; i++) {
        if (strcmp(contacts[i].nom, nomReche) == 0) {
            printf("Contact exicte !\n");
            printf("Nom : %s \n", contacts[i].nom);
            printf("Téléphone : %s \n", contacts[i].telephone);
            printf("Email : %s \n", contacts[i].email);
            return;
        }
    }

    printf("Aucun contact trouve avec ce nom.\n");
}

void modifierContact() {
    char nomReche[20];
    printf("Entrez le nom du contact que vous voulez modifier : ");
    scanf("%s", nomReche);

    for (int i = 0; i < nbrContacts; i++) {
        if (strcmp(contacts[i].nom, nomReche) == 0) {
            printf("Contact exict !\n");
            printf("Entrez le nouveau numero de telephone : ");
            scanf("%s", contacts[i].telephone);
            printf("Entrez la nouvelle adresse e-mail : ");
            scanf("%s", contacts[i].email);
            printf("Contact modifie avec succes.\n");
            return;
        }
    }

    printf("Aucun contact trouve avec ce nom.\n");
}
void supprimerContact() {
    char nomReche[20];
    printf("Entrez le nom du contact à supprimer : ");
    scanf("%s", nomReche);

    for (int i = 0; i < nbrContacts; i++) {
        if (strcmp(contacts[i].nom, nomReche) == 0) {
           
            for (int j = i; j < nbrContacts - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            nbrContacts--;
            printf("Contact supprime avec succes.\n");
            return;
        }
    }

    printf("Aucun contact trouve avec ce nom.\n");
}


int main() {
    int choix;

    do {
        printf("\n ------------GESTIONS DE CONTACTS-----------\n");
        printf("    1. Ajouter un contact\n");
        printf("    2. Afficher tous les contacts\n");
        printf("    3. Rechercher un contact\n");
        printf("    4. Modifier un contact\n");
        printf("    5. Supprimer un contact\n");
        printf("    6. Quitter\n");
         printf(" -------------------------------------------\n");
        printf("    Entrez votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajouterContact();
                break;
            case 2:
                afficherContacts();
                break;
            case 3:
                rechercherContact();
                break;
            case 4:
                modifierContact();
                break;
            case 5:
                supprimerContact();
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
                break;
        }
    } while (choix != 6);

    return 0;
}