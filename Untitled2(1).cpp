#include<stdio.h>
#include<conio.h>
int main()
{
	int n,m,i,j;
	printf("emter no of process and resources\n");
	scanf("%d\n%d",&n,&m);
	int alloc[n][m];
	printf("enter allocation matrix\n");
	for(i=0;i<n;i++)
     {
			for(j=0;j<m;j++)
			{
				scanf("%d\n",&alloc[i][j]);
				
				}
			}
}
