#include<stdio.h>
#include<unistd.h> 
void main()
{
char p[10][5],temp[5]; 
int c=0,pt[10],i,j,n,temp1;
 float bst=0.0,turn=0.0;
printf("enter no of processes:");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("enter process%d name:\n",i+1);
scanf("%s",&p[i]); 
printf("enter process time");
scanf("%d",&pt[i]);
}
printf("\n.....................................................\n");
 for(i=0;i<n;i++)
{
printf("|\t %s\t",p[i]);
}
 printf("|\n.....................................................\n");
 for(i=0;i<n;i++)
{
printf("\t\t%d",pt[i]);
}
printf("\n.....................................................\n");
printf("0");
for(i=0;i<n;i++)
{ bst+=c;
turn+=c+pt[i]; c=c+pt[i];
printf("\t\t%d",c);
}
printf("\nAverage time is %f: ",bst/n);
 printf("\nTurn around time is %f", turn/n);
}
