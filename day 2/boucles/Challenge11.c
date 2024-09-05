#include <stdio.h>

int main() {
    int n,somme = 0.0;
    float moye;
    int compteur = 0;
  
   printf("Entrez la série de nombres positifs \n");
    while (1) {
        scanf("%d", &n);

        if (n == 0) {
          
            break;
        } else if (n > 0) {
         
            somme += n;
            compteur++;
        } else {
        
            printf("Veuillez entrer uniquement des nombres positifs.\n");
        }
    }

 
    if (compteur > 0) {
        moye = (float)somme / compteur;
        printf("La moyenne des nombres est : %.2f\n", moye);
    } else {
        printf("Aucun nombre positif n'a été entre.\n");
    }

    return 0;
}
