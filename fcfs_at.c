#include<stdio.h>
#include<conio.h>
void main()
{
	int n,i,j,p[10],bt[10],wt[10],tat[10],ct[10],s1=0,s2=0,at[10];
	int min,temp,temp1,temp2;
	float a1,a2;
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
	printf("\n enter each process arrival Time\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&at[i]);
		}
	min=at[0];
	for(i=0;i<n;i++)
	   {   
			  for(j=0;j<n;j++)
			  {
					
		 	if(at[i]<at[j])
			 {  temp=at[i];
				at[i]=at[j];
				at[j]=temp;
				
				temp1=p[j];
	           p[j]=p[i];
	           p[i]=temp1;
	           
	           temp2=bt[j];
	           bt[j]=bt[i];
	           bt[i]=temp2;
			}
				
	     }
	     
	     
		
		}
			

	ct[0]=bt[0];
	for(i=1;i<n;i++)
	{
		ct[i]=ct[i-1]+bt[i];
		}
		 
	wt[0]=0;
	
	for(i=1;i<n;i++)
	{  
		
		wt[i]=ct[i-1]-at[i];
	
		
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
			
	printf("\n process\tA.t\tB.T\tW.T\t T.A.T");
	for(i=0;i<n;i++)
	{
		printf("\n%d\t\t%d\t%d\t%d\t%d",p[i],at[i],bt[i],wt[i],tat[i]);
		
		
		}
		a1=s1/n;
		a2=s2/n;
		printf("\naverage waiting time is::%f",a1);
		printf("\n average turnaround time is::%f",a2);
		
	 
	
	
}
