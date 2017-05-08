#ifndef __CONTROL_THREAD_H__
#define __CONTROL_THREAD_H__

void log_info_console(Information info_storage);
void log_info_file(Information info_storage);

void terminate_program(int signal);

void* graceful_thread_termination (void* threads_args);

#endif
