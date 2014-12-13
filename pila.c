#include "pila.h"
#include <stdlib.h>

TPila* newPila(void) {
    TPila* pila = malloc(sizeof(TPila));
    pila->top = NULL;
    return pila;
}
void P_push(TPila* pila, int e) {
    TNodoP* nodoNuevo = malloc(sizeof(TNodoP));
    if (nodoNuevo != NULL) {
        nodoNuevo->info = e;
        nodoNuevo->sig = pila->top;
        pila->top = nodoNuevo;
    }
}
int P_pop(TPila* pila) {
    if (!P_isEmpty(pila)) {
        TNodoP* nodoElim = pila->top;
        int topInfo = nodoElim->info;
        pila->top = pila->top->sig;
        free(nodoElim);
        return topInfo;
    }
    else {
        return -1;
    }
}
int P_isEmpty(TPila* pila) {
    return pila->top == NULL;
}
void P_finalize(TPila* pila) {
    while (!P_isEmpty(pila)) {
        P_pop(pila);
    }
}
