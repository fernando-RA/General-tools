#include <iostream>
#include <iomanip>

using namespace std;

int main(){
  int tempo, media, dist;

  cin >> tempo >> media;

  dist = tempo * media;

  cout << fixed << setprecision(3) <<(dist/12.0) << endl;
  
  return 0;
}
