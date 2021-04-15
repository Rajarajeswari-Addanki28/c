#include<stdio.h>
#include<conio.h>
void main()
{
	 int n,m,i,r,e,h,l=0,j,f=0,g=0,c=0;
	 printf("enter no of process,resources\n");
	 scanf("%d\n%d",&n,&m);
	 	int alloc[n][m],max[n][m],avail[m],need[n][m],req[m];
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
     printf("enter values for max matrix\n");
     for(i=0;i<n;i++)
	 {
			for(j=0;j<m;j++)
			{
				 scanf("%d",&max[i][j]);
			}
				printf("\n");
	 }	
     printf("max matrix\n");	 
	 for(i=0;i<n;i++)
	 {
			for(j=0;j<m;j++)
			{
				printf("%d\t",max[i][j]);
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
	 printf("\nneed matrix\n");	 
     for(i=0;i<n;i++)
	{
	  for(j=0;j<m;j++)
	{      
		need[i][j]=max[i][j]-alloc[i][j];
		printf("%d\t",need[i][j]);
	}
		printf("\n");
	}
	printf("----------------------\n");	
		         printf("1.requst \n2.exit\n ");
				 while(1)
				 {	printf("\nenter your choice\n");
				    scanf("%d",&h);
				    if(h==2)
				        break;
						
		        printf("\n which process requesting\n");
		        scanf("%d",&r);
		        printf("\n enter instances\n");
		        for(j=0;j<m;j++)
                     scanf("%d",&req[j]);		        
		          e=0;
		        for(j=0;j<m;j++)
		        {    
					if(req[j]<=need[r][j]&&req[j]<=avail[j])
					 {
						e++;
				    }
				}
			if(e!=m)
			    printf("\n request rejected\n");
			else
			{
				for(j=0;j<m;j++)
				{
				alloc[r][j]=alloc[r][j]+req[j];
				need[r][j]=need[r][j]-req[j];
				avail[j]=avail[j]-req[j];
				}
	    while(1)
		{
		 c++;				
	    for(i=0;i<n;i++)
	    {   int k=0;
			if(p[i]==-1)
			{
			
			 for(j=0;j<m;j++)
			 {
				if(need[i][j]<=avail[j])
				  {
						k++;
				}
				else
			        break;	
					}
		if(k==m)
		  {   
				for(j=0;j<m;j++)
				{
				avail[j]=avail[j]-need[i][j];
				avail[j]=avail[j]+max[i][j];
			
			    }
			    p[i]=1;
			     s[l]=i;
			     l++;
		}				
	}
}
        for(i=0;i<n;i++)
		{
			if(p[i]==-1)
			 {
				f++;	
			}
			}
			if(f==n)
			{
				printf("ifdeadlock");
				break;
				}
				if(c==m)
				{
					 for(i=0;i<n;i++)
		           {
			            if(p[i]==-1)
			             {
							g=1	;
					     }
					}
			         if(g==1)
			          { printf("deadlock");
			             break;
						}
			       else
			       {
				   printf("sequence");
						
							for(i=0;i<n;i++)
							{    
								printf("%d,",s[i]);
								}
						}
				if(l==n)
                 {
		             break;
		          }
}
   
}
}
}
}

		
	
	
	
