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

//----------------------------------------------------- Réalisation de <Symbole>
void Symbole::Affiche() {
   cout<<Etiquettes[ident];
}

bool Symbole::isTerminal() const {
    return terminal;
}

//----------------------------------------------------- Réalisation de <Entier>
void Entier::Affiche() {
   Symbole::Affiche();
   cout<<"("<<valeur<<")";
}

int Entier::eval() {
    return valeur;
}

//----------------------------------------------------- Réalisation de <Expr>
void Expr::Affiche() {
    Symbole::Affiche();
}

//----------------------------------------------------- Réalisation de <ExprPlus>
void ExprPlus::Affiche() {
    cout << "EXPR_PLUS(";
    expr1->Affiche();
    cout << "+";
    expr2->Affiche();
    cout << ")";
}

int ExprPlus::eval() {
    return expr1->eval() + expr2->eval();
}

ExprPlus::~ExprPlus() {
    delete(expr1);
    delete(expr2);
}

//----------------------------------------------------- Réalisation de <ExprMult>
void ExprMult::Affiche() {
    cout << "EXPR_MULT(";
    expr1->Affiche();
    cout << "*";
    expr2->Affiche();
    cout << ")";
}

int ExprMult::eval() {
    return expr1->eval() * expr2->eval();
}

ExprMult::~ExprMult() {
    delete(expr1);
    delete(expr2);
}

//----------------------------------------------------- Réalisation de <ExprPar>
void ExprPar::Affiche() {
    cout << "EXPR_PAR(";
    expr->Affiche();
    cout << ")";
}

int ExprPar::eval() {
    return expr->eval();
}

ExprPar::~ExprPar() {
    delete(expr);
}

//----------------------------------------------------- Réalisation de <ExprVal>
void ExprVal::Affiche() {
    entier->Affiche();
}

int ExprVal::eval() {
    return entier->eval();
}

ExprVal::~ExprVal() {
    delete(entier);
}
