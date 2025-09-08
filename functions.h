#ifndef FUNCTIONS_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define FUNCTIONS_H

typedef struct livres {
    char titre[50];
    char auteur[50];
    float prix;
    int quantite;
}livres;

int SearchAlgo();

void Attend();
void Menu();
void Ajouter();
void Afficher();
void Modifier();
void Supprimer();
void AfficherTotale();

#endif
