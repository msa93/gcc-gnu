/* 
 * File:   dfs, bfs y dijkstra.h
 * Author: Sebastian
 *
 * Created on 28 de noviembre de 2014, 03:04 PM
 */

#ifndef DFS__BFS_Y_DIJKSTRA_H
#define	DFS__BFS_Y_DIJKSTRA_H

#include "grafo.h"
#define INF (1<<29)

void imprimirCamino(int u, int source, int padres[]);
void imprimirTodosLosCaminos(int numVertices, int source, int padres[], int distancias[]);
void bfs(TGrafo* grafo, int source);
void dfsIt(TGrafo* grafo, int source);
void dfsRec(TGrafo* grafo, int source, int visitados[]);
void dijkstraSimple(TGrafo* grafo, int source);

#endif	/* DFS__BFS_Y_DIJKSTRA_H */

