#include <stdio.h>

int main() {
    int n,i;
    printf("Entrez le nombre delement dans le tableau  ");
    scanf("%d", &n);
    int tableau[n];;

    if (n <= 0) {
        printf("Le nombre d'entiers doit être supérieur à 0.\n");
        return 1;
    }
     printf("Entrez les %d elements du tableau :\n", n);
    for (i = 0; i < n; i++) {
        printf("element %d : ", i + 1);
        scanf("%d", &tableau[i]);
    }
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (tableau[j] > tableau[j+1]) {
                int temp = tableau[j];
                tableau[j] = tableau[j+1];
                tableau[j+1] = temp;
            }
        }
    }
    printf("Tableau trié en ordre croissant :\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", tableau[i]);
    }
    printf("\n");

    return 0;
}
