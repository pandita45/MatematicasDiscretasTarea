#include "struct.h"
#include "recorrido.h"
#include <stdlib.h>

Cola *crearCola() {
  Cola *cola = malloc(sizeof(Cola));
  cola->cabeza = NULL;
  cola->atras = NULL;
  return cola;
}
//en la cola guardemos los recorridos, y obtenemos el vertice final 
//con una funcion
//asi tenemos el vertice, y el camino que hicimos para llegar a el
Recorrido* pop(Cola *queue) {
  if (queue->cabeza == NULL) {
    return NULL;
  }
  Recorrido* vertice = queue->cabeza->vertice;
  Nodo *popped = queue->cabeza;
  if (queue->cabeza == queue->atras) {
    queue->atras = NULL;
  }
  queue->cabeza = queue->cabeza->siguiente;
  free(popped);
  return vertice;
}

Recorrido* peek(Cola *queue){
  return queue->cabeza->vertice;
}
Recorrido* push(Cola *queue, Recorrido* vertice) {
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
  destruirRecorrido(nodo->vertice);
  free(nodo);
}

void destruirCola(Cola *cola) {
  if (cola->cabeza != NULL) {
    disposeNodos(cola->cabeza);
  }
  free(cola);
}
