#include <stdio.h>
#include <stdlib.h>
#include "estruturas.h"
#include "headers.h"

int importDataFromFile(char* fileName){
  FILE* toOpen;
  char* stringOutput = (char*) malloc(sizeof(char)*40);
  char* stateUF, *cityName;
  int surgeonAmount, totalQuantity;
  int value[8];

  toOpen = fopen(fileName, "r");
  stateUF = cityName = (char*) malloc(sizeof(char)*40);

  if(toOpen == NULL){
    printf("Error while trying to open file %s. It may not exist\n", fileName);
    exit(1);
  }
  else{
    fscanf(toOpen,"%s;%s;%d;", stateUF, cityName, &surgeonAmount);
    //%d;%d;%d;%d;%d;%d;%d
    //&value[0], &value[1], &value[2], &value[3], &value[4], &value[5], &value[6], &totalQuantity
    printf("UF:%s - CITY:%s - CD:%d", stateUF, cityName, surgeonAmount);
    // while(divededStringToken != NULL){
    //   printf("%s \n %s", stringOutput);
  }
  printf("exit");

return 0;
}
