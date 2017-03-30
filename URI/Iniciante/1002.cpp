#include <iostream>
#include <iomanip>
#define pi 3.14159
using namespace std;

int main(){
  double a, r;
  
  cin >> r;
   
  a = pi*((r*r));
  cout << fixed << setprecision(4) <<"A=" << a << endl;
  return 0;
}
