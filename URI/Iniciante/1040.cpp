#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    double n1, n2, n3, n4, ne;
    double media;

    cin >> n1 >> n2 >> n3 >> n4;

    media = ((n1*2) + (n2*3) + (n3*4) + (n4*1))/10.0;

    cout << fixed << setprecision(1) <<"Media: " << media << endl;

    if (media >= 7){
      std::cout << "Aluno aprovado." << std::endl;
    }
    else if (media < 5){
      std::cout << "Aluno reprovado." << std::endl;
    }
    else{
      std::cout << "Aluno em exame." << std::endl;
      cin >> ne;

      std::cout << "Nota do exame: " << fixed << setprecision(1) << ne << std::endl;

      media = (media+ne)/2.0;

      if (media >= 5){
        std::cout << "Aluno aprovado." << std::endl;
      }
      else if (media < 5){
        std::cout << "Aluno reprovado." << std::endl;
      }
      cout << "Media final: " << fixed << setprecision(1) << media << endl;
    }
    return 0;
}
