#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
int main()
{
pid_t pid;
pid=fork();
if(pid!=0)
{
    printf("In while loop");
   sleep(50);
}
else
{
exit(0);
}
return 0;
}
