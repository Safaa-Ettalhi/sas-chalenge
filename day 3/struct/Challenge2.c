#include <stdio.h>
#include <string.h>

typedef struct{
   char nom[20];
   char prenom[20];
   float tab_not[3];

}Etudiant;

int main() {
    Etudiant etudiant;
    strcpy(etudiant.nom, "Ettalhi");
    strcpy(etudiant.prenom, "safaa");
    int T[] = {18,17,20};
    for (int i = 0; i < 3; i++) {
        etudiant.tab_not[i] = T[i];
    }
    
    printf("Nom : %s\n", etudiant.nom);
    printf("Prenom : %s\n", etudiant.prenom);
    for(int i=0;i<3;i++){
    printf("note : %.2f\n", etudiant.tab_not[i]);
        
    }
    return 0;
}