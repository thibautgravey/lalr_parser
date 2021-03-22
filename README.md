# lalr_parser

## What is it ?
A C++ LALR Parser developed in 4th year at INSA LYON by BRANCHEREAU Corentin and GRAVEY Thibaut. Some simple errors can be handle and ignore by the parser (for example 1+e2+3 will give 1+2+3 = 6 because the unknown caracter 'e' was ignored during parsing). The parser wait for user's input on the terminal. Use 'exit' keyword to close the app.

## Makefile
### Compilation et édition des liens
`make lalr`

### Compilation, édition des liens et lancement
`make launch`

### Clear
`make clear`
