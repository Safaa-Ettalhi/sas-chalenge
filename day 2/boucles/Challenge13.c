#include <stdio.h>

int main() {
    int nombre, produit, somme = 0;
    printf("Entrez un nombre : ");
    scanf("%d", &nombre);
    printf("Table de multiplication de %d :\n", nombre);
    for (int i = 1; i <= 10; i++) {
        produit = nombre * i;
        printf("%d x %d = %d\n", nombre, i, produit);
        somme += produit; 
    }
    printf("La somme des produits est : %d\n", somme);

    return 0;
}
