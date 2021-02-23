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

void Entier::Affiche() {
   Symbole::Affiche();
   cout<<"("<<valeur<<")";
}

void Expr::Affiche() {
    Symbole::Affiche();
    cout<<"("<<valeur<<")";
}

