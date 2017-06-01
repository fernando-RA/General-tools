#include <stdio.h>
#include "libseno.h"
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
  int i;
  double angle = 0, sine = 0;

  if(argc-1 == 0){
    printf("No parameters passed\n");
    return 0;
  }

  for (i = 1; i < argc; ++i) {
    printf("Parametro #%d: %s\n", i, argv[i]);

    if(strcmp(argv[i], "-s") == 0){
      angle = strtod(argv[i+1], NULL);

      printf("seno (%.3lf) = %lf\n", angle, seno(angle));
    }

    else if (strcmp(argv[i], "-a") == 0){
      sine = strtod(argv[i+1], NULL);

      printf("arc_seno (%.3lf) = %lf\n", sine, arc_seno(sine) );
    }
    else{
      printf("Invalid parameters passing. Exiting");
      exit(1);
    }
  }

  return 0;
}
