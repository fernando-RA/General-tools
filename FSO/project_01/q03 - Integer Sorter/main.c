#include <stdio.h>
#include "sortFunctions.h"
#include "headers.h"
#include <string.h>

int main(int argc, char** argv){
  char* option = "-d";
  List list;
  readNumbers(list);
  printList(list);

  if(argc - 1 > 0) {
		if(strcmp("-r", argv[1]) == 0) {
			option = "-r";
		}
	}
  printf("%s\n", option);
  //TODO - ler inteiros, salvar em um vetor dinamico


  //TODO - imprimir vetor ordenado

  return 0;
}
