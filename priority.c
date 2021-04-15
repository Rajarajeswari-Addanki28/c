#include<stdio.h>
#include<conio.h>
void main()
{
	int n,i,j,p[10],bt[10],wt[10],tat[10],ct[10],s1=0,s2=0,pr[10];
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
	printf("\n enter each process priorities\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&pr[i]);
		}
	
	for(i=0;i<n;i++)
	   {   
			  for(j=0;j<n;j++)
			  {
					
		 	if(pr[i]<pr[j])
			 {  temp=pr[i];
				pr[i]=pr[j];
				pr[j]=temp;
				
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
		
			for(i=0;i<n;i++)
		{
			
			tat[i]=ct[i-1]+bt[i];
			s2=s2+tat[i];
			} 
	wt[0]=0;
	
	for(i=1;i<n;i++)
	{  
		
		wt[i]=ct[i-1];
	
		
		}
		for(i=0;i<n;i++)
		{
			s1=s1+wt[i];
			}
	
			
	printf("\n process\tpri\tB.T\tW.T\t T.A.T\tCT");
	for(i=0;i<n;i++)
	{
		printf("\n%d\t\t%d\t%d\t%d\t%d\t%d",p[i],pr[i],bt[i],wt[i],tat[i],ct[i]);
		
		
		}
		a1=s1/n;
		a2=s2/n;
		printf("\naverage waiting time is::%f",a1);
		printf("\n average turnaround time is::%f",a2);
		
	 
	
	
}
