#include <stdio.h>

int main() {
    char jours[7][10] = {"Lundi", "Mardi", "Mercredi", "Jeudi", "Vendredi", "Samedi", "Dimanche"};
    int choix;
    printf("Jours de la semaine :\n");
    for (int i = 0; i < 7; i++) {
        printf("%d. %s\n", i + 1, jours[i]);
    }
    printf("Choisissez un jour (1-7) : ");
    scanf("%d", &choix);
    if (choix < 1 || choix > 7) {
        printf("Choix invalide. Veuillez entrer un nombre entre 1 et 7.\n");
    } else {
        printf("Vous avez sélectionné : %s\n", jours[choix - 1]);
        printf("Les jours qui suivent sont :\n");
        for (int i = choix - 1; i < choix - 1 + 7; i++) {
            printf("%s\n", jours[i % 7]);
        }
    }

    return 0;
}
