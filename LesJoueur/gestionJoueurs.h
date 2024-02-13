
/* 
 * File:   gestionJoueurs.h
 * Author: mdeneau
 *
 * Created on 7 février 2024, 08:39
 */

#ifndef GESTIONJOUEURS_H
#define GESTIONJOUEURS_H
#include <string>
#include "joueur.h"

int RechercherJoueur(Joueur * _tab, const int _nb, const string &_pseudo);
void TrierTableauJoueurs(Joueur * _tab, const int _nb);
#endif /* GESTIONJOUEURS_H */

