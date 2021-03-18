/*************************************************************************
						   Etat  -  Header file
							 -------------------
	début                : 23/02/2021
	copyright            : (C) 2021 par BRANCHEREAU Corentin, GRAVEY Thibaut
*************************************************************************/

//---------- Interface de la classe <Etat> (fichier etat.h) ------
#ifndef LALR_PARSER_ETAT_H
#define LALR_PARSER_ETAT_H

//--------------------------------------------------- Interfaces utilisées
#include "symbole.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
class Automate;

//------------------------------------------------------------------------
// Rôle de la classe <Etat>
// Implémentation d'une sorte de design pattern STATE permettant, selon
// l'état dans lequel l'automate se trouve, d'utiliser le polymorphisme
// afin d'effectuer la transition nécessire suivant le symbole lu sur la
// tête de lecture de l'analyseur lexical.
//------------------------------------------------------------------------

class Etat
{
    //----------------------------------------------------------------- PUBLIC
public:
    //-------------------------------------------- Constructeurs - destructeur
    Etat() {}
    virtual ~Etat() {}

    //----------------------------------------------------- Méthodes publiques
    virtual bool transition(Automate &automate, Symbole *s) = 0;
    void PrintErreur(string flux, int tete, Symbole *s);
};

//---------- Interface de la classe <Etat0> (fichier etat.h) ------
class Etat0 : public Etat
{
    //----------------------------------------------------------------- PUBLIC
public:
    //-------------------------------------------- Constructeurs - destructeur
    Etat0() {}
    virtual ~Etat0() {}

    //----------------------------------------------------- Méthodes publiques
    virtual bool transition(Automate &automate, Symbole *s);
};

//---------- Interface de la classe <Etat1> (fichier etat.h) ------
class Etat1 : public Etat
{
    //----------------------------------------------------------------- PUBLIC
public:
    //-------------------------------------------- Constructeurs - destructeur
    Etat1() {}
    virtual ~Etat1() {}

    //----------------------------------------------------- Méthodes publiques
    virtual bool transition(Automate &automate, Symbole *s);
};

//---------- Interface de la classe <Etat2> (fichier etat.h) ------
class Etat2 : public Etat
{
    //----------------------------------------------------------------- PUBLIC
public:
    //-------------------------------------------- Constructeurs - destructeur
    Etat2() {}
    virtual ~Etat2() {}

    //----------------------------------------------------- Méthodes publiques
    virtual bool transition(Automate &automate, Symbole *s);
};

//---------- Interface de la classe <Etat3> (fichier etat.h) ------
class Etat3 : public Etat
{
    //----------------------------------------------------------------- PUBLIC
public:
    //-------------------------------------------- Constructeurs - destructeur
    Etat3() {}
    virtual ~Etat3() {}

    //----------------------------------------------------- Méthodes publiques
    virtual bool transition(Automate &automate, Symbole *s);
};

//---------- Interface de la classe <Etat4> (fichier etat.h) ------
class Etat4 : public Etat
{
    //----------------------------------------------------------------- PUBLIC
public:
    //-------------------------------------------- Constructeurs - destructeur
    Etat4() {}
    virtual ~Etat4() {}

    //----------------------------------------------------- Méthodes publiques
    virtual bool transition(Automate &automate, Symbole *s);
};

//---------- Interface de la classe <Etat5> (fichier etat.h) ------
class Etat5 : public Etat
{
    //----------------------------------------------------------------- PUBLIC
public:
    //-------------------------------------------- Constructeurs - destructeur
    Etat5() {}
    virtual ~Etat5() {}

    //----------------------------------------------------- Méthodes publiques
    virtual bool transition(Automate &automate, Symbole *s);
};

//---------- Interface de la classe <Etat6> (fichier etat.h) ------
class Etat6 : public Etat
{
    //----------------------------------------------------------------- PUBLIC
public:
    //-------------------------------------------- Constructeurs - destructeur
    Etat6() {}
    virtual ~Etat6() {}

    //----------------------------------------------------- Méthodes publiques
    virtual bool transition(Automate &automate, Symbole *s);
};

//---------- Interface de la classe <Etat7> (fichier etat.h) ------
class Etat7 : public Etat
{
    //----------------------------------------------------------------- PUBLIC
public:
    //-------------------------------------------- Constructeurs - destructeur
    Etat7() {}
    virtual ~Etat7() {}

    //----------------------------------------------------- Méthodes publiques
    virtual bool transition(Automate &automate, Symbole *s);
};

//---------- Interface de la classe <Etat8> (fichier etat.h) ------
class Etat8 : public Etat
{
    //----------------------------------------------------------------- PUBLIC
public:
    //-------------------------------------------- Constructeurs - destructeur
    Etat8() {}
    virtual ~Etat8() {}

    //----------------------------------------------------- Méthodes publiques
    virtual bool transition(Automate &automate, Symbole *s);
};

//---------- Interface de la classe <Etat9> (fichier etat.h) ------
class Etat9 : public Etat
{
    //----------------------------------------------------------------- PUBLIC
public:
    //-------------------------------------------- Constructeurs - destructeur
    Etat9() {}
    virtual ~Etat9() {}

    //----------------------------------------------------- Méthodes publiques
    virtual bool transition(Automate &automate, Symbole *s);
};

#endif //LALR_PARSER_AUTOMATE_H
