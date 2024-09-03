#include <stdio.h>

int main() {
    int n;


    printf("Entrez un nombre entier : ");
    scanf("%d", &n);
    printf("Valeur en octal : %o\n", n);
    printf("Valeur en hexadécimal : %X\n", n); 
    return 0;
}