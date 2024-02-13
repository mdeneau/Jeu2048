/* 
 * File:   Joueur.cpp
 * Author: mdeneau
 * 
 * Created on 6 février 2024, 09:37
 */

#include "joueur.h"

Joueur::Joueur() :
duree(0),
score(0)
{
    pseudo.clear();
}

Joueur::Joueur(const string _pseudo, const int _score, const int _duree) :
pseudo(_pseudo),
score(_score),
duree(_duree)
{

}

void Joueur::Actualiser(const int _nouveauScore, const int _duree)
{
    if (_nouveauScore > score)
    {
        score = _nouveauScore;
    }
    duree = duree + _duree;
}

void Joueur::ObtenirInfo(string &_pseudo, int &_score, int &_duree)
{
    _pseudo = pseudo;
    _duree = duree;
    _score = score;
}

bool Joueur::operator<(const Joueur &_autre)const
{
    bool retour = false;
    if (score < _autre.score)
        retour = true;
    return retour;
}

bool Joueur::operator!=(const string _pseudo) const
{
    bool retour = false;
    if (pseudo != _pseudo)
        retour = true;
    return retour;
}

friend bool Joueur::operator<<(const string _pseudo , int _score , int _duree)const
{
    bool retour = false;
    if ( << )
        retour = true;
    return retour;
}