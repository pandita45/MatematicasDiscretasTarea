#include "struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int input(){
    int tipoGrafo;
     printf("Elija el tipo de estructura a utilizar seleccionando el valor numerico correspondiente\n");
     printf("1 - Grafo\n");
     printf("2 - Digrafo\n");
    do{
      scanf("%d", &tipoGrafo);
  
      if(tipoGrafo != 1 && tipoGrafo != 2){
	printf("Ingrese uno de los valores numericos correspondientes\n");
      }
    } while(tipoGrafo != 1 && tipoGrafo != 2);
  return tipoGrafo;
}

void seleccionarVertices(char *inicio, char *final, Grafo *grafo){
  char auxInicio;
  char auxFinal;
  int valido = 0 ;
  printf("Seleccione uno de los vertices de inicio disponibles:\n");
  for(int i = 0; i<grafo->numVertices; i++){
    printf("%c ", grafo->vertices[i]);
  }
  printf("\n");
  while(1){
    valido = 0;
    scanf(" %c",&auxInicio);
    for(int i = 0; i<grafo->numVertices; i++){
      if(auxInicio == grafo->vertices[i]){
	valido = 1;
	break;
      }
    }
    if(valido){
      *inicio = auxInicio;
      break;
    }
    else{
      printf("Ingrese un vertice valido\n");
    }
  }
  printf("Seleccione uno de los vertices de destino disponibles:\n");
  for(int i = 0; i<grafo->numVertices; i++){
    printf("%c ", grafo->vertices[i]);
  }
  printf("\n");
  
  while(1){
    valido = 0;
    scanf(" %c",&auxFinal);
    for(int i = 0; i<grafo->numVertices; i++){
      if(auxFinal == grafo->vertices[i]){
	valido = 1;
	break;
      }
    }
    if(valido){
      *final = auxFinal;
      break;
    }
    else{
      printf("Ingrese un vertice valido\n");
    }
  
  }
  
}

  

void leerGrafo(char *source, char *dest) {
  char linea[1024];
  char *pc = linea;
  int inicio = 0;
  int final = 0;
  int j = 0, k = 0;
  FILE *p = fopen("src/grafo1.txt", "r");
  if (p == NULL) {
    perror("No se pudo abrir correctamente el archivo\n");
    exit(EXIT_FAILURE);
  }

  while (fgets(linea, sizeof(linea), p) != NULL) {
    for (int i = 0; i < strlen(linea); i++) {
      if (linea[i] == '{') {
        j++;
        inicio = ++i;
      }
      if (!j) {
        continue;
      }
      if (linea[i] == '}') {
        final = --i;
        break;
      }
    }

    if (!k) {
      pc += inicio;
      strncpy(source, pc, final - inicio + 1);
      source[final - inicio + 1] = '\0';
      k++;
    } else {
      strncpy(dest, pc, final - inicio + 1);
      dest[final - inicio + 1] = '\0';
    }
  }

  fclose(p);
}
int contV(char *vertices) {
  int cont = 1;
  if (strlen(vertices) == 0) {
    return 0;
  }
  for (int i = 0; i < strlen(vertices); i++) {
    if (vertices[i] == ',') {
      cont++;
    }
  }
  return cont;
}

char *devolverVertices(char *linea, int numV) {

  char *finalVertices = malloc(sizeof(char) * numV);
  int contador = 0;

  for (int i = 0; i < strlen(linea); i++) {
    if (linea[i] != ',' && linea[i] != ' ') {
      finalVertices[contador] = linea[i];
      contador++;
    }
  }
  return finalVertices;
}

int indiceVertice(Grafo *grafo, char vertice) {

  for (int i = 0; i < grafo->numVertices; i++) {

    if (grafo->vertices[i] == vertice) {
      return i;
    }
  }
  return -1;
}

char verticePorIndice(Grafo* grafo, int indice){
  if(indice < 0 || indice >= grafo->numVertices){
    return -1;
  }
  return grafo->vertices[indice];
}

char **crearMatrizAdjacencia(Grafo *grafo, char *aristas, int esGrafo) {
  char **matrizAdjacencia = malloc(sizeof(char *) * grafo->numVertices);

  for (int i = 0; i < grafo->numVertices; i++) {
    matrizAdjacencia[i] = malloc(sizeof(char) * grafo->numVertices);
    for (int j = 0; j < grafo->numVertices; j++) {
      matrizAdjacencia[i][j] = 0;
    }
  }
  char *token = strtok(aristas, ",");
  do {
    char* parsed = token;
    while (*parsed == ' ') parsed++;
    int inicio = indiceVertice(grafo, parsed[0]);
    int final = indiceVertice(grafo, parsed[1]);
    matrizAdjacencia[inicio][final] = 1;
    if (esGrafo) {
      matrizAdjacencia[final][inicio] = 1;
    }
  } while ((token = strtok(NULL, ",")));
  return matrizAdjacencia;
}

Grafo *crearGrafo(int esGrafo) {
  Grafo *grafo = malloc(sizeof(Grafo));
  char aristas[1024];
  char vertices[1024];
  leerGrafo(vertices, aristas);
  grafo->numVertices = contV(vertices);
  grafo->vertices = devolverVertices(vertices, contV(vertices));
  grafo->matrizAdjacencia = crearMatrizAdjacencia(grafo, aristas, esGrafo);
  return grafo;
}

void destruirGrafo(Grafo* grafo){
  free(grafo->vertices);
  for(int i = 0; i < grafo->numVertices; i++){
    free(grafo->matrizAdjacencia[i]);
  }
  free(grafo->matrizAdjacencia);
  free(grafo);
}
