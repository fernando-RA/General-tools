#ifndef COMPOSEDTYPES
#define COMPOSEDTYPES

typedef struct point{
  double x;
  double y;
} Point;

typedef struct quadrangle{
  Point A;
  Point B;
  Point C;
  Point D;
  int side;
} Quadrangle;

#endif
