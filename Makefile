#Makelife
programa: main.c reconocedor_automata.c
	gcc main.c reconocedor_automata.c -o programa

clean: 
	rm -f programa *.o

#desde el terminal
## make programa
## ./programa