#include <stdio.h>
#include "reconocedor.h"

int Automata(int estado_actual, int x) {
    static int tabla[4][2] = {
        {1, -1},
        {1,  2},
        {3,  2},
        {1,  3}
    };
    if (x >= 48 && x <= 57) {
        return tabla[estado_actual][0];
    } else if (x >= 40 && x <= 47) {
        return tabla[estado_actual][1];
    } else {
        return -1;
    }
}
