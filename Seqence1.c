#include<stdio.h>
#include<conio.h>

int main()
{ int i,st,l,k,j,x,ds;
	printf("\nEnter the disk size");
	scanf("%d",&ds);
	int f[ds];
	for(i=0;i<ds;i++)//intially allocating all the blocks with 0;
		f[i]=0;
	while(1)
	{
	
	int c=0;
	printf("\nenter the starting block and length of file");
	scanf("%d%d",&st,&l);
	if((st+l)>ds) 
		printf("\nInsufficent memory");
	else{
			for(k=st;k<(st+l);k++)
				{
					if(f[k]==0)
					{
					
					c++;
					}
				}
			if(c==l)//if length of the file equal to the c then file is allocated
				{	printf("\nThe alloated blocks for this file");
					for(k=st;k<(st+l);k++)
						{
						f[k]=1;
						printf("\n%d\n",k);
				}
				}
			else
				printf("\nThe file is not allocated\n");
		
	}
	printf("do you want to continue (yes=1 a/no=0)");
	scanf("%d",&x);
	if(x==0)
		break;
}

	
}
