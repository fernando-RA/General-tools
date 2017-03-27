//http://stackoverflow.com/a/15435045
//http://stackoverflow.com/a/565282/202451
//http://stackoverflow.com/questions/471962/how-do-determine-if-a-polygon-is-complex-convex-nonconvex
//https://github.com/morris821028/UVa/blob/master/volume004/460%20-%20Overlapping%20Rectangles.c

#include <stdio.h>
#include <math.h>

#include "composed_types.h"

double calculate_point_distance(Point p, Point q)
{
  return sqrt(pow((q.x)-(p.x), 2) + pow((q.y) - (p.y) , 2));
}

Quadrangle read_input_points(){
  Point a, b, c, d;
  Quadrangle new;

  printf("a(x,y)\n");
  scanf("%lf %lf", &a.x, &a.y);
  printf("b(x,y)\n");
  scanf("%lf %lf", &b.x, &b.y);
  printf("c(x,y)\n");
  scanf("%lf %lf", &c.x, &c.y);
  printf("d(x,y)\n");
  scanf("%lf %lf", &d.x, &d.y);

  new.dist_ab = calculate_point_distance(a, b);

  new.dist_bc = calculate_point_distance(b, c);

  printf("TSTE: %lf\n", new.dist_bc);

  new.dist_cd = calculate_point_distance(c, d);

  new.dist_da = calculate_point_distance(d, a);

  return new;
}

int main(){
  //Quadrangle* new = (Quadrangle*) malloc(siezof(Quadrangle));
  Quadrangle new;
  new = read_input_points();

  printf("DIST_ab: %.2lf\n", new.dist_ab);
  printf("DIST_bc: %.2lf\n", new.dist_bc);
  printf("DIST_cd: %.2lf\n", new.dist_cd);
  printf("DIST_da: %.2lf\n", new.dist_da);

  return 0;
}
