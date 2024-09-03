#include <stdio.h>

int main() {
    int nombre, m, c, d, u, inverse;
    printf("Entrez un nombre entier a 4 chiffres : ");
    scanf("%d", &nombre);
     m = nombre / 1000;        
     c = (nombre / 100) % 10; 
     d = (nombre / 10) % 10;   
     u= nombre % 10;            
    inverse = (u * 1000) + (d * 100) + (c * 10) + m;

    printf("L'inverse de %d est : %d\n", nombre, inverse);

    return 0;
}
