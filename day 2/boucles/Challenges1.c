#include <stdio.h>

int main() {
    int n,i,m;

    printf("Entrez un nombre : ");
    scanf("%d", &n);

    
    for (int i =10 ; i>=1 ; i--) {
         m=n*i;
         printf(" %d x %d = %d \n",n,i,m);
    }
    

    return 0;
}
