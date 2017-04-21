#ifndef __CHILDPROCESS_H__
#define __CHILDPROCESS_H__

  void execute_active_process(pid_t pipeActiveProcess[2], struct timeval *startTime);
  void execute_lazy_child(pid_t pipeSleepyChild[2], struct timeval *startTime);
  void controll_process(FILE* outputFile);
  void finish_execution();

#endif
