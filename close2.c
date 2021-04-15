#include<stdio.h> 
#include<fcntl.h> 
int main() 
{ 
    
    int fd1 = open("meow.txt", O_RDONLY, 0);  
    close(fd1); 
      
   
    int fd2 = open("me.txt", O_RDONLY, 0);  
      
    printf("fd2 = % d\n", fd2); 
    exit(0); 
}  
