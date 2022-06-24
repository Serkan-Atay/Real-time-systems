#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char* argv[]) {
    if (argc != 5) {
        fprintf(stderr, "Syntax is: %s <label> <operations> <sleep> <cycles>\n", argv[0]);
        return 1;
    }
    const long operations = atol(argv[2]);
    const long sleep = atol(argv[3]);
    long cycle = atol(argv[4]);

    struct timespec time_req, time_rem;
    time_req.tv_sec = sleep;
    time_req.tv_nsec = 0;

    while (cycle--) {
        char cmd[128];
        sprintf(cmd, "./load-generator %s %ld", argv[1], operations);
        system(cmd);
        if (cycle) nanosleep(&time_req, &time_rem);
    }
    
    printf("%s last cycle ended\n", argv[1]);

    return 0;
}