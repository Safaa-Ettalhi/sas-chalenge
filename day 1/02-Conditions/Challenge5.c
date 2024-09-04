#include <stdio.h>

int main() {
    int annee;
    int mois, jours, heures, minutes, secondes;

    printf("Entrez le nombre d'annees a convertir : ");
    scanf("%d", &annee);

    mois = annee * 12;
    jours = annee * 365;
    heures = annee * 365 * 24;
    minutes = annee * 365 * 24 * 60;
    secondes = annee * 365 * 24 * 60 * 60;

    // Affichage des résultats
    printf("%d année(s) equivalent à :\n", annee);
    printf("- %d mois\n", mois);
    printf("- %d jours\n", jours);
    printf("- %d heures\n", heures);
    printf("- %d minutes\n", minutes);
    printf("- %d secondes\n", secondes);

    return 0;
}