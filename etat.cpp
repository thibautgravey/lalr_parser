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
void Etat::PrintErreur(const string & flux, int tete, Symbole * s) {
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
} //Fin de PrintErreur

bool Etat0::Transition(Automate & automate, Symbole * s) {
    switch (*s) {
        case INT:
            automate.Decalage(s, new Etat3);
            break;
        case OPENPAR:
            automate.Decalage(s, new Etat2);
            break;
        case EXPR:
            automate.Decalage(s, new Etat1);
            break;
        default:
            automate.SetError();
            cout << endl
                 << "Erreur E0" << endl;
            this->PrintErreur(automate.GetLexer()->GetFlux(), automate.GetLexer()->GetTete(), s);
            cout << "Attendu : INT, (" << endl;
            cout << "Obtenu : " << s->GetSymbole() << endl
                 << endl;
            return true;
    }
    return false;
} //Fin de Etat0::Transition

bool Etat1::Transition(Automate & automate, Symbole * s) {
    switch (*s) {
        case PLUS:
            automate.Decalage(s, new Etat4);
            break;
        case MULT:
            automate.Decalage(s, new Etat5);
            break;
        case FIN:
            return true;
        default:
            automate.SetError();
            cout << endl
                 << "Erreur E1" << endl;
            this->PrintErreur(automate.GetLexer()->GetFlux(), automate.GetLexer()->GetTete(), s);
            cout << "Attendu : +, *, FIN" << endl;
            cout << "Obtenu : " << s->GetSymbole() << endl
                 << endl;
            return true;
    }
    return false;
} //Fin de Etat1::Transition

bool Etat2::Transition(Automate & automate, Symbole * s) {
    switch (*s) {
        case INT:
            automate.Decalage(s, new Etat3);
            break;
        case OPENPAR:
            automate.Decalage(s, new Etat2);
            break;
        case EXPR:
            automate.Decalage(s, new Etat6);
            break;
        default:
            automate.SetError();
            cout << endl
                 << "Erreur E2" << endl;
            this->PrintErreur(automate.GetLexer()->GetFlux(), automate.GetLexer()->GetTete(), s);
            cout << "Attendu : INT, ( " << endl;
            cout << "Obtenu : " << s->GetSymbole() << endl
                 << endl;
            return true;
    }
    return false;
} //Fin de Etat2::Transition

bool Etat3::Transition(Automate & automate, Symbole * s) {
    Entier * e1;
    ExprVal * exprVal;
    switch (*s) {
        case PLUS:
        case MULT:
        case CLOSEPAR:
        case FIN:
            e1 = (Entier *) automate.PopSymbole();
            exprVal = new ExprVal(e1);
            automate.Reduction(1, exprVal);
            //delete(exprVal);
            break;
        default:
            automate.SetError();
            cout << endl
                 << "Erreur E3" << endl;
            this->PrintErreur(automate.GetLexer()->GetFlux(), automate.GetLexer()->GetTete(), s);
            cout << "Attendu : +, *, ), FIN " << endl;
            cout << "Obtenu : " << s->GetSymbole() << endl
                 << endl;
            return true;
    }
    return false;
} //Fin de Etat3::Transition

bool Etat4::Transition(Automate & automate, Symbole * s) {
    switch (*s) {
        case INT:
            automate.Decalage(s, new Etat3);
            break;
        case OPENPAR:
            automate.Decalage(s, new Etat2);
            break;
        case EXPR:
            automate.Decalage(s, new Etat7);
            break;
        default:
            automate.SetError();
            cout << endl
                 << "Erreur E4" << endl;
            this->PrintErreur(automate.GetLexer()->GetFlux(), automate.GetLexer()->GetTete(), s);
            cout << "Attendu : INT, ( " << endl;
            cout << "Obtenu : " << s->GetSymbole() << endl
                 << endl;
            return true;
    }

    return false;
} //Fin de Etat4::Transition

