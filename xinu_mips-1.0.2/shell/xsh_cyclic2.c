#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <clock.h>
#define SLOTS 10
#define FRAME 2


int x, y;
void first_task(void){
    printf("Task 1 is running\n");
    sleep(500);
}

void second_task(void){ 
   printf("Task 2 is running\n");
    sleep(500);
    
}

void third_task(void){    
printf("Task 3 is running\n");
    sleep(500);
    
}

void task_four(void){
    printf("Task 4 is running\n");
    sleep(500);
}


void smallburn(void){
        printf("SMALL BURN\n");
}
void bigburn(void){
printf("BURN\n");
}




void(*table[SLOTS][FRAME])(void)= {
    {first_task, third_task},                       
    {second_task,smallburn},
    {task_four, task_four},
    {first_task, bigburn},
    {second_task , smallburn},
    {first_task, bigburn},
    {second_task, smallburn},
    {first_task, bigburn},
    {first_task, bigburn},
    {second_task, smallburn}
}; 



command xsh_cyclic2(char second_diagram[],  ushort stdin, ushort stdout, ushort stderr, ushort nargs, char *args[]) {
second_diagram = "Part 2 of the cyclic executive";   
printf("%s\n",second_diagram);
 while (1) {
        for (x=0; x<SLOTS; x++) {
            printf ("\n NEW FRAME\n");
            for (y=0; y<FRAME;y++) {
                (*table[x][y])();
            }
        }
    }
    return OK;
}



