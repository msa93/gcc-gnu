/* 
 * File:   grafo.h
 * Author: Sebastian
 *
 * Created on 18 de noviembre de 2014, 01:56 AM
 */

#ifndef GRAFO_H
#define	GRAFO_H



//una arista es un nodo de la lista de adyacencia de cada
//vertice, tiene un identificador y un peso

typedef struct arista {
    int info;
    double peso;
    struct arista* sig;
} TArista;

//un vertice contiene punteros al inicio y fin de su lista
//de adyacencia y un puntero al siguiente vertice, tiene un
//identificador

typedef struct vertice {
    int info;
    TArista* aristasInicio;
    TArista* aristasFin;
    struct vertice* sig;
} TVertice;

//un grafo es una lista de vertices

typedef struct grafo {
    int numVertices;
    TVertice* adjInicio;
    TVertice* adjFin;
} TGrafo;

TGrafo* newGrafo(void);
void G_insertarVertice(TGrafo*, int);
void G_insertarArista(TGrafo*, int, int, double);
void G_insertarArista2(TGrafo*, int, int, double);
TVertice* G_buscarVertice(TGrafo*, int);
TArista* G_buscarArista(TGrafo*, int, int);
//void G_eliminarVertice(TGrafo*, int);
//void G_eliminarArista(TGrafo*, int, int);
void G_imprimir(TGrafo*);
void G_finalizar(TGrafo*);

#endif	/* GRAFO_H */

