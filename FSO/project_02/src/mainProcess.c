#include "coreIncludes.h"

pid_t g_activeProcess = -1;
pid_t g_sleepyChild = -1;

void controll_process(FILE* outputFile){
    int pipeActiveProcess[2];
    int pipeSleepyChild[2];
    struct timeval startTime;

    pipe (pipeActiveProcess);
    pipe (pipeSleepyChild);

    g_activeProcess = fork();
    g_sleepyChild = fork();

    /* Active child process */
    if (g_activeProcess == (pid_t)0) {
        gettimeofday(&startTime, NULL);
        execute_active_process(pipeActiveProcess, &startTime);
    }

    else if (g_sleepyChild == (pid_t)0) {
        gettimeofday(&startTime, NULL);
        execute_lazy_child(pipeSleepyChild, &startTime);
    }

    /* Parent process */
    else {
        gettimeofday(&startTime, NULL);

        signal(SIGALRM, finish_execution);
        alarm(TIME_MAX);

        close (pipeActiveProcess[1]);
        close (pipeSleepyChild[1]);

        dup2 (pipeActiveProcess[0], STDIN_FILENO);
        dup2 (pipeSleepyChild[0], STDIN_FILENO);

        FILE* pipeActiveChild;
        pipeActiveChild = fdopen (pipeActiveProcess[0], "r");

        FILE* pipeLazyChild;
        pipeLazyChild = fdopen (pipeSleepyChild[0], "r");

        fd_set exceptfds;
        FD_ZERO(&exceptfds);

        // Main parent process loop
        while(1){
            FD_SET(pipeActiveProcess[0], &exceptfds);
            FD_SET(pipeSleepyChild[0], &exceptfds);

            select(FD_SETSIZE, &exceptfds, NULL, NULL, 0);

            if (FD_ISSET(pipeActiveProcess[0], &exceptfds)) {
                get_message_pipe_and_write_file (pipeActiveChild, outputFile, &startTime);
            }
            if (FD_ISSET(pipeSleepyChild[0], &exceptfds)) {
                get_message_pipe_and_write_file (pipeLazyChild, outputFile, &startTime);
            }
        }
        close(pipeActiveProcess[0]);
        close(pipeSleepyChild[0]);
        fclose(outputFile);
    }
}

void finish_execution() {
    kill(g_activeProcess, SIGTERM);
    kill(g_sleepyChild, SIGTERM);
    printf("Finishing...\n");
    exit(0);
}

void execute_active_process(pid_t pipeActiveProcess[2], struct timeval *startTime) {
  close (pipeActiveProcess[0]); // close read

  FILE* pipe;
  pipe = fdopen (pipeActiveProcess[1], "w");

  int count = 1;

  while(1) {
    char message_user[100];
    scanf("%s", message_user);

    struct timeval finishedTime, elapsedTime;
    gettimeofday(&finishedTime, NULL);

    calcute_time_elapsed(startTime, &finishedTime, &elapsedTime);

    output_pipe_active_process(message_user, &elapsedTime, pipe, count);
    count++;
  }

  close (pipeActiveProcess[1]);
}
