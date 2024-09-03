#include <stdio.h>
#include <math.h>
float nbr1,nbr2,nbr3;
float Moyenne_geometrique;

int main() {
  
    printf("entrer le nombre1 ");
    scanf("%f",&nbr1);
    printf("entrer nombre2");
    scanf("%f",&nbr2);
    printf("entrer nombre3");
    scanf("%f",&nbr3);
 
  Moyenne_geometrique = pow(nbr1 * nbr1 * nbr1, 1.0 / 3.0);
 printf("la moyenne geometrique de %.2f %.2f %.2f EST %.2f ",nbr1,nbr2,nbr3,Moyenne_geometrique);
  
    return 0;
}