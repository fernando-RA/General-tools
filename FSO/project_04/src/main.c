#include <stdio.h>
#include "libseno.h"
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
    int i;
    double angle;
    if(argc-1 == 0){
        printf("No parameters passed\n");
        return 0;
    }

    for (i = 1; i < argc; ++i) {
        printf("Parametro #%d: %s\n", i, argv[i]);

        if(strcmp(argv[i], "-s") == 0){
            angle = strtod(argv[i+1], NULL);

            printf("seno (%.3lf) = %lf\n", angle, seno(angle));
        }
    }

    return 0;
}
