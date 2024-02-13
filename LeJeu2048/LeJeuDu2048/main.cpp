#include <cstdlib>
#include "plateau.h"

using namespace std;


int main(int argc, char** argv)
{
    Plateau lePlateau;
    
    bool fin = false;
    
    lePlateau.Afficher();
    
    do{
        fin = lePlateau.JouerCoup();
    }while(fin != true);

    return 0;
}

