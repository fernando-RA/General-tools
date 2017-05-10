#ifndef CONTROLLER_THREAD_H
#define CONTROLLER_THREAD_H

  void* wait_terminate_threads (void* received_threads);
  void console_log_information ();
  void write_informations_on_file ();
  void terminate_program (int signal);
  
#endif
