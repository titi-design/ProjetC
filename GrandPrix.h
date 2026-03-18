#ifndef GRANDPRIX_H
#define GRANDPRIX_H

#include "pilote.h"

typedef struct {
    int jour;
    int mois;
    int annee;
} Date;

typedef struct {
    int heure;
    int minute;
} Horaire;

typedef struct {
    Pilote *pilote;       // Référence vers le pilote
    int position;
    char temps[15];
    int pointsObtenus;
} ResultatGP;

typedef struct {
    char nom[50];
    char pays[50];
    ResultatGP resultats[20];
    int nbResultats;
    Date d;
    Horaire h;
} GrandPrix;

// Fonctions liées aux Grands Prix
void ajouterGrandPrix(GrandPrix *gp);
void saisirResultats(GrandPrix *gp, Pilote pilotes[], int nbPilotes);
void afficherGrandsPrix(GrandPrix g[], int n);
void supprimerGrandPrix(GrandPrix g[], int *n, int index);

#endif
