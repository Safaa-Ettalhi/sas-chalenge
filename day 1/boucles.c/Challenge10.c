#include <stdio.h>

int main() {
    int jour, mois, annee;
    char nom_mois[20];

    printf("Entrez une date au format JJ/MM/AAAA : ");
    if (scanf("%2d/%2d/%4d", &jour, &mois, &annee) != 3) {
        printf("Format de date invalide.\n");
        return 1;
    }

    switch (mois) {
       
        case 1:  sprintf(nom_mois, "Janvier"); break;
        case 2:  sprintf(nom_mois, "Février"); break;
        case 3:  sprintf(nom_mois, "Mars"); break;
        case 4:  sprintf(nom_mois, "Avril"); break;
        case 5:  sprintf(nom_mois, "Mai"); break;
        case 6:  sprintf(nom_mois, "Juin"); break;
        case 7:  sprintf(nom_mois, "Juillet"); break;
        case 8:  sprintf(nom_mois, "Août"); break;
        case 9:  sprintf(nom_mois, "Septembre"); break;
        case 10: sprintf(nom_mois, "Octobre"); break;
        case 11: sprintf(nom_mois, "Novembre"); break;
        case 12: sprintf(nom_mois, "Décembre"); break;
        default: 
            printf("Mois invalide.\n");
            return 1;
    }

   
    printf("%d-%s-%d\n", jour, nom_mois, annee);

    return 0;
}