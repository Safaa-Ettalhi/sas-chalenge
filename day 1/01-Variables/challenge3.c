
#include <stdio.h>
float distance;
float yards;
int main() {
  
    printf("entrer la distance");
    scanf("%f",&distance);
    yards=distance*1093.61;
    
printf(" la distance %.2f km en yards est %.2f ",distance,yards);
    return 0;
}