#include "dijkstra.h"
#include "grafo.h"
#include "struct.h"
#include <stdio.h>
int main() {
  Grafo *grafo = crearGrafo();
  Recorrido *recorrido = empezarDijkstra(grafo, 'a', 'e');
  for (int i = 0; i <= recorrido->largo; i++) {
    printf("%c\n", recorrido->camino[i]);
  }
}
