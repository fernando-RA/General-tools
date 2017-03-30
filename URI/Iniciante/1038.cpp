#include <iostream>
#include <iomanip>


using namespace std;

int main(){
  int cod , quant;
  float preco[6] = {0, 4.00, 4.50, 5.00, 2.00, 1.50};

  cin >> cod >> quant;

  cout << "Total: R$ " << fixed << setprecision(2) << quant* preco[cod] << endl;

  return 0;
}
