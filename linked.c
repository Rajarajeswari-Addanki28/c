#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node
{
    int data;
    struct node*link;
};
int main()
{
    int n,fs,i,bk,t;
    printf("enter the size");
    scanf("%d",&n);
    printf("enter the block size");
    scanf("%d",&bk);
    n=n/bk;
    t=n;
    int b[n];
     for(i=0;i<n;i++)
    {
        b[i]=1;
    }
    x:
    printf("enter the file size");
    scanf("%d",&fs);
    struct node*root=NULL;
    fs=ceil((float)fs/bk);
    while(fs)
    {
        if(t)
        {
            i=rand()%n;
            if(b[i]==1)
            {
                b[i]=0;
                struct node* temp;
                temp=(struct node*)malloc(sizeof(struct node));
                temp->data=i;
                temp->link=NULL;
                if(root==NULL)
                {
                    root=temp;
                }
                else{
                    struct node* p;
                    p=root;
                    while(p->link!=NULL)
                    {
                        p=p->link;
                    }
                    p->link=temp;
	}
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
        printf("no enough space to allocate for file");
    }
    else
    {
        printf("\nmemory allocated for file successfully\n");
        while(root!=NULL)
        {
            printf(" ||%d|%d|------>",root->data,root->link);
            root=root->link;
        }
    }
    int c;
    printf("1.continue\n2.break");
    printf("enter your choice");
    scanf("%d",&c);
    switch(c)
    {
    case 1:
        goto x;
        break;
    case 2:
        exit(0);
    }
}
