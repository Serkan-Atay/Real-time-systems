#include <stdlib.h>
#include <stdio.h>
#include <time.h>

//Function for the difference, to calculate the execution time
struct timespec difference(struct timespec start, struct timespec end)
{
    struct timespec laufzeit;
    
    if(start.tv_nsec > end.tv_nsec)
    {
        laufzeit.tv_sec = end.tv_sec-1 - start.tv_sec;
        laufzeit.tv_nsec = end.tv_nsec+1e+9 - start.tv_nsec;
    }
    else
    {
        laufzeit.tv_sec = end.tv_sec - start.tv_sec;
        laufzeit.tv_nsec = end.tv_nsec - start.tv_nsec;
    }
    
    return laufzeit;
}

int main(int argc, char* argv[])
{
    int innerloop, nots, h1, h2, i = 0, j = 0, sum = 0;
    struct timespec start, end, laufzeit;
    //Error if not 3 arguments
    if(argc < 3 || argc > 4)
    {
        printf("Sorry, but you had to have 3 arguments!\n");
        printf("<label> <innerloop> <no of time slices>\n", *argv);
        return EXIT_FAILURE;
    }
    
    //Convert string to long (innerloop)
    h1 = strtol(argv[2], NULL, 10);
    if(h1 == 0)
    {
        printf("Sorry, the number is not an integer!\n");
        return EXIT_FAILURE;
    }
    else
    {
        innerloop = h1;
    }
    
    //Convert string to long (no time slice)
    h2 = strtol(argv[3], NULL, 10);
    if(h2 == 0)
    {
        printf("Sorry, the number is not an integer!\n");
        return EXIT_FAILURE;
    }
    else
    {
        nots = h2;
    }
    
    //Process ID
    printf("The PID is: %d\n", getpid());
    
    clock_gettime(CLOCK_REALTIME, &start);
    printf("Start: Label = %s, %ld seconds and %ld nanoseconds!\n", argv[1], start.tv_sec, start.tv_nsec);
     printf("Start: Label = %s, %ld%09ld nanoseconds!\n", argv[1], start.tv_sec, start.tv_nsec);
    for(i = 0; i < nots; i++)
    {
        for(j = 0; j < innerloop; j++)
        {
            sum = sum + 1;
        }
        clock_gettime(CLOCK_REALTIME, &end);
        printf("Label = %s_%d , %ld seconds and %ld nanoseconds!\n", argv[1], i, end.tv_sec, end.tv_nsec);
    }
    
    laufzeit = difference(start, end);
    printf("The difference between Start and End with Label = %s is %ld seconds and %ld nanoseconds!\n", argv[1], laufzeit.tv_sec, laufzeit.tv_nsec);
    return 0;
}
