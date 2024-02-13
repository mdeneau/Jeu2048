#ifndef PLATEAU_H
#define PLATEAU_H
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <future>
#include "jeu2048.h"
#include <math.h>
#include <time.h>


class Plateau
{
public:

    Plateau();
    void Afficher();
    bool JouerCoup();

private:
    int nbCoups;
    int score;
    Jeu2048 leJeu;

};

#endif /* PLATEAU_H */

