#include <stdio.h>

int main() {
    int n, i, j, min, temp;
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

    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (tableau[j] < tableau[min]) {
                min = j;
            }
        }
        if (min != i) {
            temp = tableau[i];
            tableau[i] = tableau[min];
            tableau[min] = temp;
        }
    }
    printf("Tableau trie : ");
    for (i = 0; i < n; i++) {
        printf("%d ", tableau[i]);
    }
    printf("\n");

    return 0;
}
