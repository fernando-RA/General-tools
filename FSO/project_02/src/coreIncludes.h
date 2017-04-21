#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <unistd.h>
#include <signal.h>

#include "inputOutput.h"
#include "childProcess.h"
#include "time.h"

#define TIME_MAX 30
#define PARAMETER 1000000
