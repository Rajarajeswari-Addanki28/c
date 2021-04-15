#include<stdio.h>
#include<conio.h>
int memory[100],sizes[100];
void ff(int,int,int);
void bf(int,int,int);
void wf(int,int,int);
int m,temp;
void main()
{

	int ch=1,f;
	int mp,i;
	printf("enter total memory available\n");
	scanf("%d",&m);
	temp=m;
	int j=0;
	for(i=0;ch==1;i++)
	{
		printf("enter memory required for p%d\t",i+1);
		scanf("%d",&mp);
		if(mp<=temp)
		{
			printf("memory is allocated to p%d\n",i+1);
			temp=temp-mp;
			memory[j]=i+1;
			sizes[j]=mp;
			j++;
		}
		else
		{
			
			printf("memoery is full\n");
			printf("pid\tallocatd size\n");
			for(i=0;i<j;i++)
			{
			 printf("%d\t%d\n",memory[i],sizes[i]);
			}
			printf("external fragentation:%d",temp);
			printf("1.first fit\t2.best fit\t3.worst fir\n");
			printf("enter your choice\n");
			scanf("%d",&f);
			if(f==1)
				ff(mp,j,i+1);
			else if(f==2)
				bf(mp,j,i+1);
			else if(f==3)
				wf(mp,j,i+1);
		
			printf("after performing first fit\n");
			break;
		}
		printf("continue?");
		scanf("%d",&ch);
	
	}
	printf("pid\tallocatd size\n");
	
	for(i=0;i<j;i++)
	{
		printf("%d\t%d\n",memory[i],sizes[i]);
	}
	printf("external fragentation:%d",temp);			
}
void ff(int s,int p, int n)
{
	int flag=0,i,val;
	for(i=0;i<p;i++)
	{
		if(s<=sizes[i])
		{
			val=sizes[i]-s;
			sizes[i]=s;
			memory[i]=n;
			flag=1;
			temp=temp+val;
			break;
		}	
	}
	if(flag==0)
	{
		printf("we cannot accomadate this process\n");
	}
}
void bf(int s,int p,int n)
{
	int flag=0,i,val,pos=-1;
	int min=m;
	for(i=0;i<p;i++)
	{
		if(min>sizes[i]&&s<=sizes[i])
		{
			min=sizes[i];
			pos=i;
		}
	}
	if(pos!=-1)
	{
			val=sizes[pos]-s;
			sizes[pos]=s;
			memory[pos]=n;
			
			temp=temp+val;
			
		
	}
	else
	{
		printf("we cannot accomadate the process:%d",n);
	}
}
void wf(int s,int p,int n)
{
	int flag=0,i,val,pos=-1;
	int max=0;
	for(i=0;i<p;i++)
	{
		if(max<sizes[i]&&s<=sizes[i])
		{
			max=sizes[i];
			pos=i;
		}
	}
	if(pos!=-1)
	{
			val=sizes[pos]-s;
			sizes[pos]=s;
			memory[pos]=n;
			
			temp=temp+val;
			
		
	}
	else
	{
		printf("we cannot accomadate the process:%d",n);
	}
}
