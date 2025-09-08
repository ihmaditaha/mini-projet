#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "functions.h"

char titres[30][50]; // the first one is the cells index and the second one is the string size
char auteurs[30][50];
float prixs[30];
int quantites[30];
int stock = 0; //the number of books

void Menu(){
    system("cls"); // system allows us to write console commands and cls clears the screen
    printf("------- Menu: -------\n");
    printf("1. Ajouter un Livre au Stock.\n");
    printf("2. Afficher Tous les Livres Disponibles.\n");
    printf("3. Mettre à jour la quantité d'un livre.\n");
    printf("4. Supprimer un livre du stock.\n");
    printf("5. Afficher le nombre total de livres en stock.\n");
    printf("0. Quitter\n");
    printf("Choisir : ");
}

void Ajouter() {
    system("cls");
    printf("----- Ajout -----\n");
    for (int i = stock; i <= stock; i++) {
        printf("Titre : ");
        scanf("%[^\n]%*c", titres[i]); // %[^\n] allows us to input the whole line and %*c consumes the leftover new line
        printf("Auteur : ");
        scanf("%[^\n]%*c", auteurs[i]);
        printf("Prix : ");
        scanf("%f%*c", &prixs[i]);
        printf("Quantite : ");
        scanf("%d%*c", &quantites[i]);
        printf("\n");
    }
    stock++;
    printf("Livre ajouté.\n");
    Attend();
}

void Afficher() {
    system("cls");
    if (stock == 0) {
        printf("Pas de livres dans le stock.\n");
    } else {
        printf("----- Le Stock ----- \n");
        for (int i = 0; i < stock; i++) {
            printf("Titre : %s\n", titres[i]);
            printf("Auteur : %s\n", auteurs[i]);
            printf("Prix : %.2f DH\n", prixs[i]);
            printf("Quantité : %d unité\n", quantites[i]);
            printf("\n");
        }
    }
    Attend();
}

int SearchAlgo(){
    char titre[50];
    if (stock == 0) {
        return -1;
    } else {
    printf("Titre : ");
    scanf("%[^\n]%*c", titre);
        for (int i = 0; i < stock; i++) {
            if (strcasecmp(titres[i], titre) == 0) { // strcasecmp is an insenstive strcmp
                return i;
                break;
            }
        }
        return -2;
    }
}

void Modifier() {
    system("cls");
    printf("----- modification -----\n");
    int s = SearchAlgo();
    if(s == -2){
        printf("Nous n'avons pas trouvé ce livre.\n");
    } else if (s == -1){
        printf("Pas de livres dans le stock.\n");
    } else {
        printf("----- Le livre est trouvé -----\n");
        printf("titre : %s\n", titres[s]);
        printf("quantité : %d unité\n", quantites[s]);
        int nquant;
        printf("donnez la nouvelle quantité : ");
        scanf("%d%*c", &nquant);
        quantites[s] = nquant;
        printf("quantité mise à jour avec succès.\n");
    }
    Attend();
}

void Supprimer() {
    system("cls");
    printf("---- Suppression -----\n");
    int s = SearchAlgo();
    if(s == -2){
        printf("Nous n'avons pas trouvé ce livre.\n");
    } else if (s == -1){
        printf("Pas de livres dans le stock.\n");
    } else {
        for (int j = s; j < stock - 1; j++) {
            strcpy(titres[j], titres[j + 1]);
            strcpy(auteurs[j], auteurs[j + 1]);
            prixs[j] = prixs[j + 1];
            quantites[j] = quantites[j + 1];
        }
        stock--;
        printf("Le livre est supprimé avec succès.\n");
    }
    Attend();
}

void AfficherTotale() {
    system("cls");
    int quantitetotal = 0;
    if (stock == 0 ){
            printf("Pas de livres dans le stock.\n");
    } else {
        for (int i = 0; i < stock; i++) {
            quantitetotal += quantites[i];
        }
        printf("Le nombre total des livres en stock est : %d\n", quantitetotal);
    }
    Attend();
}

void Attend() { // this function is just there to make the program a bit professional hhh
    printf("\n Cliquez sur ENTRER pour retourner à l'acceuil...");
    getchar();
}
