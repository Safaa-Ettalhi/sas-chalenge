#include <stdio.h>

int main() {
    int n,inverse=0 ;
    printf("Entrez un entier : ");
    scanf("%d", &n);
    while(n!=0) {
        int ext_dernier = n % 10;
        inverse =inverse * 10 + ext_dernier;
        n /= 10;
    }

    printf("Le nombre inversé est : %d\n", inverse);

    return 0;
}
