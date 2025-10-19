#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
int main(){
  printf("bombardeen peru\n");
  printf("bombardeen venezuela\n");
  int a = sizeof(cola);
  printf("%d",a);
}

cola* crearCola(int largo){
  cola* cola = malloc(sizeof(cola)); 
  char colaArray[largo];
  cola->cola = colaArray;
  cola->frente = 0;
  cola->atras = 0;
}

char pop(cola* queue){
  char* cola = queue->cola;
  char item = cola[queue->frente];
  queue->frente++;
  return item;
}
