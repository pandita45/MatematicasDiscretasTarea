#include "cola.h"
#include "grafo.h"
#include "struct.h"
#include <stdlib.h>

void destruirRecorrido(Recorrido *recorrido) {
  if (recorrido == NULL) {
    return;
  }
  free(recorrido->camino);
  free(recorrido);
}

void encolarVecinosYActualizarDistancias(Dijkstra *d, char verticeInicio,
                                         Recorrido *recorrido) {
  int indiceVerticeInicial = indiceVertice(d->grafo, verticeInicio);
  for (int i = 0; i < d->grafo->numVertices; i++) {
    // si visitamos un vertice o no es adjacente entonces no encolamos nada
    if (!d->grafo->matrizAdjacencia[indiceVerticeInicial][i]) {
      continue;
    }
    // pq el largo del arreglo es el largo del camino + 1
    char *nuevoCamino = malloc((recorrido->largo + 2) * sizeof(char));
    for (int j = 0; j <= recorrido->largo; j++) {
      nuevoCamino[j] = recorrido->camino[j];
    }
    nuevoCamino[recorrido->largo + 1] = verticePorIndice(d->grafo, i);

    Recorrido *recorridoNuevo = malloc(sizeof(Recorrido));
    recorridoNuevo->camino = nuevoCamino;
    recorridoNuevo->largo = recorrido->largo + 1;

    if (d->distancias[i] == -1 || d->distancias[i] > recorridoNuevo->largo) {
      push(d->cola, recorridoNuevo);
      d->distancias[i] = recorridoNuevo->largo;
    } else {
      destruirRecorrido(recorridoNuevo);
    }
    // tengo como 3 bugs, despues lo arreglo
  }
}

Recorrido *empezarDijkstra(Grafo *grafo, char inicio, char fin) {
  // eso mismo
  if (indiceVertice(grafo, inicio) == -1 || indiceVertice(grafo, fin) == -1) {
    return NULL;
  }
  Recorrido *caminoFinal = NULL;
  Dijkstra d;
  d.grafo = grafo;
  d.distancias = malloc(grafo->numVertices * sizeof(int));
  d.cola = crearCola();
  for (int i = 0; i < grafo->numVertices; i++) {
    d.distancias[i] = -1;
  }
  d.distancias[indiceVertice(grafo, inicio)] = 0;

  Recorrido recorridoInicial;
  recorridoInicial.camino = malloc(sizeof(char));
  recorridoInicial.largo = 0;
  recorridoInicial.camino[0] = inicio;
  encolarVecinosYActualizarDistancias(&d, inicio, &recorridoInicial);

  free(recorridoInicial.camino);

  while (d.cola->cabeza != NULL) {
    Recorrido *r = pop(d.cola);
    char vertice = r->camino[r->largo];
    if (vertice == fin) {
      if (caminoFinal == NULL || r->largo < caminoFinal->largo) {
        destruirRecorrido(caminoFinal);
        caminoFinal = r;
      } else {
        destruirRecorrido(r);
      }
    } else {
      encolarVecinosYActualizarDistancias(&d, vertice, r);
      destruirRecorrido(r);
    }
  }
  destruirCola(d.cola);
  free(d.distancias);
  return caminoFinal;
}
