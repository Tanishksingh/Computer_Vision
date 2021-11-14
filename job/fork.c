#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
int main()
{
 fork();
 printf("HELLO 1\n");
 fork();
 printf("HELLO 2\n");
 fork();
printf("HELLO 3 \n");
 return 0;
}
