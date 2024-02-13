#include "plateau.h"

Plateau::Plateau()
{
    score = 0;
    nbCoups = 0;
}

void Plateau::Afficher()
{
    int laGrille[TAILLE][TAILLE];
    int indice;

    system("clear");
    leJeu.ObtenirGrille(laGrille);
    cout << "| Score : " << score << " | Nombre de coups : " << nbCoups << " |" << endl;
    cout << endl;
    for (int ligne = 0; ligne < 4; ligne++)
    {
        cout << " +";
        for (indice = 0; indice < 4; indice++)
        {
            cout << setw(7) << setfill('-') << '+';

        }
        cout << endl << " |";
        for (indice = 0; indice < 4; indice++)
        {
            if (laGrille[ligne][indice] != 0)
                cout << setfill(' ') << setw(6) << laGrille[ligne][indice] << '|';
            else
            {
                cout << setfill(' ') << setw(7) << '|';
            }
        }
        cout << endl;
    }
    cout << " +";
    for (indice = 0; indice < 4; indice++)
        cout << setw(7) << setfill('-') << '+';

    cout << endl << endl << "F pour sortir du jeu" << endl;
    cout << "Votre déplacement : H(↑), B(↓), G(←), D(→) : " << endl;
}

bool Plateau::JouerCoup()
{
    bool retour = false;
    char touche;
    cin >> touche;
    touche = toupper(touche);
    if (strchr("BHGD", touche) != nullptr)
    {
        nbCoups++;
        leJeu.Deplacer(touche);
        leJeu.PlacerNouvelleTuille();
        Afficher();
    }
    if (touche == 'F')
        retour = true;
    return retour;
}

