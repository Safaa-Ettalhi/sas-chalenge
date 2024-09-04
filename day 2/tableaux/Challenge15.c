#include <stdio.h>

int main() {
    int n1, n2;

    printf("Entrez le nombre delements pour le tableau 1 : ");
    scanf("%d", &n1);

    int tableau1[n1];

    printf("Entrez delements du tableau 1 :\n");
    for (int i = 0; i < n1; i++) {
        printf("Élément %d : ", i + 1);
        scanf("%d", &tableau1[i]);
    }

    printf("Entrez le nombre delements pour le tableau 2 : ");
    scanf("%d", &n2);

    int tableau2[n2];

    printf("Entrez les elements du  tableau 2 :\n");
    for (int i = 0; i < n2; i++) {
        printf("Élément %d : ", i + 1);
        scanf("%d", &tableau2[i]);
    }

    int tabl_fusionne[n1 + n2];

    for (int i = 0; i < n1; i++) {
        tabl_fusionne[i] = tableau1[i];
    }

    for (int i = 0; i < n2; i++) {
        tabl_fusionne[n1 + i] = tableau2[i];
    }
    printf("Le tableau fusionne est :\n");
    for (int i = 0; i < n1 + n2; i++) {
        printf("%d ", tabl_fusionne[i]);
    }
    printf("\n");

    return 0;
}
