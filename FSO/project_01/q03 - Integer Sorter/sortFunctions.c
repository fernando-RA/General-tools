#include "headers.h"
#include "sortFunctions.h"
#include <stdlib.h>
#include <stdio.h>

#define TEMPMAXSIZE 50

List readNumbers(List toReturn){
  int count = 0;
  int numRead;
  int* tmp;

  toReturn.array = allocArray();
  toReturn.currentSize = 0;

  for(count = 0; count < TEMPMAXSIZE; count++ ){
    scanf("%d", &numRead);

    if(numRead == -1){
      return toReturn;
    }
    toReturn.array[count] = numRead;
  }

  toReturn.size = count;

  if(toReturn.size == TEMPMAXSIZE){
      tmp = realloc(toReturn.array, sizeof(int)*TEMPMAXSIZE*2);
      if(tmp == NULL){
        printf("Error on realloc\n EXITING\n");
        exit(0);
      }
      toReturn.array = tmp;
  }
  return toReturn;

}

void printList(List toPrint){
  int i;

  for(i = 0; i<toPrint.size; i++){
    printf("NUM %d = %d\n", i, toPrint.array[i]);
  }

}

int* allocArray(){
  int* array = (int*) malloc(sizeof(int) * TEMPMAXSIZE);

  return array;
}
