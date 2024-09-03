#include <stdio.h>
#include <math.h> 

int main() {
    float rayon, volume,pi=3.14;

    printf("Entrez le rayon : ");
    scanf("%f", &rayon);
    volume = (4.0/3.0) * pi * pow(rayon, 3);

    printf("Le volume de la sphere est : %.2f \n", volume);

    return 0;
}
