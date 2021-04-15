#include<stdio.h>
#include<stdlib.h>
int main()
{
	int pid[10],at[10],bt[10],ct[10],tat[10],wt[10],tbt[10],index[30],n,i,j,ttat=0,twt=0,tq,count=0,l=0,c=0;
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
		tbt[i]=bt[i];
	}
	printf("enter time quantum: ");
	scanf("%d",&tq);
	i=0;
	j=0;
	while(count!=n)
	{
		while(at[i]<=c+tq && i<n)
		{
			index[j]=i;
			i++;
			j++;
		}
		if(bt[index[l]]<=tq)
		{
			c=c+bt[index[l]];
			count++;
			ct[index[l]]=c;
			tat[index[l]]=ct[index[l]]-at[index[l]];
			wt[index[l]]=tat[index[l]]-tbt[index[l]];	
		}
		else
		{
			c=c+tq;
			bt[index[l]]=bt[index[l]]-tq;
			index[j]=index[l];
			j++;
		}
		l++;
	}
	printf("\nPID   |    BT    |     AT    | TAT    |   WT   | CT  |");
	for(i=0;i<n;i++)
	{
		ttat=ttat+tat[i];
		twt=twt+wt[i];
		printf("\n%d   |   %d    |   %d    |    %d   |    %d   |   %d   |",pid[i],tbt[i],at[i],tat[i],wt[i],ct[i]);
	}
	printf("\nAverage turn around time is: %f",(float)ttat/n);
	printf("\nAverage waiting time is: %f",(float)twt/n);
}
