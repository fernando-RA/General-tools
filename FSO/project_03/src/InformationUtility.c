#include "../lib/CoreIncludes.h"
#include "../lib/InformationUtility.h"

Information initilize_info_struct(Information strorageInfo, char* fileName){

  strorageInfo.biggest_value = 0;
  strorageInfo.smallest_value = 0;
  strorageInfo.current_position = 0;
  strorageInfo. biggest_vector_occupation = 0;
  pthread_mutex_init(&strorageInfo.lock_mutex, NULL);
  strorageInfo.file = fopen(fileName, "w");

  return strorageInfo;
}

void print_information(Information strorageInfo){
  int count = 0;

  while(count < MAX_BUFFER_SIZE){
    printf("(%d)\n", strorageInfo.buffer[count++]);
  }
}
