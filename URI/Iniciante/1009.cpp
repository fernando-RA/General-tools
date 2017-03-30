#include <iostream>
#include <iomanip>

using namespace std;

int main(){
  string nome;
  double v1, v2;
  double salario;

  cin >> nome >> v1 >> v2;
  
  salario = v1 + (0.15*v2); 
  
  cout << "TOTAL = R$ " << fixed << setprecision(2) << salario << endl;

  return 0;
}
