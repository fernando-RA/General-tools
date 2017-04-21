#include "coreIncludes.h"

/*
TODO ->
Fazer cabeçalho para arquivo

Documentação:
* Sistema Operacional
* Ambiente de desenvolvimento
* Telas/Instrução de Uso
* Limitações conhecidas
*/



int main(){
    FILE* output = fopen("output.txt", "w");

    controll_process(output);

    return 0;
}
