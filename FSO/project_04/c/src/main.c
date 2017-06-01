#include <stdio.h>
#include <string.h>
#include <dlfcn.h>

#include "libseno.h"

void dynamic_load(double, char*);

int main(int argc, char** argv) {
  int i;
  double angle = 0, m_sine = 0, m_arco_seno = 0;

  if(argc-1 == 0){
    printf("No parameters passed. Exiting...\n");
    return 0;
  }

  else{
    angle = strtod(argv[2], NULL);

    for (i = 1; i < argc; ++i) {
      if(strcmp(argv[i], "-s") == 0){
        dynamic_load(angle, "seno");
        printf("seno (%.2lf) = %.4lf\n", angle, m_sine);
      }

      dynamic_load(angle, "arco_seno");
      else if (strcmp(argv[i], "-a") == 0){
        printf("arc_seno (%.2lf) = %.4lf\n", m_sine, m_arco_seno);
      }
    }
  }
  return 0;
}

void dynamic_load(double rads, char * function_name){
  void * handle = dlopen("libseno.so", RTLD_LAZY);
  if(!handle) {
    printf("%s\n", dlerror());
    exit(1);
  }

  dlerror();
  double (*function)(double);
  *(void **) (&function) = dlsym(handle, function_name);
  char *error = dlerror();

  if(error != NULL){
    printf("%s\n", error);
    exit(1);
  }
  dlclose(handle);
}
