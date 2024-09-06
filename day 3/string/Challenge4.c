#include <stdio.h>
#include <string.h>
//Écrivez un programme C qui lit deux chaînes de caractères et compare si elles sont égales ou non. Affichez un message indiquant si les chaînes sont égales ou différentes.
int main() {
    char c1[20];
    char c2[20];
   
    
    printf("Entrez le caractere 1  ");
    scanf("%[^\n]", &c1);
   
    printf("Entrez le caractere 2  ");
    scanf(" %[^\n]", &c2);
    if(strcmp(c1,c2)==0){
        printf("les caracteres sont egales");
    }else{
        printf("les caracteres non egales");
    }
    return 0;
}
