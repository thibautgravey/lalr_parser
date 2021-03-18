/*************************************************************************
						   Automate  -  Header file
							 -------------------
	début                : 23/02/2021
	copyright            : (C) 2021 par BRANCHEREAU Corentin, GRAVEY Thibaut
*************************************************************************/

//---------- Interface de la classe <Automate> (fichier automate.h) ------
#ifndef LALR_PARSER_AUTOMATE_H
#define LALR_PARSER_AUTOMATE_H

//--------------------------------------------------- Interfaces utilisées
#include "lexer.h"
#include "symbole.h"
#include "etat.h"
#include <stack>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Automate>
// L'automate gère les différentes actions de décalage et de réduction
// à réaliser. Il gère aussi sa pile d'état et de symbole (automate à pile)
// afin de pouvoir, grâce à une sorte de design pattern STATE d'analyser
// la chaîne lexicale. De plus, la classe permet aussi une facilité d'accès
// à la pile des symboles avec des fonctions telles que popSymbole ou
// popAndDestroy.
// Enfin, un flag d'erreur permet de vérifier à la fin de l'analyse
// si une erreur a été détectée ou non durant le parsage.
//------------------------------------------------------------------------

class Automate
{
    //----------------------------------------------------------------- PUBLIC
public:
    //-------------------------------------------- Constructeurs - destructeur
    Automate(Lexer *l) : lexer(l), errorFlag(false)
    {
        stateStack.push(new Etat0);
    }

    ~Automate() {}

    //----------------------------------------------------- Méthodes publiques
    void lecture();
    void decalage(Symbole *s, Etat *e);
    void reduction(int n, Symbole *s);
    Symbole *popSymbole();
    void popAndDestroySymbole();
    void setError();
    Lexer *getLexer();

    //------------------------------------------------------------------ PRIVE
protected:
    //----------------------------------------------------- Attributs protégés
    stack<Etat *> stateStack;
    stack<Symbole *> symbolStack;
    bool errorFlag;
    Lexer *lexer;
};

#endif //LALR_PARSER_AUTOMATE_H
