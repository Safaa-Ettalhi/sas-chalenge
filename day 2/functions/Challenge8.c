#include <stdio.h>


int parite(int a){
    if(a%2==0){
       printf("%d est pair.\n", a);
    }else
     printf("%d est impair.\n", a);
    
}

int main() {
    int n;
  
    printf("Entrez un entier: ");
    scanf("%d", &n);
    parite(n);
  
    return 0;
}

