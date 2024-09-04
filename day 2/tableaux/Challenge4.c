#include <stdio.h>

int main() {
    int n,i,max;  
    printf("Entrez le nombre delement dans le tableau  ");
    scanf("%d", &n);
    int tableau[n];
    printf("Entrez les %d elements du tableau :\n", n);
    for (i = 0; i < n; i++) {
        printf("element %d : ", i + 1);
        scanf("%d", &tableau[i]);
    }
    max=tableau[0];
    for (i = 0; i < n; i++) {
        if(max<tableau[i]){
            max=tableau[i];
        }
        
    }
    printf(" le plus grand élément dans un tableau d'entiers est %d",max);

    return 0;
}
