/*************************************************************************
						  Automate  -  Implementation
							 -------------------
	début                : 23/02/2021
	copyright            : (C) 2021 par BRANCHEREAU Corentin, GRAVEY Thibaut
*************************************************************************/

//---------- Réalisation de la classe <Automate> (fichier automate.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel
#include "automate.h"
//----------------------------------------------------------------- PUBLIC

void Automate::decalage(Symbole *s, Etat *e){
	symbolStack.push(s);
	stateStack.push(e);
	if (s->isTerminal()) {
		lexer->Avancer();
	}
}
//----------------------------------------------------- Méthodes publiques