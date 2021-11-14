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
VirtualBox:-/Desktop/code$ gcc fork

VirtualBox:-/Desktop/code$ ./a.out

Sneha 1 
Sneha 2
Sneha 3
VirtualBox:-/Desktop/codes 
Sneha 3

Sneha 2 
 Sneha 1

Sneha 3

Sneha 2

Sneha 3

Sneha 3

Sneha 3

Sneha 2

Sneha 3

Sneha 3
