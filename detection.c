#include<stdio.h>
#include<conio.h>
void main()
{
	 int n,m,i,c=0;
	 printf("enter no of process,resources\n");
	 scanf("%d\n%d",&n,&m);
	 	int alloc[n][m],req[n][m],avail[m];
	 	int p[n],s[n];
	 	for(i=0;i<n;i++)
	 	{
			p[i]=-1;
				}
	  printf("enter values for allocated matrix\n");
	 for(i=0;i<n;i++)
	 {
	    for(j=0;j<m;j++)
			{
				 scanf("%d",&alloc[i][j]);
			}
	   printf("\n");	
	}
	printf(" allocated matrix::\n"); 
	  for(i=0;i<n;i++)
	 {
	   for(j=0;j<m;j++)
			{
				printf("%d\t",alloc[i][j]);
				}
				printf("\n");
			}	 
printf("enter values for request matrix\n");
 for(i=0;i<n;i++)
	 {
			for(j=0;j<m;j++)
			{
				 scanf("%d",&req[i][j]);
				}
				printf("\n");
			}	
 printf("request matrix\n");	 
	  for(i=0;i<n;i++)
	 {
			for(j=0;j<m;j++)
			{
				 printf("%d\t",req[i][j]);
				}
				printf("\n");
}
printf("enter values for available matrix\n");
            for(j=0;j<m;j++)
			{
				 scanf("%d",&avail[j]);
				}
		 printf("available matrix\n");	 
    for(j=0;j<m;j++)
			{
				 printf("%d\t",avail[j]);
				}
	     
		
		
	printf("__________________________");
	while(1)
	{  for(i=0;i<n;i++){
		  if(p[i]==1)
		  { 
				c++;
		  }
		
		}
		if(c==n)
		 printf("no deadlock");
		 printf("the " );
		  break;
		else
	
}
