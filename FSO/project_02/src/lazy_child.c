#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

#include "children.h"
#include "writers.h"
#include "time_functions.h"

void execute_lazy_child(pid_t pipeSleepyChild[2], struct timeval *startTime) {
  close (pipeSleepyChild[0]); // close read

  FILE* pipe;
  pipe = fdopen (pipeSleepyChild[1], "w");

  int i = 1;
  while(1) {
    int random = rand() % 3;
    sleep (random);

    struct timeval finishedTime, elapsedTime;
    gettimeofday(&finishedTime, NULL);

    calcute_time_elapsed(startTime, &finishedTime, &elapsedTime);

    writer_pipe_lazy_child(&elapsedTime, pipe, i++);
  }

  close (pipeSleepyChild[1]);
}
