#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "struct.h"

void leerGrafo(char* source, char* dest){
  char linea[1024];
  char* pc = linea;
  int inicio = 0;
  int final = 0;
  int j = 0,k = 0;
  FILE* p = fopen("src/grafo1.txt", "r");
  if(p == NULL){
    perror("No se pudo abrir correctamente el archivo\n");
    exit(EXIT_FAILURE);
  }
  
  while(fgets(linea,sizeof(linea),p)!= NULL){
    for(int i = 0; i < strlen(linea); i++){
      if(linea[i] == '{'){
	j++;
	inicio = ++i;
      }
      if(!j){
	continue;
      }
      if(linea[i] == '}'){
	final = --i;
	break;
      }
    }
    
    if(!k){
      pc += inicio;
      strncpy(source,pc,final - inicio + 1);
      source[final - inicio + 1] = '\0';
      k++;
    }
    else{
      strncpy(dest,pc,final - inicio + 1);
      dest[final - inicio + 1] = '\0';
      
    }
  }

  fclose(p);
}
int contV(char* vertices){
  int cont = 1;
  if(strlen(vertices)==0){return 0;}
  for(int i = 0; i < strlen(vertices); i++){
    if(vertices[i] == ',') {
      cont++;
    }
  }
   return cont;
  
}
  
Grafo* crearGrafo(){
  char aristas[1024];
  char vertices[1024];
  leerGrafo(vertices,aristas);
  printf("%s\n",vertices);
  printf("%s\n",aristas);
  printf("%d\n",contV(vertices));
  return NULL;
  /*
  Grafo grafo;
    grafo.numVertices = numV;
    grafo.vertices = nodos;
    grafo.matrizAdjacencia = matriz;*/

}
