// Online C compiler to run C program online
#include <stdio.h>
void echanger(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int T[],int bas,int haut){
    int pivot=T[haut];
    int i=bas -1;
    for (int j=bas;j<haut;j++){
        if(T[j]<=pivot){
            i++;
            echanger(&T[i],&T[j]);
        }
    }
    echanger(&T[i+1],&T[haut]);
    return(i+1);
}
void triRapide(int T[],int bas,int haut){
    if(bas<haut){
        int pi=partition(T,bas,haut);
        triRapide(T,bas,pi-1);
        triRapide(T,pi+1,haut);
    }
}
void affichage(int T[],int n){
     for (int i = 0; i < n; i++) {
        printf("%d ",T[i]);
    }
}
int main() {
   int n ;
   printf("Entrez le nombre d'elements dans le tableau : ");
    scanf("%d", &n);
    int T[n];
    printf("Entrez les %d elements du tableau :\n", n);
    for (int i = 0; i < n; i++) {
        printf("element %d : ", i + 1);
        scanf("%d", &T[i]);
    }
    triRapide(T,0,n-1);
    affichage(T,n);

    return 0;
}