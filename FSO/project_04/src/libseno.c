#include "libseno.h"

#define PI 3.1415926535897932384650288
#define TERMS 10

int fatorial (int n) {
  if (n >= 1)
    return n * fatorial(n-1) ;
  else
    return 1;
}

double my_pow(double base, int exponent){
  double temp = 1;
  int index;

  for(index = 0; index < exponent; index++){
    temp *= base;
  }

  return temp;
}

double seno(double angulo){
  double seno=0, tempSin=0;
  int index;

  for(index=0; index<TERMS; index++){
    tempSin = (my_pow((-1),index) * (my_pow(angulo,(2*index+1))) / fatorial(2*index+1));
    seno = seno + tempSin;
  }

  return seno;
}
