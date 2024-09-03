#include <stdio.h>
#include <math.h> 

int main() {
    float x1, y1, z1,x2, y2, z2;
    float distance;
    printf("Entrez les coordonnées du premere point :\n");
    printf("x1 = ");
    scanf("%f", &x1);
    printf("y1 = ");
    scanf("%f", &y1);
    printf("z1 = ");
    scanf("%f", &z1);
    printf("Entrez les coordonnées du deuxieme point  :\n");
    printf("x2 = ");
    scanf("%f", &x2);
    printf("y2 = ");
    scanf("%f", &y2);
    printf("z2 = ");
    scanf("%f", &z2);
    float dx = x2 - x1;
    float dy = y2 - y1;
    float dz = z2 - z1;

    distance = sqrt(pow(dx, 2) + pow(dy, 2) + pow(dz, 2));
   
    printf("La distance entre les deux points est : %.2f\n", distance);

    return 0;
}
