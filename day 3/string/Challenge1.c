#include <stdio.h>

int main() {
    char chaine[40];
    printf("Entrez une chaîne de caractères : ");
    scanf("%[^\n]", chaine); 
    printf("Vous avez entré : %s\n", chaine);

    return 0;
}