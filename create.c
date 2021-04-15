#include<stdio.h>
#include<fcntl.h>
int main()
{
	int fd=open("meow.txt",O_RDONLY | O_CREAT);
}
  
