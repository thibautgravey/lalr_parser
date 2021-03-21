/*************************************************************************
						    Symbole  -  Header file
							 -------------------
	début                : 23/02/2021
	copyright            : (C) 2021 par LG, INSA LYON
*************************************************************************/

//---------- Interface de la classe <Symbole> (fichier symbole.h) ------
#pragma once

//--------------------------------------------------- Interfaces utilisées
#include <string>

using namespace std;

//------------------------------------------------------------- Constantes
const string Etiquettes[] = {"OPENPAR", "CLOSEPAR", "PLUS", "MULT", "INT", "FIN", "ERREUR", "EXPR"};

//------------------------------------------------------------------ Types
enum Identificateurs {
    OPENPAR, CLOSEPAR, PLUS, MULT, INT, FIN, ERREUR, EXPR
};

//------------------------------------------------------------------------
// Rôle de la classe <Symbole>
// Permet la représentation des éléments lus par le lexer. L'affichage,
// l'évaluation d'un symbole et ses propriétés terminales ou non sont gérées
// par le polymorphisme de cette classe.
//------------------------------------------------------------------------

class Symbole {
    //----------------------------------------------------------------- PUBLIC
  public:
    //-------------------------------------------- Constructeurs - destructeur
    Symbole(int i, bool term, char s) : ident(i), terminal(term), symbole(s) {}

    Symbole(int i, char s) : ident(i), terminal(true), symbole(s) {}

    virtual ~Symbole() = default;

    //------------------------------------------------- Surcharge d'opérateurs
    operator int() const { return ident; }

    //----------------------------------------------------- Méthodes publiques
    virtual void Affiche();

    bool IsTerminal() const;

    char GetSymbole() const;

    //------------------------------------------------------------------ PRIVE
  protected:
    //----------------------------------------------------- Attributs protégés
    int ident;
    bool terminal;
    char symbole;
};

class Entier : public Symbole {
    //----------------------------------------------------------------- PUBLIC
  public:
    //-------------------------------------------- Constructeurs - destructeur
    Entier(int v) : Symbole(INT, true, v), valeur(v) {}

    ~Entier() override {}

    //----------------------------------------------------- Méthodes publiques
    virtual void Affiche();

    int Eval();

    //------------------------------------------------------------------ PRIVE
  protected:
    //----------------------------------------------------- Attributs protégés
    int valeur;
};

class Expr : public Symbole {
    //----------------------------------------------------------------- PUBLIC
  public:
    //-------------------------------------------- Constructeurs - destructeur
    Expr(char s) : Symbole(EXPR, false, s) {}

    ~Expr() override = default;

    //----------------------------------------------------- Méthodes publiques
    void Affiche() override;

    virtual int Eval() = 0;

    //------------------------------------------------------------------ PRIVE
  protected:
    //----------------------------------------------------- Attributs protégés

};

class ExprPlus : public Expr {
//----------------------------------------------------------------- PUBLIC
  public:
    //-------------------------------------------- Constructeurs - destructeur
    ExprPlus(Expr * e1, Expr * e2) : Expr('+'), expr1(e1), expr2(e2) {}

    ~ExprPlus() override;

    //----------------------------------------------------- Méthodes publiques
    void Affiche() override;

    int Eval() override;

    //------------------------------------------------------------------ PRIVE
  protected:
    //----------------------------------------------------- Attributs protégés
    Expr * expr1;
    Expr * expr2;
};

class ExprMult : public Expr {
//----------------------------------------------------------------- PUBLIC
  public:
    //-------------------------------------------- Constructeurs - destructeur
    ExprMult(Expr * e1, Expr * e2) : Expr('*'), expr1(e1), expr2(e2) {}

    ~ExprMult() override;

    //----------------------------------------------------- Méthodes publiques
    void Affiche() override;

    int Eval() override;

    //------------------------------------------------------------------ PRIVE
  protected:
    //----------------------------------------------------- Attributs protégés
    Expr * expr1;
    Expr * expr2;
};

class ExprPar : public Expr {
//----------------------------------------------------------------- PUBLIC
  public:
    //-------------------------------------------- Constructeurs - destructeur
    ExprPar(Expr * e) : Expr('('), expr(e) {}

    ~ExprPar() override;

    //----------------------------------------------------- Méthodes publiques
    void Affiche() override;

    int Eval() override;

    //------------------------------------------------------------------ PRIVE
  protected:
    //----------------------------------------------------- Attributs protégés
    Expr * expr;
};

class ExprVal : public Expr {
//----------------------------------------------------------------- PUBLIC
  public:
    //-------------------------------------------- Constructeurs - destructeur
    ExprVal(Entier * e) : Expr(e->Eval()), entier(e) {}

    ~ExprVal() override;

    //----------------------------------------------------- Méthodes publiques
    void Affiche() override;

    int Eval() override;

    //------------------------------------------------------------------ PRIVE
  protected:
    //----------------------------------------------------- Attributs protégés
    Entier * entier;
};

