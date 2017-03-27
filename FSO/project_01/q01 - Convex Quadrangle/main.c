/*
  http://stackoverflow.com/a/15435045
  http://stackoverflow.com/a/565282/202451
  http://stackoverflow.com/questions/471962/how-do-determine-if-a-polygon-is-complex-convex-nonconvex
  https://github.com/morris821028/UVa/blob/master/volume004/460%20-%20Overlapping%20Rectangles.c

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "composedTypes.h"


int print_header(char* message){
  int option;

  system("clear");
  printf("CONVEXITY CALCULATOR\n");
  printf("------------------------------------------------\n");
  printf("\n %s \n", message);
  printf("0 - SAIR\n");
  printf("1 - CALCULAR CONVEXIDADE DO QUADRILATERO\n");

  scanf("%d", &option);

  return option;
}

void menu(){
  
  while(1){
    switch (print_header("Choose a option")) {
        case 0:
          exit(0);
        case 1:
          printf("TESTE\n");
          break;
          /*calculate_quadrangle();*/
        default:
          print_header("Errou");
    }
  }
}

int main(){
  menu();
  return 0;
}
