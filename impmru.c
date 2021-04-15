#include<stdio.h>
void main()
{
  int n,m,b[n],d[n],i,j,k=0,x=0,s,l,a;
  	int max=0;
   printf("enter page frames");
   scanf("%d",&n);
   printf("enter page references");
   scanf("%d",&m);
   for(i=0;i<n;i++)
   {
		b[i]=d[i]=-1;
		}
		for(i=0;i<m;i++)
		{
			printf("next reference");
			scanf("%d",&s);
				int c=0;
				for(j=0;j<n;j++)
				{
					if(b[j]==s)
					{
						printf("\thit\n");
					c++;
					break;
				     }
					}
					if(c==0)
					{
					if(k<n)
						{
							if(b[k]==-1)
							{
								b[k]=s;
								x++;
								d[k]=x;
								k++;
								printf("\tmiss with space\n");
							  }
							}
						      else{
									for(l=0;l<n;l++)
							{
								if(d[max]<d[l])
								     max=l;
								}
								b[max]=s;
								x++;
								d[max]=x;
								printf("\tmiss with no space\n");
								}
							}
					      else{
								x++;
								d[j]=x;
								}
					for(a=0;a<n;a++)
			printf("%d\n",b[a]);
		}
		}
	



