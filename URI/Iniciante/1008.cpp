#include <iostream>
#include <iomanip>

using namespace std;


int main(){
  int n1, n2;
  double valor;
  double salario;
  
  cin >> n1 >> n2 >> valor;

  salario = valor * n2;

  cout << "NUMBER = " << n1 << endl;
  cout << fixed << setprecision(2) << "SALARY = " << salario << endl;

  return 0;
}
