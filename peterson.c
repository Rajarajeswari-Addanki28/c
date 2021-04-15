#include<stdio.h>
#include<conio.h>
int turn,x;
int  flag[2]={0,0};
int main()
{
     int i,j,n;
     printf("enter which process do you want you execute 0 or 1");
     scanf("%d",&n);
     if(n==0)
           goto p0;
     else 
          goto p1;
     p0:
			i=0;
			j=1;
			flag[i]=1;
	p0_start:
		turn=j;
		printf("p0::\n");
		while(flag[j]&&turn==j)
		{
			printf("#p0 in waiting state\n");
		
		   goto p1;
		   	
			}
			printf("#p0 critical section\n");
			  x=5;
			 flag[i]=0;
			
    
     p1:
			i=1;
			j=0;
			flag[i]=1;
	p1_start:
		turn=j;
		printf("#p1::\n");
		while(flag[j]&&turn==j)
		{  printf("#p1 is waiting state");
		   goto p0;
		   	
			}
				printf("#p1 critical section\n");
			 x=5;
			 flag[i]=0;
			 
			 return 0;
			
}
