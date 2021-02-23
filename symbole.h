/*************************************************************************
						    Symbole  -  Header file
							 -------------------
	début                : 23/02/2021
	copyright            : (C) 2021 par LG, INSA LYON
*************************************************************************/

//---------- Interface de la classe <Symbole> (fichier symbole.h) ------
#pragma once

//--------------------------------------------------- Interfaces utilisées
#include <string>
using namespace std;

//------------------------------------------------------------- Constantes
const string Etiquettes[] = { "OPENPAR", "CLOSEPAR", "PLUS", "MULT", "INT", "FIN", "ERREUR", "EXPR"};

//------------------------------------------------------------------ Types
enum Identificateurs { OPENPAR, CLOSEPAR, PLUS, MULT, INT, FIN, ERREUR, EXPR };

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
        virtual bool isTerminal();

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
        virtual bool isTerminal();
        int eval();

    //------------------------------------------------------------------ PRIVE
    protected:
        //----------------------------------------------------- Attributs protégés
        int valeur;
};

class Expr : public Symbole {
    //----------------------------------------------------------------- PUBLIC
    public:
        //-------------------------------------------- Constructeurs - destructeur
        Expr(int v) : Symbole(EXPR), valeur(v) { }
        ~Expr() { }

        //----------------------------------------------------- Méthodes publiques
        virtual void Affiche();
        virtual bool isTerminal();
        int eval();

    //------------------------------------------------------------------ PRIVE
protected:
    //----------------------------------------------------- Attributs protégés
    int valeur;
};

