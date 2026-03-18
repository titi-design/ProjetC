//
// Created by 20250973 on 29/10/2025.
//
#include "GrandPrix.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ecurie.h"
//#include "date.h"
Ecurie tabEcuries[50];
int nbEcuries;
// Ajouter un Grand Prix
void ajouterGrandPrix(GrandPrix *gp) {
    int nombreTours;
    char nomCircuit[50];
    int c;
    int jour;
    int mois;
    int annee;
    int bissextile;
    int bigMois[]={1, 3, 5, 7, 8, 10, 12};
    int taille = sizeof(bigMois) / sizeof(bigMois[0]);
    int heure;
    int minutes;

    printf("Entrez le nom du circuit que vous voulez sélectionner : ");
    fgets(nomCircuit, sizeof(nomCircuit), stdin);
    nomCircuit[strcspn(nomCircuit, "\n")] = '\0'; // Supprimer l'espace garder par le fgets

    // On répète la même logique pour le pays
    char nomPays[50];
    printf("Entrez le nom du Pays que vous voulez sélectionner : "); // Supprimer l'espace garder par le fgets
    fgets(nomPays, sizeof(nomPays), stdin);
    nomPays[strcspn(nomPays, "\n")] = '\0';

    // Demande le nombre de tours et valide qu'il est entre 10 et 100
    do {
        printf("Entrez le nombre de Tours que contient le Grand Prix : ");
        scanf("%d", &nombreTours);
    } while (nombreTours > 100 || nombreTours < 10);

    // Vide le buffer après scanf pour éviter les problèmes avec fgets
    while ((c = getchar()) != '\n' && c != EOF);
    // Demande la date (jour, mois, année) et valide les bornes
    printf("Vous allez désormais entrer la date du Grand Prix.");
    do {
        printf("Entrez l'année durant laquelle va se dérouler le Grand Prix : ");
        scanf("%d", &annee);
    } while (annee < 1900 || annee > 2100);
    if ((annee % 4 == 0 && annee % 100 != 0) || (annee % 400 == 0)) {
        bissextile = 1;
    } else {
        bissextile = 0;
    }
    if (bissextile == 1) {
        do {
            printf("Entrez le mois, sous forme décimale, que vous choisissez pour le Grand Prix : ");
            scanf("%d", &mois);
        } while (mois > 12 || mois < 1);

        for (int i=0; i < taille; i++) {
            if (bigMois[i] == mois) {
                do {
                    printf("Entrez le jour, sous forme décimale, que vous choisissez pour le Grand Prix : ");
                    scanf("%d", &jour);
                } while (jour > 31 || jour < 1);
            } else if (mois == 2) {
                do {
                    printf("Entrez le jour, sous forme décimale, que vous choisissez poue le Grand Prix : ");
                    scanf("%d", &jour);
                } while (jour > 29 || jour < 1);
            } else {
                do {
                    printf("Entrez le jour, sous forme décimale, que vous choisissez pour le Grand Prix : ");
                    scanf("%d", &jour);
                } while (jour > 30 || jour < 1);
            }
        }
    } else {
        do {
            printf("Entrez le mois, sous forme décimale, que vous choisissez pour le Grand Prix : ");
            scanf("%d", &mois);
        } while (mois > 12 || mois < 1);

        for (int i=0; i < taille; i++) {
            if (bigMois[i] == mois) {
                do {
                    printf("Entrez le jour, sous forme décimale, que vous choisissez pour le Grand Prix : ");
                    scanf("%d", &jour);
                } while (jour > 31 || jour < 1);
            } else if (mois == 2) {
                do {
                    printf("Entrez le jour, sous forme décimale, que vous choisissez poue le Grand Prix : ");
                    scanf("%d", &jour);
                } while (jour > 28 || jour < 1);
            } else {
                do {
                    printf("Entrez le jour, sous forme décimale, que vous choisissez pour le Grand Prix : ");
                    scanf("%d", &jour);
                } while (jour > 30 || jour < 1);
            }
        }
    }
    gp->d.jour = jour;
    gp->d.mois = mois;
    gp->d.annee = annee;
    // Demande l’horaire (heure, minute) et valide les bornes
    printf("Vous allez désormais entrer l'horaire.");
    do {
        printf("Entrez une heure : ");
        scanf("%d", &heure);
    } while (heure > 23 || heure < 0);

    do {
        printf("Entrez les minutes : ");
        scanf("%d", &minutes);
    } while (minutes > 59 || minutes < 0);

    // Initialise nombreResultats à 0 et actif à 1
    gp->nbResultats = 0;
}

