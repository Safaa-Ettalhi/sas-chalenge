#include <stdio.h>
int main() {
    int n,i,s=0;
    float m=0;
    printf("entrer la taille de tableau");
    scanf("%d",&n);
    int tableau[n];
    
    for (int i = 0; i < n; i++) {
        printf("Entrer la valeur: %d\n", i+1);
        scanf("%d", &tableau[i]);
    }
    for(i=0;i<n;i++){
        s+=tableau[i];
    }
    m=s/n;
    
    printf("\n la moyenne d'elements de tableau est %.2f",m);
    
    return 0;
}
