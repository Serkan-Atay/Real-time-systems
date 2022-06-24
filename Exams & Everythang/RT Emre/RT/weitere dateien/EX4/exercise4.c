#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int myfunc1 (int in){
	int val1, i;
	float val2, val3;
	for (i =0; i < 4500; i++){
		val1 = in*in*i;
 		val2 = (in+i )*( in+i )*( in+i);
 		val3 = val2 / val1;
 	}
 	return val3;
}

int myfunc2 (int in){
	int i, j = in;
	for(i=0; i <= 999; i++) j=j+i;


	return j;
}



//MAIN

int main(int argc , char ** argv
){
	int i,j;

	 struct timespec mytimestamp;
	 struct timespec mytimestamp1;
	 struct timespec endergebnis;

	 //CASE 1
	 clock_gettime(CLOCK_REALTIME,&mytimestamp);
	 for (i = 0; i < 500000; i++){
		myfunc1(j);
	 }
	 clock_gettime(CLOCK_REALTIME, &mytimestamp1);
	 endergebnis.tv_sec =(mytimestamp1.tv_sec) - (mytimestamp.tv_sec);
	 printf("MAXIMUM TIME FOR myfunc1: %ld \n",endergebnis.tv_sec);


	 //CASE 2
	 clock_gettime(CLOCK_REALTIME,&mytimestamp);
	 for (i = 0; i < 500000; i++){
		myfunc2(j);
	 }
	 clock_gettime(CLOCK_REALTIME, &mytimestamp1);
	 endergebnis.tv_sec =(mytimestamp1.tv_sec) - (mytimestamp.tv_sec);
	 printf("MINIMUM TIME FOR myfunc2: %ld \n",endergebnis.tv_sec);


	 //CASE 3
	 clock_gettime(CLOCK_REALTIME, &mytimestamp);
	 for (i = 0; i < 500000; i++){
	 	if ((j = rand() ) > 0x3fffffff ){
	 		myfunc1(j);
	 	}else myfunc2(j);
	 }

	 clock_gettime(CLOCK_REALTIME, &mytimestamp1);
	 endergebnis.tv_sec =(mytimestamp1.tv_sec) - (mytimestamp.tv_sec);
	 printf("AVERAGE TIME OF BOTH FUNCTIONS: %ld \n",endergebnis.tv_sec);


	 //CASE 4
	 clock_gettime(CLOCK_REALTIME, &mytimestamp);
	 for (i = 0; i < 500000; i++){
	 	if ((j = rand() ) > 40 ){
	 		myfunc1(j);
	 	}else myfunc2(j);
	 }

	 clock_gettime(CLOCK_REALTIME, &mytimestamp1);
	 endergebnis.tv_sec =(mytimestamp1.tv_sec) - (mytimestamp.tv_sec);
	 printf("AVERAGE TIME OF 40PERCENT myfunc2: %ld \n",endergebnis.tv_sec);	 







}