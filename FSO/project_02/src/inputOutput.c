#include "coreIncludes.h"

void output_pipe_active_process(const char* message, struct timeval *elapsedTime, FILE* pipe, int i) {
  fprintf(pipe, "0:%02ld.%03ld: Mensagem do %02d do usuario: <%s>\n", elapsedTime->tv_sec, elapsedTime->tv_usec, i, message);
  fflush(pipe);
}

void writer_pipe_lazy_child(struct timeval *elapsedTime, FILE* pipe, int i) {
  fprintf(pipe, "0:%02ld.%03ld: Mensagem do %02d do filho dorminhoco\n", elapsedTime->tv_sec, elapsedTime->tv_usec, i);
  fflush(pipe);
}

void get_message_pipe_and_write_file(FILE* pipe, FILE *outputFilePtr, struct timeval *startTime) {
  char buffer[1024];

  struct timeval finishedTime, elapsedTime;
  gettimeofday(&finishedTime, NULL);

  calcute_time_elapsed(startTime, &finishedTime, &elapsedTime);

 	if(!feof(pipe) && !ferror(pipe) && fgets(buffer, sizeof(buffer), pipe) != NULL){
    fprintf(outputFilePtr, "0:%02ld.%03ld: %s\n",elapsedTime.tv_sec, elapsedTime.tv_usec, buffer);
    fflush(outputFilePtr);
  }

}
