#include<stdio.h>
#include<conio.h>
void main()
{
	int n,i,j,p[10],bt[10],wt[10],tat[10],s1=0,s2=0;
	float a1,a2,temp,temp1;
	printf("\nenter no of process\n");
	scanf("%d",&n);
	printf("\n enter processes\n");
	for(i=0;i<n;i++)
	{
	scanf("%d",&p[i]);
    }
	printf("\n enter each process burst time\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&bt[i]);
		
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(bt[i]<bt[j])
				{
				   temp=bt[i];
				   bt[i]=bt[j];
				   bt[j]=temp;
				   
				   temp1=p[i];
				   p[i]=p[j];
				   p[j]=temp1;	
					}
				}
			}
		 
	wt[0]=0;
	wt[1]=bt[0];
	for(i=2;i<n;i++)
	{  
		
		wt[i]=bt[i-1]+wt[i-1];
	
		
		}
		for(i=0;i<n;i++)
		{
			s1=s1+wt[i];
			}
		for(i=0;i<n;i++)
		{
			
			tat[i]=wt[i]+bt[i];
			s2=s2+tat[i];
			}
			
	printf("\n process\tB.T\tW.T\t T.A.T");
	for(i=0;i<n;i++)
	{
		printf("\n%d\t\t%d\t%d\t%d",p[i],bt[i],wt[i],tat[i]);
		
		
		}
		a1=s1/n;
		a2=s2/n;
		printf("\naverage waiting time is::%f",a1);
		printf("\n average turnaround time is::%f",a2);
		
	 
	
	
}
