#ifndef COLA_H
#define COLA_H
#include "struct.h"

Cola *crearCola();

char pop(Cola *queue);

char push(Cola *queue, char vertice);

void destruirCola(Cola *cola);

#endif
