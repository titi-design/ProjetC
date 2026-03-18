#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ecurie.h"





// DETAILS ET CORPS DE LA FONCTION CALCULPOINTS
void CalculPoints (Ecurie tab[],Pilote tableau[], int *nbEcuries, int *nbPilotes) {

    //BOUCLE QUI COMPTE LE NOMBRE DE POINTS DE TOUTES LES ECURIES
    for (int i = 0; i < *nbEcuries; i++) {
        int ite = 0;
        int p1 = 0;
        int p2 = 0;
        char n1[50]="";
        char n2[50]="";

        //BOUCLE  QUI VIENT SOMMER LES POINTS DES PILOTES DE CHAQUE ECURIE
        for (int j = 0; j < *nbPilotes; j++) {

            //TROUVE LE PREMIER PILOTE LE SAUVEGARDE ET PRENDS SON NOMBRE DE POINTS
            if (ite == 0 && (strcmp(tableau[j].ecurie, tab[i].nom) == 0)) {
                p1 = tableau[j].points;
                strcpy(n1, tableau[j].nom);
                ite = 1;
                continue;
            }

            //PRENDS LE DEUXIEME PILOTE LE SAUVEGARDE ET PRENDS SON NOMBRE DE POINTS
            if (ite == 1 && (strcmp(tableau[j].ecurie, tab[i].nom) == 0)) {
                p2 = tableau[j].points;
                strcpy(n2, tableau[j].nom);
                ite = 2;
                break;
            }

        }
        tab[i].points = p1 + p2;

        //REPONSES EN FONCTION DU NOMBRE DE PILOTES DE L'ECURIE
        if (ite == 0) {
            printf("L'ecurie \"%s\" ne possede aucun pilote donc n'a pas de points \n",&tab[i].nom);
        }
        else {
            if (ite == 1) {
                printf("L'ecurie \"%s\" possede %d points. Grace aux %d points de %s \n",tab[i].nom, tab[i].points, p1, n1);
            }
            else {
                if (ite == 2) {
                    printf("L'ecurie \"%s\" possede %d points. Grace aux %d points de %s + les %d points de %s \n",tab[i].nom, tab[i].points, p1, n1, p2, n2);
                }
            }
        }
    }
}





// DETAILS ET CORPS DE LA FONCTION AFFICHERECURIES
void AfficherEcuries (Ecurie tab[],int *nbEcuries) {

    int i;

    // BOUCLE POUR AFFICHER TOUTES LES INFORMATIONS DE CHAQUE ECURIES
    for ( i = 0; i < *nbEcuries; i++)
    {
        printf("Nom : %s", tab[i].nom);
        printf(" Pays : %s", tab[i].pays);
        printf(" Points : %d", tab[i].points);
        printf(" Annee de creation : %d", tab[i].anneeCreation);
        printf(" Directeur : %s", tab[i].directeur);
        printf(" Actif : %d", tab[i].actif);
        printf("\n");
    }
}





void AjouterEcuries (Ecurie tab[],int *nbEcuries){

    int i,j;
    int existant;
    i = (*nbEcuries)-1;


    //DEMANDE DE SAISIR CHAQUE INFORMATIONS DE L'ECURIE A AJOUTER,
    //VERIFIE LES CRITERES DE VALABILITES
    //ET REDEMANDE DE SAISIR LES INFORMATIONS SI ELLES NE REPONDENT PAS AUX CRITERES
    do {
        existant = 0;
        printf("Nom de l'ecurie (non vide): ");
        scanf(" %49[^\n]",tab[i].nom);  // espace devant et [^ \n] pour ne pas prendre en compte les aspaces et retour a la ligne par ChatGPT
        for (j =0 ; j < i; j++) {
            if (strcmp(tab[j].nom, tab[i].nom) == 0 ) { //VERIFIE QUE LE NOM DONNE N'EST PAS DEJA PRIS
                printf("Ce nom existe deja, donnez en un autre.\n");
                existant = 1;
            }
        }
    }while (existant == 1 || tab[i].nom[0] == '\0');

    do {
        printf("Pays (non vide): ");
        scanf("%49s",tab[i].pays);
    }while (tab[i].pays == '\0'); // VERIFIE QUE PAYS N'EST PAS VIDE
    tab[i].points = 0;

    do {
        printf("Annee de creation ( >=1900 et <=2026): ");
        scanf("%d",&tab[i].anneeCreation);
    }while (tab[i].anneeCreation < 1900 || tab[i].anneeCreation > 2026); //VERIFIE QUE L'ANNEE EST BIEN VALABLE

    do {
        printf("Directeur (non vide): ");
        scanf(" %49[^\n]",tab[i].directeur);
    }while (tab[i].directeur == '\0'); // VERIFIE QUE DIRECTEUR N'EST PAS VIDE

    do {
        printf("Actif ( 1 = Oui, 0 = Non): ");
        scanf("%d",&tab[i].actif);
    }while (tab[i].actif < 0 || tab[i].actif > 1); // VERIFIE QUE LA REPONSE EST SOIT 0 SOIT 1

    printf("L'ecurie a bien ete ajoutee.");
    printf("\n");
}





