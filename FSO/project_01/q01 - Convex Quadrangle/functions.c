#include "functions.h"
#include "geometricOperations.h"

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
  int is_convex = calculate_convexity_condition(quad);

  if(is_convex == 1) {
    double area = calculate_area(quad);
    printf("\nAREA Calculada: %.2lf\n", area);
  }
}

void print_convexity(Quadrangle quad)
{
  int is_convex = calculate_convexity_condition(quad);

  if(is_convex == 1) {
    printf("\nEste quadrilatero e convexo\n");
  }
  else if( is_convex == -1) {
    printf("Estes pontos nao formam um quadrilatero\n");
  }
  else {
    printf("Nao e convexo\n");
  }
}

void print_points_distance(Quadrangle quad)
{
  int i;

  char id_points[5] = { 'A','B','C','D','A' };
  Point points[5] = { quad.A, quad.B, quad.C, quad.D, quad.A };

  printf("\nDistance between points:\n");

  for(i = 0; i < quad.side; i++){
    printf("(%c,%c): %.2lf\n", id_points[i], id_points[i+1],
                                calculate_point_distance(points[i], points[i+1]));
  }
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
  printf("Digite um par ordenado (x, y):\n");

  if( scanf("%lf %lf",&x ,&y) == 2)
  {
      toRead.x = x;
      toRead.y = y;
  }
  else {
    printf("\n-----\nError on reading input points. Exiting\n\n");
    exit(1);
  }
  return toRead;
}
