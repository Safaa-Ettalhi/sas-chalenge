#include <stdio.h>
#include <string.h>

// un programme C qui lit une chaîne de caractères et supprime tous les espaces

int main() {
    char car1[20];
    char convertion[20];
    printf("entrer la chaine a converter");
    scanf("%[^\n]",&car1);
    for (int i = 0; i < strlen(car1); i++) {
        if (car1[i] == ' '){
            for (int j = i; j < strlen(car1); j++) {
                char tmp = car1[j];
                car1[j] = car1[j+1];
                car1[j+1] = tmp;
            }
        }
    }
    printf("la caractere sont espace  est %s",car1);
    return 0;
}