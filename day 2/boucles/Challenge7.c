#include <stdio.h>

int main() {
    int n;
    printf("Entrez le nombre a generer : ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Le nombre de termes doit être positif.\n");
        return 1; 
    }

     int a = 0, b = 1, c;

    printf("Les %d premiers termes sont :\n", n);
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            printf("%d ", a);
        } else if (i == 1) {
            printf("%d ", b);
        } else {
            c = a + b;  
            a = b;      
            b = c;      
            printf("%d ", c); 
        }
    }
    printf("\n");

    return 0;
}
