#include <iostream>
#include <iomanip>

using namespace std;

int main(){
  int i = 0;
  int cod, quant;
  double valor, total = 0;
  
  while (i < 2){
    cin >> cod >> quant >> valor;
    total += quant*valor;
    i++;
  }
  cout << "VALOR A PAGAR: R$ " << fixed << setprecision(2) << total << endl;
  return 0;
}
