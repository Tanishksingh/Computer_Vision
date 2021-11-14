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
if(pid==0)
{
	sleep(6);
	printf("\n I m Child.\n My PID = %d \n My Parent PID = %d",
	getpid(),getppid());
}
else
{
	printf("\nI m Parent.\n My Child PID = %d \n  my PID = %d",pid,getpid());
}
printf("\nTerminating PID = %d\n",getpid());
return 0;
}
