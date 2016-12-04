#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PRESSAO 1
#define TEMPERATURA 2


typedef enum { false, true } bool;

FILE* importarArquivo(char* fileName);
int definirConsulta();
void choose_P_or_T();
void choose_P_and_T();

//Visao
void printMenuInicial();
void desenharLinha(int lineSize);
void limparTela();
void tabular(int tabValue);
FILE* definirTabela(bool hasX);
void header(char* headerOutput);

int main(){
  int opcao;
  char resposta;
   char c;
   definirConsulta();

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

int definirConsulta(){
  char respostaTitulo;

  header("Realizar Consulta");
  printf("Possui titulo? (S/N)\n");
  do{
    printf("\n--> OPCAO: ");
    scanf("%c", &respostaTitulo);
    getchar();
  }
  while(respostaTitulo != 'S' && respostaTitulo != 'N');

  if (respostaTitulo == 'S'){
    choose_P_or_T();
  }
  else{
    choose_P_and_T();
  }
} /*.#END definirConsulta().*/

void choose_P_or_T(){
  int opcaoT;
  char* fileName;
  float pressaoIN;

  header("Consultar Tabela de Saturacao");

  printf("Qual A tabela que deseja pesquisar?\n");
  do{
    printf("01 - Pressao. \n02 - Temperatura.\n\n--> OPCAO: ");
    scanf("%d", &opcaoT);
  }
  while(opcaoT != PRESSAO && opcaoT != TEMPERATURA);

  if (opcaoT == PRESSAO){
    fileName = "pressure_table.txt";

    header("Consultar via Pressao");

    printf("Digite a 'pressão' a ser consultada: \n\n");
    printf("--> P = ");
    scanf("%f", &pressaoIN);
    // if(/*foundInTable(tempIN, fileName)*/){
    //   //return 0;
    // }
    // else{
    //   //interpolate(tempIN);
    // }
  }

  if(opcaoT == TEMPERATURA){
    fileName = "temp_table.txt";

    header("Consultar via Temperatura");

    printf("Digite a 'temperatura' a ser pesquisada:\n\n" );
    printf("--> T = ");
    //scanf("%d", &tempIN);
    //if(foundInTable(tempIN, "temp_table.txt"))
  }
} /*.#END choose_P_or_T().*/

void choose_P_and_T(){
  float tempIN;
  float pressaoIN;

  header("Pesquisa sem Titulo:");
  printf("Digite a 'pressão' a ser consultada: \n\n");
  printf("--> P = ");
  scanf("%f", &pressaoIN);

  printf("Digite a 'temperatura' a ser consultada:\n\n" );
  printf("--> T = ");
  scanf("%d", &tempIN);
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

  printf("\n01. Consultar dados especificos\n");
  printf("02. Imprimir tabela completa.\n");
  printf("Sair");
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
