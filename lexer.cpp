/*************************************************************************
						  Lexer  -  Implementation
							 -------------------
	début                : 23/02/2021
	copyright            : (C) 2021 par LG, INSA LYON
*************************************************************************/

//---------- Réalisation de la classe <Lexer> (fichier lexer.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel
#include "lexer.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
Symbole * Lexer::Consulter() {
    if (!tampon) {

        if (tete == flux.length())
            tampon = new Symbole(FIN, ' ');
        else {

            switch (flux[tete]) {
                case '(':
                    tampon = new Symbole(OPENPAR, '(');
                    tete++;
                    break;
                case ')':
                    tampon = new Symbole(CLOSEPAR, ')');
                    tete++;
                    break;
                case '*':
                    tampon = new Symbole(MULT, '*');
                    tete++;
                    break;
                case '+':
                    tampon = new Symbole(PLUS, '+');
                    tete++;
                    break;
                default:
                    if (flux[tete] <= '9' && flux[tete] >= '0') {
                        int resultat = flux[tete] - '0';
                        int i = 1;
                        while (flux[tete + i] <= '9' && flux[tete + i] >= '0') {
                            resultat = resultat * 10 + (flux[tete + i] - '0');
                            i++;
                        }
                        tete = tete + i;
                        tampon = new Entier(resultat);
                    } else {
                        tampon = new Symbole(ERREUR, flux[tete]);
                        tete++;
                    }
            }
        }
    }
    return tampon;
} //Fin de Consulter

void Lexer::Avancer() {
    tampon = nullptr;
} //Fin de Avancer

string Lexer::GetFlux() {
    return this->flux;
} //Fin de GetFlux

int Lexer::GetTete() {
    return this->tete;
} //Fin de GetTete
