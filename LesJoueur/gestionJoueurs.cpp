
/* 
 * File:   gestionJoueurs.cpp
 * Author: mdeneau
 * 
 * Created on 7 février 2024, 08:39
 */

#include <curses.h>

#include "gestionJoueurs.h"

int RechercherJoueur(Joueur * _tab, const int _nb, const string &_pseudo)
{
    int retour = 0;
    while(retour < _nb && _tab[retour] != _pseudo){
        retour++;
    }
    if (retour == _nb)
        retour = -1;
    
    return retour ;
}

void TrierTableauJoueurs(Joueur * _tab, const int _nb)
{
    bool tri = false;
    int borne = _nb;
    
    while (tri == false)
    {
        tri = true;
        for (int i = 0; i < borne - 1 ; i++)
        {
            if(_tab[i] < _tab[i+1])
            {
                Joueur sub = _tab[i];
                _tab[i] = _tab[i+1];
                _tab[i+1] = sub;
                tri = false;
            }//fin Si 
        }//fin Pour
        borne = borne -1;
    }// fin TantQue 
}