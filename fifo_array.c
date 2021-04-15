#include<stdio.h>
#include<conio.h>
int main()
{
	
	int i,j,a[50],frame[10],n,nf,k,hit,count=0;
	printf("enter no.of elements");
	scanf("%d",&n);
	printf("enter elements");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		}
	printf("enter no.of frames");
	scanf("%d",&nf);
	for(i=0;i<nf;i++)
	{
		frame[i]=-1;
		}
	j=0;
	printf("page frames\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t\t",a[i]);
		hit=0;
		for(k=0;k<nf;k++)
		  {
				if(frame[k]==a[i])
				{
					
		    hit=1;
			}
		}
		if(hit==0)
		{
			frame[j]=a[i];
			j=(j+1)%nf;
			count++;
			
		}
		for(k=0;k<nf;k++)
			 {
					printf("%d\t",frame[k]);
			}
			
		printf("\n");
			
		}
	 printf("page faults is %d",count);
	 return 0;
}
