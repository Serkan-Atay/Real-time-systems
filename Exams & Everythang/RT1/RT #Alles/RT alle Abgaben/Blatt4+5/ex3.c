#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include<sys/resource.h>


int main(int c, char *a[]) {
    long j,k,i = 0;
    long t_ns;
    struct timespec TP0;
    struct timespec TP;


    clock_gettime(CLOCK_REALTIME, &TP0);
    if (setpriority (PRIO_PROCESS, getpid (), atoi(a[4]) ) == -1) {
        perror ("Fehler bei setpriority()"); }
      
    struct timespec tim, tim2;
    tim.tv_sec = 0;
    sd
tim.tv_nsec =atol(a
    [5]);

   

   
	
        
    for(k=0; k < atol(a[3]); k++)
    {
        j=0;
        for(i=0; i < atol(a[2]); i++){
            j=j+1;
        }
        clock_gettime(CLOCK_REALTIME, &TP);
        t_ns =TP.tv_nsec - TP0.tv_nsec;
        
        
        if (t_ns < 0) {
            t_ns = t_ns + 1000000000;
            TP.tv_sec = TP.tv_sec -1;
            
        }
	
        printf(" %s", a[1]);
        printf("%12ld s  ", (TP.tv_sec-TP0.tv_sec));
        printf("%12ld ns  ",t_ns);
        printf("PID: %d\n", getpid());
        nanosleep(&tim , &tim2);
    }




    clock_gettime(CLOCK_REALTIME, &TP);
    t_ns =TP.tv_nsec - TP0.tv_nsec;
    
      if (t_ns < 0) {
            t_ns = t_ns + 1000000000;
            TP.tv_sec = TP.tv_sec -1;
      }

    return 0;
}

