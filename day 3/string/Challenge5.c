#include <stdio.h>
#include <string.h>
//Écrivez un programme C qui lit une chaîne de caractères et affiche la chaîne inversée. Par exemple, si la chaîne est "abcd", le programme doit afficher "dcba".
int main() {
    char c1[20];
  
    printf("Entrez le caractere 1  ");
    scanf("%[^\n]", &c1);
    int debut=0, fin=strlen(c1)-1;
    while(debut<fin){
        char temp=c1[debut];
        c1[debut]=c1[fin];
        c1[fin]=temp;
        debut++;
        fin--;
        
    }
   printf("liverse cest %s",c1);
    return 0;
}
