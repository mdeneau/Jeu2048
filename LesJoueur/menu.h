/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Menu.h
 * Author: mdeneau
 *
 * Created on 6 février 2024, 16:20
 */

#ifndef MENU_H
#define MENU_H

#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>


using namespace std;

enum CHOIX_MENU
{
    AJOUTER = 1,
    VISUALISER,
    CHARGER,
    SAUVEGARDER,
    QUITTER
};

class Menu
{
public:

    Menu(const string &_nom);
    virtual ~Menu();
    int AfficherEtAttendreChoix();
    static void EffacerEcran();
    static void AttendreAppuiTouche();
private:
    string nom;
    string* options;
    int nbOptions;
    int longueurMax;


};

#endif /* MENU_H */

