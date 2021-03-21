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
    cout << Etiquettes[ident];
} //Fin de Symbole::Affiche

bool Symbole::IsTerminal() const {
    return terminal;
} //Fin de Symbole::IsTerminal

char Symbole::GetSymbole() const {
    return symbole;
} //Fin de Symbole::GetSymbole

//----------------------------------------------------- Réalisation de <Entier>
void Entier::Affiche() {
    Symbole::Affiche();
    cout << "(" << valeur << ")";
} //Fin de Entier::Affiche

int Entier::Eval() {
    return valeur;
} //Fin de Entier::Eval

//----------------------------------------------------- Réalisation de <Expr>
void Expr::Affiche() {
    Symbole::Affiche();
} //Fin de Expr::Affiche

//----------------------------------------------------- Réalisation de <ExprPlus>
void ExprPlus::Affiche() {
    cout << "EXPR_PLUS(";
    expr1->Affiche();
    cout << "+";
    expr2->Affiche();
    cout << ")";
} //Fin de ExprPlus::Affiche

int ExprPlus::Eval() {
    return expr1->Eval() + expr2->Eval();
} //Fin de ExprPlus::Eval

ExprPlus::~ExprPlus() {
    delete (expr1);
    delete (expr2);
} //Fin de ~ExprPlus

//----------------------------------------------------- Réalisation de <ExprMult>
void ExprMult::Affiche() {
    cout << "EXPR_MULT(";
    expr1->Affiche();
    cout << "*";
    expr2->Affiche();
    cout << ")";
} //Fin de ExprMult::Affiche

int ExprMult::Eval() {
    return expr1->Eval() * expr2->Eval();
} //Fin de ExprMult::Eval

ExprMult::~ExprMult() {
    delete (expr1);
    delete (expr2);
} //Fin de ~ExprMult

//----------------------------------------------------- Réalisation de <ExprPar>
void ExprPar::Affiche() {
    cout << "EXPR_PAR(";
    expr->Affiche();
    cout << ")";
} //Fin de ExprPar::Affiche

int ExprPar::Eval() {
    return expr->Eval();
} //Fin de ExprPar::Eval

ExprPar::~ExprPar() {
    delete (expr);
} //Fin de ~ExprPar

//----------------------------------------------------- Réalisation de <ExprVal>
void ExprVal::Affiche() {
    entier->Affiche();
} //Fin de ExprVal::Affiche

int ExprVal::Eval() {
    return entier->Eval();
} //Fin de ExprVal::Eval

ExprVal::~ExprVal() {
    delete (entier);
} //Fin de ~ExprVal
