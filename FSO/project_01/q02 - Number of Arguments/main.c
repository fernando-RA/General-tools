#include <stdio.h>

int main(int argc, char** argv) {
  int i;

  printf("# de parametros: %d\n", argc-1);
  printf("Nome do executavel: %s\n", argv[0]);

  for (i = 1; i < argc; ++i) {
    printf("Parametro #%d: %s\n", i, argv[i]);
  }
  return 0;
}
