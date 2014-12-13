/* 
 * File:   cola.h
 * Author: Sebastian
 *
 * Created on 18 de noviembre de 2014, 01:02 AM
 */

#ifndef COLA_H
#define	COLA_H

typedef struct nodoCola {
    int info;
    struct nodoCola* sig;
} TNodoC;

typedef struct {
    TNodoC* inicio;
    TNodoC* fin;
} TCola;

TCola* newCola(void);
void C_enqueue(TCola*, int);
int C_dequeue(TCola*);
int C_isEmpty(TCola*);
void C_finalize(TCola*);

#endif	/* COLA_H */

