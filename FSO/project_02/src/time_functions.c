#include <sys/time.h>

#include "time_functions.h"

#define PARAMETER 1000000

void calcute_time_elapsed(struct timeval *startTime, struct timeval *finishedTime, struct timeval *result) {
  long int diff = (finishedTime->tv_usec + PARAMETER * finishedTime->tv_sec) - (startTime->tv_usec + PARAMETER * startTime->tv_sec);
  result->tv_sec = diff / PARAMETER;
  result->tv_usec = diff % PARAMETER;
}
