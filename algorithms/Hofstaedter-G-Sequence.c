/*
 * The sequence C of hosfstader is defined by:
 * G(0) = 0
 * G(n) = n - G(G(n-1))
 * 
 * It can be written as a simply recurrence relation:
 *
 * G(n) = n - G(floor(n*(phi^-1)))
 * G(n) = floor((n+1)/phi)
*/ 

#include <stdio.h>
#include <math.h>

  /* Golden Ratio */
double phi(){
  return 0.5*(1+sqrt(5));
}

  /* G(n) */
int G(int n){
  if(n == 0) return 0;
  if(n == 1) return 1;

  return floor((n+1)/phi());
}

int main(){
  int n, quant;
  
  scanf("%d", &quant);
  
  while(quant--){
    scanf("%d", &n);
    printf("%d\n", G(n));
  }

  return 0;
}
