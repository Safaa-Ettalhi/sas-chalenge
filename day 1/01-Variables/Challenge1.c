
#include <stdio.h>
char nom[50];
char prenom[50];
int age;
char sexe[10];
char email[100];
int main() {
  
    printf("entrer votre nom");
    scanf("%[^\n]s",nom);
    while(getchar() != '\n');//pour clener le buffer
    printf("entrer votre prenom");
    scanf("%[^\n]s",prenom);
    printf("entrer votre age");
    scanf("%d",&age);
    while(getchar() != '\n');
    printf("entrer votre email");
    scanf("%[^\n]s",email);
    
printf(" mes informations personnels sont \n :nom: %s  -prenom: %s -age: %d -email: %s",nom,prenom,age,email);
    return 0;
}