#include <stdio.h>
#include <stdlib.h>
#include "../include/struct.h"



Grafo crearGrafo(){
  FILE* p = fopen("grafo1.txt", "r");
  char linea[1024];
  char linea2[1024];
  while(fgetc != EOF){
    fgets(linea, sizeof(linea), p);
    fgets(linea2, sizeof(linea2), p);
    printf("%s", linea);
    printf("%s", linea2);
  }

  if (p == NULL){
    printf("Error al abrir el archivo\n");
    exit(1);
  }
  fclose(p);
 
  

  Grafo grafo;
  /*
  grafo.numVertices = numV;
  grafo.vertices = nodos;
  grafo.matrizAdjacencia = matriz;*/
  return grafo;
}

cola *crearCola(int largo){
  cola *cola = malloc(sizeof(cola));
  char *colaArray = malloc(largo * sizeof(char));
  cola->cola = colaArray;
  cola->frente = 0;
  cola->atras = 0;
  return cola;
}

char pop(cola *queue){
  char *cola = queue->cola;
  char item = cola[queue->frente];
  queue->frente++;
  return item;
}

char push(cola *queue, char vertice){
  char *cola = queue->cola;
  cola[queue->atras] = vertice;
  queue->atras++;
  return vertice;
}

int main(){
  cola *cola = crearCola(3);
  /*char verticeUno = 'A';
  char verticeDos = 'B';
  char verticeTre = 'C';
  push(cola, verticeUno);
  push(cola, verticeDos);
  push(cola, verticeTre);
  char *vertices = {verticeUno, verticeDos, verticeTre};
  */
  //char **matriz = {{0, 1, 1},
  //                 {1, 0, 1},
  //                 {1, 1, 0}};
  //Grafo grafo = crearGrafo(numV, vertices,matriz);

  int a = sizeof(cola);

  for (int i = 0; i < 3; i++)
  {
    printf("%c\n", pop(cola));
  }
  printf("%d", a);
}

