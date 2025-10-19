#include "struct.h"
#include <stdlib.h>
#include <stdio.h>

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
