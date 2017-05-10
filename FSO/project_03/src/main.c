#include "core_includes.h"

int main(int argc, char const *argv[]) {
  char *fileName;
  Information info_storage;

  if(argc <= 1){
    printf("\tOutput file not Specified on call\n\tExiting 1...\n");
    return 1;
  }

  fileName = (char*) argv[1];
  info_storage = initialize_information (fileName);

  controll_threads(info_storage);

  return 0;
}
