#include <stdio.h>

int main() {
    int n,i;  
    printf("Entrez le nombre delement dans le tableau  ");
    scanf("%d", &n);
    int tableau[n];
    printf("Entrez les %d elements du tableau :\n", n);
    for (i = 0; i < n; i++) {
        printf("element %d : ", i + 1);
        scanf("%d", &tableau[i]);
    }
    for (i = 0; i < n; i++) {
        printf("les elements de tableau sont %d \n",tableau[i]);
        
    }
      return 0;
}
