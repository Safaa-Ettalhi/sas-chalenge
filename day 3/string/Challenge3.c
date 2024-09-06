#include <stdio.h>
#include <string.h>
//Écrivez un programme C qui lit deux chaînes de caractères et les concatène en une seule chaîne. Affichez la chaîne résultante.
int main() {
    char c1[20];
    char c2[20];
    char c[45];
    
    printf("Entrez le caractere 1  ");
    scanf("%[^\n]", &c1);
    getchar();
    printf("Entrez le caractere 2  ");
    scanf(" %[^\n]", &c2);
    strcat(c,c1);
    strcat(c," ");
    strcat(c,c2);
    printf("la concatenation est :%s",c);
    return 0;
}
