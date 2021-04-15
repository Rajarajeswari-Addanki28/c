#include<stdio.h>
#include<conio.h>
void main()
{
	int process[10],bt[10],n,tat[10],wt[10],at[10],ct[10],rt[10],i,j,temp,temp2,temp3,val,min,pos,k;
	float awt=0.0,atat=0.0;
	printf("enter total number of process\n");
	scanf("%d",&n);
	printf("enter arrival time and  burst time\n");
	for(i=0;i<n;i++)
	{
		process[i]=i+1;
		printf("p%d\t",process[i]);
		scanf("%d\t%d",&at[i],&bt[i]); 
	}
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(at[i]>at[j])
			{
						temp=process[i];
						process[i]=process[j];
						process[j]=temp;
				
						temp2=bt[i];
						bt[i]=bt[j];
						bt[j]=temp2;
				
						temp3=at[i];
						at[i]=at[j];
						at[j]=temp3;
				
			}
			if(at[i]==at[j])
			{
				if(bt[i]>bt[j])
				{
					temp=process[i];
						process[i]=process[j];
						process[j]=temp;
				
						temp2=bt[i];
						bt[i]=bt[j];
						bt[j]=temp2;
				
						temp3=at[i];
						at[i]=at[j];
						at[j]=temp3;
				}
			}
		}
	}
	
	ct[0]=bt[0]+at[0];
	tat[0]=ct[0]-at[0];
	wt[0]=tat[0]-bt[0];
	rt[0]=0;
	for(i=1;i<n;i++)
	{
		if(at[i]<=ct[i-1])
		{
			min=bt[i];
			pos=i;
			}	
		for(k=i+1;k<n;k++)
		{
			if(at[k]<=ct[i-1])
			{
				if(min>bt[k])
				{
					min=bt[k];
					pos=k;
				}
			}
		}
			if(pos!=i)
			{
						temp=process[i];
						process[i]=process[pos];
						process[pos]=temp;
				
						temp2=bt[i];
						bt[i]=bt[pos];
						bt[pos]=temp2;
				
						temp3=at[i];
						at[i]=at[pos];
						at[pos]=temp3;
			
			}
		
			
	
		if(at[i]<=ct[i-1])
		{
			
			ct[i]=ct[i-1]+bt[i];
			tat[i]=ct[i]-at[i];
			wt[i]=tat[i]-bt[i];
			rt[i]=ct[i-1]-at[i];
		}
		else
		{
			val=at[i]-ct[i-1];
			ct[i]=ct[i-1]+bt[i]+val;
			tat[i]=ct[i]-at[i];
			wt[i]=tat[i]-bt[i];
			rt[i]=ct[i-1]-at[i];
		}
	}
	printf("pid\tA_TIME\tB_TIME\tC_TIME\tTAT\tWT\tRT\n");
	
		for(i=0;i<n;i++)
		{
			printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",process[i],at[i],bt[i],ct[i],tat[i],wt[i],rt[i]);
			atat=atat+tat[i];
			awt=awt+wt[i];
			
		}
		printf("average waiting time:%.2f",(float)(awt/n));
		printf("\naverage turnaround time:%.2f",(float)(atat/n));
	
}
