#include "struct.h"
#include <stdlib.h>
/// Permite destruir un recorrido guardado
void destruirRecorrido(Recorrido *recorrido) {
  if (recorrido == NULL) {
    return;
  }
  free(recorrido->camino);
  free(recorrido);
}

char verticeFinal(Recorrido* r){
  return r->camino[r->largo];
}
