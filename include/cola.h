#ifndef COLA_H
#define COLA_H
#include "struct.h"

Cola *crearCola();

Recorrido *pop(Cola *queue);

Recorrido *push(Cola *queue, Recorrido *vertice);

Recorrido *peek(Cola *queue);
void destruirCola(Cola *cola);

#endif
