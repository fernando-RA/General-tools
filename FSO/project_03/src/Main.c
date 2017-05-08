#include "../lib/CoreIncludes.h"
#include "../lib/InformationUtility.h"

int main(int argc, char const *argv[]) {
  //Declarations
  char* fileName;
  Information strorageInfo;
  pthread_t control_thread;

  //Test if file name was given on execution
  if(argc <= 1){
    printf("\tOutput file not Specified on call\n\tExiting 1...\n");
    return 1;
  }

  //Main Logic
  fileName = (char*) argv[1];

  strorageInfo = initilize_info_struct(strorageInfo, fileName);
  printf("filename = %d\n", random_number_generator());
  
  log_info_console();
  return 0;
}