// DETAILS ET CORPS DE LA FONCTION SUPPRIMERECURIE
void SupprimerEcurie (Ecurie tab[],Pilote tableau[], int *nbEcuries,int *EcurieC, int *nbPilotes) {

    int i;

    //BOUCLE DE TRI A BULLE POUR DEPLACER L'ELEMENT CHOISIS A LA FIN DE LA LISTE
    for (i = *EcurieC - 1; i < (*nbEcuries) - 1; ++i)
    {
        Ecurie Sauvegarde = tab[i];
        tab[i] = tab[i+1];
        tab[i+1] = Sauvegarde;
    }

    //BOUCLE QUI SUPPRIME LE NOM DES ECURIES AUX PILOTES ATTACHES ET LES RENDS INACTIFS
    for (int j = 0; j < *nbPilotes; j++) {
        if (strcmp(tab[i].nom, tableau[j].ecurie) == 0) { //VERIFIE QUE LES CHAINES DE DCARACTERES SONT IDENTIQUES
            strcpy(tableau[j].ecurie, "Aucune");
            tableau[j].actif = 0;
        }
    }

    (*nbEcuries)--; //REDUIT LE NOMBRE D'ECURIES DE 1
    tab = realloc(tab, (*nbEcuries) * sizeof(Ecurie)); //REDUIT LA TAILLE DU TABLEAU EN MEMOIRE DE 1 ET SUPPRIME DONC LA DERNIERE ECURIE DU TABLEAU
    printf("L'ecurie a bien ete supprimee."); // MESSAGE DE CONFIRMATION DE SUPPRESSION DE L'ECURIE
}





//DETAILS ET CORPS DE LA FONCTION AJOUTERPILOTE
void AjouterPilote (Pilote tab[], Ecurie tableau[], int nbEcurie, int nbPilotes)
{
    int i,j;
    int num,cool;
    int good,pil;
    int c;
    char ecu[50];

    i = (nbPilotes)-1;

    //DEMANDE DE SAISIR CHAQUE INFORMATIONS DU PILOTE A AJOUTER,
    //VERIFIE LES CRITERES DE VALABILITES
    //ET REDEMANDE DE SAISIR LES INFORMATIONS SI ELLES NE REPONDENT PAS AUX CRITERES
        do {
            printf("\nNom du pilote (non vide) : ");
            scanf("%49s", tab[i].nom);
        }while (tab[i].nom == '\0');

        do {
            printf("Prenom du pilote (non vide) :");
            scanf("%49s", tab[i].prenom);
        }while (tab[i].prenom == '\0');

        do {
            printf("Nationalite du pilote (non vide) : ");
            scanf("%49s", tab[i].nationalite);
        }while (tab[i].nationalite == '\0');

        do {
            good = 0; // 0 INITIALEMENT 2 SI L'ECURIE EXISTE 1 SI TOUT EST BON
            pil = 0;

            do {
                printf("Pour ajouter le pilote a une ecurie existante tappez : 0\nPour affecter le pilote a aucune ecurie tappez: 1\n\n"); //CHOIX ENTRE DEUX OPTIONS
                scanf("%d",&c);
            }while (c != 0 && c != 1);

            if (c == 1) { // SI LA REPONSE CHOISIE EST 1 ON  ATRIBUE AUCUNE A ECURIE
                strcpy(tab[i].ecurie, "Aucune");
                break;
            }

            for (c ; c == 0 ; c) { // SI LA REPONSE EST 0 ON CHERCHE A AFFECTER UNE ECURIE

                printf("Ecurie du pilote : ");
                scanf(" %49[^\n]",ecu);
                for ( j = 0; j < nbEcurie; j++) {
                    if (strcmp(ecu, tableau[j].nom) == 0) { //VERIFIE QUE LE NOM DE L'ECURIE EXISTE
                        good = 2;
                        break;
                    }
                }

                if (good == 0) { //AFFICHE UN MESSAGE D'ERREUR SI L'ECURIE N'EXISTE PAS
                    printf("Cette ecurie n'existe pas veillez choisir une ecurie existante.\n\n");
                    continue;
                }


                for ( j = 0; j < nbPilotes; j++) {
                    //VERIFIE COMBIEN DE PILOTES APPARTIENNENT A L'ECURIE CHOISIE
                    if (strcmp(ecu, tab[j].ecurie) == 0) {
                        pil++;
                    }
                }

                if (pil == 2) {
                    //MESSAGE A AFFICHER SI LE NOMBRE DE PILOTE EST DE 2
                    printf("L'ecurie possede deja 2 pilotes\n\n");
                    break;
                }

                if (good == 2 && pil < 2) {
                    strcpy(tab[i].ecurie, ecu);// SI IL EXISTE ET QUE IL Y A MOINS DE 2 PILOTES DANS L'ECURIE ON ATTRIBUE L'ECURIE
                    good = 1;
                    break;
                }
            }
        }while (good != 1 );

        do {
            printf("Points du pilote (seulement > ou = a 0) : ");
            scanf("%d", &tab[i].points);
        }while (tab[i].points < 0);

        do {
            printf("Numero du pilote (entre 1 et 99) : ");
            scanf(" %d", &num);

            cool = 0;
            if (num < 1 || num > 99) {
                printf("Le numero choisis n'est pas dans la bonne intervalle.\n\n");
                cool = 1;
            }

            for (j = 0; j < nbPilotes-1; j++) {
                if (num == tab[j].numero) {
                    printf("Le numero choisis est deja pris.\nVeillez en choisir un autre.\n\n");
                    cool = 1;
                }
            }

        }while (cool != 0);
        tab[i].numero = num;

        do {
            printf("Age du pilote (entre 18 et 50ans) : ");
            scanf("%d", &tab[i].age);
        }while (tab[i].age < 18 || tab[i].age > 50);

        if (c == 1) {
            tab[i].actif = 0;
        }

        if (c == 0) {
            do {
                printf("Le pilote est il actif (1 = oui, 0 = non): ");
                scanf("%d", &tab[i].actif);
            }while (tab[i].actif < 0 || tab[i].actif > 1);
        }

        printf("Le pilote a bien ete ajoute."); //MESSAGE DE CONFIRMATION D'AJOUT
        printf("\n");
}