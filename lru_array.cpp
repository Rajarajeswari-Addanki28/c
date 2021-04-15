#include<stdio.h>
struct frames
{
	int pno;
	int counter;
}frames[30];
int ref_string[30], np,n,i,j,currtime;
int pagefound(int pno)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(frames[i].pno==pno)
		{
			return i;
		}
		return -1;
	}
}
int get_lru()
{
	int min=0;
	for(i=0;i<n;i++)
	{
		if((frames[i].counter)<(frames[min].counter))
		{
			min=i;
		}
	}
	return min;
}
int main()
{
	int i,j,pno,p,faults=0,flag;
	printf("Enter the no.of page requests : ");
	scanf("%d",&np);
	for(i=0;i<np;i++)
    {
        printf("ref_string[%d] : ",i+1);
        scanf("%d",&ref_string[i]);
    }
	printf("Enter the no.of frames:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		frames[i].pno=-1;
		frames[i].counter=-1;
	}
	printf("\npageno\t\tframes");
	currtime=1;
	for(p=0;p<np;p++)
	{
		flag=0;
		pno=ref_string[p];
		j=pagefound(pno);
		if(j==-1)
		{
			faults++;
			j=get_lru();
			frames[j].pno=pno;
			flag=1;
		}
		frames[j].counter=currtime;
		currtime++;
		printf("\n%d\t",pno);
		for(i=0;i<n;i++)
		{
			printf("%d\t",frames[i].pno);
		}
	}
	printf("\nNo.of page faults : %d",faults);
	return 0;
}
