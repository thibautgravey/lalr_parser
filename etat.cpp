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
#include "automate.h"
#include "etat.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
bool Etat::PrintErreur(Symbole * s, Automate & automate, const string numero, const string grammaire) {

    cout << endl
         << "    Erreur " << numero << endl;

    cout << "    " << automate.GetLexer()->GetFlux() << endl;
    for (int i = 0; i < automate.GetLexer()->GetTete() - 1; i++) {
        cout << " ";
    }
    cout << "    ^" << endl;
    if (*s == ERREUR) {
        cout << "    Symbole '" << s->GetSymbole() << "' non reconnu dans cette grammaire." << endl;
    } else {
        cout << "    Symbole '" << s->GetSymbole() << "' innatendu à cet endroit" << endl;
    }

    cout << "    Attendu: " << grammaire << endl;
    cout << "    Obtenu : " << s->GetSymbole() << endl;

    if (*s != FIN && *s != INT) {
        cout << "    caractère ignoré, poursuite de l'analyse" << endl
             << endl;
        automate.GetLexer()->Avancer();
        return false;
    } else {
        automate.SetError();
        return true;
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
            return this->PrintErreur(s, automate, "E0", "INT, (");
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
            return this->PrintErreur(s, automate, "E1", "+, *, FIN");
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
            return this->PrintErreur(s, automate, "E2", " INT, (");
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
            e1 = (Entier *)automate.PopSymbole();
            exprVal = new ExprVal(e1);
            automate.Reduction(1, exprVal);
            //delete(exprVal);
            break;
        default:
            return this->PrintErreur(s, automate, "E3", "+, *, ), FIN ");
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
            return this->PrintErreur(s, automate, "E4", " INT, (");
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
            return this->PrintErreur(s, automate, "E5", " INT, (");
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
            return this->PrintErreur(s, automate, "E6", "+, *, )");
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
            e1 = (Expr *)automate.PopSymbole();
            automate.PopAndDestroySymbole();
            e2 = (Expr *)automate.PopSymbole();
            exprPlus = new ExprPlus(e2, e1);
            automate.Reduction(3, exprPlus);
            //delete(exprPlus);
            break;
        default:
            return this->PrintErreur(s, automate, "E7", "+, *, ), FIN ");
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
            e1 = (Expr *)automate.PopSymbole();
            automate.PopAndDestroySymbole();
            e2 = (Expr *)automate.PopSymbole();
            exprMult = new ExprMult(e2, e1);
            automate.Reduction(3, exprMult);
            //delete(exprMult);
            break;
        default:
            return this->PrintErreur(s, automate, "E8", "+, *, ), FIN ");
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
            e1 = (Expr *)automate.PopSymbole();
            automate.PopAndDestroySymbole();
            exprPar = new ExprPar(e1);
            automate.Reduction(3, exprPar);
            //delete(exprPar);
            break;
        default:
            return this->PrintErreur(s, automate, "E9", "+, *, ), FIN ");
    }
    return false;
} //Fin de Etat9::Transition