#include "cola.h"
#include "dijkstra.h"
#include "grafo.h"
#include "struct.h"
#include <stdio.h>
#include <stdlib.h>

void printMatrizAdjacencia(Grafo* grafo) {
  printf("Esta es la matriz de adjacencia de esta orientación\n");
  for (int i = 0; i < grafo->numVertices; i++) {
    for (int j = 0; j < grafo->numVertices; j++) {
      printf("%d ", grafo->matrizAdjacencia[i][j]);
    }
    printf("\n");
  }
}

int main(int argc, char **argv) {
  char verticeInicio = 'a';
  char verticeFinal = 'b'; 
  Grafo **grafo = crearGrafo();
  Cola **colaRecorridos = malloc(5 * sizeof(Cola*));
  
  for (int i = 0; i < 5; i++) {
    colaRecorridos[i] = empezarDijkstra(grafo[i], verticeInicio, verticeFinal);
    
    if (i == 0) {
      printf("Se esta ejecutando el algoritmo en el grafo no dirigido\n");
    } else {
      printf("Se esta ejecutando el algoritmo en la orientacion numero %d\n", i);
    }
    printMatrizAdjacencia(grafo[i]);

    if (!colaRecorridos[i]) {
      printf("No se encontro un camino entre los vertices %c y %c en este grafo/digrafo\n", verticeInicio, verticeFinal);
      continue;
    }

    Recorrido *recorrido = pop(colaRecorridos[i]);
    while (recorrido != NULL) {
      for (int j = 0; j < recorrido->largo; j++) {
        printf("%c->", recorrido->camino[j]);
      }
      printf("%c\n", recorrido->camino[recorrido->largo]);
      recorrido = pop(colaRecorridos[i]);
    }

    destruirCola(colaRecorridos[i]);
  }
  for (int i = 0; i < 5; i++) {
    destruirGrafo(grafo[i]);
  }
  free(grafo);
  free(colaRecorridos);
}


