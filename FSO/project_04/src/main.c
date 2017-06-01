#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "libseno.h"

int main(int argc, char** argv) {
  int i;
  double angle = 0, sine = 0;

  if(argc-1 == 0){
    printf("No parameters passed\n");
    return 0;
  }

  for (i = 1; i < argc; ++i) {
    if(strcmp(argv[i], "-s") == 0){
      angle = strtod(argv[i+1], NULL);

      printf("seno (%.2lf) = %.4lf\n", angle, seno(angle));
    }

    else if (strcmp(argv[i], "-a") == 0){
      sine = strtod(argv[i+1], NULL);
      printf("arc_seno (%.3lf) = %lf\n", sine, arc_seno(sine) );
    }

  }
  return 0;
}
