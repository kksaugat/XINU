#include <semaphore.h>
#include <string.h>
#include <kernel.h>
#include <stdio.h>
#include <stdlib.h>


int counter = 0;
static semaphore synch12 = NULL;
static semaphore synch23 = NULL;
static semaphore synch31 = NULL;


void proc1(void)
{   while (counter<50) {
    sleep (rand()%1000);
wait(synch31);    
fprintf(TTY0,"Process 1 Counter = %d\n",counter);
 counter++;
signal(synch12);
    } } 
void proc2(void)
{   while (counter<50) {
    sleep (rand()%1000);
    wait(synch12  );
fprintf(TTY0,"Process 2 Counter = %d\n",counter);     
 counter++;
signal(synch23);
} } 

void proc3(void){
  while(counter<50){
sleep (rand()%1000);
wait(synch23);
fprintf(TTY0, "Process 3 Counter = %d\n",counter);
counter++;
signal(synch31);
}}  






command	xsh_semaphore2 (ushort stdin, ushort stdout, ushort stderr, ushort nargs, char *args[]) {
	synch12 = newsem(0);
	synch23 = newsem(0);
	synch31 = newsem(0);
	
	ready(create((void*)proc1 , 1024, 20, "PROC1", 2, 0, NULL), RESCHED_NO);
	ready(create((void*)proc2 , 1024, 20, "PROC2", 2, 0, NULL), RESCHED_NO);
	ready(create((void*)proc3 , 1024, 20, "PROC3", 2, 0, NULL), RESCHED_NO);
	signal(synch31);
	return OK;
}







