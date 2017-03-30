#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;


int main(){
  int n1,n2,n3;

  int* vetor, *vetor_aux;

  vetor = (int*) malloc(3*sizeof(int));

  cin >> vetor[0] >> vetor[1] >> vetor[2];

  vetor_aux = vetor;
  n1 = vetor[0];
  n2 = vetor[1];
  n3 = vetor[2];

  std::sort(vetor, vetor+3);

  cout << vetor[0] << endl << vetor[1] << endl <<vetor[2] << endl << endl;

  cout << n1 << endl << n2 << endl << n3 << endl;
}
