#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double timespec_diff(struct timespec *tstart, struct timespec *tend) {
    double seconds = difftime(tend->tv_sec, tstart->tv_sec);
    long nanoseconds = tend->tv_nsec - tstart->tv_nsec;
    double timediff = seconds + (nanoseconds / 1000000000.0);
    return timediff;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Syntax is: %s <label> <operations>\n", argv[0]);
        return 1;
    }
    const long operations = atol(argv[2]);

    struct timespec time_start, time_now;
    timespec_get(&time_start, TIME_UTC);

    printf("%ld.%09ld | %s started\n", time_start.tv_sec, time_start.tv_nsec, argv[1]);

    for (long i = 1; i <= operations; ++i) {
        log(i);
        timespec_get(&time_now, TIME_UTC);
    }

    printf("%ld.%09ld | %s ended\n", time_now.tv_sec, time_now.tv_nsec, argv[1]);

    return 0;
}