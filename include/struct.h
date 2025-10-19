
#ifndef STRUCT_H
#define STRUCT_H

typedef struct {
  int numVertices;
  char* vertices;
  char** matrizAdjacencia;
} Grafo;

typedef struct {
  int largo;
  char* camino;
} Recorrido;

typedef struct {
  char* cola; //arreglo de tamaño fijo
  int frente; //indice
  int atras; //indice
} cola;

typedef struct {
  Recorrido* distancias;
  char* visitado; //se inicializa en 0
  cola nodoSiguiente; //hay que hacer la cola
} Dijkstra;


#endif
