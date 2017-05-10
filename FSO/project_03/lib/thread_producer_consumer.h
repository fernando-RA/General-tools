#ifndef _THREAD_PRODUCER_CONSUMER_H
#define _THREAD_PRODUCER_CONSUMER_H

  void controll_threads(Information info_storage);
  void* control_consumer_thread (void* received_threads);
  void* control_producer_thread (void* received_threads);

#endif