bool Etat5::Transition(Automate & automate, Symbole * s) {
    switch (*s) {
        case INT:
            automate.Decalage(s, new Etat3);
            break;
        case OPENPAR:
            automate.Decalage(s, new Etat2);
            break;
        case EXPR:
            automate.Decalage(s, new Etat8);
            break;
        default:
            automate.SetError();
            cout << endl
                 << "Erreur E5" << endl;
            this->PrintErreur(automate.GetLexer()->GetFlux(), automate.GetLexer()->GetTete(), s);
            cout << "Attendu : INT, ( " << endl;
            cout << "Obtenu : " << s->GetSymbole() << endl
                 << endl;
            return true;
    }
    return false;
} //Fin de Etat5::Transition

bool Etat6::Transition(Automate & automate, Symbole * s) {
    switch (*s) {
        case PLUS:
            automate.Decalage(s, new Etat4);
            break;
        case MULT:
            automate.Decalage(s, new Etat5);
            break;
        case CLOSEPAR:
            automate.Decalage(s, new Etat9);
            break;
        default:
            automate.SetError();
            cout << endl
                 << "Erreur E6" << endl;
            this->PrintErreur(automate.GetLexer()->GetFlux(), automate.GetLexer()->GetTete(), s);
            cout << "Attendu : +, *, ) " << endl;
            cout << "Obtenu : " << s->GetSymbole() << endl
                 << endl;
            return true;
    }
    return false;
} //Fin de Etat6::Transition

bool Etat7::Transition(Automate & automate, Symbole * s) {
    Expr * e1;
    Expr * e2;
    ExprPlus * exprPlus;
    switch (*s) {
        case MULT:
            automate.Decalage(s, new Etat5);
            break;
        case PLUS:
        case CLOSEPAR:
        case FIN:
            e1 = (Expr *) automate.PopSymbole();
            automate.PopAndDestroySymbole();
            e2 = (Expr *) automate.PopSymbole();
            exprPlus = new ExprPlus(e2, e1);
            automate.Reduction(3, exprPlus);
            //delete(exprPlus);
            break;
        default:
            automate.SetError();
            cout << endl
                 << "Erreur E7" << endl;
            this->PrintErreur(automate.GetLexer()->GetFlux(), automate.GetLexer()->GetTete(), s);
            cout << "Attendu : *, +, ), FIN " << endl;
            cout << "Obtenu : " << s->GetSymbole() << endl
                 << endl;
            return true;
    }
    return false;
} //Fin de Etat7::Transition

bool Etat8::Transition(Automate & automate, Symbole * s) {
    Expr * e1;
    Expr * e2;
    ExprMult * exprMult;
    switch (*s) {
        case PLUS:
        case MULT:
        case CLOSEPAR:
        case FIN:
            e1 = (Expr *) automate.PopSymbole();
            automate.PopAndDestroySymbole();
            e2 = (Expr *) automate.PopSymbole();
            exprMult = new ExprMult(e2, e1);
            automate.Reduction(3, exprMult);
            //delete(exprMult);
            break;
        default:
            automate.SetError();
            cout << endl
                 << "Erreur E8" << endl;
            this->PrintErreur(automate.GetLexer()->GetFlux(), automate.GetLexer()->GetTete(), s);
            cout << "Attendu : +, *, ), FIN " << endl;
            cout << "Obtenu : " << s->GetSymbole() << endl
                 << endl;
            return true;
    }
    return false;
} //Fin de Etat8::Transition

bool Etat9::Transition(Automate & automate, Symbole * s) {
    Expr * e1;
    ExprPar * exprPar;
    switch (*s) {
        case PLUS:
        case MULT:
        case CLOSEPAR:
        case FIN:
            automate.PopAndDestroySymbole();
            e1 = (Expr *) automate.PopSymbole();
            automate.PopAndDestroySymbole();
            exprPar = new ExprPar(e1);
            automate.Reduction(3, exprPar);
            //delete(exprPar);
            break;
        default:
            automate.SetError();
            cout << "Erreur E9" << endl;
            this->PrintErreur(automate.GetLexer()->GetFlux(), automate.GetLexer()->GetTete(), s);
            cout << "Attendu : +, *, ), FIN " << endl;
            cout << "Obtenu : " << s->GetSymbole();
            s->Affiche();
            return true;
    }
    return false;
} //Fin de Etat9::Transition