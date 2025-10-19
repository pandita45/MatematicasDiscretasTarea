#ifndef STRUCT_H
#define STRUCT_H

typedef struct Nodo Nodo;

typedef struct {
  int numVertices;
  char* vertices;
  char** matrizAdjacencia;
} Grafo;

typedef struct {
  int largo;
  char* camino;
} Recorrido;

typedef struct{
  Nodo* cabeza;
  Nodo* atras;
} Cola;

struct Nodo {
  char vertice;
  Nodo* siguiente;
};

typedef struct {
  Recorrido* distancias;
  char* visitado; //se inicializa en 0
  Cola nodoSiguiente; //hay que hacer la cola
} Dijkstra;


#endif
