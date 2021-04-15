#include<stdio.h>
#include<conio.h>
int n,nf,i,j,pos;
int queue[100];
int a[50];
int front=-1;
int rare=-1;
int insert()
{ 
      int l,m;
		if(front==-1&&rare==-1)
		{
			front=0;
			rare=0;
			queue[rare]=a[i];
			
			}
		
		 else if(front==0&&rare==nf-1)
		 {     
				   for(l=0;l<rare;l++)
				   {    
						queue[l]=queue[l+1];
						
					
						 
						}
						queue[rare]=a[i];
				
				}
		else 
		{
			rare++;
			queue[rare]=a[i];
			
			}
			
		
		
	
	 
	}
insertn()
{
	 int k,x,y;   
  
     for(k=pos;k<rare;k++)
      
    {  
        
		  queue[k]=queue[k+1];
		  
		  
			}
		queue[rare]=a[i];
		

}
display()
{   int d; 
	for(d=front;d<=rare;d++)
	{
		printf("%d",queue[d]);
		}
	
}
void main()
{
	int hit=0,count=0;
	printf("enter page frames");
	scanf("%d",&nf);
	printf("enter number of page requests");
	scanf("%d",&n);
	for(j=0;j<n;j++)
	{
		scanf("%d",&a[j]);
		
		}
      for(i=0;i<n;i++)
      {
			for(j=front;j<=rare;j++)
			{
				if(queue[j]==a[i])
				{
					hit=1;
					pos=j;
			
					break;
					}
			
		}
		if(hit==1)
		{
			insertn();
			
			}
		else
		{   
			insert();
			count++;
		
			}
				
			
			}
			printf("page faults is %d\n",count);
			display();
      
      
   
}


