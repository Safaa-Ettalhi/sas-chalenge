#include <stdio.h>

int main() {
    int base, exposant;
    int resultat = 1;  
    printf("Entrez la base positif : ");
    scanf("%d", &base);
    if (base <= 0) {
        printf("La base doit être un nombre positif.\n");
        return 1;
    }

    printf("Entrez l'exposant positif : ");
    scanf("%d", &exposant);

    if (exposant < 0) {
        printf("L'exposant doit être positif.\n");
        return 1;  
    }
     int i=0;
    while (i < exposant) {
        resultat *= base;
        i++;
    }

    printf("la puissance de la base %d et lexposant %d est %d.\n", base, exposant, resultat);

    return 0;
}
