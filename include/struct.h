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
  char* camino; //largo del arreglo = largo+1
} Recorrido;

typedef struct{
  Nodo* cabeza;
  Nodo* atras;
} Cola;

struct Nodo {
  Recorrido* vertice;
  Nodo* siguiente;
};

typedef struct {
  int* distancias;
  Cola* cola; //hay que hacer la cola
  Grafo* grafo;
} Dijkstra;


#endif
