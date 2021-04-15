#include<stdio.h>
#include<stdlib.h>
int main()
{
	int pid[20],at[20],bt[20],time,end,tbt[20],tat[20],wt[20],ct[20],index[30],i,j,k,l=0,n,count=0,c=0,tq,temp1,temp2,temp3,ttat=0,twt=0;
	printf("enter no.of processes: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter process id: ");
		scanf("%d",&pid[i]);
		printf("enter process arrival time: ");
		scanf("%d",&at[i]);
		printf("enter process burst time: ");
		scanf("%d",&bt[i]);
	}
	printf("enter quantum time: ");
	scanf("%d",&tq);
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(at[j]<at[i])
			{
				temp1=pid[i];
				temp2=at[i];
				temp3=bt[i];
				pid[i]=pid[j];
				at[i]=at[j];
				bt[i]=bt[j];
				pid[j]=temp1;
				at[j]=temp2;
				bt[j]=temp3;
				
			}
		}
	}
	for(i=0;i<n;i++)
	{
		tbt[i]=bt[i];
	}
	i=0;j=0;
	for(time=0;count!=n;time++)
	{
		
		for(i=0;i<n;i++)
		{
			if(at[i]<=time&&bt[i]>=tq&&bt[i]>0)
			{
			  bt[i]=bt[i]-tq;	
			}
			if(bt[i]<tq&&bt[i]!=0)
		    {
				bt[i]=0;
				}
		
		if(bt[i]==0)
		{
			count++;
  			end=time+1;
 			ct[i]=end;
			tat[i]=ct[i]-at[i];
			wt[i]=tat[i]-tbt[i];
		}
}
	}
	
	for(i=0;i<n;i++)
	{
		ttat=ttat+tat[i];
		twt=twt+wt[i];
	}
	printf("\npid\tat\tbt\twt\ttat\n");
	   for(i=0;i<n;i++)
	   {
			printf("\n%d\t%d\t%d\t%d\t%d\n",pid[i],at[i],bt[i],wt[i],tat[i]);	
			}
	printf("Average turn around time is: %f\n",(float)ttat/n);
	printf("Average waiting time is: %f",(float)twt/n);

}
