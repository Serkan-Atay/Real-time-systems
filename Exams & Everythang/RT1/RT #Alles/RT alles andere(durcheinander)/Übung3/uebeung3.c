#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<sys/resource.h>


void timespec_diff(struct timespec *start, struct timespec *stop, struct timespec *result)
{
    if ((stop->tv_nsec - start->tv_nsec) < 0) {
        result->tv_sec = stop->tv_sec - start->tv_sec - 1;
        result->tv_nsec = stop->tv_nsec - start->tv_nsec + 1000000000;
    } else {
        result->tv_sec = stop->tv_sec - start->tv_sec;
        result->tv_nsec = stop->tv_nsec - start->tv_nsec;
    }
}



int main(int anz, char* arguments[]){
    
    if(anz < 3){
        printf("Sie benötigen mindestens 2 Input Argumente\n");
        return 1;
    }      
    struct timespec beginTime;
    clock_gettime(CLOCK_REALTIME, &beginTime);
    
    char* label = arguments[1];
    int maxload = atoi(arguments[2]);
    int maxround = 10;
    int i,y;
    
    if(anz > 3){
        maxround = atoi(arguments[3]);
    }
    if(anz > 4){
        int prio = atoi(arguments[4]);
                
        printf("Momentane PID ist %d\n", getpid());
        
        printf("PID wird auf %d gesetzt!\n", prio);
        
        if (setpriority(PRIO_PROCESS, getpid (), prio) == -1) {
            perror ("Fehler bei setpriority()");
        }
        
        printf("PID nach setPriority ist %d\n", getpid());
    }
        
    for(i = 0; i < maxround; i++){
        
        printf("\n%s\n", label);
        int numb = 1;
        for(y=0; y< maxload; y++){
            numb += 1;
            struct timespec innerRoundTime, innerDiffTime;
            clock_gettime(CLOCK_REALTIME, &innerRoundTime);
        
            timespec_diff(&beginTime, &innerRoundTime, &innerDiffTime);
            if(innerDiffTime.tv_sec < 1){
                maxload += 1;
            }
            /*else{
                break;
            }*/
        }
        
        struct timespec roundTime, diffTime;
        clock_gettime(CLOCK_REALTIME, &roundTime);
        
        timespec_diff(&beginTime, &roundTime, &diffTime);
        
        printf("%ld sec, %ld nansec", diffTime.tv_sec, diffTime.tv_nsec);
    }
    
    printf("\n");
    
    
      
    
}
