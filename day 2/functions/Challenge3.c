#include <stdio.h>
int max(int a,int b){
    int max;
    if(a>b)
    max=a;
    else 
    max=b;
    return max;
}
int main() {
    int a, b, mx;
    printf("Entrez le premier nombre : ");
    scanf("%d", &a);
    printf("Entrez le deuxième nombre : ");
    scanf("%d", &b);
    mx = max(a, b);
    printf("Le max  de %d et %d est %d.\n", a, b,mx);

    return 0;
}