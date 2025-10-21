#include "dijkstra.h"
#include "grafo.h"
#include "struct.h"
#include "cola.h"
#include <stdio.h>
int main() {
  Grafo *grafo = crearGrafo();
  Cola *colaRecorridos = empezarDijkstra(grafo, 'a', 'e');
  Recorrido* recorrido;
  while ((recorrido = pop(colaRecorridos))) {
    for (int i = 0; i <= recorrido->largo-1; i++) {
      printf("%c->", recorrido->camino[i]);
    }
    printf("%c",recorrido->camino[recorrido->largo]);
    printf("\n");
  }
}
