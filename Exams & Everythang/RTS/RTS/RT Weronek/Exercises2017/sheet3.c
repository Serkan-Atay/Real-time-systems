/* argument.c */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
       
    struct timespec timestamp;
    clock_gettime(CLOCK_REALTIME, &timestamp);
    
        printf("full-seconds: %ld, nano-seconds: %ld\n", timestamp.tv_sec, timestamp.tv_nsec);
        
        long int tmpsec = timestamp.tv_sec;
        long int tmpnsec = timestamp.tv_nsec;
        
        long int tmp0 = 1000000000*timestamp.tv_sec+timestamp.tv_nsec;
    
   long int i;
   long int j;
   long int k=0;

  /* for(i=0; i < num; i++) {
      printf("argv[%d] = %s ", i, argv[i]);
      printf("\n");
   }*/
  
    long int maxround;
    long int maxload;
    int prio;
    sscanf(argv[3], "%ld", &maxround);
    sscanf(argv[2], "%ld", &maxload);
    sscanf(argv[4], "%d", &prio);
        if (setpriority (PRIO_PROCESS, getpid (), prio ) == -1) { perror ("Fehler bei setpriority()");
} 

   for(i=0; i<maxround; i++){
        printf("%ld- Label: %s\n",i+1, argv[1]);
        clock_gettime(CLOCK_REALTIME, &timestamp);
        printf("full-seconds: %ld, nano-seconds: %ld\n\n", timestamp.tv_sec, timestamp.tv_nsec);

        for(j=0; j<maxload; j++){
            k++;
        }
    }
    
    clock_gettime(CLOCK_REALTIME, &timestamp);
   
    printf("\n\n===================================================\n\n");
    long int tmp1 = 1000000000*timestamp.tv_sec+timestamp.tv_nsec;

    printf("full-seconds: %ld, nano-seconds: %ld\n\n", timestamp.tv_sec-tmpsec, timestamp.tv_nsec-tmpnsec);
    
    long int tmp2;
    // Calculate the seconds
    tmp2 = tmp1 / 1000000000 - timestamp.tv_nsec;
  //  printf("sec: %ld\n\n", tmp2);
    
    //  Calculate the nano seconds 
    tmp2 = tmp1 - tmp0;
    printf("NANO sec: %ld\n\n", tmp2);

    printf("Process ID: %d\n",getpid());
    


   return EXIT_SUCCESS;
}
