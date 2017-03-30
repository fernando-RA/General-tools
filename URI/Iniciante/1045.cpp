#include <iostream>
#include <cmath>
#include <algorithm>

#define EPS 1e-9

using namespace std;
bool equals(double a, double b);

int main(){

  double a, b, c;
  int i;

  cin >> a >> b >> c;
  
  if(a < b) swap(a,b);
  if(a < c) swap(a,c);
  if(c > b) swap(b,c);

  if(a >= b+c){
    cout << "NAO FORMA TRIANGULO" << endl;
    return 0;
  }
  
  float d = sqrt((b*b) + (c*c));
  
  if(equals(a,d))
    cout <<"TRIANGULO RETANGULO" << endl;
  if((a*a) > ((b*b) + (c*c)))
    cout << "TRIANGULO OBTUSANGULO" << endl;
  if((a*a) < ((b*b)+(c*c))) 
    cout << "TRIANGULO ACUTANGULO" << endl;
  if(equals(a,b) && equals(b,c))
    cout << "TRIANGULO EQUILATERO" << endl;
  else if (equals(a,b) || equals(b,c) || equals(c,a))
    cout << "TRIANGULO ISOSCELES" << endl;
}

bool equals(double a, double b){
  if (fabs(a-b) < EPS){
    return true;
  }
  return false;
}
