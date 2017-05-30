#include <stdio.h>

#define PI 3.1415926535897932384650288
#define TERMS 10

int fatorial (int n) {
  if ((n==1) || (n==0)) return 1;
  else
  return fatorial(n-1) * n;
}

double my_pow(double base, int exponent){
  double temp;

  if( exponent == 0){
    return 1;
  }

  temp = my_pow(base, exponent/2);

  if (exponent % 2 == 0)
    return temp*temp;

  else {
    if(exponent > 0){
      return base*temp*temp;
    }
    else{
      return (temp*temp)/base;
    }
  }
}

double seno(double angulo){
  double seno=0, tempSin=0;
  int index;

  for(index=0; index<TERMS; index++){
    tempSin = (my_pow((-1),index)*(my_pow(angulo,(2*index+1)))/fatorial(2*index+1));
    seno = seno + tempSin;
  }
  return seno;
}
