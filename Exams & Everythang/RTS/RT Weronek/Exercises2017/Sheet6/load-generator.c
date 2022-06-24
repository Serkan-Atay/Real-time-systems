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
        fprintf(stderr, "Syntax is: %s <label> <seconds>\n", argv[0]);
        return 1;
    }
    const long seconds = atol(argv[2]);

    struct timespec time_start, time_now;
    timespec_get(&time_start, TIME_UTC);

    printf("%ld.%ld | %s started\n", time_start.tv_sec, time_start.tv_nsec, argv[1]);

    timespec_get(&time_now, TIME_UTC);
    while (timespec_diff(&time_start, &time_now) < seconds) {
        long c = 100000;
        while (c--) timespec_get(&time_now, TIME_UTC);
    }
    printf("%ld.%ld | %s ended\n", time_now.tv_sec, time_now.tv_nsec, argv[1]);

    return 0;
}