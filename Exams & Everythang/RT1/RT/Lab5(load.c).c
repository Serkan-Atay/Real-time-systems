#include<stdio.h> // printf
#include<time.h> // timespec, clock_gettime, CLOCK_PROCESS_CPUTIME_ID ...
#include<stdlib.h> // atoi
#include<unistd.h> // getpid
#include<sys/resource.h> // setPriority, PRIO_PROCESS

/*
 This program generates a specified amount of load on the CPU depending on the parameters it was given.
 parameters:
	$label = a label for this process. Used to differenciate between different processes' outputs.
	$NUM_slices = the number of slices before the process ends
	$prio = the Unix-priority for the Job 0..19
	$load = (optional) the size of a single slice.
*/
int main(int argc, char *argv[]){	//argc=Anzahl der Parameter
	// first let's make sure, the number of parameters is acceptable.
	// your program should be called with four parameters. Hint: don't forget the program name.
	if (argc != 5){
		printf("Usage: %s label num_slices priority load\n", argv[0]);
		return -1;
	}

	// use variables to store the parameters and make the code readable. 
	// Hint: int atoi(char *) https://linux.die.net/man/3/atoi
	char *programName = argv[0];
	char *label = argv[1];
	int NUM_slices = atoi(argv[2]);  //atoi=char in int umwandeln
	int prio = atoi(argv[3]);
	int load = atoi(argv[4]);
	int x=1;
	// Set the priority of this process to what was given as argument. 
	if (setpriority (PRIO_PROCESS, getpid(), prio ) == -1) {
        	perror ("Error when using setpriority()");
    	}
	
	// Print the column names of the output. We can use this later as header for tables
	printf("program_name label PID sec nsec slice\n");
	
	
	/*
	Loop example: NUM_slices = 2, load = 3
	
	>-time-->
	|<--iter-->|<--iter-->|<--iter-->|<--iter-->|<--iter-->|<--iter-->|
	|<------------slice------------->|<------------slice------------->|
	|<----------------------------program---------------------------->|
	
	*/
	int cnt_slice, cnt_iteration;
	// (outer)loop for slices
	for (cnt_slice = 0; cnt_slice < NUM_slices ; cnt_slice++){				
		// (inner)loop for iterations of single slice. This (inner)loop will take one second each time to process.
		for (cnt_iteration = 0; cnt_iteration < load ; cnt_iteration++){
			cnt_slice^2 + cnt_iteration - (2*cnt_slice); // some bogus calculation.
		}
		
		// create variable to hold a timespec and measure current time.	
		struct timespec tPnow;
		clock_gettime(CLOCK_REALTIME, &tPnow);
		// p_Pnow print the output as requested in the exercise.
		printf("%s %s %d %10ld %9ld %d\n", 
			programName, 
			label, 
			prio,
			tPnow.tv_sec,
			tPnow.tv_nsec,
			x++);
	}
	return 0;
}
