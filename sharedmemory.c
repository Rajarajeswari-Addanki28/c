#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define BUFFER_SIZE 5
int buffer[BUFFER_SIZE];
int in=0;
int out=0;
int counter=0;
void producer();
void consumer();
int main()
{
	int n;
	printf("\n1.producer\n2.consumer\n3.Exit");
	while(1)
	{
		printf("\nenter your choice");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
					producer();
					break;
			case 2:
				
					consumer();
					break;
			case 3:
					exit(0);
					break;
		}
	}
	
}
void producer()
{
	int val;
	if(counter==BUFFER_SIZE)
		printf("buffer is full\n");
	else
	{
		printf("enter next produce item\n");
		scanf("%d",&val);
		buffer[in]=val;
		in=(in+1)%BUFFER_SIZE;
		counter++;
	}
}
void consumer()
{
	if(counter==0)
		printf("buffer is empty\n");
	else
	{
		printf("consumed item:%d\n",buffer[out]);
		out=(out+1)%BUFFER_SIZE;
		counter--;
	}
}
