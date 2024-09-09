#include <stdio.h>

int main() {
    int n, i, j, temp;

    printf("Entrez le nombre d'elements dans le tableau : ");
    scanf("%d", &n);

    int tableau[n];

    printf("Entrez les %d elements du tableau :\n", n);
    for (i = 0; i < n; i++) {
        printf("element %d : ", i + 1);
        scanf("%d", &tableau[i]);
    }

    printf("\nTableau avant le tri : ");
    for (i = 0; i < n; i++) {
        printf("%d ", tableau[i]);
    }
    printf("\n");

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (tableau[j] > tableau[j + 1]) {
                temp = tableau[j];
                tableau[j] = tableau[j + 1];
                tableau[j + 1] = temp;
            }
        }
    }

    printf("Tableau  trie : ");
    for (i = 0; i < n; i++) {
        printf("%d ", tableau[i]);
    }
    printf("\n");

    return 0;
}
