#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <unistd.h>
#include <signal.h>

#include "writers.h"
#include "children.h"

#define TIME_MAX 30


/*
TODO -> Refactor main
Refactor g_activeProcess
Refactor children
Refactor comunication
Refactor g_sleepyChild
Refactor time_functions
Refactor writers
Change code
Fix name output.txt
Print if it is on process -> to receive an input
Testar 30 segundos finalizar execução
Fazer cabeçalho para arquivo
Documentação:
* Sistema Operacional
* Ambiente de desenvolvimento
* Telas/Instrução de Uso
* Limitações conhecidas
*/

pid_t g_activeProcess = -1;
pid_t g_sleepyChild = -1;

void finishExecution(int signal) {
    int status;
    kill(g_activeProcess, SIGTERM);
    kill(g_sleepyChild, SIGTERM);

    exit(0);
}

void controllProcess(FILE* outputFile){
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

        signal(SIGALRM, finishExecution);
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

int main(){
    FILE* output = fopen("output.txt", "w");
    controllProcess(output);

    return 0;
}
