#include "core_includes.h"

Information initialize_information (char* file_name) {
  Information info_storage;

  info_storage.maximum_value = 0;
  info_storage.smallest_value = 0;
  info_storage.current_position = 0;
  info_storage.biggest_buffer_occupation = 0;
  pthread_mutex_init (&info_storage.lock_mutex, NULL);
  info_storage.file = fopen (file_name, "w");;

  return info_storage;
}

int get_random(){
  long random_number = random();
  return random_number - (RAND_MAX/2);
}
