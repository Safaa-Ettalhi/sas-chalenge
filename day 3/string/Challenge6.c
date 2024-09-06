#include <stdio.h>
#include <string.h>
//Écrivez un programme C qui lit une chaîne de caractères et un caractère, puis compte et affiche combien de fois le caractère apparaît dans la chaîne.
int main() {
    char c1[20];
     char c;
     int nbrocc=0;
    printf("Entrez le caractere 1  ");
    scanf("%s",&c1);
 
    printf("Entrez le caractere rechercher  ");
    scanf(" %c", &c);
    
    for (int i = 0; i < strlen(c1); i++) {
        if (c1[i] == c) {
            nbrocc++;
        }
    }
    if(nbrocc > 0){
        printf("Le caractère '%c' apparaît %d fois.\n",c,nbrocc);
   }else{
            printf("ce caractere n'apparait pas a cette chaine");
        }
    return 0;
}
