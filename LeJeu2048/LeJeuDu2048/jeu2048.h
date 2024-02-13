#ifndef JEU2048_H
#define JEU2048_H
#include <string>
#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <future>
#include <math.h>
#include <time.h>
#define TAILLE 4

using namespace std;

class Jeu2048
{
public:

    enum ETATS_DU_JEU
    {
        EN_COURS,
        PERDU,
        GAGNE
    };

    Jeu2048();
    void PlacerNouvelleTuille();
    bool Calculer(const char _direction);
    void Deplacer(const char _direction);
    int CalculerScore();
    void ObtenirGrille(int _grille[][TAILLE]);
    ETATS_DU_JEU RechercherFinDePartie();
private:
    int grille[TAILLE][TAILLE];
};

#endif /* JEU2048_H */

