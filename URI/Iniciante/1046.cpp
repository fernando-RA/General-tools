#include <iostream>

using namespace std;

int main(){
  int init, end, total;


   cin >> init >> end;

    if(init == 0)
      init = 24;
    if (end == 0)
      end = 24;

    if (init >= 12 && init >= end){
      total = 24 - init + end;
    }
    else if( init < 12 && init <= end){
      total = end - init;
    }
    cout << "O JOGO DUROU " << total << " HORA(S)" << endl;
}
