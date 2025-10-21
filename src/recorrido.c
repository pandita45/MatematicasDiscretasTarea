#include "struct.h"
#include <stdlib.h>
/// Permite destruir un recorrido guardado

void destruirRecorrido(Recorrido *r) {
  if (r == NULL) {
    return;
  }
  free(r->camino);
  free(r);
}

char verticeFinal(Recorrido* r){
  return r->camino[r->largo];
}
