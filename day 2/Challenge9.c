#include <stdio.h>
int main() {
    int n;
    printf("entrer la taille de tableau");
    scanf("%d",&n);
    int tableau_initial[n];
    for (int i = 0; i < n; i++) {
        printf("Entrer la valeur: %d\n", i+1);
        scanf("%d", &tableau_initial[i]);
    }
    for(int i=0;i<n;i++){
        printf("le tableau initial est : %d",tableau_initial[i]);
    }
    printf("\n");
    int temp, i=0, fin = n-1;
    while (i < fin) {
        temp = tableau_initial[i];
        tableau_initial[i] = tableau_initial[n-1];
        tableau_initial[n-1] = temp;
        i++;
        fin--;
     }
    for(int i=0;i<n;i++){
        printf("le tableau inverse est : %d",tableau_initial[i]);
    }
    return 0;
}
