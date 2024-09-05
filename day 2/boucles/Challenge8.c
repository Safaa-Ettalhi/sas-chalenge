#include<stdio.h>



int main(){
    int n,i,rech;
    int resultat = -1; 
    printf("Entrez le nombre d'element dans le tableau  ");
    scanf("%d", &n);
    int debut=0,fin=n-1;
    int tableau[n];
    printf("Entrez les %d elements du tableau :\n", n);
    for (i = 0; i < n; i++) {
        printf("element %d : ", i + 1);
        scanf("%d", &tableau[i]);
    }
    printf("Entrez le nombre d'element rechercher  ");
    scanf("%d", &rech);
    while (debut<=fin)
    {
       int milieu=(debut+fin)/2;

        if (tableau[milieu] == rech) {
            resultat = milieu;
            break;
        } else if (tableau[milieu] < rech) {
            debut = milieu + 1;
        } else {
            fin = milieu - 1;
        }
    }
     if (resultat != -1) {
        printf("Le nombre %d a été trouvé à l'indice %d.\n", rech, resultat+1);
    } else {
        printf("Le nombre %d n'est pas dans le tableau.\n", rech);
    }

    return 0;
}

 