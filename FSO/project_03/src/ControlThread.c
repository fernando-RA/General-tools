#include "../lib/CoreIncludes.h"
#include "../lib/InformationUtility.h"

void log_info_console(Information info_storage){
  printf("[Aviso]: Maior numero gerado: %d\n", info_storage.maximum_value);
  printf("[Aviso]: Menor numero gerado: %d\n", info_storage.smallest_value);
  printf("[Aviso]: Maior ocupacao de buffer: %d\n", info_storage.biggest_buffer_occupation);
}
