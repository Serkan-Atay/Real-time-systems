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
    const long seconds = 5;

    struct timespec time_start, time_now;
    timespec_get(&time_start, TIME_UTC);

    //printf("%ld.%ld | Benchmark started\n", time_start.tv_sec, time_start.tv_nsec);

    timespec_get(&time_now, TIME_UTC);
    long i = 0;
    while (timespec_diff(&time_start, &time_now) < seconds) {
        log(++i);
        timespec_get(&time_now, TIME_UTC);
    }
    //printf("%ld.%ld | Benchmark ended\n", time_now.tv_sec, time_now.tv_nsec);
    //printf("Counted %ld floating point operations in %ld seconds (%ld FLOPS)\n", i, seconds, i/seconds);
    printf("%ld\n", i/seconds);

    return 0;
}