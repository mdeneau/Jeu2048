#include "gestionJoueurs.h"

int RechercherJoueur(Joueur * _tab, const int _nb, const string &_pseudo)
{
    int i = -1;

    while (_tab[i] != _pseudo && i < _nb)
        i++;

    if (i == _nb)
    {
        i = -1;
    }

    return i;
}