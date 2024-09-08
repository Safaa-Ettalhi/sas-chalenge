#include <stdio.h>
int factorielle(int a){
    int result = 1;
    for (int i = 1; i <= a; i++) {
        result *= i;
    }
    return result;
}
int main() {
    int a;
    printf("Entrez un entier : ");
    scanf("%d", &a);
    if (a < 0) {
        printf(" les entiers positifs doivent etre positif.\n");
    } else {
        
        printf("La factorielle de %d est %d\n", a, factorielle(a));
    }

    return 0;
}