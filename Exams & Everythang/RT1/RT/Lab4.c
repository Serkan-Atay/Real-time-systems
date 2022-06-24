/*Selma Spahic,
  Exercise 4
*/




#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>


int myfunc1 (int in)
    {
        int val1, i;
        float val2, val3;
        for (i =0; i < 4500; i++)
        {
            val1 = in*in*i;
            val2 = (in+i )*( in+i )*( in+i);
            val3 = val2 / val1;
        }
        return val3;
    }


int myfunc2 (int in)
    {
        int i, j = in;
        for(i=0; i <= 999; i++) j=j+i;
        return j;
    }


int main()
{
    struct timeval time1;
    struct timeval time2;
    int i,j;

    printf("time1: %ld\n",time1);
    printf("time2: %ld\n",time2);
    printf("\n");

// ---- Max. Zeit ----


  gettimeofday(&time1,0);
  for(i=0; i < 500000; i++)
  {
    myfunc1(j);
  }
  gettimeofday(&time2,0);

  int rechnung = (time2.tv_sec - time1.tv_sec) * 1000000 + (time2.tv_usec - time1.tv_usec);
  int Rerg = rechnung/1000;

  printf("Maximum:   %ld Ms\n",Rerg);

// ---- Min. Zeit ----

 gettimeofday(&time1,0);
  for(i=0; i < 500000; i++)
  {
    myfunc2(j);
  }
  gettimeofday(&time2,0);

  rechnung = (time2.tv_sec - time1.tv_sec) * 1000000 + (time2.tv_usec - time1.tv_usec);
  Rerg = rechnung/1000;

  printf("Minimum:    %ld Ms\n",Rerg);



  // ---- Average ----

  gettimeofday(&time1,0);
  for(i=0; i < 500000; i++) {
    if((j=rand()) > 0x3fffffff) {    // Zufallszahl       
      myfunc1(j);
    } else {
      myfunc2(j);
    }
  }
  gettimeofday(&time2,0);

  rechnung = (time2.tv_sec - time1.tv_sec) * 1000000 + (time2.tv_usec - time1.tv_usec);     
  Rerg = rechnung/1000;    

  printf("Average:     %ld Ms\n",Rerg);


// ---- Average Execution 40%  ----

  gettimeofday(&time1,0);
  for(i=0; i < 500000; i++)
  {
    if((j=rand()%100) > 40)    
    {
      myfunc1(j);
    }
    else
    {
      myfunc2(j);
    }
  }
  gettimeofday(&time2,0);

  rechnung = (time2.tv_sec - time1.tv_sec) * 1000000 + (time2.tv_usec - time1.tv_usec);
  Rerg = rechnung/1000;

  printf("Average Execution time for 40 Prozent: %ld Ms\n\n",Rerg);

    return 0;
}
