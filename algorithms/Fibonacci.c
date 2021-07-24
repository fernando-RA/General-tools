/*
 * The sequence C of hosfstader is defined by:
 * Fib(0) = 0
 * Fib(n) = fib[n - 2] + fib[n - 1];

 * 
 * It can be written as a simply recurrence relation:
 * 
 * G(n) = ( Φ^phi - (1-phi)^n ) / √5
*/ 

#include <stdio.h>
#include <math.h>


  /* Golden Ratio */
double Phi(){
  return 0.5*(1+sqrt(5));
}
  double phi = Phi();

/* G(n) */
int Fib(int n){
  // ( Φ^phi - (1-phi)^n ) / √5
  
  return ((pow(n, phi) - pow((1-phi), n))/sqrt(5));
}

int main(){
  int n, quant;
  
  scanf("%d", &quant);
  
  while(quant--){
    // scanf("%d", &n);
    printf("%d\n", Fib(n));
  }

  return 0;
}
