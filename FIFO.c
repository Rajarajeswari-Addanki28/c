#include<stdio.h>
#include<conio.h>
int n,nf,i;
int queue[100];
int a[50];
int front=-1;
int rare=-1;

int pghit=0,pgfault=0;
void insert()
{
	if(front==0 && rare==nf-1)
	{
		rare=0;
		queue[front]=a[i];
		++front;
		
		}
		else if(front==rare+1)
		{
			queue[++rare]=a[i];
			front++;
			}
	
	else if(front==-1&&rare==-1)
			{   front=rare=0;
				queue[rare]=a[i];
				
				}
				
			else if(rare==nf-1)
			{
				rare=0;
				queue[rare]=a[i];
				
				}
			else
			{  
				queue[++rare]=a[i];
				
				
			
			}
			
}


void display()
{    int j;
	if(front<=rare)
   {
			for(j=front;j<=rare;j++)
		{
			printf("\n%d\n",queue[j]);
		}
	}
   else
	{
			for(j=front;j<=nf-1;j++)
			{
				printf("\n%d\n",queue[j]);
				}
			for(j=0;j<=rare;j++)
			{
			  printf("\n%d\n",queue[j]);	
				}
			}
	
}
int isit(int ele)
{
	int hit=0,j=0;
	for(j=0;j<nf;j++)
	{
		if(queue[j]==ele)
		{ 
		  hit=1;
		  break;	
			}
   
		}
		  return hit;
}







void main()
{
	int j=0;
	printf("enter page frames");
	scanf("%d",&nf);
	printf("enter number of page requests");
	scanf("%d",&n);
	for(j=0;j<n;j++)
	{
		scanf("%d",&a[j]);
		
		}
			for(i=0;i<n;i++)
	{    printf("\n for %d",a[i]);
	    if( isit(a[i])==0)
	    {  
			 pgfault++;
			insert();
			
			}
			else
			{
			  pghit++;	
				}
			display();
			
		}	
		printf("pagefaults is %d",pgfault);
		printf("page hits is %d",pghit);
		
   
}


