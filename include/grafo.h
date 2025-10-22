#ifndef GRAFO_H
#define GRAFO_H

#include "struct.h"

Grafo** crearGrafo(char* filepath);


void seleccionarVertices(char *inicio, char *final, Grafo *grafo);

int indiceVertice(Grafo* grafo, char vertice);

char verticePorIndice(Grafo* grafo, int indice);

void destruirGrafo(Grafo* grafo);
#endif
