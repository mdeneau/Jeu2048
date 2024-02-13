#include "jeu2048.h"

Jeu2048::Jeu2048()
{
    for (int i = 0; i < 4; i++)
    {
        for (int i2 = 0; i2 < 4; i2++)
        {
            grille[i][i2] = 0;
        }
    }
    srand(time(nullptr));
    PlacerNouvelleTuille();
}

void Jeu2048::ObtenirGrille(int _grille[][TAILLE])
{
    for (int i = 0; i < 4; i++)
    {
        for (int i2 = 0; i2 < 4; i2++)
        {
            _grille[i][i2] = grille[i][i2];
        }
    }
}

void Jeu2048::PlacerNouvelleTuille()
{
    int chiffre = (((rand() % 2) + 1) * 2);
    int largeur = rand() % 4;
    int longueur = rand() % 4;


    while (grille[longueur][largeur] = 0)
    {
        largeur = rand() % 4;
        longueur = rand() % 4;
    }

    grille[longueur][largeur] = chiffre;

}

//bool Jeu2048::Calculer(const char _direction)
//
//{
//
//    bool retour = false;
//    int ligne;
//    int colonne;
//       
//    for (int indice = 0; indice < 4; indice++)
//    {
//        switch (_direction)
//        {
//        case 'G':
//            for (ligne = 0; ligne < 4; ligne++)
//            {
//                for (colonne = 0; colonne < 3; colonne++)
//                {
//                    if (grille[ligne][colonne] == grille[ligne][colonne + 1])
//                    {
//                        grille[ligne][colonne] = grille[ligne][colonne + 1] * 2;
//                        grille[ligne][colonne + 1] = 0;
//                        return retour = true;
//                    }
//                }
//            }
//            break;
//
//        case 'D':
//
//        
//
//            break;
//
//        case 'H':
//
//            
//
//            break;
//
//        case 'B':
//
//            
//
//            break;
//
//        default:
//
//            return false;
//            
//        }
//
//    }
//
//
//    return true;
//
//}


void Jeu2048::Deplacer(const char _direction)
{
    int ligne;
    int colonne;
    for (int indice = 0; indice < 4; indice++)
    {
        switch (_direction)
        {
        case 'G':
            for (ligne = 0; ligne < 4; ligne++)
            {
                for (colonne = 0; colonne < 3; colonne++)
                {
                    if (grille[ligne][colonne] == 0)
                    {
                        grille[ligne][colonne] = grille[ligne][colonne + 1];
                        grille[ligne][colonne + 1] = 0;
                    }
                }
            }
            break;
             
        }
        
        switch (_direction)
        {
        case 'D':
            for (ligne = 0; ligne < 4; ligne++)
            {
                for (colonne = 1; colonne < 4; colonne++)
                {
                    if (grille[ligne][colonne] == 0)
                    {
                        grille[ligne][colonne] = grille[ligne][colonne - 1];
                        grille[ligne][colonne - 1] = 0;
                    }
                }
            }
            break;
            
        }
        
        switch (_direction)
        {
        case 'B':
            for (ligne = 1; ligne < 4; ligne++)
            {
                for (colonne = 0; colonne < 4; colonne++)
                {
                    if (grille[ligne][colonne] == 0)
                    {
                        grille[ligne][colonne] = grille[ligne-1][colonne];
                        grille[ligne-1][colonne] = 0;
                    }
                }
            }
            break;
            
        }
        
        switch (_direction)
        {
        case 'H':
            for (ligne = 0; ligne < 3; ligne++)
            {
                for (colonne = 0; colonne < 4; colonne++)
                {
                    if (grille[ligne][colonne] == 0)
                    {
                        grille[ligne][colonne] = grille[ligne+1][colonne];
                        grille[ligne+1][colonne] = 0;
                    }
                }
            }
            break;
            
        }
    }
    
    }





//int Jeu2048::CalculerScore() {
//
//return ;
//}
//
//
//
//ETATS_DU_JEU Jeu2048::RechercherFinDePartie() {
//
//return;
//}


