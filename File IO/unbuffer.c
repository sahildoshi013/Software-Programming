#include<stdio.h>
/* #include<sys/types.h>
#include<sys/stat.h>*/
#include<fcntl.h>
//#include<unistd.h>
#include<stdlib.h>

void main(){

	int fd=open("temp",O_RDONLY);

	if(fd<0){
		printf("Can't open!");
		exit(-1);
	}
	
	char buf[100];
	
	while(read(fd,buf,100)!=0){
		printf("%s",buf);	
	}

	close(fd);

	int fd1=open("temp1",O_RDWR);
	
	if(fd1<0){
		printf("Can't open temp1!\n");
		exit(-1);
	}
	
	char buf1[]="first Line.";
	int n;
	

	lseek(fd1,0,SEEK_END);

	if(n=write(fd1,buf1,10)!=10)
		printf("Writing Error! %d",n);
	
	close(fd1);
	exit(0);
}
