#include <stdio.h>
#include <stdlib.h>
#include "pilote.h"
#include "../Ecurie/ecurie.h"




//DETAILS ET CORPS DE LA FONCTION AFFICHERPILOTE
void AfficherPilotes (Pilote tab[],int *nbPilotes)
{
    int i;

    // BOUCLE POUR AFFICHER TOUTES LES INFORMATIONS DE CHAQUE PILOTES
    for ( i = 0; i < *nbPilotes; i++)
    {
        printf("Nom : %s", tab[i].nom);
        printf(" Prenom : %s", tab[i].prenom);
        printf(" Nationalite : %s", tab[i].nationalite);
        printf(" Ecurie : %s", tab[i].ecurie);
        printf(" Points : %d", tab[i].points);
        printf(" Numero : %d", tab[i].numero);
        printf(" Age : %d", tab[i].age);
        printf(" Actif : %d", tab[i].actif);
        printf("\n");
    }
}





//DETAILS ET CORPS DE LA FONCTION SUPPRIMERPILOTE
void SupprimerPilote(Pilote tab[],int *nbPilotes, int *PiloteC)
{
    //BOUCLE DE TRI A BULLE POUR DEPLACER L'ELEMENT CHOISIS A LA FIN DE LA LISTE
    for (int i = *PiloteC - 1; i < (*nbPilotes) - 1; ++i)
    {
        Pilote Sauvegarde = tab[i];
        tab[i] = tab[i+1];
        tab[i+1] = Sauvegarde;
    }
    (*nbPilotes)--; //REDUIT LE NOMBRE DE PILOTE DE 1
    tab = realloc(tab, (*nbPilotes) * sizeof(Pilote)); //REDUIT LA TAILLE DU TABLEAU DE EN MEMOIRE DE 1 ET SUPPRIME DONC LE DERNIER PILOTE DU TABLEAU
    printf("Le pilote a bien ete supprime."); // MESSAGE DE CONFIRMATION DE SUPPRESSION DU PILOTE
}





//DETAILS ET CORPS DE LA FONCTION MODIFIERPILOTE
void ModifierPoints (Pilote tab[], int *PiloteC) {
    int i = *PiloteC - 1;
    int pts;
    do {
        printf("Quel est le nouveau nombre de points du pilote ? ( > ou = a 0) "); //DEMANDE A L'UTILISATEUR DE CHOISIR LE NOMBRE DE POINTS DU PILOTE
        scanf("%d",&pts);
    }while (pts <0); //VERIFIE QUE LE NOMBRE DE POINT EST >0 ET SI "NON" DEMANDE DE REDONNER UN NOMBRE DE POINT VALABLE
    tab[i].points = pts; //ENREGISTE LA MODIFICATION
    printf("Les points ont bien ete modifie."); //MESSAGE DE CONFIRMATION D'AJOUT
}