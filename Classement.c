#include <stdio.h>
#include "grandprix.h"
#include "pilote.h"
#include "ecurie.h"

// ===== Classement d'une course =====
void afficherClassementCourse(GrandPrix gp) {
    printf("===== Classement du Grand Prix : %s =====\n", gp.nom);

    // On parcourt tous les résultats du GP
    for (int i = 0; i < gp.nbResultats; i++) {
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

// ===== Top 3 d'une course =====
void afficherTop3(GrandPrix gp) {
    printf("===== Top 3 du Grand Prix : %s =====\n", gp.nom);

    // Parcourt les 3 premiers résultats ou moins
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

// ===== Classement général des pilotes =====
void afficherClassementPilotes(Pilote pilotes[], int nbPilotes) {
    printf("===== Classement général des pilotes =====\n");

    // Version simple : on ne trie pas, juste on affiche tous les pilotes
    for (int i = 0; i < nbPilotes; i++) {
        if (pilotes[i].actif) { // On affiche seulement les pilotes actifs
            printf("%s %s (%s) - Points : %d\n",
                   pilotes[i].nom,
                   pilotes[i].prenom,
                   pilotes[i].nationalite,
                   pilotes[i].points);
        }
    }
    printf("\n");
}

// ===== Classement général des écuries =====
void afficherClassementEcuries(Ecurie tabEcuries[], int nbEcuries) {
    printf("===== Classement général des écuries =====\n");

    // Version simple : on affiche toutes les écuries sans tri
    for (int i = 0; i < nbEcuries; i++) {
        if (tabEcuries[i].actif) { // Seulement les écuries actives
            printf("%s (%s) - Points : %d\n",
                   tabEcuries[i].nom,
                   tabEcuries[i].pays,
                   tabEcuries[i].points);
        }
    }
    printf("\n");
}
