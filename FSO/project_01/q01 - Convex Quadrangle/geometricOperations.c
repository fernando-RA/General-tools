#include <math.h>
#include "functions.h"
#include "geometricOperations.h"

#define MIN 1e-10

double calculate_area(Quadrangle quad)
{
  int single = 0;
  double area = 0;
  Point points[5];

  if(calculate_convexity_condition(quad) == 1){
      points = {quad.A, quad.B, quad.C, quad.D, quad.A};
      for(single = 0; single < quad.side; single++){
        area += points[single].x * points[single+1].y;
        area -= points[single+1].x * points[single].y;
      }
      area = fabs(area) / 2;
  }
  else{
    area = 0;
  }
  return 0;
}


double calculate_point_distance(Point p, Point q)
{
  return sqrt( pow((q.x)-(p.x) , 2) + pow((q.y) - (p.y) , 2));
}

int calculate_convexity_condition(Quadrangle quad)
{
  int abc, bcd, cda, dab, is_convex;

  abc = calculate_determinant(quad.A, quad.B, quad.C);
  abc = calculate_determinant(quad.B, quad.C, quad.D);
  abc = calculate_determinant(quad.C, quad.D, quad.A);
  abc = calculate_determinant(quad.D, quad.A, quad.B);
  is_convex = 0;

  if((abc*bcd*cda*dab)){
    is_convex = (abc > 0) && (bcd > 0) && (cda > 0) && (dab > 0)
  } else {
    is_convex = -1;
  }

  return is_convex;
}

int calculate_determinant(Point A, Point B, Point C)
{
  double det;
  int answer = 0;

  value = (A.x * B.y + A.y * C.x + B.x * C.y) - (C.x * B.y + C.y * A.x + B.x * A.y);

  if(value < 0){
    answer = 1;
  }
  else if( value > 0){
    answer = -1;
  }

  return answer;
}
