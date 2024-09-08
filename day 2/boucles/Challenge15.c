#include <stdio.h>

int main() {
    int n, i;
    int factorielle = 1;
    printf("Entrez un nombre entier : ");
    scanf("%d", &n);
    if (n < 0) {
        printf("La factorielle n'est pas définie pour les nombres négatifs.\n");
    } else {
        for (i = 1; i <= n; i++) {
            factorielle *= i;    
        }

        printf("La factorielle de %d est : %d\n", n, factorielle);
    }

    return 0;
}
