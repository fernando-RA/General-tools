#include "../lib/CoreIncludes.h"
#include "../lib/InformationUtility.h"


void log_info_console(Information info_storage){
  printf("[Aviso]: Maior numero gerado: %d\n", info_storage.maximum_value);
  printf("[Aviso]: Menor numero gerado: %d\n", info_storage.smallest_value);
  printf("[Aviso]: Maior ocupacao de buffer: %d\n", info_storage.biggest_buffer_occupation);
}

void log_info_file(Information info_storage){
  fprintf(info_storage.file, "[Aviso]: Termino solicitado. Aguardando threads...\n");
  fprintf(info_storage.file, "[Aviso]: Maior numero gerado: %d\n", info_storage.maximum_value);
  fprintf(info_storage.file, "[Aviso]: Menor numero gerado: %d\n", info_storage.smallest_value);
  fprintf(info_storage.file, "[Aviso]: Maior ocupacao de buffer: %d\n", info_storage.biggest_buffer_occupation);
  fprintf(info_storage.file, "[Aviso]: Aplicacao encerrada.\n");
}

void exit_program(Information info_storage, int signal){
  printf("[Aviso]: Termino solicitado. Aguardando threads...\n");

  pthread_cancel (info_storage.thread_id[0]);
  pthread_cancel (info_storage.thread_id[1]);
  pthread_cancel (info_storage.thread_id[2]);

  log_info_console(info_storage);
  log_info_file(info_storage);

  fclose (info_storage.file);
  printf("[aviso]: Aplicacao encerrada.\n");
}

void wait_for_exit(Information info_storage, void* thread){
  info_storage = (Information*) thread;

  signal(SIGINT, exit_program);

  return (void*) 0;
}
