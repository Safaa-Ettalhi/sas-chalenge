#include <stdio.h>
float a,b;
float addition,substraction,multiplication,division;
int main() {
  
    printf("entrer a");
    scanf("%f",&a);
    printf("entrer b");
    scanf("%f",&b);
   addition=a+b;
   substraction=a-b;
   multiplication=a*b;
  
  printf(" l'addition de %.2f et %.2f est %.2f \n",a,b,addition);
  printf(" la substraction de %.2f et %.2f est %.2f \n",a,b,substraction);
  printf("la multiplication de %.2f et %.2f est %.2f \n",a,b,multiplication);
  if(b>0){
       division=a/b;
       printf(" la division de %.2f et %.2f est %.2f \n",a,b,division);
   }else{
   printf(" division impossible b doit etre positif");
   
   }
  
    return 0;
}