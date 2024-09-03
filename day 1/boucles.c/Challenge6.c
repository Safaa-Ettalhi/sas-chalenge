
#include <stdio.h>

int main() {
    int nombre;
    printf("Entrez un nombre entier : ");
    scanf("%d", &nombre);
    if (nombre > 0) {
        printf("Le nombre %d est positif.\n", nombre);
    } else if (nombre < 0) {
        printf("Le nombre %d est negatif.\n", nombre);
    } else {
        printf("Le nombre %d est null.\n", nombre);
    }

    return 0;
}