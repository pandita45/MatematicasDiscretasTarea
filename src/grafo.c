#include "struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
  // +1 para el terminador nulo
  char *finalVertices = malloc(sizeof(char) * (numV + 1));
  int contador = 0;

  for (int i = 0; i < strlen(linea); i++) {
    if (linea[i] != ',' && linea[i] != ' ') {
      finalVertices[contador] = linea[i];
      contador++;
    }
  }
  finalVertices[contador] = '\0';
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

char verticePorIndice(Grafo *grafo, int indice) {
  if (indice < 0 || indice >= grafo->numVertices) {
    return -1;
  }
  return grafo->vertices[indice];
}

char **crearMatrizAdjacencia(Grafo *grafo, char *aristas, int esGrafo) {
  // duplicamos para no modificar aristas original
  char *aristasCopia = strdup(aristas);
  if (aristasCopia == NULL) {
    perror("Error al duplicar cadena de aristas");
    exit(EXIT_FAILURE);
  }

  char **matrizAdjacencia = malloc(sizeof(char *) * grafo->numVertices);
  for (int i = 0; i < grafo->numVertices; i++) {
    matrizAdjacencia[i] = calloc(grafo->numVertices, sizeof(char));
  }

  char *token = strtok(aristasCopia, ",");
  while (token != NULL) {
    char *parsed = token;
    while (*parsed == ' ')
      parsed++;

    if (strlen(parsed) >= 2) {
      int inicio = indiceVertice(grafo, parsed[0]);
      int final = indiceVertice(grafo, parsed[1]);

      if (inicio != -1 && final != -1) {
        if (esGrafo) {
          matrizAdjacencia[inicio][final] = 1;
          matrizAdjacencia[final][inicio] = 1;
        } else {
          if (rand() % 2)
            matrizAdjacencia[inicio][final] = 1;
          else
            matrizAdjacencia[final][inicio] = 1;
        }
      }
    }
    token = strtok(NULL, ",");
  }

  free(aristasCopia);
  return matrizAdjacencia;
}

Grafo **crearGrafo() {
  Grafo *grafo = malloc(sizeof(Grafo));
  Grafo **grafos = malloc(5 * sizeof(Grafo *));
  char aristas[1024];
  char vertices[1024];

  leerGrafo(vertices, aristas);

  grafo->numVertices = contV(vertices);
  grafo->vertices = devolverVertices(vertices, contV(vertices));

  char aristascpy[1024];
  strcpy(aristascpy, aristas);

  grafo->matrizAdjacencia = crearMatrizAdjacencia(grafo, aristas, 1);
  grafos[0] = grafo;

  for (int i = 1; i < 5; i++) {
    grafos[i] = malloc(sizeof(Grafo));
    grafos[i]->numVertices = grafo->numVertices;
    grafos[i]->vertices = grafo->vertices;

    grafos[i]->matrizAdjacencia = crearMatrizAdjacencia(grafo, aristascpy, 0);
  }

  return grafos;
}

void destruirGrafo(Grafo *grafo) {
  free(grafo->vertices);
  for (int i = 0; i < grafo->numVertices; i++) {
    free(grafo->matrizAdjacencia[i]);
  }
  free(grafo->matrizAdjacencia);
  free(grafo);
}


