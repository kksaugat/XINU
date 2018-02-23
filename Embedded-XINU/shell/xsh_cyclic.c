#include <stdio.h>	
#include <ctype.h>
#include <clock.h>
#define SLOTS 6   
#define FRAME 2
#define SLOT_T 100	    


	int row;
	int col;    


	void task_one(void) {
		printf("Task 1 is running\n");
		sleep(500);
	}


	void task_two(void) {
		printf("Task 2 is running\n");
		sleep(500);
	}


	void task_three(void) {
		printf("Task 3 is running\n");
		sleep(500);
	}


	void burn(){
 printf ("Burn\n");
}

void(*datatable[SLOTS][FRAME])(void)={

		{task_one, task_one},
		{task_two, task_three},
		{task_one, task_one},
		{task_two, burn},
		{task_one, task_one},
		{burn, burn}
	};


	command xsh_cyclic(ushort stdin, ushort stdout, ushort stderr, ushort nargs, char *args[]) {
	    	while (1) {
	      		for(row=0;row <SLOTS;row++) { 
				printf ("\n NEW FRAME\n");
				for (col=0; col<FRAME;col++) {
		  			(*datatable[row][col])();


				}
			}
		}	
		return OK;

 	}



