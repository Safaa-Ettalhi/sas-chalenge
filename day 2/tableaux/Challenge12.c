#include <stdio.h>
int main() {
    int n,i;
    printf("entrer la taille de tableau");
    scanf("%d",&n);
    int tableau[n];
    
    for (int i = 0; i < n; i++) {
        printf("Entrer la valeur: %d\n", i+1);
        scanf("%d", &tableau[i]);
    }
    for(i=0;i<n;i++){
        if(tableau[i]%2==0){
         printf("%d ", tableau[i]);
         
        }
    }
     printf("\n");
    
    return 0;
}
