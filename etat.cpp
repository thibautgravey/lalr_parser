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
void Etat::PrintErreur(const string& flux, int tete, Symbole *s) {
    cout << flux << endl;
    for (int i = 0; i < tete; i++) {
        cout << " ";
    }
    cout << "^" << endl;
    if (*s == ERREUR) {
        cout << "Symbole '" << s->GetSymbole() << "' non reconnu dans cette grammaire." << endl;
    } else {
        cout << "Symbole '" << s->GetSymbole() << "' innatendu à cet endroit" << endl;
    }
}

bool Etat0::transition(Automate &automate, Symbole *s) {
	switch(*s) {
		case INT:
			automate.decalage(s, new Etat3);
			break;
		case OPENPAR:
			automate.decalage(s,new Etat2);
			break;
		case EXPR:
			automate.decalage(s,new Etat1);
			break;
		default:
            automate.setError();
            cout << endl
                 << "Erreur E0" << endl;
            this->PrintErreur(automate.getLexer()->GetFlux(), automate.getLexer()->GetTete(), s);
            cout << "Attendu : INT, (" << endl;
            cout << "Obtenu : " << s->GetSymbole() << endl
                 << endl;
            return true;
    }
	return false;
}

bool Etat1::transition(Automate &automate, Symbole *s) {
    switch(*s) {
		case PLUS:
			automate.decalage(s, new Etat4);
			break;
		case MULT:
			automate.decalage(s,new Etat5);
			break;
		case FIN:
			return true;
		default:
            automate.setError();
            cout << endl
                 << "Erreur E1" << endl;
            this->PrintErreur(automate.getLexer()->GetFlux(), automate.getLexer()->GetTete(), s);
            cout << "Attendu : +, *, FIN" << endl;
            cout << "Obtenu : " << s->GetSymbole() << endl
                 << endl;
            return true;
	}
	return false;
}

bool Etat2::transition(Automate &automate, Symbole *s) {
    switch(*s) {
		case INT:
			automate.decalage(s, new Etat3);
			break;
		case OPENPAR:
			automate.decalage(s,new Etat2);
			break;
		case EXPR:
			automate.decalage(s,new Etat6);
			break;
		default:
            automate.setError();
            cout << endl
                 << "Erreur E2" << endl;
            this->PrintErreur(automate.getLexer()->GetFlux(), automate.getLexer()->GetTete(), s);
            cout << "Attendu : INT, ( " << endl;
            cout << "Obtenu : " << s->GetSymbole() << endl
                 << endl;
            return true;
	}
	return false;
}

bool Etat3::transition(Automate &automate, Symbole *s) {
    Entier *e1;
    ExprVal *exprVal;
	switch(*s) {
		case PLUS:
		case MULT:
		case CLOSEPAR:
		case FIN:
		    e1 = (Entier*) automate.popSymbole();
		    exprVal = new ExprVal(e1);
			automate.reduction(1, exprVal);
			//delete(exprVal);
			break;
		default:
            automate.setError();
            cout << endl
                 << "Erreur E3" << endl;
            this->PrintErreur(automate.getLexer()->GetFlux(), automate.getLexer()->GetTete(), s);
            cout << "Attendu : +, *, ), FIN " << endl;
            cout << "Obtenu : " << s->GetSymbole() << endl
                 << endl;
            return true;
	}
	return false;
}

bool Etat4::transition(Automate &automate, Symbole *s) {
    switch(*s) {
		case INT:
			automate.decalage(s,new Etat3);
			break;
		case OPENPAR:
			automate.decalage(s,new Etat2);
			break;
		case EXPR:
			automate.decalage(s,new Etat7);
			break;
		default:
            automate.setError();
            cout << endl
                 << "Erreur E4" << endl;
            this->PrintErreur(automate.getLexer()->GetFlux(), automate.getLexer()->GetTete(), s);
            cout << "Attendu : INT, ( " << endl;
            cout << "Obtenu : " << s->GetSymbole() << endl
                 << endl;
            return true;
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
            automate.setError();
            cout << endl
                 << "Erreur E5" << endl;
            this->PrintErreur(automate.getLexer()->GetFlux(), automate.getLexer()->GetTete(), s);
            cout << "Attendu : INT, ( " << endl;
            cout << "Obtenu : " << s->GetSymbole() << endl
                 << endl;
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
            automate.setError();
            cout << endl
                 << "Erreur E6" << endl;
            this->PrintErreur(automate.getLexer()->GetFlux(), automate.getLexer()->GetTete(), s);
            cout << "Attendu : +, *, ) " << endl;
            cout << "Obtenu : " << s->GetSymbole() << endl
                 << endl;
            return true;
    }
    return false;
}

bool Etat7::transition(Automate &automate, Symbole *s) {
    Expr *e1;
    Expr *e2;
    ExprPlus *exprPlus;
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
            exprPlus = new ExprPlus(e2,e1);
            automate.reduction(3, exprPlus);
            //delete(exprPlus);
            break;
        default:
            automate.setError();
            cout << endl
                 << "Erreur E7" << endl;
            this->PrintErreur(automate.getLexer()->GetFlux(), automate.getLexer()->GetTete(), s);
            cout << "Attendu : *, +, ), FIN " << endl;
            cout << "Obtenu : " << s->GetSymbole() << endl
                 << endl;
            return true;
    }
    return false;
}

bool Etat8::transition(Automate &automate, Symbole *s) {
    Expr *e1;
    Expr *e2;
    ExprMult *exprMult;
    switch (*s) {
        case PLUS:
        case MULT:
        case CLOSEPAR:
        case FIN:
            e1 = (Expr*) automate.popSymbole();
            automate.popAndDestroySymbole();
            e2 = (Expr*) automate.popSymbole();
            exprMult = new ExprMult(e2,e1);
            automate.reduction(3, exprMult);
            //delete(exprMult);
            break;
        default:
            automate.setError();
            cout << endl
                 << "Erreur E8" << endl;
            this->PrintErreur(automate.getLexer()->GetFlux(), automate.getLexer()->GetTete(), s);
            cout << "Attendu : +, *, ), FIN " << endl;
            cout << "Obtenu : " << s->GetSymbole() << endl
                 << endl;
            return true;
    }
    return false;
}

bool Etat9::transition(Automate &automate, Symbole *s) {
    Expr *e1;
    ExprPar *exprPar;
    switch (*s) {
        case PLUS:
        case MULT:
        case CLOSEPAR:
        case FIN:
            automate.popAndDestroySymbole();
            e1 = (Expr*) automate.popSymbole();
            automate.popAndDestroySymbole();
            exprPar = new ExprPar(e1);
            automate.reduction(3, exprPar);
            //delete(exprPar);
            break;
        default:
            automate.setError();
            cout << "Erreur E9" << endl;
            this->PrintErreur(automate.getLexer()->GetFlux(), automate.getLexer()->GetTete(), s);
            cout << "Attendu : +, *, ), FIN " << endl;
            cout << "Obtenu : " << s->GetSymbole();
            s->Affiche();
            return true;
    }
    return false;
}