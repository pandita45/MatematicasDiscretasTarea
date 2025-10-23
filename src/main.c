#include "cola.h"
#include "dijkstra.h"
#include "grafo.h"
#include "struct.h"
#include <stdio.h>
#include <stdlib.h>

void printMatrizAdjacencia(Grafo* grafo) {
  printf("La matriz de adjacencia correspondiente es:\n");
  printf("  ");
  for(int i = 0; i < grafo->numVertices;i++){
    printf("\033[1;34m%c\033[0m ", grafo->vertices[i]);
  }
  printf("\n");
  for (int i = 0; i < grafo->numVertices; i++) {
    printf("\033[1;34m%c\033[0m ",grafo->vertices[i]);
    for (int j = 0; j < grafo->numVertices; j++) {
      printf("%d ", grafo->matrizAdjacencia[i][j]);
    }
    printf("\n");
  }
}

int main(int argc, char **argv) {
  if(argc < 4){
    printf("Error, ejecute nuevamente introduciendo la cantidad de parametros necesaria\n");
    exit(EXIT_FAILURE);
  }
  
  char verticeInicio = argv[1][0];
  char verticeFinal = argv[2][0];
  char* grafoTexto = argv[3];
  Grafo **grafo = crearGrafo(grafoTexto);
  Cola **colaRecorridos = malloc(5 * sizeof(Cola*));
  
  for (int i = 0; i < 5; i++) {
    colaRecorridos[i] = empezarDijkstra(grafo[i], verticeInicio, verticeFinal);
    if(colaRecorridos[i] == NULL){
      printf("Alguno de los vertices introducidos, no existe, verifique los parametros de entrada\n");
      exit(EXIT_FAILURE);
    }
    
    if (i == 0) {
      printf("Se esta ejecutando el algoritmo en el grafo no dirigido\n");
    } else {
      printf("Se esta ejecutando el algoritmo en la orientacion numero %d\n", i);
    }
    printMatrizAdjacencia(grafo[i]);

    Recorrido *recorrido = pop(colaRecorridos[i]);

    if(recorrido == NULL){
      printf("No se encontro un camino entre %c y %c\n", verticeInicio, verticeFinal);
    }
    while (recorrido != NULL) {
      printf("El camino encontrado es:\n");
      for (int j = 0; j < recorrido->largo; j++) {
        printf("%c->", recorrido->camino[j]);
      }
      printf("%c\n", recorrido->camino[recorrido->largo]);
      recorrido = pop(colaRecorridos[i]);
    }
    printf("\n");

    destruirCola(colaRecorridos[i]);
  }
  for (int i = 0; i < 5; i++) {
    destruirGrafo(grafo[i]);
  }
  free(grafo);
  free(colaRecorridos);
}


