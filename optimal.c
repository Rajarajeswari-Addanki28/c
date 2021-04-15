#include<stdio.h>
#include<conio.h>
void main()
{
   int i,j,k,l,m,n,p,c=0,s;
   int a[100],b[100],q,max;
   printf("enter no of reference: ");
   scanf("%d",&n);
   printf("enter size of frame");
   scanf("%d",&m);
   printf("enter the elements");
   for(i=0;i<n;i++)
     scanf("%d",&a[i]);
    
   for(j=0;j<m;j++)
     b[j]=-1;
   
   for(i=0;i<n;i++)
   {
		for(k=0;k<m;k++)
		{
			if(b[k]==a[i])
			{
				goto here;
				
				}
			
			}
		for(j=0;j<m;j++)
		{
			if(b[j]==-1)
			{
				b[j]=a[i];
				c++;
				goto here;
				}
			
			}
		if(j==m)
		{
			
			l=i+1,max=0;
			 for(j=0;j<m;j++)
			 {
					for(s=l;s<n;s++)
					{
						if(a[s]==b[j])
						{
							if(s>max)
							{
								max=s;
								p=j;
								
								}
								break;
							
							
							}
					}
					if(s==n)
					{
						max=s;
						p=j;
						
						}
					
					}
			}
			
	here:printf("\n\n");
	for(k=0;k<m;k++);
	  printf("%d",b[k]);
		 
		 
		 }
		  printf("\n No of page fault is :%d",c);
}
