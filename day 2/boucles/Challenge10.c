#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    const char chars[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    int n;

    srand(time(NULL));

    printf("Entrer la longueur du mot de passe: ");
    scanf("%d", &n);

    char mdp[n+1];

    for (int i = 0; i < n; i++) {
        int ind = rand() % 62;
        mdp[i] = chars[ind];
    }
    mdp[n] = '\0';

    printf("votre mot de passe est : %s", mdp);

    return 0;
}