#include "../lib/CoreIncludes.h"
#include "../lib/InformationUtility.h"

int main(int argc, char const *argv[]) {

  char* fileName;
  Information strorageInfo;

  pthread_t control_thread;

  if(argc <= 1){
    printf("\tOutput file not Specified on call\n\tExiting 1...\n");
    return 1;
  }

  fileName = (char*) argv[1];

  strorageInfo = initilize_info_struct(strorageInfo, fileName);
  printf("filename = %s\n", fileName);

  return 0;
}
