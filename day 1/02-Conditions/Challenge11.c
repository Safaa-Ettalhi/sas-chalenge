#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    
    const char *jours_de_semaine[] = {
        "Lundi",
        "Mardi",
        "Mercredi",
        "Jeudi",
        "Vendredi",
        "Samedi",
        "Dimanche"
    };

    
    srand(time(NULL));
    int index = rand() % 7;

   
    printf("Le jour est : %s\n", jours_de_semaine[index]);

    return 0;
}
