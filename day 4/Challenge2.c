#include <stdio.h>

int main() {
    int n, i, j, tmp;
    printf("Entrez le nombre d'éléments dans le tableau : ");
    scanf("%d", &n);

    int tableau[n];

    printf("Entrez les %d éléments du tableau :\n", n);
    for (i = 0; i < n; i++) {
        printf("Élément %d : ", i + 1);
        scanf("%d", &tableau[i]);
    }

    printf("\nTableau avant le tri : ");
    for (i = 0; i < n; i++) {
        printf("%d ", tableau[i]);
    }
    printf("\n");

    for (i = 1; i < n; i++) {
        tmp = tableau[i]; 
        j = i - 1;

        while (j >= 0 && tableau[j] > tmp) {
            tableau[j + 1] = tableau[j];
            j = j - 1;
        }
        tableau[j + 1] = tmp; 
    }

    printf("Tableau après le tri : ");
    for (i = 0; i < n; i++) {
        printf("%d ", tableau[i]);
    }
    printf("\n");

    return 0;
}
