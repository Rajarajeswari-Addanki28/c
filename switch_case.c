#include<stdio.h>
#include<conio.h>
void FIFO();
void LRU();
void OPTIMAL();
int n,nf,i,j,pos;
int queue[100];
int a[50];
int front=-1;
int rare=-1;
int insert();
int insertn();
void display();
void main()
{
	int op;
	printf("\nselect one page replacement algorithm\n");
	printf("1.FIFO\n");
	printf("2.LRU\n");
	printf("3.OPTIMAL\n");
	do
	{
	printf("\n enter your option\n");
	scanf("%d",&op);
		switch(op)
		{
			case 1:
				 FIFO();
				 break;
		    case 2:
				 LRU();
				 break;
			case 3:
				OPTIMAL();
				break;
			default:
				printf("Invalid option\n");
				break;
				
				
	   }
   }while(op<4);
}
void FIFO()
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
					
		    hit=1;}
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


void LRU()
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
		{   count++;
			insert();
		
			}
				
			
			}
			display();
      printf("page faults is %d",count);
	}
int insert()
{ 
      int l;
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
	 int k;   
  
     for(k=pos;k<rare;k++)
     {
		  queue[k]=queue[k+1];
			}
			queue[rare]=a[i];
		

}
void display()
{   int d; 
	for(d=front;d<=rare;d++)
	{
		printf("%d",queue[d]);
		}
	
}



void OPTIMAL()
{
    int no_of_frames, no_of_pages, frames[10], pages[30], temp[10], flag1, flag2, flag3, i, j, k, pos, max, faults = 0;
    printf("Enter number of frames: ");
    scanf("%d", &no_of_frames);
    
    printf("Enter number of pages: ");
    scanf("%d", &no_of_pages);
    
    printf("Enter page reference string: ");
    
    for(i = 0; i < no_of_pages; i++){
        scanf("%d", &pages[i]);
    }
    
    for(i = 0; i < no_of_frames; i++){
        frames[i] = -1;
    }
    
    for(i = 0; i < no_of_pages; i++){
        flag1 = flag2 = 0;
        
        for(j = 0; j < no_of_frames; j++){
            if(frames[j] == pages[i]){
                   flag1 = flag2 = 1;
                   break;
               }
        }
        
        if(flag1 == 0){
            for(j = 0; j < no_of_frames; j++){
                if(frames[j] == -1){
                    faults++;
                    frames[j] = pages[i];
                    flag2 = 1;
                    break;
                }
            }    
        }
        
        if(flag2 == 0){
        	flag3 =0;
        	
            for(j = 0; j < no_of_frames; j++){
            	temp[j] = -1;
            	
            	for(k = i + 1; k < no_of_pages; k++){
            		if(frames[j] == pages[k]){
            			temp[j] = k;
            			break;
            		}
            	}
            }
            
            for(j = 0; j < no_of_frames; j++){
            	if(temp[j] == -1){
            		pos = j;
            		flag3 = 1;
            		break;
            	}
            }
            
            if(flag3 ==0){
            	max = temp[0];
            	pos = 0;
            	
            	for(j = 1; j < no_of_frames; j++){
            		if(temp[j] > max){
            			max = temp[j];
            			pos = j;
            		}
            	}            	
            }
			
			frames[pos] = pages[i];
			faults++;
        }
        
        printf("\n");
        
        for(j = 0; j < no_of_frames; j++){
            printf("%d\t", frames[j]);
        }
    }
    
    printf("\n\nTotal Page Faults = %d", faults);
    
   
}
      
   



