#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

TGrafo* newGrafo(void) {
    TGrafo* grafo = malloc(sizeof(TGrafo));
    grafo->adjInicio = grafo->adjFin = NULL;
    grafo->numVertices = 0;
    return grafo;
}

void G_insertarVertice(TGrafo* grafo, int v) {
    //si no existe el vertice, es solo insertar al final
    if (G_buscarVertice(grafo, v) == NULL) {
        TVertice* verticeNuevo = malloc(sizeof(TVertice));
        if (verticeNuevo != NULL) {
            verticeNuevo->info = v;
            verticeNuevo->aristasInicio = NULL;
            verticeNuevo->aristasFin = NULL;
            verticeNuevo->sig = NULL;
            if (grafo->adjInicio == NULL) {
                grafo->adjInicio = verticeNuevo;
            }
            else {
                grafo->adjFin->sig = verticeNuevo;
            }
            grafo->adjFin = verticeNuevo;
            (grafo->numVertices)++;
        }
    }
}

void G_insertarArista(TGrafo* grafo, int u, int v, double peso) {
    TVertice* verticeU = G_buscarVertice(grafo, u);
    TVertice* verticeV = G_buscarVertice(grafo, v);
    if (verticeU != NULL && verticeV != NULL && G_buscarArista(grafo, u, v) == NULL) {
        TArista* aristaNueva = malloc(sizeof(TArista));
        aristaNueva->info = v;
        aristaNueva->peso = peso;
        aristaNueva->sig = NULL;
        if (verticeU->aristasInicio == NULL) {
            verticeU->aristasInicio = aristaNueva;
        }
        else {
            verticeU->aristasFin->sig = aristaNueva;
        }
        verticeU->aristasFin = aristaNueva;
    }
}

void G_insertarArista2(TGrafo* grafo, int u, int v, double peso) {
    G_insertarArista(grafo, u, v, peso);
    G_insertarArista(grafo, v, u, peso);
}

TVertice* G_buscarVertice(TGrafo* grafo, int v) {
    if (grafo->adjInicio != NULL) {
        TVertice* nodoRec = grafo->adjInicio;
        while (nodoRec != NULL) {
            if (nodoRec->info == v) {
                return nodoRec;
            }
            nodoRec = nodoRec->sig;
        }
    }
    return NULL;
}

TArista* G_buscarArista(TGrafo* grafo, int u, int v) {
    TVertice* vertice = G_buscarVertice(grafo, u);
    if (vertice != NULL) {
        TArista* nodoRec = vertice->aristasInicio;
        while (nodoRec != NULL) {
            if (nodoRec->info == v) {
                return nodoRec;
            }
            nodoRec = nodoRec->sig;
        }
    }
    return NULL;
}

void G_imprimir(TGrafo* grafo) {
    TVertice* vertice = grafo->adjInicio;
    while (vertice != NULL) {
        printf("%d", vertice->info);
        TArista* arista = vertice->aristasInicio;
        while (arista != NULL) {
            printf(" -> %d (%.2lf)", arista->info, arista->peso);
            arista = arista->sig;
        }
        printf("\n");
        vertice = vertice->sig;
    }

}

void G_finalizar(TGrafo*);

