#ifndef __CONTROL_THREAD_H__
#define __CONTROL_THREAD_H__

void log_info_console();
void log_info_file();

void terminate_program(int signal);

void* graceful_thread_termination (void* threads_args);

#endif
