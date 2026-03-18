#ifndef CLASSEMENT_H
#define CLASSEMENT_H

#include "grandprix.h"
#include "pilote.h"

// Fonctions pour gérer les classements
void afficherClassementCourse(GrandPrix gp);        // Classement détaillé d’un Grand Prix
void afficherClassementPilotes(Pilote pilotes[], int nbPilotes); // Classement général des pilotes
void afficherClassementConstructeurs(Ecurie ecuries[], int nbEcuries); // Classement des écuries

#endif
