/*************************************************************************
						    Symbole  -  Header file
							 -------------------
	début                : 22/02/2020
	copyright            : (C) 2020 par LG, INSA LYON
*************************************************************************/

//---------- Interface de la classe <Symbole> (fichier symbole.h) ------
#pragma once

//--------------------------------------------------- Interfaces utilisées
#include <string>
using namespace std;

//------------------------------------------------------------- Constantes
const string Etiquettes[] = { "OPENPAR", "CLOSEPAR", "PLUS", "MULT", "INT", "FIN", "ERREUR" };

//------------------------------------------------------------------ Types
enum Identificateurs { OPENPAR, CLOSEPAR, PLUS, MULT, INT, FIN, ERREUR };

//------------------------------------------------------------------------
// Rôle de la classe <Symbole>
//
//
//------------------------------------------------------------------------

class Symbole {
    //----------------------------------------------------------------- PUBLIC
    public:
        //-------------------------------------------- Constructeurs - destructeur
        Symbole(int i) : ident(i) {  }
        virtual ~Symbole() { }

        //------------------------------------------------- Surcharge d'opérateurs
        operator int() const { return ident; }

        //----------------------------------------------------- Méthodes publiques
        virtual void Affiche();

    //------------------------------------------------------------------ PRIVE
    protected:
        //----------------------------------------------------- Attributs protégés
        int ident;
};

class Entier : public Symbole {
    //----------------------------------------------------------------- PUBLIC
    public:
        //-------------------------------------------- Constructeurs - destructeur
        Entier(int v) : Symbole(INT), valeur(v) { }
        ~Entier() { }

        //----------------------------------------------------- Méthodes publiques
        virtual void Affiche();

    //------------------------------------------------------------------ PRIVE
    protected:
        //----------------------------------------------------- Attributs protégés
        int valeur;
};

