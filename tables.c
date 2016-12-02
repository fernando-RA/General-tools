#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void header(char* headerOutput);
void printMenu();
void tabulate(int tabValue);
void clearScreen();
void drawLine(int lineSize);

int main(){
  printMenu();
  return 0;
}



void algortitmo{
/*
 *Primeira tabela: para saber se estara titulo varia de zero ate um, descarta a tabela de valor super aquecido. SE of titylo for 1 ele vai para a segunda primeira tabela. Titulo  é a porcentagem de gas da amostra. Varia de zero ate um.
 * 
 * x = titulo 0 < x < 1
 * T = temperatura 
 * P pressao;
 *
 * * */



}
void clearScreen(){
  //Linux: Descomente a linha de baixo
  system("clear");
  //Windows:
  //system("cls");
}

void drawLine(int lineSize){
  int i;
  for(i=0; i<lineSize; i++){
    printf("-");
  }
  printf("\n");
}

void tabulate(int tabValue){
  int i;
  for (i=0; i<tabValue; i++){
    printf(" ");
  }
}

void printMenu(){
  header("MENU INICIAL");
}

void header(char* headerOutput){
  int i;
  clearScreen();
  drawLine(70);
  tabulate((70/2)-strlen(headerOutput));
  printf("%s\n", headerOutput);
  drawLine(70);
}

