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
void Automate::lecture() {
	Symbole * s;
	bool end = false;
	while(!end) {
		s->Affiche();
		end = stateStack.top()->transition(*this,s);
		cout<<endl;
	}
	
}

void Automate::decalage(Symbole *s, Etat *e){
	symbolStack.push(s);
	stateStack.push(e);
	if (s->isTerminal()) {
		lexer->Avancer();
	}
}

void Automate::reduction(int n, Symbole *s) {
    for(int i = 0 ; i<n ; i++){
        delete(stateStack.top());
        stateStack.pop();
    }
    stateStack.top()->transition(*this,s);
}

Symbole* Automate::popSymbole() {
    Symbole* res = symbolStack.top();
    symbolStack.pop();
    return res;
}

void Automate::popAndDestroySymbole() {
    symbolStack.pop();
}
