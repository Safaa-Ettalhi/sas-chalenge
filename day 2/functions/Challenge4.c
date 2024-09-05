#include <stdio.h>
int min(int a,int b){
    int min;
    if(a>b)
    min=b;
    else 
    min=a;
    return min;
}
int main() {
    int a, b, mn;
    printf("Entrez le premier nombre : ");
    scanf("%d", &a);
    printf("Entrez le deuxième nombre : ");
    scanf("%d", &b);
    mn = min(a, b);
    printf("Le MINIMUM  de %d et %d est %d.\n", a, b,mn);

    return 0;
}