#include <stdio.h>
#include <stdlib.h> 
typedef struct {
    float x;
    float y;
} Point;

int main() {
    
    Point *pointeurPoint = (Point *)malloc(sizeof(Point));
    if (pointeurPoint == NULL) {
        fprintf(stderr, "Échec de l'allocation de mémoire.\n");
        return 1;
    }
    pointeurPoint->x = 8.0;
    pointeurPoint->y = 3.0;

   
    printf("Coordonnée x : %.2f\n", pointeurPoint->x);
    printf("Coordonnée y : %.2f\n", pointeurPoint->y);
    

    free(pointeurPoint);

    return 0;
}
