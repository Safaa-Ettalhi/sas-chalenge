#include <stdio.h>
#include <string.h>

void inverse(char caractere[]) {
    int debut = 0, fin = strlen(caractere) - 1;
    char tmp;

    while (debut < fin) {
        tmp = caractere[debut];
        caractere[debut] = caractere[fin];
        caractere[fin] = tmp;
        debut++;
        fin--;
    }
}

int main() {
    char caractere[100];

    printf("Entrez la chaine de caractères: ");
    scanf("%[^\n]s", caractere);

    if (strlen(caractere) > 0 && caractere[strlen(caractere) - 1] == '\n') {
        caractere[strlen(caractere) - 1] = '\0';
    }

    inverse(caractere);

    printf("Chaine inversée: %s\n", caractere);

    return 0;
}