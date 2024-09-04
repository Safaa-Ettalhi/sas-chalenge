#include<stdio.h>
int main() {
    char caractere;

    printf("Entrez un caractère : ");
    scanf(" %c", &caractere); 
    if ((caractere >= 'A' && caractere <= 'Z') || (caractere >= 'a' && caractere <= 'z')) {
        if (caractere >= 'A' && caractere <= 'Z') {
            printf("Le caractere '%c' est une lettre majuscule.\n", caractere);
        } else {
            printf("Le caractere '%c' est une lettre minuscule.\n", caractere);
        }
    } else {
        printf("Le caractere '%c' n'est pas une lettre de l'alphabet.\n", caractere);
    }

    return 0;
}