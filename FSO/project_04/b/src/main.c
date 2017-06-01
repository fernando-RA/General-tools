#include <stdio.h>
#include <string.h>

#include "libseno.h"

int main(int argc, char** argv) {
  int i;
  double angle = 0, m_sine = 0, m_arco_seno = 0;

  if(argc-1 == 0){
    printf("No parameters passed. Exiting...\n");
    return 0;
  }

  else{
    angle = strtod(argv[2], NULL);
    m_sine = seno(angle);
    m_arco_seno = arco_seno(m_sine);

    for (i = 1; i < argc; ++i) {
      if(strcmp(argv[i], "-s") == 0){
        printf("seno (%.2lf) = %.4lf\n", angle, m_sine);
      }

      else if (strcmp(argv[i], "-a") == 0){
        printf("arc_seno (%.2lf) = %.4lf\n", m_sine, m_arco_seno);
      }
    }
  }

  return 0;
}
