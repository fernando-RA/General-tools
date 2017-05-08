#include "../lib/CoreIncludes.h"
#include "../lib/InformationUtility.h"

Information initilize_info_struct(Information strorageInfo, char* fileName){

  strorageInfo.maximum_value = 0;
  strorageInfo.smallest_value = 0;
  strorageInfo.current_position = 0;
  strorageInfo.biggest_buffer_occupation = 0;
  pthread_mutex_init(&strorageInfo.lock_mutex, NULL);
  strorageInfo.file = fopen(fileName, "w");

  return strorageInfo;
}

void print_information_on_buffer(Information strorageInfo){
  int count = 0;

  while(count < MAX_BUFFER_SIZE){
    printf("(%d)\n", strorageInfo.buffer[count++]);
  }
}

int random_number_generator(){
  int number1 = rand();
  int number2 = rand();
  return (number2-number1);
}
