#include <stdio.h>

int main() {
    int n,i,facteur ;  
    printf("Entrez le nombre delement dans le tableau  ");
    scanf("%d", &n);
    int tableau[n];
    printf("Entrez le facteur de multiplication : ");
    scanf("%d", &facteur);
    printf("Entrez les %d elements du tableau :\n", n);
    for (i = 0; i < n; i++) {
        printf("element %d : ", i + 1);
        scanf("%d", &tableau[i]);
    }
    printf("résultat de la multiplication  par %d :\n", facteur);
    for (i = 0; i < n; i++) {
        printf("Element %d revient %d \n",i+1, tableau[i] * facteur);
    }
    printf("\n");

    return 0;
}