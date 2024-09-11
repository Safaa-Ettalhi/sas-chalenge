#include <stdio.h>

int main() {
    int nombreElements;
    printf("Entrez le nombre d'éléments dans le tableau : ");
    scanf("%d", &nombreElements);
    int tableau[nombreElements];
 
    printf("Entrez les %d éléments du tableau :\n", nombreElements);
    for (int i = 0; i < nombreElements; i++) {
        printf("Élément %d : ", i + 1);
        scanf("%d", &tableau[i]);
    }

    printf("Tableau avant le tri :\n");
    for (int i = 0; i < nombreElements; i++) {
        printf("%d ", tableau[i]);
    }
    printf("\n");

    int sousTableauGauche[nombreElements / 2 + 1];
    int sousTableauDroit[nombreElements / 2 + 1];

    for (int taille = 1; taille < nombreElements; taille *= 2) {
        for (int debutGauche = 0; debutGauche < nombreElements - taille; debutGauche += 2 * taille) {
            int finGauche = debutGauche + taille - 1;
            int debutDroit = debutGauche + taille;
            int finDroit = debutDroit + taille - 1;
            if (finDroit >= nombreElements) finDroit = nombreElements - 1;

            int tailleGauche = finGauche - debutGauche + 1;
            int tailleDroit = finDroit - debutDroit + 1;

            for (int i = 0; i < tailleGauche; i++) sousTableauGauche[i] = tableau[debutGauche + i];
            for (int i = 0; i < tailleDroit; i++) sousTableauDroit[i] = tableau[debutDroit + i];

     
            int indexGauche = 0, indexDroit = 0, indexTableau = debutGauche;
            while (indexGauche < tailleGauche && indexDroit < tailleDroit) {
                if (sousTableauGauche[indexGauche] <= sousTableauDroit[indexDroit]) {
                    tableau[indexTableau++] = sousTableauGauche[indexGauche++];
                } else {
                    tableau[indexTableau++] = sousTableauDroit[indexDroit++];
                }
            }
            while (indexGauche < tailleGauche) tableau[indexTableau++] = sousTableauGauche[indexGauche++];
            while (indexDroit < tailleDroit) tableau[indexTableau++] = sousTableauDroit[indexDroit++];
        }
    }


    printf("Tableau après le tri :\n");
    for (int i = 0; i < nombreElements; i++) {
        printf("%d ", tableau[i]);
    }
    printf("\n");

    return 0;
}
