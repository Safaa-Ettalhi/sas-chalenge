#include <stdio.h>
int main() {
    int n,val_rem,i,val_new;
    printf("entrer la taille de tableau");
    scanf("%d",&n);
    int tableau[n];
    
    for (int i = 0; i < n; i++) {
        printf("Entrer la valeur: %d\n", i+1);
        scanf("%d", &tableau[i]);
    }
    printf("entrer  la valeur à remplacer :");
    scanf("%d",&val_rem);
    printf("entrer  la nouvelle valeur  :");
    scanf("%d",&val_new);
    for(i=0;i<n;i++){
        if(tableau[i]==val_rem){
          tableau[i]=val_new;
        }
    }
    printf("Le nouveau tableau est :\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", tableau[i]);
    }
    printf("\n");
    return 0;
}
