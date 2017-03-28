#include <math.h>
#include "functions.h"
#include "geometricOperations.h"

#define MIN 1e-10

double calculate_area(Quadrangle quad)
{
  int i = 0;
  double area = 0;

  if(calculate_convexity_condition(quad) == 1){
    Point points[5] = {quad.A, quad.B, quad.C, quad.D, quad.A};
      for(i = 0; i < quad.side; i++){
        area += points[i].x * points[i+1].y;
        area -= points[i+1].x * points[i].y;
      }
    area = fabs(area) * 0.5;
  }
  else{
    area = 0;
  }
  return area;
}


double calculate_point_distance(Point p, Point q)
{
  return hypot(p.x-q.x, p.y-q.y);
}

int calculate_convexity_condition(Quadrangle quad)
{
  int abc, bcd, cda, dab, is_convex;

  abc = calculate_determinant(quad.A, quad.B, quad.C);
  bcd = calculate_determinant(quad.B, quad.C, quad.D);
  cda = calculate_determinant(quad.C, quad.D, quad.A);
  dab = calculate_determinant(quad.D, quad.A, quad.B);
  is_convex = 0;

  if((abc*bcd*cda*dab)){
    is_convex = (abc > 0) && (bcd > 0) && (cda > 0) && (dab > 0);
  } else {
    is_convex = -1;
  }

  return is_convex;
}

int calculate_determinant(Point A, Point B, Point C)
{
  double det;
  int answer = 0;

  det = (A.x * B.y + A.y * C.x + B.x * C.y) - (C.x * B.y + C.y * A.x + B.x * A.y);

  if(det < 0){
    answer = 1;
  }
  else if(det > 0){
    answer = -1;
  }

  return answer;
}
