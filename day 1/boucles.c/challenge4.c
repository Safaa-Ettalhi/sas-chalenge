#include <stdio.h>
#include <math.h> 

int main() {
    double a, b, c;  
    double delta; 
    double x1, x2; 

    
    printf("Entrez les coefficients a, b et c de l'equation ax^2 + bx + c = 0 :\n");
    printf("a = ");
    scanf("%lf", &a);
    printf("b = ");
    scanf("%lf", &b);
    printf("c = ");
    scanf("%lf", &c);


        delta = b * b - 4 * a * c;
        
        
        if (delta > 0) {
            // Deux solutions 
            x1 = (-b + sqrt(delta)) / (2 * a);
            x2 = (-b - sqrt(delta)) / (2 * a);
            printf("L'equation a deux solutions distinctes :\n");
            printf("x1 = %.2lf\n", x1);
            printf("x2 = %.2lf\n", x2);
        } else if (delta == 0) {
            // Une solution reelle 
            x1 = -b / (2 * a);
            printf("L'equation a une solution double : x = %.2lf\n", x1);
        } else {
            // Pas de solution réelle
            printf("L'équation n'a pas de solution réelle.\n");
        }
    

    return 0;
}