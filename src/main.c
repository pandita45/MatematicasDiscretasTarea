#include "dijkstra.h"
#include "grafo.h"
#include "struct.h"
#include "cola.h"
#include <stdio.h>
int main() {
  char verticeInicio;
  char verticeFinal;
  Grafo *grafo = crearGrafo(input());
  seleccionarVertices(&verticeInicio,&verticeFinal,grafo);
  Cola *colaRecorridos = empezarDijkstra(grafo, verticeInicio, verticeFinal);
  Recorrido* recorrido;
  while ((recorrido = pop(colaRecorridos))) {
    for (int i = 0; i <= recorrido->largo-1; i++) {
      printf("%c->", recorrido->camino[i]);
    }
    printf("%c",recorrido->camino[recorrido->largo]);
    printf("\n");
  }
  destruirCola(colaRecorridos);
  destruirGrafo(grafo);
}
