#ifndef CARTESIANFUNCTIONS
#define CARTESIANFUNCTIONS
#include "composedTypes.h"
#include <stdio.h>

void printMenuInicial();
void header(char* headerOutput);

void calculate_geometry(Quadrangle quad);

void print_area(Quadrangle quad);
void print_convexity(Quadrangle quad);
void print_points_distance(Quadrangle quad);

void calculate_quadrangle();
double check_area();

int check_convexity(Quadrangle quad);

Quadrangle input_quadrangle();
Point input_point();

#endif
