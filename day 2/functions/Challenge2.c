#include <stdio.h>
int mult(int a,int b){
    return a*b;
}
int main() {
    int a, b, m;
    printf("Entrez le premier nombre : ");
    scanf("%d", &a);
    printf("Entrez le deuxième nombre : ");
    scanf("%d", &b);
    m = mult(a, b);
    printf("La multiplications  de %d et %d est %d.\n", a, b,m);

    return 0;
}