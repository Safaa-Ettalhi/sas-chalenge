
#include <stdio.h>
float vitesse;
float transforme;
int main() {
  
    printf("entrer la vitesse en km/h");
    scanf("%f",&vitesse);
    transforme=vitesse*0.27778;
    
printf(" la vitesse %.2f km/h en mètres par seconde = %.2f ",vitesse,transforme);
    return 0;
}