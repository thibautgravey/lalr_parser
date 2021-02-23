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
//
//
//------------------------------------------------------------------------

class Automate {
    //----------------------------------------------------------------- PUBLIC
    public:
        //-------------------------------------------- Constructeurs - destructeur
        Automate(Lexer *l) : lexer(l){
            stateStack.push(new Etat0());
        }

        ~Automate();

        //----------------------------------------------------- Méthodes publiques
        void lecture();
        void decalage(Symbole *s, Etat *e);
        void reduction(int n, Symbole *s);
        Symbole* popSymbole();
        void popAndDestroySymbole();

    //------------------------------------------------------------------ PRIVE
    protected:
        //----------------------------------------------------- Attributs protégés
        stack<Etat *> stateStack;
        stack<Symbole *> symbolStack;
        Lexer *lexer;
};

#endif //LALR_PARSER_AUTOMATE_H
