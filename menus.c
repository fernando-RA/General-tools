#include <stdio.h>
#include "headers.h"

/** Function to clear screen */
void clearScreen(){
  //LINUX ->
  system("clear");
  //WINDOWS -
  //system("cls");*/
}

/*Imprimir Cabecalho*/
void printNavbar(char* navbarTitle){
  printf("%s\n", navbarTitle);
  printf("------------------------------------------------\n\n");
}

/**
00 - Imprimir o menu inicial
**/
void printInitialMenu(GenTree* rootCityTree, GenTree* rootCDTree, GenTree* rootTotalTree){
  int choosenOption;

  clearScreen();
  printNavbar("SISTEMA DE CONSULTA AO CADASTRO - CFO");

  printf("01 - Importar dados\n");
  printf("02 - Abrir menu para gerar Relatorios\n");
  printf("03 - Relatorio de um determinado Estado\n");
  printf("04 - Consultar via Municipio\n");

  printf("Digite a opçao desejada:\n");
  scanf("%d", &choosenOption);

  switch (choosenOption) {
    case 1:
      //TODO menuImportData
      printImportDataMenu(rootCityTree, rootCDTree, rootTotalTree);
      break;
    case 2:
      //TODO menuReport
      printReportOrdenedMenu();
      break;
    case 3:
      //TODO menuReportState
      break;
    case 4:
      //TODO menuSearchByCounty
      break;
    default:
      exit(0);
  }
}

/**
01 - Imprimir menu para confirmar importacao dos dados
**/
void printImportDataMenu(GenTree* rootCityTree, GenTree* rootCDTree, GenTree* rootTotalTree){
  char inputConfirm;

  clearScreen();
  printNavbar("IMPORTAR DADOS PARA O SISTEMA");

  printf("Digite (Y) para confirmar ou (N) para voltar ao menu principal\n");

  do{
    printf("Opcao: ");
    scanf(" %c", &inputConfirm);
    inputConfirm = toupper(inputConfirm);
  }
  while((int)inputConfirm != 89 && inputConfirm != 78);

  if(inputConfirm == 'Y'){
    //TODO -> logica para importacao dos dados
  }
  // else
  //   printInitialMenu();
}

/**
02 - Imprimir o menu de relatórios
**/
void printReportOrdenedMenu(){
  char choosenOptionInput;

  clearScreen();
  printNavbar("IMPORTAR DADOS PARA O SISTEMA");

  printf("E possivel ordenar os dados por:\n\n");
  printf("A - Municipio\n");
  printf("B - CD (Quantide de cirurgiões dentistas)\n");
  printf("C - Total\n");

  do{
    printf("Escolha uma opcao:");
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
