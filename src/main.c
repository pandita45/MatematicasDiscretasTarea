#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "cola.c"

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


int main(){
  Cola *cola = crearCola();
  push(cola, 'a');
  push(cola, 'b');
  push(cola, 'c');
  push(cola, 'd');
  push(cola, 'e');
  push(cola, 'f');
  push(cola, 'g');
  //char **matriz = {{0, 1, 1},
  //                 {1, 0, 1},
  //                 {1, 1, 0}};
  //Grafo grafo = crearGrafo(numV, vertices,matriz);

  for (int i = 0; i < 7; i++)
  {
    printf("%c\n", pop(cola));
  }
  destruirCola(cola);
}

