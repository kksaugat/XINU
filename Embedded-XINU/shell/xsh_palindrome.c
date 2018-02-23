#include <kernel.h>
#include <stdio.h>
#include <string.h>


int stringlen(char*p);
void reverse(char *s);

void reverse (char *s){
int length,i;
char *first, *last, temp;

length = stringlen(s);
first =s;
last = s;

for(i=0;i<length-1; i++){
last++;
}
for(i=0; i<length/2; i++){
temp = *last;
*last = *first;
*first = temp;

first++;
last--;
}}

int stringlen(char *p){
int j  = 0;
while(*(p+j)!= '\0'){
j++;
}
return j;
}   














command xsh_palindrome (ushort stdin, ushort stderr, ushort nargs,ushort stdout,char*args[]){
if(nargs ==2 && strncmp(args[1],"--help",6)==0){
fprintf(stdout, "Usage: clear\n");
fprintf(stdout, "Clean the terminal.\n");
fprintf(stdout, "\t--help\t display the help and exit\n");
return SYSERR;
}  

char pali[100];
strcpy(pali, args[1]);
reverse(pali);
if(strcmp(pali, args[1])==0)
fprintf(stdout, "yes");
else
fprintf(stdout, "no");
fprintf(stdout, "\n");

return OK;
}




  

