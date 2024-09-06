#include <stdio.h>
#include <string.h>
#include <ctype.h>
// Conversion en Majuscules

int main() {
    char car1[20];
    char convertion[20];
    printf("entrer la chaine a converter");
    scanf("%[^\n]",&car1);
    
    for (int i = 0; i < strlen(car1); i++) {
        car1[i] = toupper(car1[i]);
    }
    printf("la convertition  est %s",car1);
    return 0;
}