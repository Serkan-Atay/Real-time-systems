#include <time.h>
#include <stdio.h>
#include <stdlib.h>




int complex_func(int in){
     int tmp1, i;
     float tmp2, tmp3;
    
    for(i=0; i<4112; i++){
        tmp1 = in*in*i;
        tmp2 = (in+i)*(in+i)*(in+i);
        tmp3 = tmp2 / tmp1;
    }
        return tmp3;
}

int simple_func(int in){
    
    int i,j=in;
    
    for(i=0; i<921; i++)
        j=j+i;
    return j;
}

int main(){
    
    int i,j;
    
    struct timespec timestamp;
    clock_gettime(CLOCK_REALTIME, &timestamp);
    
        printf("full-seconds: %ld, nano-seconds: %ld\n", timestamp.tv_sec, timestamp.tv_nsec);
        
        long int tmpsec = timestamp.tv_sec;
        long int tmpnsec = timestamp.tv_nsec;
        
        long int tmp0 = 1000000000*timestamp.tv_sec+timestamp.tv_nsec;
    
    for(i=0; i<350000; i++){
        j= rand();
        if(j > 0x3fffffff){
       // if(j > 0x7fffffff){   // to calculate 50% chance
        //if(j > 0x66666666){   // to calculate 40% chance 
            complex_func(j);
        }
        else{
            simple_func(j);
        }
    }
    
    clock_gettime(CLOCK_REALTIME, &timestamp);
    printf("\nfull-seconds: %ld, nano-seconds: %ld\n", timestamp.tv_sec, timestamp.tv_nsec);
    printf("\nThe Difference\n\n");
    long int tmp1 = 1000000000*timestamp.tv_sec+timestamp.tv_nsec;

    printf("full-seconds: %ld, nano-seconds: %ld\n\n", timestamp.tv_sec-tmpsec, timestamp.tv_nsec-tmpnsec);
    
    long int tmp2;
    // Calculate the seconds
    tmp2 = tmp1 / 1000000000 - timestamp.tv_nsec;
  //  printf("sec: %ld\n\n", tmp2);
    
    //  Calculate the nano seconds 
    tmp2 = tmp1 - tmp0;
    printf("NANO sec: %ld\n\n", tmp2);
    return 0;
}

