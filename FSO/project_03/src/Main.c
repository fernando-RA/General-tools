#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char const *argv[]) {
  char* filename = (char*) argv[1];
  pthread_t control_thread;

  if(argc > 1){
    printf("filename = %s\n", filename);
  }

  return 0;
}
