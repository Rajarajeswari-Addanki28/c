#include<stdio.h>
#include<conio.h>
struct node
{
	int data;
	int fq;
	int pri;
};
int main()
{
	int no_of_frames,no_of_pages;
	int i,flag1,flag2,j,c=0,f=0,min,pos,k;
	printf("enter number of frames\n");
	scanf("%d",&no_of_frames);
	printf("enter number of pages\n");
	scanf("%d",&no_of_pages);
	int pages[no_of_pages];
	struct node frames[no_of_frames];
	printf("enter pages\n");
	for(i=0;i<no_of_pages;i++)
	{
		scanf("%d",&pages[i]);
	}
	//initialization of frames
	for(i=0;i<no_of_frames;i++)
	{
		frames[i].data=-1;
		frames[i].fq=0;
		frames[i].pri=0;
	}
	for(i=0;i<no_of_pages;i++)
	{
		flag1=flag2=0;
		for(j=0;j<no_of_frames;j++)
		{
			if(frames[j].data==pages[i])
			{
				c++;
				frames[j].fq=frames[j].fq+1;
				frames[j].pri=c;
				flag1=1;
				break;
			}
		}
		if(flag1==0)
		{
			for(j=0;j<no_of_pages;j++)
			{
				if(frames[j].data==-1)
				{
					frames[j].data=pages[i];
					frames[j].fq=1;
					c++;
					frames[j].pri=c;
					f++;
					flag2=1;
					break;
				}
			}
			if(flag2==0)
			{
				min=frames[0].fq;
				pos=0;
				for(j=1;j<no_of_frames;j++)
				{
					if(min>frames[j].fq)
					{
						min=frames[j].fq;
						pos=j;
					}
					else if(min==frames[j].fq)
					{
						if(frames[pos].pri>frames[j].pri)
						{
							pos=j;
							
						}
					}
				}
				frames[pos].data=pages[i];
				frames[pos].fq=1;
				c++;
				frames[pos].pri=c;
				f++;
			}
		}
		for(k=0;k<no_of_frames;k++)
		{
			printf("%d\t",frames[k].data);
		}
		printf("\n");
		
	}
	printf("page faults:%d",f);
}
