#include <stdio.h>
#include "reconocedor.h"

int main(int argc, char **argv) {
    int x;
    char expresion[100];
    int i = 0;
    int estado_actual = 0;
    int linea = 1;
    int columna = 1;

    while ((x = getchar()) != EOF) {
        if (x == '\n') {
            if (estado_actual == 1 || estado_actual == 2 || estado_actual == 3) {
                printf("Expresión Válida\n");
            } else {
                fprintf(stderr, "Expresión Rechazada (Línea %d, Columna %d)\n", linea, columna);
            }
            estado_actual = 0;
            linea++;
            columna = 1;
            continue;
            i++;
        }
        if (x == ' ' || x == '\t') {
            columna++;
            continue;
        }

        //Me muestra el recorrido que hace en cada estado
        //printf("%d -> %c -> ", estado_actual, x);
        estado_actual = Automata(estado_actual, x);
        //printf("%d\n", estado_actual);

        if (estado_actual == -1) {
            fprintf(stderr, "Expresion Rechazada (Línea %d, Columna %d)\n", linea, columna);
            return 0;
        }
        columna++;
        expresion[i] = x;
        i++;
    }

    printf("\nExpresion completa %s\n", expresion); // muestro lo que contiene "expresion", asi corroboro con la expresion que escribi
    
    printf("\nLista de Tokens: \n"); //Imprimo el token de la expresion
    printf("En el codigo \t token\n");
    int j = 0;
    while (expresion[j] != '\0'){
        if (expresion[j] >= '0' && expresion[i] <= '9') {
            printf("\t%c   -> \tNumero\n", expresion[j]);
            j++;
        } else if (expresion[j] == '+' || expresion[j] == '-' || expresion[j] == '*' || expresion[j] == '/') {
            printf("\t%c   -> \tOperador\n", expresion[j]);
            j++;
        } else if (expresion[j] == '(' || expresion[j] == ')') {
            printf("\t%c   -> \tOperador\n", expresion[j]);
            j++;
        } else {
            printf("\t%c   -> \tCaracter Desconocido\n", expresion[j]);
            return '\0';
            //j++;
        }
    } 

    return 0;
}