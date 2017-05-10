#ifndef __CONTROLLER_THREAD_H__
#define __CONTROLLER_THREAD_H__

  void* wait_terminate_threads (void* received_threads);
  void console_log_information ();
  void write_informations_on_file ();
  void terminate_program (int signal);

#endif
