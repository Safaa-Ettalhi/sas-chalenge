#include <stdio.h>
float temperature;
int main() {
  
    printf("entrer la temperature en Celsius");
    scanf("%f",&temperature);
   
    
printf(" la temperature est %.2f Celsius ",temperature);
if(temperature<0){
    printf("l'etat de l'eau a cette temperature est solide");
}else if(temperature>=0 && temperature<100){
    printf("l'etat de l'eau a cette temperature est liquide");
}else{
    printf("l'etat de l'eau a cette temperature est Gaz");
}
    return 0;
}