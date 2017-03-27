#include "composed_types.h"

Quadrangle read_input_points(){
  Point a, b, c, d;
  Quadrangle new;

  scanf("%lf %lf", &a.x, &a.y);
  scanf("%lf %lf", &b.x, &b.y);
  scanf("%lf %lf", &c.x, &c.y);
  scanf("%lf %lf", &d.x, &d.y);

  new.dis_ab = calculate_point_distance(a, b);

  new.dist_bc = calculate_point_distance(b, c);

  new.dist_cd = calculate_point_distance(c, d);

  new.dist_da = calculate_point_distance(d, a);

  return new;
}
