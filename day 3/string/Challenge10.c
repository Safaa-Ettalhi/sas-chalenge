#include <stdio.h>
#include <string.h>

// Trouver un Sous-String

int main() {
    char caract1[50];
    char sous_chaine[20];
    printf("entrer une chaîne de caracteres");
    scanf("%[^\n]",&caract1);
    getchar();
    printf("entrer une une sous-chaine");
    scanf("%[^\n]",&sous_chaine);
    getchar();
   if (strstr(caract1, sous_chaine) != NULL) {
        printf("La sous-chaîne \"%s\" est présente dans la chaîne principale.\n", sous_chaine);
    } else {
        printf("La sous-chaîne \"%s\" n'est pas présente dans la chaîne principale.\n", sous_chaine);
    }
   
    return 0;
}