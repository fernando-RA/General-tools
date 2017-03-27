#include <math.h>
#include "functions.h"
#include "geometricOperations.h"

#define MIN 1e-10

double calculate_area(Quadrangle quad)
{
  return 0.1;
}


double calculate_point_distance(Point p, Point q)
{
  return sqrt( pow((q.x)-(p.x) , 2) + pow((q.y) - (p.y) , 2));
}

double calculate_convexity_condition()
{
  return 0.1;
}

int isEqual(double a, double b){
  return fabs(a-b) < MIN;
}
