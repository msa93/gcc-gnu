#include "cola.h"
#include <stdlib.h>

TCola* newCola(void) {
    TCola* cola = malloc(sizeof(TCola));
    cola->inicio = cola->fin = NULL;
    return cola;
}

void C_enqueue(TCola* cola, int e) {
    //es solo insertar al final
    TNodoC* nodoNuevo = malloc(sizeof(TNodoC));
    if (nodoNuevo != NULL) {
        nodoNuevo->info = e;
        nodoNuevo->sig = NULL;
        if (cola->inicio == NULL) {
            cola->inicio = nodoNuevo;
        }
        else {
            cola->fin->sig = nodoNuevo;
        }
        cola->fin = nodoNuevo;
    }
}

int C_dequeue(TCola* cola) {
    //es solo eliminar al inicio
    if (!C_isEmpty(cola)) {
        TNodoC* nodoElim = cola->inicio;
        int headInfo = nodoElim->info;
        cola->inicio = cola->inicio->sig;
        free(nodoElim);
        return headInfo;
    }
    else {
        return -1;
    }
}

int C_isEmpty(TCola* cola) {
    return (cola->inicio == NULL);
}
void C_finalize(TCola* cola) {
    while (!C_isEmpty(cola)) {
        C_dequeue(cola);
    }
}
