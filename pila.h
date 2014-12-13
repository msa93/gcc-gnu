/* 
 * File:   pila.h
 * Author: Sebastian
 *
 * Created on 18 de noviembre de 2014, 01:40 AM
 */

#ifndef PILA_H
#define	PILA_H

typedef struct nodoPila {
    int info;
    struct nodoPila* sig;
} TNodoP;

typedef struct {
    TNodoP* top;
} TPila;

TPila* newPila(void);
void P_push(TPila*, int);
int P_pop(TPila*);
int P_isEmpty(TPila*);
void P_finalize(TPila*);

#endif	/* PILA_H */

