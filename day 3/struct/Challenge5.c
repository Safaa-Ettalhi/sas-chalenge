
#include <stdio.h>
#include <string.h>
typedef struct {
    char titre[100];
    char auteur[100];
    int annee; 
}Livre;
Livre creerLivre(char titre[], char auteur[], int annee) {
    Livre l;
    strcpy(l.titre, titre);
    strcpy(l.auteur, auteur);
    l.annee = annee;
    return l;
}
void afficherLivre(Livre l) {
    printf("Titre : %s\n", l.titre);
    printf("Auteur : %s\n", l.auteur);
    printf("Année de publication : %d\n", l.annee);
}
int main() {
    Livre livre1 = creerLivre("la boite a merveille","ahmed sefrioui",1954);
    afficherLivre(livre1);
    return 0;
}