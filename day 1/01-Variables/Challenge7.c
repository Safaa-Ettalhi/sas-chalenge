#include <stdio.h>

int main() {
    
    float nbr1, nbr2, nbr3;
    float poids1 = 2, poids2 = 3, poids3 = 5;
    float moyenne_ponderee;

  
    printf("Entrez le premier nombre : ");
    scanf("%f", &nbr1);
    printf("Entrez le deuxieme nombre : ");
    scanf("%f", &nbr2);
    printf("Entrez le troisieme nombre : ");
    scanf("%f", &nbr3);
    moyenne_ponderee = (nbr1 * poids1 +nbr2 * poids2 + nbr3 * poids3) / (poids1 + poids2 + poids3);

    printf("La moyenne pondérée est : %.2f\n", moyenne_ponderee);

    return 0;
}
