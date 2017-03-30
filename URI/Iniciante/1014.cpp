#include <iostream>
#include <iomanip>

using namespace std;

int main(){
  int x;
  double y;
  double media;

  cin >> x >> y;
  
  media = x/y;
  
  cout << fixed << setprecision(3) << media << " km/l\n"; 
  return 0;
}
