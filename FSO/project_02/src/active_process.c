#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

#include "children.h"
#include "writers.h"
#include "time_functions.h"

void execute_active_process(pid_t pipeActiveProcess[2], struct timeval *startTime) {
  close (pipeActiveProcess[0]); // close read

  FILE* pipe;
  pipe = fdopen (pipeActiveProcess[1], "w");

  int count = 1;

  while(1) {
    char message_user[100];
    scanf("%s", message_user);

    struct timeval finishedTime, elapsedTime;
    gettimeofday(&finishedTime, NULL);

    calcute_time_elapsed(startTime, &finishedTime, &elapsedTime);

    output_pipe_active_process(message_user, &elapsedTime, pipe, count);
    count++;
  }

  close (pipeActiveProcess[1]);
}
