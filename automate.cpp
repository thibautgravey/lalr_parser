/*************************************************************************
						  Automate  -  Implementation
							 -------------------
	début                : 23/02/2021
	copyright            : (C) 2021 par BRANCHEREAU Corentin, GRAVEY Thibaut
*************************************************************************/

//---------- Réalisation de la classe <Automate> (fichier automate.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
//------------------------------------------------------ Include personnel
#include "automate.h"
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Automate::Lecture() {
    Symbole * s;
    bool end = false;
    while (!end) {
        s = lexer->Consulter();
        end = stateStack.top()->Transition(*this, s);
    }
    if (!errorFlag) {
        cout << "Structure de l'arbre obtenue : ";
        symbolStack.top()->Affiche();
        cout << endl
             << "Resultat final apres analyse LALR : " << ((Expr *)symbolStack.top())->Eval() << endl;
    }

    //Libération de mémoire
    int size = symbolStack.size();
    for (int i = 0; i < size; i++) {
        delete (symbolStack.top());
        symbolStack.pop();
    }

    size = stateStack.size();
    for (int i = 0; i < size; i++) {
        delete (stateStack.top());
        stateStack.pop();
    }

    delete (s);
} //Fin de Lecture

void Automate::Decalage(Symbole * s, Etat * e) {
    symbolStack.push(s);
    stateStack.push(e);
    if (s->IsTerminal()) {
        lexer->Avancer();
    }
} //Fin de Decalage

void Automate::Reduction(int n, Symbole * s) {
    for (int i = 0; i < n; i++) {
        delete (stateStack.top());
        stateStack.pop();
    }
    stateStack.top()->Transition(*this, s);
} //Fin de Reduction

Symbole * Automate::PopSymbole() {
    Symbole * res = symbolStack.top();
    symbolStack.pop();
    return res;
} //Fin de PopSymbole

void Automate::PopAndDestroySymbole() {
    delete (symbolStack.top());
    symbolStack.pop();
} //Fin de PopAndDestroySymbole

void Automate::SetError() {
    errorFlag = true;
} //Fin de SetError

Lexer * Automate::GetLexer() {
    return this->lexer;
} //Fin de GetLexer