#include<stdio.h>
#include<conio.h>
struct node
{
	int data;
	int pri;
};

int main()
{
	int no_of_frames,no_of_pages;
	int pages[50];
	struct node frames[10];
	
	int i,j,k,c=0,f=0,flag1,flag2,max,pos=0;
	printf("enter no of frames\n");
	scanf("%d",&no_of_frames);
	printf("enter no of pages\n");
	scanf("%d",&no_of_pages);
	printf("enter pages\n");
	for(i=0;i<no_of_pages;i++)
	{
		scanf("%d,",&pages[i]);
	}
	for(j=0;j<no_of_frames;j++)
	{
		frames[j].data=-1;
		frames[j].pri=0;
	}
	for(i=0;i<no_of_pages;i++)
	{
		flag1=0,flag2=0;
		for(j=0;j<no_of_frames;j++)
		{
			if(pages[i]==frames[j].data)
			{
				c++;
				frames[j].pri=c;
				flag1=1;
				break;
			}
		}
		if(flag1==0)
		{
			for(k=0;k<no_of_frames;k++)
			{
				if(frames[k].data==-1)
				{
					c++;
					f=f+1;
					frames[k].data=pages[i];
					frames[k].pri=c;
					flag2=1;
					break;
				}
			}
				if(flag2==0)
				{
					max=frames[0].pri;
					for(k=1;k<no_of_frames;k++)
					{
						if(frames[k].pri>max)
						{
							max=frames[k].pri;
							pos=k;
						}
					}
				c++;
				f=f+1;
				frames[pos].data=pages[i];
				frames[pos].pri=c;
				}		
		}
		for(j=0;j<no_of_frames;j++)
	{
		printf("%d\t",frames[j].data);
	}
	printf("\n");
		
	}
	
	printf("page faults:%d",f);
}
