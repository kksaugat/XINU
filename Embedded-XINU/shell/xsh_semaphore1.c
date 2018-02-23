#include <stdio.h>
#include <semaphore.h>
#include <string.h>
#include <kernel.h>
#include <stdlib.h>

int count = 0;
static semaphore mutex1 = NULL;


void process1 (void){
while(count<55)   {
sleep(rand()%1000);
wait(mutex1);
fprintf(TTY0, "Process 1, Count = %d\n", count); 
count++;
signal(mutex1);
}}

void process2(void){

while(count<55){
sleep(rand()%1000);
wait(mutex1);
fprintf(TTY0, "Process 2, Count = %d\n",count);
count++;
signal(mutex1);
}

}

void process3(void){
while (count<55){
sleep(rand()%1000);
wait(mutex1);
fprintf(TTY0, "Process 3, Count = %d\n", count);
count++;
signal(mutex1);
}}

command xsh_semaphore1(ushort stdin, ushort stdout, ushort stderr, ushort nargs,char*args[]){
mutex1 = newsem(1);
ready(create((void*)process1, 0,0, "PROCESS1", 2, 0, NULL),RESCHED_NO);
	ready(create((void*)process2, 1024, 20, "PROCESS2", 2, 0, NULL), RESCHED_NO);
ready(create((void*)process3, 0,0, "PROCESS3",2,0,NULL),RESCHED_NO);
	return OK;
}








