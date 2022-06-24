#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

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

//Convert slacktime = nanoseconds into slacktime = seconds and nanoseconds
struct timespec ns(long nanoseconds)
{
    struct timespec slacktime;
    
    if(nanoseconds > 1000000000)
    {
        slacktime.tv_sec = (int)(nanoseconds/1000000000);
        slacktime.tv_nsec = nanoseconds%1000000000;
        printf("Slacktime = %ld s and %ld ns\n", slacktime.tv_sec, slacktime.tv_nsec);
        
    }
    else
    {
        slacktime.tv_sec = 0;
        slacktime.tv_nsec = nanoseconds;
        printf("Slacktime = %ld s and %ld ns\n", slacktime.tv_sec, slacktime.tv_nsec);
    }
    
    return slacktime;
}

int main(int argc, char* argv[])
{
    long innerloop, nots, delta_t_period, h1, h2, h3, i = 0;
    struct timespec delta, absolutetime, laufzeit, start, end;

    //Error if not 4 arguments
    if(argc < 4 || argc > 5)
    {
        printf("Sorry, but you had to have 4 arguments!\n");
        printf("<label> <innerloop> <no of time slices> <delta_t_period>\n", *argv);
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
    
    //Convert string to long (delta t period)
    h3 = strtol(argv[4], NULL, 10);
    if(h3 == 0)
    {
        printf("Sorry, the number is not an integer!\n");
        return EXIT_FAILURE;
    }
    else
    {
        delta_t_period = h3;
    }
    
    delta = ns(delta_t_period);
    
    clock_gettime(CLOCK_REALTIME, &absolutetime);
    start.tv_sec = absolutetime.tv_sec;
    start.tv_nsec = absolutetime.tv_nsec;
    printf("Before loop = Label: %s, %ld seconds and %ld nanoseconds!\n", argv[1], absolutetime.tv_sec, absolutetime.tv_nsec); 
    for(i = 0; i < 10; i++)
    {
        //char mycmd[100] = "taskset 2 ./job ";
        char mycmd[100] = "./taskset2 ";
        char stringi[2];
        sprintf(stringi, "%d", i); //convert i to string
        strcat(mycmd, argv[1]);
        strcat (mycmd, stringi);
        strcat (mycmd, " ");
        strcat (mycmd, argv[2]); //iterations inner loop
        strcat (mycmd, " ");
        strcat(mycmd, argv[3]); //iterations outer loop
        strcat (mycmd, "&");
        printf("%s\n",mycmd);       
        system(mycmd);
        nanosleep(&delta, NULL);
        clock_gettime(CLOCK_REALTIME, &absolutetime);
        end.tv_sec = absolutetime.tv_sec;
        end.tv_nsec = absolutetime.tv_nsec;
        laufzeit = difference(start, end);
        start.tv_sec = end.tv_sec;
        start.tv_nsec = end.tv_nsec;
        printf("Task = Label: %s%d, %ld seconds and %ld nanoseconds!\n", argv[1], i,laufzeit.tv_sec, laufzeit.tv_nsec); 
    }
    
    return 0;
}
