#include <stdio.h>

int main() {
    int a, b, somme;
    printf("Entrez la première valeur : ");
    scanf("%d", &a);
    printf("Entrez la deuxième valeur : ");
    scanf("%d", &b);
    somme = a + b;

    if (a == b) {
        somme=somme*3;
        printf("Les deux valeurs sont identiques.\n");
        printf("Le triple de leur somme est : %d\n",  somme);
    } else {
        // Sinon, renvoyer simplement la somme
        printf("La somme des deux valeurs est : %d\n", somme);
    }
    return 0;
}