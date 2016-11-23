#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers.h"
#include "estruturas.c"

typedef struct generalTree{
  struct cityTree* left;  //Node a esquerda da arvore
  struct cityTree* right; //Node a direita da arvore
  void* informations;
  int positionNumber;
}tree;

int main(){

  return 0;
}
