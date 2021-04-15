#include<stdio.h>
#define MAX 15
int i,j,n,total_time=0;
float avgtat=0.0,avgwt=0.0;
int queue[MAX];
int time=0,front=0,rear=0,q_count=0,tempt;
struct data
{
    int at,bt,ct,tat,wt;
};
void display(struct data a[])
{
    for(i=0;i<n;i++)
    {
        a[i].tat = a[i].ct - a[i].at;
        a[i].wt = a[i].tat - a[i].bt;
    }
    for(i=0;i<n;i++)
    {
        avgtat=avgtat+a[i].tat;
        avgwt=avgwt+a[i].wt;
    }
   /* avgtat = avgtat/n;
    avgwt = avgwt/n;*/
    printf("\n-------------------------------------------\n");
    printf("PNO\t AT\t BT\t CT\t TAT\t WT\n");
    for(i=0;i<n;i++)
    {
        printf("p%d\t %d\t %d\t %d\t %d\t %d\n",i+1,a[i].at,a[i].bt,a[i].ct,a[i].tat,a[i].wt);
    }
    printf("----------------------------------------------\n");
    printf("Sum of Waiting time : %.2f\n",avgwt);
    printf("Sum of Turnaround time : %.2f\n",avgtat);
    printf("Average Waiting time : %.2f\n",avgwt/n);
    printf("Average Turnaround time : %.2f\n",avgtat/n);
}
void push(int q)
{
    queue[rear++]=q;
}
int pop()
{
    int x;
    x=queue[front++];
    return x;
}
void check(struct data a[])
{
    while(a[j].at<=time && j<n)
    {
        q_count++;
        push(j++);
    }
}
void finding(struct data a[] )
{
    int temp_bt[n],flag=0,count=0,p_process;
    j=0;
    int tq;
    printf("Enter the time quantum : ");
    scanf("%d",&tq);
    for(i=0;i<n;i++)
    {
        temp_bt[i]=a[i].bt;
    }
    time = a[0].at;
    q_count=1;
    push(j++);
    while(time<=total_time)
    {
        if(flag==1||q_count!=0)
        {
            if(flag==0 && count==0)
            {
                p_process=pop();
                count=0;
                flag=1;
            }
            temp_bt[p_process]--;
            if(temp_bt[p_process]==0)
            {
                time++;
                count=0;
                a[p_process].ct = time;
                flag=0;
                q_count--;
                check(a);
                continue;
            }
            count++;
            if(count==tq)
            {
                count=0;
                time++;
                check(a);
                push(p_process);
                flag=0;
            }
            else
            {
                time++;
                check(a);
            }
        }
        else
        {
            time++;
            check(a);
        }
    }
    display(a);
}
int main()
{
    printf("Enter the no.of processes : ");
    scanf("%d",&n);
    struct data temp[n];
    for(i=0;i<n;i++)
    {
        printf("Arr_time[%d] : ",i+1);
        scanf("%d",&temp[i].at);
    }
    for(i=0;i<n;i++)
    {
        printf("Burst_time[%d] : ",i+1);
        scanf("%d",&temp[i].bt);
    }
    for(i=0;i<n;i++)
    {
        for(j=i;j>=1;j--)
        {
            if(temp[j].at<temp[j-1].at)
            {
                tempt = temp[j-1].at;
                temp[j-1].at= temp[j].at;
                temp[j].at = tempt;

                tempt = temp[j-1].bt;
                temp[j-1].bt= temp[j].bt;
                temp[j].bt = tempt;
            }
        }
    }
    total_time+=temp[0].at+temp[i].bt;
    for(i=1;i<n;i++)
    {
        if(temp[i].at>total_time)
        {
            total_time=temp[i].at;
            total_time+=temp[i].bt;
        }
    }
    finding(temp);
    return 0;
}
