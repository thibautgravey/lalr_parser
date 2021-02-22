CC=g++
CFLAGS=-g -Wall -Werror -ansi -pedantic -std=c++11
DFLAGS=

MAIN=lalr
SRCS= main.cpp lexer.cpp symbole.cpp
OBJS=$(SRCS:.c=.o)

$(MAIN): $(OBJS)
	@echo Compilation des objets et edition des liens
	@$(CC) -o $(MAIN) $(OBJS) $(DFLAGS)

%.o : %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY : launch
launch : $(MAIN)
	./$(MAIN)

.PHONY : clean
clean:
	rm -f $(MAIN) *.o core
