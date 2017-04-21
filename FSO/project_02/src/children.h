#ifndef CHILDREN_H
#define CHILDREN_H

  void execute_active_process(pid_t pipeActiveProcess[2], struct timeval *startTime);
  void execute_lazy_child(pid_t pipeSleepyChild[2], struct timeval *startTime);
  
#endif