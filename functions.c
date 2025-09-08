#include "functions.h"

livres livre[20];
int stock = 0; //the number of books

// menu to show the options in the menu
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

// ajouter to add a book to the stock
void Ajouter() {
    system("cls");
    printf("----- Ajout -----\n");
        printf("Titre : ");
        scanf("%[^\n]%*c", livre[stock].titre); // %[^\n] allows us to input the whole line and %*c consumes the leftover new line
        printf("Auteur : ");
        scanf("%[^\n]%*c", livre[stock].auteur);
        printf("Prix : ");
        scanf("%f%*c", &livre[stock].prix);
        printf("Quantite : ");
        scanf("%d%*c", &livre[stock].quantite);
        printf("\n");
    stock++;
    printf("Livre ajouté.\n");
    Attend();
}
// afficher to show the stock
void Afficher() {
    system("cls");
    if (stock == 0) {
        printf("Pas de livres dans le stock.\n");
    } else {
        printf("----- Le Stock ----- \n");
        for (int i = 0; i < stock; i++) {
            printf("Titre : %s\n", livre[i].titre);
            printf("Auteur : %s\n", livre[i].auteur);
            printf("Prix : %.2f DH\n", livre[i].prix);
            printf("Quantité : %d unité\n", livre[i].quantite);
            printf("\n");
        }
    }
    Attend();
}
// searchalgo is the searching algorithm
int SearchAlgo(){
    char titre[50];
    if (stock == 0) {
        return -1;
    } else {
    printf("Titre : ");
    scanf("%[^\n]%*c", titre);
        for (int i = 0; i < stock; i++) {
            if (strcasecmp(livre[i].titre, titre) == 0) { // strcasecmp is an insenstive strcmp
                return i;
            }
        }
    return -2;
    }
}
// modifier to edit the quantity
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
        printf("titre : %s\n", livre[s].titre);
        printf("quantité : %d unité\n", livre[s].quantite);
        int nquant;
        printf("donnez la nouvelle quantité : ");
        scanf("%d%*c", &nquant);
        livre[s].quantite = nquant;
        printf("quantité mise à jour avec succès.\n");
    }
    Attend();
}
// supprimer to delete a book from the stock
void Supprimer() {
    system("cls");
    printf("---- Suppression -----\n");
    int s = SearchAlgo();
    if(s == -2){
        printf("Nous n'avons pas trouvé ce livre.\n");
    } else if (s == -1){
        printf("Pas de livres dans le stock.\n");
    } else {
        for (int i = s; i < stock - 1; i++) {
            strcpy(livre[i].titre, livre[i + 1].titre);
            strcpy(livre[i].auteur, livre[i + 1].auteur);
            livre[i].prix = livre[i + 1].prix;
            livre[i].quantite = livre[i + 1].quantite;
        }
        stock--;
        printf("Le livre est supprimé avec succès.\n");
    }
    Attend();
}
// affichertotale to add the quantities of all the books
void AfficherTotale() {
    system("cls");
    int quantitetotal = 0;
    if (stock == 0 ){
            printf("Pas de livres dans le stock.\n");
    } else {
        for (int i = 0; i < stock; i++) {
            quantitetotal += livre[i].quantite;
        }
        printf("Le nombre total des livres en stock est : %d\n", quantitetotal);
    }
    Attend();
}

void Attend() { // this function is just there to make the program a bit professional
    printf("\n Cliquez sur ENTRER pour retourner à l'acceuil...");
    getchar();
}
