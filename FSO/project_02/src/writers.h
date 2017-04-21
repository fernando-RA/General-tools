#ifndef GENERATE_OUTPUT_H
#define GENERATE_OUTPUT_H

void output_pipe_active_process(const char* message, struct timeval *elapsedTime, FILE* pipe, int i);
void writer_pipe_lazy_child(struct timeval *elapsedTime, FILE* pipe, int i);
void get_message_pipe_and_write_file(FILE* pipe, FILE* outputFilePtr, struct timeval *startTime);

#endif
