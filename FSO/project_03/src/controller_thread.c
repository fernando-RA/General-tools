#include "core_includes.h"

Information *info_storage;




void* wait_terminate_threads (void* received_threads) {
  info_storage = (Information*) received_threads;

  signal (SIGINT, terminate_program);

  return (void*) 0;
}

void terminate_program (int signal) {
  printf("\n[aviso]: Termino solicitado. Aguardando threads...\n");
  pthread_cancel (info_storage->ids_thread[0]);
  pthread_cancel (info_storage->ids_thread[1]);
  pthread_cancel (info_storage->ids_thread[2]);

  console_log_information ();
  write_informations_on_file ();
  fclose (info_storage->file);

  printf("[aviso]: Aplicacao encerrada.\n");
}

void console_log_information () {
  printf("[aviso]: Maior numero gerado: %d\n", info_storage->maximum_value);
  printf("[aviso]: Menor numero gerado: %d\n", info_storage->smallest_value);
  printf("[aviso]: Maior ocupacao de buffer: %d\n", info_storage->biggest_buffer_occupation);
}

void write_informations_on_file () {
  fprintf(info_storage->file, "[aviso]: Termino solicitado. Aguardando threads...\n");
  fprintf(info_storage->file, "[aviso]: Maior numero gerado: %d\n", info_storage->maximum_value);
  fprintf(info_storage->file, "[aviso]: Menor numero gerado: %d\n", info_storage->smallest_value);
  fprintf(info_storage->file, "[aviso]: Maior ocupacao de buffer: %d\n", info_storage->biggest_buffer_occupation);
  fprintf(info_storage->file, "[aviso]: Aplicacao encerrada.\n");
}
