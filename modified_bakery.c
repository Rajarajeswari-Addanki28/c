#include<stdio.h>
#include<stdlib.h>
struct bakery{
    int process;
    int token_num;
};
int critical_section(int x){
     return --x;
}
int main(){
    int n,i,pid,j,temp;
    static int count=0,x=10;
    printf("\n enter the no.of process: ");
    scanf("%d",&n);
    struct bakery b[n];
    for(i=0;i<n;i++){
        b[i].token_num=rand()%n+1;
    }
    printf("\nprocess\t token_no");
    for(i=0;i<n;i++){
        pid=count++;
        b[i].process=pid;
        printf("\np%d",pid);
        printf("\t%d",b[i].token_num);
    }
    printf("\n----------------------------------------->");
    printf("\n Shared data before execution: %d",x);
    printf("\n------------------------------------------>");
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(b[i].token_num>b[j].token_num){
                    temp=b[i].token_num;
                    b[i].token_num=b[j].token_num;
                    b[j].token_num=temp;
                    temp=b[i].process;
                    b[i].process=b[j].process;
                    b[j].process=temp;
                    x=critical_section(x);
            }
            else if(b[i].token_num==b[j].token_num){
                    if(b[i].process>b[j].process){
                      temp=b[i].token_num;
                      b[i].token_num=b[j].token_num;
                      b[j].token_num=temp;
                      temp=b[i].process;
                      b[i].process=b[j].process;
                      b[j].process=temp;
                    }
                x=critical_section(x);
        }
    }
    }
    printf("\nprocess\t token_no");
    for(i=0;i<n;i++){
        printf("\np%d",b[i].process);
        printf("\t%d",b[i].token_num);
    }
    printf("\n----------------------------------------->");
    printf("\n Shared data after execution: %d",x);
    printf("\n------------------------------------------>");
    return 0;
}

