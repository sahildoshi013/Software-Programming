#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main(){

	FILE *fd=fopen("temp","r");

	if(fd==NULL){
		printf("Can't open! temp");
		exit(-1);
	}

	printf("Char At a time\n");
	rewind(fd);
	//Single character at a time	
	int c;
	while((c = fgetc(fd))!=EOF){
		printf("%c",c);
		printf("-");
	}
	
	printf("\n\nLine At a time\n");
	char buf[10];
	rewind(fd);	
	//Line At a time
	while(fgets(buf,sizeof(buf),fd)!=0){
		printf("%s",buf);	
		printf("-");
	}

	printf("\n\nDirect I/o\n");
	char buf0[100];
	rewind(fd);
	//Direct I/O
	while(fread(buf0,1,15,fd)!=0){
		printf("%s",buf0);
		printf("-");
	}

	close(fd);

	FILE *fd1=fopen("temp1","w");
	
	if(fd1==NULL){
		printf("Can't open!");
		exit(-1);
	}
	
	printf("\nPut Single Char\n");
	fseek(fd1,0,SEEK_END);	
	char bufC[]="\nPut Single Char\n";
	int i=0;
	
	for(i=0;i<strlen(bufC);i++)
		fputc(bufC[i],fd1);

	printf("\nPut Line To FIle\n");

	char buf1[]="\nPut Line To File\n";
	fseek(fd1,0,SEEK_END);
	fputs(buf1,fd1);
	
	printf("\nDirect I/O To FIle\n");

	char buf2[]="Direct I/O To File\n";	
	fseek(fd1,0,SEEK_END);
	fwrite(buf2,sizeof(buf2),1,fd1);
	

	close(fd1);
	exit(0);
}
