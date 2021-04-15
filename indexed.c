#include<stdio.h>
#include<math.h>
int main()
{
    int n,f,i,t,j,k,fs,in;
    printf("enter the size");
    scanf("%d",&n);
    t=n;
    int b[n];
    for(i=0;i<n;i++)
    {
        b[i]=0;
    }
    printf("enter the no.of files ");
    scanf("%d",&f);
    int ia[f];
    for(i=1;i<=f;i++)
    {
        printf("enter the file size");
        scanf("%d",&fs);
        int d[fs];
        in=0;
        while(t)
        {
            j=rand()%n;
            if(!b[j])
            {
                b[j]=1;
                ia[i]=j;
                t--;
                break;
            }
        }
        while(fs)
        {
            if(t)
            {
                j=rand()%n;
                if(!b[j])
                {
                    b[j]=1;
                    d[in]=j;
                    in++;
                    fs--;
                    t--;
                }
            }
            else
            {
                break;
            }
        }
        if(fs)
        {
            printf("memory is not allocated successfully");
        }
        else
        {
            printf("memory is allocated successfully\n");
            printf("file no %d\n",i);
            for(k=0;k<in;k++)
            {
                printf("%d\t",d[k]);
            }
            printf("\n");
        }
    }
    printf("\nfile no\tindex\n");
    for(i=1;i<=f;i++)
    {
        printf("%d\t%d\n",i,ia[i]);
    }
}
