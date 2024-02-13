/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Menu.cpp
 * Author: mdeneau
 * 
 * Created on 6 février 2024, 16:20
 */

#include <string>

#include "menu.h"

Menu::Menu(const string &_nom) : nom(_nom), longueurMax(0)
{
    char option[50];
    string nomDuFichier = _nom;
    if (_nom.empty())
    {
        cout << "Entrer le nom du fichier à lire : ";
        cin >> nomDuFichier;
    }
    //Création du flux en lecture sur le fichier
    ifstream leFichier(nomDuFichier.c_str()); // ouvrir le fichier
    if (!leFichier.is_open()) // Si il y a une erreur
    {
        cerr << "Erreur lors de l'ouverture du fichier" << endl; // alors Afficher un message indiquant une erreur de lecture
        nbOptions = 0; // et mettre nbOptions à 0
    }
    else
    {

        int nbLignes = static_cast<int> (count(istreambuf_iterator<char>(leFichier), istreambuf_iterator<char>(), '\n'));
        nbOptions = nbLignes; // Sinon calculer nbOptions, le nombre d’options dans le fichier
        leFichier.seekg(0, ios::beg);
    }
    options = new string[nbOptions]; // allouer dynamiquement le tableau options en fonction de nbOptions
    for (int indice = 0; indice < nbOptions; indice++)
    { // Pour chaque option dans le fichier
        if (leFichier.good())
        {
            leFichier.getline(option, 50);
            options[indice] = option; // Lire l’option et l’affecter dans le tableau options
            if (options[indice].length() > longueurMax)
            {// Si la taille de l’option est plus grande que longueurMax
                longueurMax = options[indice].length(); // alors longueurMax reçoit la taille de l’option

            }// FinSi
        }// FinSi
    }// FinPour

}

Menu::~Menu()
{
    delete [] options;
}

void Menu::AttendreAppuiTouche()
{
    string uneChaine;
    cout << endl << "appuyer sur la touche Entrée pour continuer...";
    getline(cin, uneChaine);
    cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
    system("clear");
}

int Menu::AfficherEtAttendreChoix()
{
    int choix;
    cout << "+" << setfill('-') << setw(6) << "+" << setw(longueurMax + 3) << "+" << endl;
    for (int indice = 0; indice < nbOptions; indice++)
    {
        int nbChoix = indice + 1;
        cout << "|  " << left << setfill(' ') << setw(3) << nbChoix << setw(3) << "|" << setfill(' ') << setw(longueurMax) << options[indice] << "|" << endl;
    }

    cout << "+" << right << setfill('-') << setw(6) << "+" << setw(longueurMax + 3) << "+" << endl;
    cout << "entrez un nombre entre 1 et 5" << endl;
    if (!(cin >> choix))
    {
        cin.clear();
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
        choix = -1;
    }

    return choix;
}

void Menu::EffacerEcran()
{
    system("clear");
}
