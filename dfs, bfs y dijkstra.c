#include "dfs, bfs y dijkstra.h"
#include "pila.h"
#include "cola.h"
#include <stdio.h>
#include <stdlib.h>

void imprimirCamino(int u, int source, int padres[]) {
    if (u == source) {
        printf("%d", u);
        return;
    }
    imprimirCamino(padres[u], source, padres);
    printf("->%d", u);
}

void imprimirTodosLosCaminos(int numVertices, int source, int padres[], int distancias[]) {
    int i;
    for (i = 0; i < numVertices; i++) {
        if (distancias[i] == INF) {
            printf("El vertice %d es inaccesible desde %d.\n");
        }
        else {
            printf("La distancia minima desde %d hasta %d es: %d\n", source, i, distancias[i]);
            printf("El camino mas corto es: ");
            imprimirCamino(i, source, padres);
            printf("\n");
        }
    }
}

void bfs(TGrafo* grafo, int source) {
    int V = grafo->numVertices;
    int* padres = malloc(V * sizeof(int));
    int* distancias = malloc(V * sizeof(int));
    TCola* cola = newCola();
    int i;
    for (i = 0; i < V; i++) {
        padres[i] = -1;
        distancias[i] = INF;
    }
    distancias[source] = 0;
    C_enqueue(cola, source);
    while (!C_isEmpty(cola)) {
        int v = C_dequeue(cola);
        TVertice* vertice = G_buscarVertice(grafo, v);
        TArista* arista = vertice->aristasInicio;
        while (arista != NULL) {
            int w = arista->info;
            if (distancias[w] == INF) {
                padres[w] = v;
                distancias[w] = distancias[v] + 1;
                C_enqueue(cola, w);
            }
            arista = arista->sig;
        }
    }
    imprimirTodosLosCaminos(V, source, padres, distancias);
    C_finalize(cola);
    free(padres);
    free(distancias);
}

void dfsIt(TGrafo* grafo, int source) {
    //identico al bfs, solo cambiar cola por pila
    int i, V = grafo->numVertices;
    int* visitados = malloc(V * sizeof(int));
    TPila* pila = newPila();
    for (i = 0; i < V; i++) visitados[i] = 0;
    P_push(pila, source);
    visitados[source] = 1;
    while (!P_isEmpty(pila)) {
        int v = P_pop(pila);
        printf("%d ", v);
        TVertice* vertice = G_buscarVertice(grafo, v);
        TArista* arista = vertice->aristasInicio;
        while (arista != NULL) {
            int w = arista->info;
            if (!visitados[w]) {
                visitados[w] = 1;
                P_push(pila, w);
            }
            arista = arista->sig;
        }
    }
    P_finalize(pila);
    free(pila);
    free(visitados);
}

void dfsRec(TGrafo* grafo, int source, int visitados[]) {
    visitados[source] = 1;
    printf("%d ", source);
    TVertice* vertice = G_buscarVertice(grafo, source);
    TArista* arista = vertice->aristasInicio;
    while (arista != NULL) {
        int w = arista->info;
        if (!visitados[w]) {
            visitados[w] = 1;
            dfsRec(grafo, w, visitados);
        }
        arista = arista->sig;
    }
}

int min(int a, int b) {
    return a < b ? a : b;
}

int hallarVerticeMenorPeso(int numVertices, int distancias[], int visitados[]) {
    int i, menor = INF, indMenor = 0;
    for (i = 0; i < numVertices; i++) {
        if (!visitados[i] && menor > distancias[i]) {
            menor = distancias[i];
            indMenor = i;
        }
    }
    return indMenor;
}

void dijkstraSimple(TGrafo* grafo, int source) {
    int V = grafo->numVertices;
    int* visitados = malloc(V * sizeof(int));
    int* padres = malloc(V * sizeof(int));
    int* distancias = malloc(V * sizeof(int));
    int i;
    for (i = 0; i < V; i++) {
        padres[i] = -1;
        distancias[i] = INF;
        visitados[i] = 0;
    }
    distancias[source] = 0;
    for (i = 0; i < V; i++) { //O(V)
        int v = hallarVerticeMenorPeso(V, distancias, visitados); //O(V)
        //esta funcion se asegura de buscar solo entre los no visitados
        visitados[v] = 1;
        TVertice* vertice = G_buscarVertice(grafo, v);
        TArista* arista = vertice->aristasInicio;
        while (arista != NULL) { //O(E)
            int w = arista->info;
            if (!visitados[w]) {
                int peso = arista->peso;
                //distancias[w] = min(distancias[w], distancias[v] + peso);
                if (distancias[w] > distancias[v] + peso) {
                    distancias[w] = distancias[v] + peso;
                    padres[w] = v;
                }
            }
            arista = arista->sig;
        }
    }
    //Complejidad: O(V^2 + E) = O(V^2)
    imprimirTodosLosCaminos(V, source, padres, distancias);
    free(padres);
    free(distancias);
}
