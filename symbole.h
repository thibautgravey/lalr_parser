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
const string Etiquettes[] = {"OPENPAR", "CLOSEPAR", "PLUS", "MULT", "INT", "FIN", "ERREUR", "EXPR"};

//------------------------------------------------------------------ Types
enum Identificateurs
{
    OPENPAR,
    CLOSEPAR,
    PLUS,
    MULT,
    INT,
    FIN,
    ERREUR,
    EXPR
};

//------------------------------------------------------------------------
// Rôle de la classe <Symbole>
// Permet la représentation des éléments lus par le lexer. L'affichage,
// l'évaluation d'un symbole et ses propriétés terminales ou non sont gérées
// par le polymorphisme de cette classe.
//------------------------------------------------------------------------

class Symbole
{
    //----------------------------------------------------------------- PUBLIC
public:
    //-------------------------------------------- Constructeurs - destructeur
    Symbole(int i, char s) : ident(i), symbole(s) {}
    virtual ~Symbole() {}

    //------------------------------------------------- Surcharge d'opérateurs
    operator int() const { return ident; }

    //----------------------------------------------------- Méthodes publiques
    virtual void Affiche();
    virtual char GetSymbole();
    virtual bool IsTerminal();

    //------------------------------------------------------------------ PRIVE
protected:
    //----------------------------------------------------- Attributs protégés
    int ident;
    char symbole;
};

class Entier : public Symbole
{
    //----------------------------------------------------------------- PUBLIC
public:
    //-------------------------------------------- Constructeurs - destructeur
    Entier(int v) : Symbole(INT, v), valeur(v) {}
    ~Entier() {}

    //----------------------------------------------------- Méthodes publiques
    virtual void Affiche();
    virtual bool IsTerminal();
    int eval();

    //------------------------------------------------------------------ PRIVE
protected:
    //----------------------------------------------------- Attributs protégés
    int valeur;
};

class Expr : public Symbole
{
    //----------------------------------------------------------------- PUBLIC
public:
    //-------------------------------------------- Constructeurs - destructeur
    Expr(int v) : Symbole(EXPR, v), valeur(v) {}
    ~Expr() {}

    //----------------------------------------------------- Méthodes publiques
    virtual void Affiche();
    virtual bool IsTerminal();
    int eval();

    //------------------------------------------------------------------ PRIVE
protected:
    //----------------------------------------------------- Attributs protégés
    int valeur;
};
