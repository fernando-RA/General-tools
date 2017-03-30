#include <iostream>
#include <iomanip>

using namespace std;

#define pi 3.14159

int main(){
  double raio;
  double volume;

  cin >> raio;
  volume = (4/3.0)*pi*(raio*raio*raio);

  cout << fixed << setprecision(3) << "VOLUME = " << volume << endl;
  return 0; 
}
