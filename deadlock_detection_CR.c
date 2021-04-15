#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void detect(int avail[],int allocate[5][3],int request[5][3],int p,int r)
{
	int finish[p],work[r],i,j,k,sum;
	for(i=0;i<r;i++)
	{
		work[i]=avail[i];
	}
	for(i=0;i<p;i++)
	{
		sum=0;
		for(j=0;j<r;j++)
		{
			sum=sum+allocate[i][j];
		}
		if(sum==0)
		{
			finish[i]=1;
		}
		else
			finish[i]=0;
	}
	for(k=0;k<p;k++)
	{
	
	for(i=0;i<p;i++)
	{
		if(finish[i]==0)
		{
				int flag=0;
			for(j=0;j<r;j++)
			{
				
					if(request[i][j]>work[j])
					{
						flag=1;
						break;
					}		
			}
				if(flag==0)
					{
						for(j=0;j<r;j++)
						{
							allocate[i][j]=allocate[i][j]+request[i][j];
							work[j]=work[j]+allocate[i][j];
							finish[i]=1;
						}
						
					}
		}
	}
	}	
		int count=0;
		for(i=0;i<p;i++)
		{
			if(finish[i]==1)
			{
				count++;
			}
		}
		if(count==p)
		{
			printf("system is in safe state\n");
		}
		else
		{
			printf("deadlock");
		}
	
	
}
int main()
{
	int p,r,i,j;
	printf("enter number of resources\n");
	scanf("%d",&r);
	printf("enter number of processes\n");
	scanf("%d",&p);
	int avail[r],allocate[p][r],request[p][r];
	printf("enter available vector");
	for(i=0;i<r;i++)
	{
		scanf("%d",&avail[i]);
	}
	printf("enter allocation matrix\n");
	for(i=0;i<p;i++)
	{
		for(j=0;j<r;j++)
		{
			scanf("%d",&allocate[i][j]);
		}
	}
	printf("enter request matrix\n");
	for(i=0;i<p;i++)
	{
		for(j=0;j<r;j++)
		{
			scanf("%d",&request[i][j]);
		}
	}
	detect(avail,allocate,request,p,r);
	int ch,n,request2[r];
	printf("1.request\n2.exit\n");
	printf("enter choice\n");
	scanf("%d",&ch);
	if(ch==1)
	{
		printf("enter process number\n");
		scanf("%d",&n);
		printf("enter request vector\n");
		for(i=0;i<r;i++)
		{
			scanf("%d",&request2[i]);
		}
		for(i=0;i<r;i++)
		{
			request[n][i]+=request2[i];
		}
			detect(avail,allocate,request,p,r);
	}
	else
	{
		exit(0);
	}

}

