 #include<stdio.h>
#include<conio.h>
void main()
{
	int m,bs,nob,n,p[10],size[10],tif,ef,i,r=0;
	printf("enter memory available\n");
	scanf("%d",&m);
	printf("enter each block size\n");
	scanf("%d",&bs);
	nob=m/bs;
	ef=m-nob*bs;
	printf("enter number of processes\n");
	scanf("%d",&n);
	printf("enter memory required\n");
	for(i=0;i<n;i++)
	{
		p[i]=i+1;
		printf("p[%d]\t",p[i]);
		scanf("%d",&size[i]);	
	}
	printf("process\tmemory\tstatus\tinternal fragmentation\n");
	for(i=0;i<n&&r<nob;i++)
	{
		printf("%d\t%d\t",p[i],size[i]);
		if(size[i]>bs)
		{
			printf("NO\t---\n");
		}
		else
		{
			printf("YES\t%d\n",bs-size[i]);
			tif=tif+bs-size[i];
			r++;
		}
		
	}
	if(i<n)
	{
		printf("memory is full we cannot accomadate remaining processes\n");
		printf("total intenal fragmentation:%d\n",tif);
		printf("total external fragmentation:%d",ef);
		
		
	}
	
}
