#include "struct.h"
#include <stdlib.h>

Cola *crearCola() {
  Cola *cola = malloc(sizeof(Cola));
  cola->cabeza = NULL;
  cola->atras = NULL;
  return cola;
}

char pop(Cola *queue) {
  if (queue->cabeza == NULL) {
    return '\0';
  }
  char vertice = queue->cabeza->vertice;
  Nodo *popped = queue->cabeza;
  if (queue->cabeza == queue->atras) {
    queue->atras = NULL;
  }
  queue->cabeza = queue->cabeza->siguiente;
  free(popped);
  return vertice;
}

char push(Cola *queue, char vertice) {
  Nodo *nuevoAtras = malloc(sizeof(Nodo));
  nuevoAtras->vertice = vertice;
  nuevoAtras->siguiente = NULL;
  if (queue->atras != NULL) {
    queue->atras->siguiente = nuevoAtras;
  }
  if (queue->cabeza == NULL) {
    queue->cabeza = nuevoAtras;
  }
  queue->atras = nuevoAtras;
  return vertice;
}

void disposeNodos(Nodo *nodo) {
  if (nodo->siguiente != NULL) {
    disposeNodos(nodo->siguiente);
  }
  free(nodo);
}

void destruirCola(Cola *cola) {
  if (cola->cabeza != NULL) {
    disposeNodos(cola->cabeza);
  }
  free(cola);
}
