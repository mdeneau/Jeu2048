/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: mdeneau
 *
 * Created on 6 février 2024, 09:36
 */


#include <cstdlib>
#include "joueur.h"
#include "menu.h"
#include "gestionJoueurs.h"

using namespace std;

int main(int argc, char** argv)
{
    Menu leMenu("Menu.txt");
    int choix;
    Joueur tabJoueurs[NB_MAX_JOUEURS];
    int nbJoueurs = 0;
    string pseudo;
    int score;
    int duree;
    do
    {
        choix = leMenu.AfficherEtAttendreChoix();
        switch (choix)
        {
        case AJOUTER:
        {
            int pos;
            cout << "Pseudo score durée :";
            cin >> pseudo >> score >> duree;
            pos = RechercherJoueur(tabJoueurs, NB_MAX_JOUEURS, pseudo);
            if (pos != -1)
            {
                tabJoueurs[pos].Actualiser(score, duree);
            }

            else
            {
                tabJoueurs[nbJoueurs++] = Joueur(pseudo, score, duree);
            }

            if (nbJoueurs > 1)
            {
                TrierTableauJoueurs(tabJoueurs, NB_MAX_JOUEURS);
            }

            Menu::EffacerEcran();

            break;
        }
        case VISUALISER:
        {
            Menu::EffacerEcran();
            cout << "+" << setfill('-') << setw(13) << "+" << setw(9) << "+" << setw(9) << "+" << endl;
            for (int i = 0; i < nbJoueurs; i++)
            {
                tabJoueurs[i].ObtenirInfo(pseudo, score, duree);
                cout << "| " << left << setfill(' ') << setw(10) << pseudo << " | " << right << setw(6) << score << " | " << right << setw(6) << duree << " |" << endl;
            }
            cout << "+" << setfill('-') << setw(13) << "+" << setw(9) << "+" << setw(9) << "+" << endl;
            Menu::AttendreAppuiTouche();
            break;
        }
        case CHARGER:
        {


            break;
        }
        case SAUVEGARDER:
        {


            break;
        }
        }
    }
    while (choix != QUITTER);
    return 0;
}