#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/resource.h>
#include <sys/types.h> 

double timespec_diff(struct timespec *tstart, struct timespec *tend) {
    double seconds = difftime(tend->tv_sec, tstart->tv_sec);
    long nanoseconds = tend->tv_nsec - tstart->tv_nsec;
    double timediff = seconds + (nanoseconds / 1000000000.0);
    return timediff;
}

int main(int argc, char** argv) {
    if (argc != 5) {
        printf("Syntax is %s <label> <maxload> <maxround> <priority>\n", argv[0]);
        return 1;
    }

    char label[256];
    strncpy(label, argv[1], 256);
    long maxload = atol(argv[2]); // 475000000 takes ~1 second on E5450
    long maxround = atol(argv[3]);
    double priority = atof(argv[4]);

    printf("%s: started with PID %d\n", label, getpid());

    if (setpriority(PRIO_PROCESS, getpid (), priority) == -1) {
        perror ("Unable to set priority\n");
    } else {
        printf("%s: priority set to %lf\n", label, priority);
    }

    struct timespec tp0;
    timespec_get(&tp0, TIME_UTC);

    // outer loop
    int outercount = 0;
    for (long i = 0; i <= maxround; i++) {
        // inner loop
        int innercount = 0;
        for (long j = 0; j <= maxload; j++) {
            innercount++;
        }
        struct timespec tp;
        timespec_get(&tp, TIME_UTC);
        printf("%s: Time passed after inner loop #%d: %lfs\n", label, outercount++, timespec_diff(&tp0, &tp));
    }

    printf("%s finished!\n", label);

    return 0;
}