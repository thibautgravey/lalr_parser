#include <iostream>
#include "lexer.h"
#include "automate.h"


int main(void) {
   cout << "Quelle expression voulez vous analyser ? grammaire autorisée: + - * ( ) val " <<endl;

   

   string chaine;
   cin >> chaine;

   Lexer l(chaine);

   Automate a(&l);

   a.lecture();

   return 0;
}

