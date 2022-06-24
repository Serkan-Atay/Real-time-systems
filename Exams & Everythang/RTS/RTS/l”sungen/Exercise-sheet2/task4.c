#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef max
    #define max(a,b) ((a) > (b) ? (a) : (b))
#endif
#ifndef min
    #define min(a,b) ((a) < (b) ? (a) : (b))
#endif

double minex_simple = 0xFFFFFFFF, maxex_complex = 0.0;

double timespec_diff(struct timespec *tstart, struct timespec *tend) {
    double seconds = difftime(tend->tv_sec, tstart->tv_sec);
    long nanoseconds = tend->tv_nsec - tstart->tv_nsec;
    double timediff = seconds + (nanoseconds / 1000000000.0);
    return timediff;
}

int complex_func (int in)
{
    struct timespec tstart;
    timespec_get(&tstart, TIME_UTC);

    int tmp1 ,i;
    float tmp2 , tmp3 ;
    for (i =0; i < 4112; i++) {
        tmp1 = in*in*i;
        tmp2 = (in+i )*( in+i )*( in+i);
        tmp3 = tmp2 / tmp1;
    }

    struct timespec tend;
    timespec_get(&tend, TIME_UTC);
    maxex_complex = max(maxex_complex, timespec_diff(&tstart, &tend));

    return tmp3 ;
}

int simple_func (int in) {
    struct timespec tstart;
    timespec_get(&tstart, TIME_UTC);

    int i, j = in;
    for (i = 0; i < 921; i++) j = j+i;
    
    struct timespec tend;
    timespec_get(&tend, TIME_UTC);
    minex_simple = min(minex_simple, timespec_diff(&tstart, &tend));

    return j;
}

int main (int argc , char ** argv) {
    int i, j;
    srand(time(NULL));

    struct timespec tstart;
    timespec_get(&tstart, TIME_UTC);
    //printf("Start time: %s\n", ctime(&tstart.tv_sec));

    for (i = 0; i < 350000; i++) {
        j = rand();
        if (j > 0x3fffffff ) complex_func(j);
        else simple_func(j);
    }

    struct timespec tend;
    timespec_get(&tend, TIME_UTC);
    //printf("End time: %s\n", ctime(&tend.tv_sec));

    printf("a) Time passed 50%% chance: %.9lf seconds\n", timespec_diff(&tstart, &tend));
    printf("b) Minimum execution time simple_func(): %.9lf seconds\n", minex_simple);
    printf("c) Maximum execution time complex_func(): %.9lf seconds\n", maxex_complex);

    timespec_get(&tstart, TIME_UTC);
    
    for (i = 0; i < 350000; i++) {
        j = rand();
        if (j > 0x3fffffff*0.8 ) complex_func(j);
        else simple_func(j);
    }

    timespec_get(&tend, TIME_UTC);
    printf("d) Time passed 40%% chance: %.9lf seconds\n", timespec_diff(&tstart, &tend));

    return 0;
}