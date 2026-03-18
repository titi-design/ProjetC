#ifndef TEST_ECURIE_H
#define TEST_ECURIE_H

#include "../Pilotes/pilote.h"





//CREATION D'UN NOUVEAU TYPE "Ecurie" AVEC SA STRUCTURE
typedef struct {
    char nom[50];
    char pays[50];
    int points;
    int anneeCreation;
    char directeur[50];
    int actif; //SI = 1 l'ecurie est Actif si = 0 l'ecurie est Inactif
} Ecurie;





//DEFINITIONS DES FOCNTIONS
void AfficherEcuries (Ecurie tab[],int *nbEcuries); //DECLARATION DES PARAMETRES UTILISES PAR LA FONCTION (ICI UN TABLEAU DE TYPE ECURIE ET UN ENTIER)
void AjouterEcuries (Ecurie tab[],int *nbEcuries);
void SupprimerEcurie (Ecurie tab[], Pilote tableau[], int *nbEcuries,int *EcurieC, int *nbPilotes);
void CalculPoints (Ecurie tab[], Pilote tableau[], int *nbEcuries, int *nbPilotes);
void AjouterPilote (Pilote tab[],Ecurie tableau[],int nbEcurie, int nbPilotes);





#endif //TEST_ECURIE_H