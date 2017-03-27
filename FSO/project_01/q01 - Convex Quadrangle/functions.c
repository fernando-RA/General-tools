#include "composed_types.h"


void menu(){
  int option;

  printf("CONVEXITY CALCULATOR\n");
  printf("------------------------------------------------\n");

  while(1){
    system("clear");
    printf("0 - SAIR\n");
    printf("1 - CALCULAR CONVEXIDADE DO QUADRILATERO\n");

    switch (scanf("%d", &option)) {
      case 0:
        exit(0);
      case 1:
        calculate_quadrangle();
    }
  }
}

void calculate_quadrangle(){
  Quadrangle toCalculate;
  toCalculate = input_quadrangle();
  output_geometry(toCalculate);
}

Quadrangle input_quadrangle(){
  Quadrangle quad;
  quad.side = 4;

  quad.A = input_point();
  quad.B = input_point();
  quad.C = input_point();
  quad.D = input_point();

  return quad;
}

double input_point()
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
