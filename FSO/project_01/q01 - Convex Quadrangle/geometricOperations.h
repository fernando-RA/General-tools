#ifndef GEOMETRICOPERATIONS
#define GEOMETRICOPERATIONS
#include "composedTypes.h"

double calculate_area(Quadrangle quad);
double calculate_point_distance(Point p, Point q);
int calculate_convexity_condition(Quadrangle quad);
int calculate_determinant(Point A, Point B, Point C);
int isEqual(double a, double b);


#endif
