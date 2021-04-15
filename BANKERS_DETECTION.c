#include<stdio.h>
#include<conio.h>
void main(){
	int i,j,n,m,all[20][20],max[20][20],req[20][20],avail[20],x,flag1,k,re;
	char ch;
	
	printf("enter no.of process");
	scanf("%d",&n);
	printf("enter no.of.resources");
	scanf("%d",&m);
	for(i=0;i<m;i++){
	scanf("%d",&avail[i]);
}
	for(i=0;i<n;i++)
	{
	      for(j=0;j<m;j++)
	      {
				printf("enter no.of %d resorces alloted for process[%d]",j,i);
				scanf("%d",&all[i][j]);
				printf("enter no.of resource %d  requested for process[%d]",j,i);
				scanf("%d",&req[i][j]);
			}
	}
	do{
	  int flag=0,requ;
	  printf("enter u r requestig process id");
	  scanf("%d",&requ);
	
		for(j=0;j<m;j++)
		{
			
		  if(req[requ][j]<=avail[j])
		   flag=1;
		   
		   else{
			  for(k=0;k<m;k++)
			  avail[j]=all[i][k];	
		      break;
			}	
		}  
     if(flag==1)
     {
			for(j=0;j<m;j++){
			avail[j]=avail[j]-req[requ][j];
			avail[j]=all[requ][j]+req[requ][j];
			}
	}
		printf("%d-->",requ);
		//int re;
	  	printf("enter  1 if any request");
	  	scanf("%d",&re);	
	  	}while(re==1);
}

