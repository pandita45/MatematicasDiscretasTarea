#include "recorrido.h"
#include "cola.h"
#include "grafo.h"
#include "struct.h"
#include <stdlib.h>
#include <stdio.h>
/// Esta funcion toma un camino hacia un vertice, y encola a los hijos para que
/// sean procesados por el algoritmo
void encolarVecinosYActualizarDistancias(Dijkstra *d, char verticeInicio,
                                         Recorrido *recorrido) {
  int indiceVerticeInicial = indiceVertice(d->grafo, verticeInicio);
  // Iteramos sobre todos los vertices del grafo, buscando los que sean
  // adjacentes
  for (int i = 0; i < d->grafo->numVertices; i++) {
    // si visitamos un vertice o no es adjacente entonces no encolamos nada
    if (!d->grafo->matrizAdjacencia[indiceVerticeInicial][i]) {
      continue;
    }
    // ahora encontramos un vertice que si es adjacente al vertice donde estamos
    // pedimos memoria para guardar el camino que tomamos desde el inicio de
    // nuestra busqueda hasta este nuevo vertice basicamente se nos da el camino
    // para llegar al padre, y el nuevo camino es el camino antiguo, pero con el
    // nuevo vertice apendido
    char *nuevoCamino = malloc((recorrido->largo + 2) * sizeof(char));
    for (int j = 0; j <= recorrido->largo; j++) {
      nuevoCamino[j] = recorrido->camino[j];
    }
    nuevoCamino[recorrido->largo + 1] = verticePorIndice(d->grafo, i);

    Recorrido *recorridoNuevo = malloc(sizeof(Recorrido));
    recorridoNuevo->camino = nuevoCamino;
    recorridoNuevo->largo = recorrido->largo + 1;

    // Si el camino que encontramos reduce nuestra distancia, encolamos el
    // vertice y actualizamos la distancia si no, nos acordamos de devolver la
    // memoria que pedimos
    if (d->distancias[i] == -1 || d->distancias[i] > recorridoNuevo->largo) {
      push(d->cola, recorridoNuevo);
      d->distancias[i] = recorridoNuevo->largo;
    } else {
      destruirRecorrido(recorridoNuevo);
    }
  }
}

/// Esta funcion empieza la busqueda del camino mas corto entre 2 vertices
Cola *empezarDijkstra(Grafo *grafo, char inicio, char fin) {
  if(inicio == fin){
    printf("El vertice de inicial y el final son iguales, el camino mas corto es el mismo vertice\n");
    exit(EXIT_FAILURE);
  }
  // Si alguno de los vertices de inicio o fin no existe, retornamos NULL
  if (indiceVertice(grafo, inicio) == -1 || indiceVertice(grafo, fin) == -1) {
    return NULL;
  }
  Cola *caminoFinal = crearCola();
  int largoCaminoFinal = -1;

  Dijkstra d;
  d.grafo = grafo;
  d.distancias = malloc(grafo->numVertices * sizeof(int));
  d.cola = crearCola();

  // Inicializamos todas las distancias en -1,
  for (int i = 0; i < grafo->numVertices; i++) {
    d.distancias[i] = -1;
  }
  d.distancias[indiceVertice(grafo, inicio)] = 0;

  // Creamos el primer camino, del cual se derivaran todos los otros
  // Como lo vamos a usar poco, podemos crearlo en stack
  Recorrido recorridoInicial;
  char camino[1];
  recorridoInicial.camino = camino;
  recorridoInicial.largo = 0;
  recorridoInicial.camino[0] = inicio;
  encolarVecinosYActualizarDistancias(&d, inicio, &recorridoInicial);

  while (d.cola->cabeza != NULL) {
    // La cola tecnicamente solo contiene el camino que tomamos para llegar al
    // vertice desde el inicio, pero podemos extraer el vertice facilmente, al
    // final funciona como Dijkstra normal
    Recorrido *r = pop(d.cola);
    char verticeFinalCamino = r->camino[r->largo];
    // Si nuestro camino termina en el vertice final, guardamos el camino para
    // devolverlo, si no, lo podemos usar y liberar
    if (verticeFinalCamino != fin) {
      encolarVecinosYActualizarDistancias(&d, verticeFinalCamino, r);
      destruirRecorrido(r);
      continue;
    }
    // Si el camino hasta el fin es mas corto que lo que teniamos, nos
    // deshacemos de todos los demas y dejamos solo ese Si es igual, lo
    // agregamos a cola, si no, lo descartamos
    if (largoCaminoFinal == -1 || r->largo < largoCaminoFinal) {
      Recorrido *recorridoViejo;
      while ((recorridoViejo = pop(caminoFinal)))
        destruirRecorrido(recorridoViejo);
      push(caminoFinal, r);
      largoCaminoFinal = r->largo;
      encolarVecinosYActualizarDistancias(&d, verticeFinalCamino, r);
    } else if (r->largo == largoCaminoFinal) {
      encolarVecinosYActualizarDistancias(&d, verticeFinalCamino, r);
      push(caminoFinal, r);
    } else {
      encolarVecinosYActualizarDistancias(&d, verticeFinalCamino, r);
      destruirRecorrido(r);
    }
  }

  destruirCola(d.cola);
  free(d.distancias);
  return caminoFinal;
}

