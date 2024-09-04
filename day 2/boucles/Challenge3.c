#include <stdio.h>

int main() {
    int n, i, j, premier;
    printf("Entrez un entier n : ");
    scanf("%d", &n);

    for (i = 2; i <= n; i++) {
        
        premier = 1;

        
        for (j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                premier = 0;
                break;
            }
        }

       
        if (premier) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}
