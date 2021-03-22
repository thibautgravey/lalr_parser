#include "automate.h"
#include "lexer.h"
#include <iostream>

int main(void) {
    cout << "LALR Parser - Par BRANCHEREAU Corentin & GRAVEY Thibaut " << endl;
    cout << "Pour quitter le parser, saisir 'exit' " << endl;
    cout << "Grammaire autorisée: + * ( ) INT " << endl;

    string chaine("");
    while (chaine != "exit") {
        cout << endl
             << ">>> ";
        cin >> chaine;

        if (chaine == "quit" || chaine == "q" || chaine == "exit()") {
            cout << "Utilisez 'exit' pour quitter" << endl;
        } else if (chaine != "exit") {
            Lexer l(chaine);
            Automate a(&l);
            a.Lecture();
        }
    }

    return 0;
}
