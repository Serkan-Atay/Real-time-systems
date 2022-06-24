#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char* argv[]) {
    if (argc != 5) {
        fprintf(stderr, "Syntax is: %s <label> <execution time> <period> <cycles>\n", argv[0]);
        return 1;
    }
    long exec_time = atol(argv[2]);
    long period = atol(argv[3]);
    long cycle = atol(argv[4]);

    if (period - exec_time < 0) {
        fprintf(stderr, "Execution time must be shorter than the period!\n");
        return 1;
    }

    struct timespec time_req, time_rem;
    time_req.tv_sec = period - exec_time;
    time_req.tv_nsec = 0;

    while (cycle--) {
        char cmd[128] = "./load-generator ";
        strcat(cmd, argv[1]);
        strcat(cmd, " ");
        strcat(cmd, argv[2]);
        system(cmd);
        if (cycle) nanosleep(&time_req, &time_rem);
    }
    
    printf("%s last cycle ended\n", argv[1]);

    return 0;
}