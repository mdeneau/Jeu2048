/* 
 * File:   Joueur.h
 * Author: mdeneau
 *
 * Created on 6 février 2024, 09:37
 */

#ifndef JOUEUR_H
#define JOUEUR_H
#include <string>
#define NB_MAX_JOUEURS 20

using namespace std;

class Joueur
{
public:
    Joueur();
    Joueur(const string _pseudo, const int _score = 0, const int _duree = 0);
    void Actualiser(const int _nouveauScore, const int _duree);
    void ObtenirInfo(string &_pseudo, int &_score, int &_duree);
    bool operator<(const Joueur &_autre)const;
    friend bool operator<<(const string _pseudo, int _score, int _duree) const;
    friend ostream & operator << (ostream &, &_autre);
    bool operator!=(const string _pseudo) const;
private:
    string pseudo;
    int score;
    int duree;
};

#endif /* JOUEUR_H */