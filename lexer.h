/*************************************************************************
						    Lexer  -  Header file
							 -------------------
	début                : 23/02/2021
	copyright            : (C) 2021 par LG, INSA LYON
*************************************************************************/

//---------- Interface de la classe <Lexer> (fichier lexer.h) ------
#pragma once

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include "symbole.h"

using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Lexer>
// Analyseur lexical trivial permettant la lecture de symbole telles que
// la parenthèse ouvrante, fermante, les signes + et * ainsi que des entiers.
//------------------------------------------------------------------------
class Lexer
{
    //----------------------------------------------------------------- PUBLIC
public:
    //-------------------------------------------- Constructeurs - destructeur
    Lexer(string s) : flux(s), tete(0), tampon(nullptr) {}
    ~Lexer() {}

    //----------------------------------------------------- Méthodes publiques
    Symbole *Consulter();
    void Avancer();
    string GetFlux();
    int GetTete();

    //------------------------------------------------------------------ PRIVE
protected:
    //----------------------------------------------------- Attributs protégés
    string flux;
    int tete;
    Symbole *tampon;
};
