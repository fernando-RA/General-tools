#include "headers.h"
#include <stdio.h>
#include <stdlib.h>

void printNavbar(char* navbarTitle){
  //TODO -> format string to appear good looking and menu centrilize
}

void printCompleteMenu(){
  int choosenOption;

  printf("01 - Importar dados\n");
  printf("02 - Abrir menu para gerar Relatorios\n");
  printf("03 - Relatorio de um estado\n");
  printf("04 - Consultar via Municipio\n");

  printf("Digite a opçao desejada:\n");
  scanf("%d", &choosenOption);

  switch (choosenOption) {
    case 1: //TODO menuImportData
    break;
    case 2:
    printReportOrdenedMenu();
    //TODO menuReport
    break;
    case 3: //TODO menuReportState
    break;
    case 4: //TODO menuSearchByCounty
    break;
    default:
    exit(0);
  }
}

int printReportOrdenedMenu(){
  char choosenOptionInput;

  printf("E possivel ordanar os dados por:\n\n");
  printf("a - Municipio\n");
  printf("b - CD (Quantide de cirurgiões dentistas)\n");
  printf("c - Total\n");

  do{
    scanf(" %c", &choosenOptionInput);
    choosenOptionInput = toupper(choosenOptionInput);
  }
  while((int)choosenOptionInput < 65 || choosenOptionInput > 67); //numbers represent ASCII codes for a and c

  switch (choosenOptionInput) {
    case 'A':
      //TODO ordenar-MUNICIPIO
      break;
    case 'B':
      //TODO ordenar-CD
      break;
    case 'C':
      //TODO ordenar-TOTAL
      break;
  }
}