// Saisir les résultats d’un Grand Prix
void saisirResultats(GrandPrix *gp, Pilote pilotes[], int nbPilotes) {
    char Pilote[50];
    int resChoisis;
    int j;
    int d;
    int pos;
    int existe;
    int p;
    int pointsFIA[20] = {25,18,15,12,10,8,6,4,2,1,0,0,0,0,0,0,0,0,0,0};

    // Demande combien de résultats seront saisis (max 20)
    do {
        printf("Combien de résultats souhaitez-vous saisir pour ce Grand Prix ? (maximum 20 pilotes) : ");
        scanf("%d", &resChoisis);
    } while (resChoisis > 20 || resChoisis < 1);

    // Allocation dynamique du tableau des positions
    int *position = malloc(resChoisis * sizeof(int));

    // Pour chaque résultat :
    for (j = 0; j < resChoisis; j++) {
        printf("Entrez le nom et le prénom du pilote : ");
        while ((d = getchar()) != '\n' && d != EOF); // Vide le buffer
        fgets(Pilote, sizeof(Pilote), stdin);
        Pilote[strcspn(Pilote, "\n")] = '\0'; // Supprimer le \n

        // Ici tu peux ajouter la vérification que le pilote existe dans le tableau `pilotes[]`
        int piloteExiste = 0;
        for (int k=0; k<nbPilotes; k++) {
            char nomComplet[100];
            snprintf(nomComplet, sizeof(nomComplet), "%s %s", pilotes[k].nom, pilotes[k].prenom);
            if (strcmp(Pilote, nomComplet) == 0) {
                piloteExiste = 1;
                break;
            }
        }

        if (!piloteExiste) {
            printf("Ce pilote n'existe pas dans la liste des pilotes. Veuillez réessayer.\n");
            j--; // pour répéter cette itération
            continue;
        }

        // Saisie de la position avec vérification d’unicité
        do {
            existe = 0;
            printf("Entrez la position du pilote : ");
            scanf("%d", &pos);

            if (pos > resChoisis || pos < 1) {
                printf("Position invalide. Veuillez entrer une position entre 1 et %d.\n", resChoisis);
                continue;
            }

            for (int k=0; k<j; k++) {
                if (position[k]==pos) {
                    existe = 1;
                    printf("Cette position est déjà attribuée à un autre pilote. Veuillez en choisir une autre.\n");
                    break;
                }
            }
        } while (existe);

        position[j] = pos;
    }

    // Libération de la mémoire
    free(position);

    //   - Demande le temps réalisé (format H:MM:SS.sss)
    printf("Vous allez désormais entrer le temps réalisé pour chaque pilote.\n");

    // Pour chaque résultat déjà saisi
    for (p = 0; p < resChoisis; p++) {
        char temps[15];

        printf("Entrez le temps du pilote #%d (format H:MM:SS.sss) : ", p + 1);
        while ((d = getchar()) != '\n' && d != EOF); // vide le buffer
        fgets(temps, sizeof(temps), stdin);
        temps[strcspn(temps, "\n")] = '\0'; // enlève le \n

        // On associe le temps à la bonne entrée du tableau
        strcpy(gp->resultats[p].temps, temps);

        // Stocke la position
        gp->resultats[p].position = position[p];

        // On retrouve le pilote correspondant (en fonction du nom saisi plus haut)
        for (int k = 0; k < nbPilotes; k++) {
            char nomComplet[100];
            snprintf(nomComplet, sizeof(nomComplet), "%s %s", pilotes[k].nom, pilotes[k].prenom);
            if (strcmp(Pilote, nomComplet) == 0) {
                gp->resultats[p].pilote = &pilotes[k];
                break;
            }
        }

        printf("Temps enregistré : %s\n", gp->resultats[p].temps);
    }
    //   - Calcule les points FIA en fonction de la position
    for (p = 0; p < resChoisis; p++) {
        int pts = 0;
        if (gp->resultats[p].position <= 20) {
            pts = pointsFIA[gp->resultats[p].position - 1];
        }
        gp->resultats[p].pointsObtenus = pts;
    }
    //   - Met à jour les points du pilote dans le tableau des pilotes
    for (int i = 0; i < resChoisis; i++) {
        int pos = position[i]; // position saisie par l'utilisateur
        gp->resultats[i].pilote->points += pointsFIA[pos-1]; // -1 car tableau indexé à 0
        gp->resultats[i].pointsObtenus = pointsFIA[pos-1];  // si tu veux garder le détail du GP
    }

    //   - Met à jour les points de l’écurie associée
    for (p = 0; p < resChoisis; p++) {
        for (int k = 0; k < nbEcuries; k++) { // nbEcuries doit être passé à la fonction ou global
            if (strcmp(tabEcuries[k].nom, gp->resultats[p].pilote->ecurie) == 0) {
                tabEcuries[k].points += gp->resultats[p].pointsObtenus;
                break;
            }
        }
    }
    // Incrémente nombreResultats dans la structure GrandPrix
    gp->nbResultats += resChoisis;
}



