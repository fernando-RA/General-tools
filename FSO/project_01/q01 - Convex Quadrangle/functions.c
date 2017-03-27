#include <stdio.h>
#include "composedTypes.h"
#include <stdlib.h>

void header(char* headerOutput)
{
  system("clear");
  printf("---------------------------------------\n");
  printf("%s\n", headerOutput);
  printf("---------------------------------------\n");
}

void printMenuInicial()
{
  int opcao;

  header("CALCULO DE CONVEXIDADE DO QUADRILATERO");

  printf("\n01. Calcular dados do quadrilatero\n");
  printf("02. Sair");
  printf("\nDigite a opçao desejada: ");
  scanf("%d", &opcao);

  switch (opcao) {
    case 1:
      printf("TESTE\n");
      calculate_quadrangle();
      break;
    case 2:
      exit(0);
      break;
    default:
      printMenuInicial();
  }
}


void calculate_geometry(Quadrangle quad)
{
  print_points_distance(quad);
  print_convexity(quad);
  print_area(quad);
}

void print_area(Quadrangle quad)
{
  int is_convex = check_convexity(quad);

  if(is_convex == 1) {
    double area = check_area(quad);
    printf("Calulated AREA: %.2lf\n", area);
  }
}

void print_convexity(Quadrangle quad)
{
  int is_convex = check_convexity(quad);

  if(is_convex == 1) {
    printf("Convex Quadrangle\n");
  }
  else if( is_convex == -1) {
    printf("The points does not form a quadrangle\n");
  }
  else {
    printf("It is not convex\n");
  }
}

void print_points_distance(Quadrangle quad)
{

}

void calculate_quadrangle()
{
  Quadrangle toCalculate;
  toCalculate = input_quadrangle();
  calculate_geometry(toCalculate);
}

Quadrangle input_quadrangle()
{
  Quadrangle quad;
  quad.side = 4;

  quad.A = input_point();
  quad.B = input_point();
  quad.C = input_point();
  quad.D = input_point();

  return quad;
}

Point input_point()
{
  Point toRead;
  double x, y;

  if( scanf("%lf %lf",&x ,&y) == 2)
  {
      toRead.x = x;
      toRead.y = y;
  }
  else {
    printf("Error on reading input points. Exiting");
    exit(1);
  }
  return toRead;
}
