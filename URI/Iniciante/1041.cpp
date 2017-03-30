#include <iostream>
#include <iomanip>

using namespace std;

int main(){
  double p1, p2;

  cin >> p1 >> p2;

  if(p1 == 0 && p2 == 0){
    cout << "Origem" << endl;
  }

  if (p1 > 0 && p2 > 0) //primeiro quadrante
    cout << "Q1" << endl;

  if (p1 > 0 && p2 < 0) // quarto quadrante
    cout << "Q4" << endl;
  
  if (p1 < 0 && p2 < 0) // terceiro quadrante
    cout << "Q3" << endl;
  
  if (p1 < 0 && p2 > 0)
    cout << "Q2" << endl;
}
