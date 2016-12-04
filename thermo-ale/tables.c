#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { false, true } bool;

FILE* importarArquivo(char* fileName);

//Visao
void printMenuInicial();
void desenharLinha(int lineSize);
void limparTela();
void tabular(int tabValue);
FILE* definirTabela(bool hasX);
void header(char* headerOutput);

int main(){
  int opcao;
   printMenuInicial();
   while(opcao);
  return 0;
}


void algortitmo(){
/*
 *Primeira tabela: para saber se estara titulo varia de zero ate um, descarta a tabela de valor super aquecido. SE of titylo for 1 ele vai para a segunda primeira tabela. Titulo  é a porcentagem de gas da amostra. Varia de zero ate um.
 *
 * x = titulo 0 < x < 1
 * T = temperatura
 * P pressao;
 *
 * * */
}

FILE* importarArquivo(char* fileName){
  FILE* toReturn;
  toReturn = fopen(fileName, "r");

  if (toReturn == NULL) {
    printf("Erro ao abrir o arquivo '%s'! Confira a existência deste!\n", fileName);
    return NULL;
  }
  else{
    printf("O arquivo '%s' foi importado com sucesso\n", fileName);
    return toReturn;
  }
}

void printMenuInicial(){
  int opcao;

  header("Propriedades do estado Termodinamico - Refrigerante");

  printf("\n01. Importar dados.\n");
  printf("02. Consultar tabelas.\n");
  printf("03. Sair.\n");
  printf("\nDigite a opçao desejada: ");
  scanf("%d", &opcao);

  switch (opcao) {
    case 1:
      //checarTabelas();
      break;
    case 2:
      //realizarConsulta();
      break;
    case 3:
      exit(0);
      break;
    default:
      printMenuInicial();
  }
}

void limparTela(){
  //Linux: Descomente a linha de baixo
  system("clear");
  //Windows:
  //system("cls");
}

void desenharLinha(int lineSize){
  int i;
  for(i=0; i<lineSize; i++){
    printf("-");
  }
  printf("\n");
}

void tabular(int tabValue){
  int i;
  for (i=0; i<tabValue; i++){
    printf(" ");
  }
}

void header(char* headerOutput){
  int i;
  limparTela();
  desenharLinha(70);
  tabular((70/2)-strlen(headerOutput));
  printf("%s\n", headerOutput);
  desenharLinha(70);
}
