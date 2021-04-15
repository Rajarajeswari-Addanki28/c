  #include<stdio.h>
#include<conio.h>
void main()
{
	int n,at[10],bt[10],ct[10],tat[10],wt[10],x[10],p[10],i,time,count=0,smallest,end;
	float atat=0.0,awt=0.0;
	printf("enter total number of process\n");
	scanf("%d",&n);
	printf("enter arrival and burst time and priority\n");
	for(i=0;i<n;i++)
	{
		printf("p%d\t",i+1);
		scanf("%d\t%d\t%d",&at[i],&bt[i],&p[i]);
		x[i]=bt[i];
	}

	p[11]=10;
	for(time=0;count!=n;time++)
	{
		smallest=11;
		for(i=0;i<n;i++)
		{
			if(at[i]<=time&&p[i]<p[smallest]&&bt[i]>0)
			{
				smallest=i;
			}
		}
		bt[smallest]--;
		if(bt[smallest]==0)
		{
			count++;
  			end=time+1;
 			ct[smallest]=end;
			tat[smallest]=ct[smallest]-at[smallest];
			wt[smallest]=tat[smallest]-x[smallest];
		}
	
	}
	printf("pid\tC_TIME\tTAT\tWT\n");
	for(i=0;i<n;i++)
 	{
 			printf("%d\t%d\t%d\t%d\n",i+1,ct[i],tat[i],wt[i]);
 			awt=awt+wt[i];
 			atat=atat+tat[i];	
 	}
 	printf("averege waiting time:%.2f\n",(float)(awt/n));
 	printf("average turnaround time:%.2f\n",(float)(atat/n));
	
}
