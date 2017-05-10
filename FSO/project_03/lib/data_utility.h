#ifndef VECTOR_INFORMATION_H
#define VECTOR_INFORMATION_H

#define MAX_BUFFER_SIZE 50

typedef struct info_storage {
  int buffer[MAX_BUFFER_SIZE];
  int maximum_value;
  int smallest_value;
  int biggest_buffer_occupation;
  int current_position;
  pthread_t ids_thread[3];
  pthread_mutex_t lock_mutex;
  FILE* file;
} Information;

Information initialize_information ();
void print_information(Information storage);
int get_random ();

#endif
