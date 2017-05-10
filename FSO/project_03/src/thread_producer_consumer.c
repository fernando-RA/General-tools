#include "core_includes.h"

#define CONSUMER_TIME_SLEEP 150000
#define PRODUCER_TIME_SLEEP 100000

void controll_threads(Information info_storage){
  pthread_t thread_maker, thread_first_consumer, thread_second_consumer, thread_mananger;

  pthread_create(&thread_maker, NULL, &control_producer_thread, &info_storage);
  info_storage.ids_thread[0] = thread_maker;
  pthread_create(&thread_first_consumer, NULL, &control_consumer_thread, &info_storage);
  info_storage.ids_thread[1] = thread_first_consumer;
  pthread_create(&thread_second_consumer, NULL, &control_consumer_thread, &info_storage);
  info_storage.ids_thread[2] = thread_second_consumer;
  pthread_create (&thread_mananger, NULL, &wait_terminate_threads, &info_storage);

  pthread_join (thread_mananger, NULL);
  pthread_join (thread_maker, NULL);
  pthread_join (thread_first_consumer, NULL);
  pthread_join (thread_second_consumer, NULL);
}

void* control_producer_thread (void* received_threads) {
  Information *info_storage = (Information*) received_threads;

  srand ((unsigned)time(NULL));

  while (1) {
    if (info_storage->current_position < 0) {
      info_storage->current_position = 0;
    }

    if (info_storage->current_position < MAX_BUFFER_SIZE) {
      pthread_mutex_lock (&info_storage->lock_mutex);

      int number = get_random ();

      info_storage->buffer[info_storage->current_position] = number;
      info_storage->current_position ++;

      if (info_storage->current_position > info_storage->biggest_buffer_occupation) {
        info_storage->biggest_buffer_occupation = info_storage->current_position;
      }

      fprintf(info_storage->file, "[producao]: Numero gerado: %d\n", number);
      pthread_testcancel (); // thread cancellation point
      pthread_mutex_unlock (&info_storage->lock_mutex);
    }

    usleep(PRODUCER_TIME_SLEEP);
  }
}

void* control_consumer_thread (void* received_threads) {
  Information *info_storage = (Information*) received_threads;
  char thread = 'a';

  if (info_storage->ids_thread[1] != pthread_self ()) {
    thread = 'b';
  }

  while (1) {
    pthread_mutex_lock (&info_storage->lock_mutex);

    if (info_storage->current_position > 0) {
      int number = info_storage->buffer[info_storage->current_position-1];
      info_storage->current_position --;

      fprintf(info_storage->file, "[consumo %c]: Numero lido: %d\n", thread, number);

      if (number > info_storage->maximum_value) {
        info_storage->maximum_value = number;
      }
      else if (number < info_storage->smallest_value) {
        info_storage->smallest_value = number;
      }

       pthread_testcancel (); // thread cancellation point
    }

    pthread_mutex_unlock (&info_storage->lock_mutex);
    usleep (CONSUMER_TIME_SLEEP);
  }
}
