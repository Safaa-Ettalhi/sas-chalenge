#include <stdio.h>

int main() {
    int n,i,min;  
    printf("Entrez le nombre delement dans le tableau  ");
    scanf("%d", &n);
    int tableau[n];
    printf("Entrez les %d elements du tableau :\n", n);
    for (i = 0; i < n; i++) {
        printf("element %d : ", i + 1);
        scanf("%d", &tableau[i]);
    }
    min=tableau[0];
    for (i = 0; i < n; i++) {
        if(min>tableau[i]){
            min=tableau[i];
        }
        
    }
    printf("  le plus petit élément dans un tableau d'entiers est %d",min);

    return 0;
}
