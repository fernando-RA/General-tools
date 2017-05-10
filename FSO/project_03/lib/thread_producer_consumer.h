#ifndef __THREAD_PRODUCER_CONSUMER_H__
#define __THREAD_PRODUCER_CONSUMER_H__

  void controll_threads(Information info_storage);
  void* control_consumer_thread (void* received_threads);
  void* control_producer_thread (void* received_threads);

#endif
