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

    clock_gettime(CLOCK_REALTIME, &timestamp1);

   for(i=0; i<maxround; i++){
       // printf("%ld- Label: %s\n",i+1, argv[1]);
       // clock_gettime(CLOCK_REALTIME, &timestamp);
       // printf("full-seconds: %ld, nano-seconds: %ld\n\n", timestamp.tv_sec, timestamp.tv_nsec);

        for(j=0; j<maxload; j++){
           // k++;
        }
        clock_gettime(CLOCK_REALTIME, &timestamp2);
        if(end.tv_nsec<begin.tv_nsec )
      {
	timestamp2.tv_nsec=timestamp2.tv_nsec+1000000000;				
	timestamp2.tv_sec=timestamp2.tv_sec-1;
      }
    nsec=end.tv_nsec-begin.tv_nsec;
    sec=end.tv_sec-begin.tv_sec;

    // second Answer!
    printf("\nLabel %s-%ld: The result from %ld to %ld is: \n", argv[1],i+1, i, i+1);
    printf("The execution time:\nIn full-seconds: %ld sec\nAnd in full nano-seconds: %ld nsec \n", sec, nsec);
    printf ("\nPID: %d\n",pid);

    }
    
    // first Answer down!

   /* long int tmp1 = 1000000000*timestamp.tv_sec+timestamp.tv_nsec;

    printf("full-seconds: %ld, nano-seconds: %ld\n\n", timestamp.tv_sec-tmpsec, timestamp.tv_nsec-tmpnsec);
    
    long int tmp2;
    // Calculate the seconds
    tmp2 = tmp1 / 1000000000 - timestamp.tv_nsec;
  //  printf("sec: %ld\n\n", tmp2);
    
    //  Calculate the nano seconds 
    tmp2 = tmp1 - tmp0;
    printf("NANO sec: %ld\n\n", tmp2);

    printf("Process ID: %d\n",getpid());
    
*/

   return EXIT_SUCCESS;
}
