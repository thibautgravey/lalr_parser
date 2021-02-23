/*************************************************************************
						  Symbole  -  Implementation
							 -------------------
	début                : 23/02/2021
	copyright            : (C) 2021 par LG, INSA LYON
*************************************************************************/

//---------- Réalisation de la classe <Symbole> (fichier symbole.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

//------------------------------------------------------ Include personnel
#include "symbole.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Symbole::Affiche() {
   cout<<Etiquettes[ident];
}

bool Symbole::isTerminal(){
	return true;
}

void Entier::Affiche() {
   Symbole::Affiche();
   cout<<"("<<valeur<<")";
}

bool Entier::isTerminal(){
	return true;
}

int Entier::eval() {
    return valeur;
}

bool Expr::isTerminal(){
	return false;
}

void Expr::Affiche() {
    Symbole::Affiche();
    cout<<"("<<valeur<<")";
}

int Expr::eval() {
    return valeur;
}

