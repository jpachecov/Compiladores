all: interprete run
interprete:
	bison -vd parser.y && flex lexer.l && g++ -std=c++11 parser.tab.c pylex.cpp -o parser

run:
	 ./parser prueba.py
clean:
	rm parser.tab.h
	rm parser.tab.c
	rm parser.output
	rm pylex.cpp
	rm salida.txt
	rm archivo.c
	rm parser.y
