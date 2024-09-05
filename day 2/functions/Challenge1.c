#include <stdio.h>
int somme(int a,int b){
    return a+b;
}
int main() {
    int a, b, s;
    printf("Entrez le premier nombre : ");
    scanf("%d", &a);
    printf("Entrez le deuxième nombre : ");
    scanf("%d", &b);
    s = somme(a, b);
    printf("La somme de %d et %d est %d.\n", a, b,s);

    return 0;
}