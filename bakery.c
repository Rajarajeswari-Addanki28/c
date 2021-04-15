#include<stdio.h>
#include<conio.h>
void main()
{
	int n,i,j,temp,l=1,k=100,flag=0;
	printf("enter no of process\n");
	scanf("%d",&n);
	int p[n],a[n],id[n],e[n],pid[n];
	for(i=0;i<n;i++)
	{
	
		printf("enter arrival time of p%d",i+1);
		scanf("%d",&a[i]);
		}
		for(i=0;i<n;i++)
		{
				p[i]=1;
		pid[i]=k;
		k++;
			}
    
    for(i=0;i<n;i++)
    {
		for(j=0;j<n;j++)
		{
			if(a[j]>a[i])
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
				
				temp=pid[i];
				pid[i]=pid[j];
				pid[j]=temp;
				
				
				}
			}
		}
		
		for(i=1;i<=n;i++)
		
		{
			if(i-1==n)
			{
				id[i-1]=l;
				break;
				}
		else if(a[i-1]==a[i])
		{
		  id[i]=id[i-1]=l;
		  i++;
		  l++;	
		}
		else
		{
		  id[i-1]=l;
		  l++;
		}
}
for(i=0;i<n;i++)
{
		printf("\n p%d arrival time = %d,id=%d",i,a[i],id[i]);
}
		for(i=1;i<=n;i++)
		{
			if(i==n)
			{
				e[i-1]=pid[i-1];
				}
				
		if(p[i-1]!=0&&id[i-1]<id[i])
		{
			e[i-1]=pid[i-1];
			
			}
			if(id[i]==id[i-1])
			{
				printf("\n**two process have same id\n");
				flag=1;
				break;
				}
			}
		if(flag==0)
		{  printf("\nexecution\n");
			for(i=0;i<n;i++)
			   printf("%d\n",e[i]);
			    
			}

}
	
		
			

	
		
			

