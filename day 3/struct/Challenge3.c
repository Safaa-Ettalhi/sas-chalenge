#include <stdio.h>
#include <string.h>

typedef struct{
   float largeur;
   float longeur;

}rectangle;
float air( float largeur,float longeur){
    float aire= (largeur+longeur)*2;
    return aire;
}
int main() {
    float larg,longe;
    printf("entrer la largeur ");
    scanf("%f",&larg);
    printf("entrer la longeur ");
    scanf("%f",&longe);
    printf("l'aire du rectangle est :%.2f",air(larg,longe));
    return 0;
}