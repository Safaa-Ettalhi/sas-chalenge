#include <stdio.h>
#include <string.h>

typedef struct{
   char nom[20];
   char prenom[20];
   int age;
}Personne;

int main() {
    Personne personne;
    strcpy(personne.nom, "Ettalhi");
    strcpy(personne.prenom, "safaa");
    personne.age = 22;
    printf("Nom : %s\n", personne.nom);
    printf("Prenom : %s\n", personne.prenom);
    printf("Age : %d\n", personne.age);
    return 0;
}