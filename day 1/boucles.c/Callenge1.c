#include <stdio.h>

int main() {
    int n;


    printf("Entrez un nombre entier : ");
    scanf("%d", &n);

    if(n%2==0){
        printf("le nombre %d est pair",n);
    }else{
        printf("le nombre %d est impair",n);
    }

    return 0;
}