#include <stdio.h>

int main() {
    int n,s=0;
    printf("Entrez un entier : ");
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        s=s+i;
    }

    printf("la somme des %d premiers nombres naturels. est : %d\n", n,s);

    return 0;
}