// Afficher la liste des Grands Prix
void afficherGrandsPrix(GrandPrix g[], int n) {
    printf("Liste des Grands Prix :\n");

    // On parcourt le tableau des Grands Prix
    for (int i = 0; i < n; i++) {
        // On suppose qu'un Grand Prix est actif si son nombre de résultats est >= 0
        // (actif)
        if (g[i].nbResultats >= 0) {
            printf("\nGrand Prix #%d :\n", i + 1);
            printf("Circuit : %s\n", g[i].nom);
            printf("Pays : %s\n", g[i].pays);

            // Affiche la date
            printf("Date : %02d/%02d/%04d\n", g[i].d.jour, g[i].d.mois, g[i].d.annee);

            // Affiche l'horaire si tu as un champ horaire
            // printf("Horaire : %02d:%02d\n", g[i].horaire.heure, g[i].horaire.minute);

            printf("Nombre de résultats saisis : %d\n", g[i].nbResultats);
        }
    }
}

void supprimerGrandPrix(GrandPrix g[], int *n, int index) {
    // Vérifie que l'index est valide
    if (index < 0 || index >= *n) {
        printf("Index invalide. Aucun Grand Prix supprimé.\n");
        return;
    }

    // Suppression logique : on met nbResultats à -1 pour indiquer que le GP est supprimé
    g[index].nbResultats = -1;

    printf("Grand Prix '%s' supprimé.\n", g[index].nom);

    // Réduction des points des pilotes et des écuries associés au GP
    for (int i = 0; i < 20; i++) {
        if (g[index].resultats[i].pilote != 0) {
            // Retire les points obtenus par le pilote pour ce GP
            g[index].resultats[i].pilote->points -= g[index].resultats[i].pointsObtenus;

            // Retire les points à l’écurie correspondante
            for (int k = 0; k < nbEcuries; k++) {
                if (strcmp(tabEcuries[k].nom, g[index].resultats[i].pilote->ecurie) == 0) {
                    tabEcuries[k].points -= g[index].resultats[i].pointsObtenus;
                    break;
                }
            }
        }
    }
}

#include <stdio.h>
#include "grandprix.h"

// Affiche le Top 3 d'un Grand Prix
void afficherTop3(GrandPrix gp) {
    printf("===== Top 3 du Grand Prix : %s =====\n", gp.nom);

    // On parcourt les 3 premières positions (ou moins si moins de résultats)
    for (int i = 0; i < 3 && i < gp.nbResultats; i++) {
        printf("Position %d : %s %s (%s) - Temps : %s - Points : %d\n",
               gp.resultats[i].position,
               gp.resultats[i].pilote->nom,
               gp.resultats[i].pilote->prenom,
               gp.resultats[i].pilote->nationalite,
               gp.resultats[i].temps,
               gp.resultats[i].pointsObtenus);
    }
    printf("\n");
}



