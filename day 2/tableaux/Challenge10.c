#include <stdio.h>
int main() {
    int n,elem_rech,exict=0;
    printf("entrer la taille de tableau");
    scanf("%d",&n);
    int tableau_initial[n];
    
    for (int i = 0; i < n; i++) {
        printf("Entrer la valeur: %d\n", i+1);
        scanf("%d", &tableau_initial[i]);
    }
    printf("entrer l'element rechercher :");
    scanf("%d",&elem_rech);
    for(int i=0;i<n;i++){
        if(tableau_initial[i]==elem_rech){
            exict=1;
            break;
        }
        
    }
    if(exict){
       printf("L'elEment %d est présent dans le tableau.\n", elem_rech);
       
    }else{
         printf("L'element %d est non présent dans le tableau.\n", elem_rech);
    }
    return 0;
}
