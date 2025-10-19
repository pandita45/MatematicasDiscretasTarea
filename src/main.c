#include <stdio.h>
#include "struct.h"
#include "cola.h"

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

