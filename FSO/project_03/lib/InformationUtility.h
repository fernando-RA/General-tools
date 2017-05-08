#ifndef __INFO_UTILITY_H__
#define __INFO_UTILITY_H__

  #define MAX_BUFFER_SIZE 50

  typedef struct information_stuct{
    int buffer[MAX_BUFFER_SIZE];
    int maximum_value;
    int smallest_value;
    int biggest_buffer_occupation;
    int current_position;
    pthread_t thread_id[3];
    pthread_mutex_t lock_mutex;
    FILE* file;
  }Information;

Information initilize_info_struct(Information strorageInfo, char* fileName);
void print_information();

#endif
