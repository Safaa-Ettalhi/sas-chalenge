#include <stdio.h>
int main() {
    int tableau_initial[4] = {7, 9, 2,1};
    int tableau_Copie[4];
    for (int i = 0; i < 4; i++) {
        tableau_Copie[i] = tableau_initial[i];
    }
    printf("Tableau initial : ");
    for (int i = 0; i < 4; i++) {
        printf("%d ", tableau_initial[i]);
    }
    printf("\n");
    printf("Tableau copie : ");
    for (int i = 0; i < 4; i++) {
        printf("%d ", tableau_Copie[i]);
    }
    printf("\n");
    
    return 0;
}
