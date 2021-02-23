/*************************************************************************
						  Etat  -  Implementation
							 -------------------
	début                : 23/02/2021
	copyright            : (C) 2021 par BRANCHEREAU Corentin, GRAVEY Thibaut
*************************************************************************/

//---------- Réalisation de la classe <Etat> (fichier etat.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

//------------------------------------------------------ Include personnel
#include "etat.h"
#include "automate.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
bool Etat0::transition(Automate &automate, Symbole *s) {
	switch(*s) {
		case INT:
			automate.decalage(s, new Etat3());
			break;

		case OPENPAR:
			automate.decalage(s,new Etat2());
			break;

		case EXPR:
			automate.decalage(s,new Etat1());
			break;

		default:
			cout << "erreur etat0" << endl;
			break;
    }
	return false;
}

bool Etat1::transition(Automate &automate, Symbole *s) {
	switch(*s) {
		case PLUS:
			automate.decalage(s, new Etat4());
			break;

		case MULT:
			automate.decalage(s,new Etat5());
			break;

		case FIN:
			return true;
			break;

		case EXPR:
			automate.decalage(s,new Etat1());
			break;

		default:
			cout << "erreur etat1" << endl;
			break;
	}

	return false;
}

bool Etat2::transition(Automate &automate, Symbole *s) {
	switch(*s) {
		case INT:
			automate.decalage(s, new Etat3());
			break;

		case OPENPAR:
			automate.decalage(s,new Etat2());
			break;

		case EXPR:
			automate.decalage(s,new Etat6());
			break;

		default:
			cout << "erreur etat2" << endl;
			break;
	}

	return false;
}

bool Etat3::transition(Automate &automate, Symbole *s) {
	switch(*s) {
		case PLUS:
		case MULT:
		case CLOSEPAR:
		case FIN:
			automate.reduction(3, s);
			break;

		case EXPR:
			automate.decalage(s,new Etat6());
			break;

		default:
			cout << "erreur etat3" << endl;
			break;
	}

	return false;
}

bool Etat4::transition(Automate &automate, Symbole *s) {
	switch(*s) {
		case INT:
			automate.decalage(s,new Etat3());
			break;

		case OPENPAR:
			automate.decalage(s,new Etat2());
			break;

		case EXPR:
			automate.decalage(s,new Etat6());
			break;

		default:
			cout << "erreur etat3" << endl;
			break;
	}

	return false;
}

bool Etat5::transition(Automate &automate, Symbole *s) {
    switch (*s) {
        case INT:
            automate.decalage(s, new Etat3);
            break;
        case OPENPAR:
            automate.decalage(s, new Etat2);
            break;
        case EXPR:
            automate.decalage(s, new Etat8);
            break;
        default:
            cout << "Erreur E5" << endl;
            return true;
    }
    return false;
}

bool Etat6::transition(Automate &automate, Symbole *s) {
    switch (*s) {
        case PLUS:
            automate.decalage(s, new Etat4);
            break;
        case MULT:
            automate.decalage(s, new Etat5);
            break;
        case CLOSEPAR:
            automate.decalage(s, new Etat9);
            break;
        default:
            cout << "Erreur E6" << endl;
            return true;
    }
    return false;
}

bool Etat7::transition(Automate &automate, Symbole *s) {
    Expr *e1;
    Expr *e2;
    switch (*s) {
        case MULT:
            automate.decalage(s, new Etat5);
            break;
        case PLUS:
        case CLOSEPAR:
        case FIN:
            e1 = (Expr*) automate.popSymbole();
            automate.popAndDestroySymbole();
            e2 = (Expr*) automate.popSymbole();
            automate.reduction(3, new Expr(e1->getValeur()+e2->getValeur()));
            break;
        default:
            cout << "Erreur E7" << endl;
            return true;
    }
    return false;
}

bool Etat8::transition(Automate &automate, Symbole *s) {
    Expr *e1;
    Expr *e2;
    switch (*s) {
        case PLUS:
        case MULT:
        case CLOSEPAR:
        case FIN:
            e1 = (Expr*) automate.popSymbole();
            automate.popAndDestroySymbole();
            e2 = (Expr*) automate.popSymbole();
            automate.reduction(3, new Expr(e1->getValeur()*e2->getValeur()));
            break;
        default:
            cout << "Erreur E8" << endl;
            return true;
    }
    return false;
}

bool Etat9::transition(Automate &automate, Symbole *s) {
    Expr *e1;
    switch (*s) {
        case PLUS:
        case MULT:
        case CLOSEPAR:
        case FIN:
            automate.popAndDestroySymbole();
            e1 = (Expr*) automate.popSymbole();
            automate.popAndDestroySymbole();
            automate.reduction(3, new Expr(e1->getValeur()));
            break;
        default:
            cout << "Erreur E9" << endl;
            return true;
    }
    return false;
}