
#include <stdio.h>
float temperature;
float k;
int main() {
  
    printf("entrer la temperature");
    scanf("%f",&temperature);
    k=temperature+273.15;
    
printf(" la temperature %.2f Celsius en kelvin est %.2f ",temperature,k);
    return 0;
}