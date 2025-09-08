#include <stdio.h>
#include "functions.h"

int main() {
    int ch;
    do { // use the do-while loop to run this program at least once
        Menu();
        scanf("%d%*c", &ch);
        switch (ch) {
            case 0: printf("Merci d'avoir utiliser mon programme.\n"); break;
            case 1: Ajouter(); break;
            case 2: Afficher(); break;
            case 3: Modifier(); break;
            case 4: Supprimer(); break;
            case 5: AfficherTotale(); break;
            default : printf("Choix invalide. Veuillez réessayer.\n"); Attend(); break;
        }
    } while (ch != 0); // if the user chooses 0 then exit the loop and subsequently the program
    return 0;
}
