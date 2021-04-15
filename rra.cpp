#include<stdio.h>
#include<stdlib.h>
int main()
{
	int pid[20],at[20],bt[20],tbt[20],tat[20],wt[20],ct[20],index[30],i,j,k,l,n,count=0,c=0,tq,temp1,temp2,temp3,ttat=0,twt=0;
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
	while(count!=n)
	{
		while(at[i]<=c+tq && i<n)
			{
				index[j]=i;
				i++;
				j++;
			}
	 if(tbt[index[l]]<=tq)
		{
			count++;
			c=c+tbt[index[l]];
			ct[index[l]]=c;
			tat[index[l]]=ct[index[l]]-at[index[l]];
			wt[index[l]]=tat[index[l]]-bt[index[l]];
		}
		else
		{
			c=c+tq;
			tbt[index[l]]=tbt[index[l]]-tq;
			index[j]=index[l];
			j++;
		}	
		l++;
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
