#include <iostream>
#include "lexer.h"
#include "automate.h"


int main(void) {
   string chaine("(1+34)*123");

   Lexer l(chaine);

   Automate a(&l);

   a.lecture();

   return 0;
}

