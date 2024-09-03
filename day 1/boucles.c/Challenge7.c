#include <stdio.h>

int main() {
    char caractere;

    printf("Entrez un caractère : ");
    scanf(" %c", &caractere); 

    if (caractere >= 'A' && caractere <= 'Z') {
        printf("Le caractere '%c' est  majuscule.\n", caractere);
    } else {
        printf("Le caractere '%c' est minuscule.\n", caractere);
    }

    return 0;
}