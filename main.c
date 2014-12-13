/* 
 * File:   main.c
 * Author: Sebastian
 *
 * Created on 18 de noviembre de 2014, 01:56 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "grafo.h"
#include "dfs, bfs y dijkstra.h"

void pruebaRecorridos(void) {
    TGrafo* grafo = newGrafo();
    int i;
    int n = 13;
    for (i = 0; i < n; i++) {
        G_insertarVertice(grafo, i);
    }
    G_insertarArista2(grafo, 0, 1, 1.0);
    G_insertarArista2(grafo, 1, 2, 1.0);
    G_insertarArista2(grafo, 2, 3, 1.0);
    G_insertarArista2(grafo, 0, 4, 1.0);
    G_insertarArista2(grafo, 1, 5, 1.0);
    G_insertarArista2(grafo, 2, 6, 1.0);
    G_insertarArista2(grafo, 3, 7, 1.0);
    G_insertarArista2(grafo, 5, 6, 1.0);
    G_insertarArista2(grafo, 4, 8, 1.0);
    G_insertarArista2(grafo, 8, 9, 1.0);
    G_insertarArista2(grafo, 5, 10, 1.0);
    G_insertarArista2(grafo, 6, 11, 1.0);
    G_insertarArista2(grafo, 7, 12, 1.0);
    G_insertarArista2(grafo, 9, 10, 1.0);
    G_insertarArista2(grafo, 10, 11, 1.0);
    G_insertarArista2(grafo, 11, 12, 1.0);
    printf("Para el siguiente grafo:\n");
    G_imprimir(grafo);
    printf("\nBFS\n");
    bfs(grafo, 0);
    printf("\nDFS\nIterativo: ");
    dfsIt(grafo, 0);
    printf("\nRecursivo: ");
    int* visitados = malloc(n * sizeof(int));
    for (i = 0; i < n; i++) visitados[i] = 0;
    dfsRec(grafo, 0, visitados);
    //G_finalizar(grafo);
    free(grafo);
    free(visitados);
}

void pruebaDijkstra(void) {
    TGrafo* grafo = newGrafo();
    int i;
    int n = 9;
    for (i = 0; i < n; i++) {
        G_insertarVertice(grafo, i);
    }
    G_insertarArista2(grafo, 0, 1, 4.0);
    G_insertarArista2(grafo, 0, 7, 8.0);
    G_insertarArista2(grafo, 1, 7, 11.0);
    G_insertarArista2(grafo, 1, 2, 8.0);
    G_insertarArista2(grafo, 2, 8, 2.0);
    G_insertarArista2(grafo, 6, 8, 6.0);
    G_insertarArista2(grafo, 7, 6, 1.0);
    G_insertarArista2(grafo, 7, 8, 7.0);
    G_insertarArista2(grafo, 2, 3, 7.0);
    G_insertarArista2(grafo, 2, 5, 4.0);
    G_insertarArista2(grafo, 3, 5, 14.0);
    G_insertarArista2(grafo, 6, 5, 2.0);
    G_insertarArista2(grafo, 3, 4, 9.0);
    G_insertarArista2(grafo, 5, 4, 10.0);
    printf("\n\nPara el siguiente grafo:\n");
    G_imprimir(grafo);
    printf("\nAlgoritmo de Dijkstra\n");
    dijkstraSimple(grafo, 0);
    //G_finalizar(grafo);
    free(grafo);
}

int main(int argc, char** argv) {
    pruebaRecorridos();
    pruebaDijkstra();
    return (EXIT_SUCCESS);
}

