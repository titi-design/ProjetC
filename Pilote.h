//
// Created by rapha on 29/10/2025.
//
#ifndef TEST_PILOTE_H
#define TEST_PILOTE_H



//CREATION D'UN NOUVEAU TYPE "Pilote" AVEC SA STRUCTURE
typedef struct {
    char nom[50];
    char prenom[50];
    char nationalite[50];
    char ecurie[50];
    int points;
    int numero;
    int age;
    int actif; //SI = 1 le pilote est Actif si = 0 le pilote est Inactif
} Pilote;





//DEFINITION DES FONCTIONS
void AfficherPilotes (Pilote tab[], int *nbPilotes); //DECLARATION DES PARAMETRES UTILISES PAR LA FONCTION (ICI UN TABLEAU DE TYPE PILOTE ET UN ENTIER)
void SupprimerPilote (Pilote tab[], int *nbPilotes,int *PiloteC);
void ModifierPoints (Pilote tab[],int *PiloteC);





#endif //TEST_PILOTE_H