#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h> //Use for : chmod(),stat()

void main(){

	/*Check File Permisions
		access(filepath,Mode)
			filepath: String File path to check
			MOdes: R_OK,W_OK,X_OK and F_OK
		return 0 on success */
	if(access("temp",F_OK)==0)
		printf("Temp File Exist \n");
	else
		printf("Temp File Not Exist \n");

	/*Hard Link
		link(existing filepath,new filepath)
		return 0 on success*/
	if(link("temp","temphardlink")==0)
		printf("Hardlink created\n");
	else
		printf("Error Hardlink created\n");

	/*remove Hard Link
		unlink(hardlink filepath)
		return 0 on success*/
	if(unlink("temphardlink")==0)
		printf("Unlink Hardlink\n");
	else
		printf("Error on Unlink Hardlink\n");

	/*Create Softlink
		symlink(Source filepath, DestinationFilepath)
		return 0 on success*/
	if(symlink("temp","tempsoftlink")==0)
		printf("Softlink Created\n");
	else
		printf("Error on Createing Softlink\n");

	/*Read Content of Symbolic(Soft) Link not the pointed one
		readlink(filepath, Buffer, BufferSize)
		return -1 on Fail else return count of bytes*/
	char buf[100];
	if(readlink("tempsoftlink",buf,sizeof(buf))==-1)
		printf("Error While reading Soft link\n");
	else
		printf("Data Of Soft Link : \n%s \n",buf);

	/*Remove file
		remove(filepath)
		return 0 on success*/
	if(remove("remove")==0)
		printf("Remove Successfully.\n");
	else
		printf("Error on Remove\n");

	/*Rename File
		rename(Old Filepath, new Filepath)
		return 0 on success*/
	if(rename("name","rename")==0)
		printf("Rename Successfully.\n");
	else
		printf("Error on Rename\n");

	/*change permission of file
		chmod(filepath, Mode)
			Mode : as defines in sys/stat.h
				S_ISUID - set user id on execution
				S_ISGID - set group id on execution
				S_ISVTX - On Directory restrict deletion flag
				S_IRWXU - All to Owner
				S_IRWXG - All to Group
				S_IRWXO - All to Other
				And Many Other File Permission 
				see <sys/stat.h> 
		return 0 on success*/
		
		if(chmod("temp",S_IRWXU)==0)
			printf("Permission Change Successfully\n");
		else
			printf("Error on Changing Permission\n");
	
		
	/*Show File Stat
		stat(filepath,pointer to struct stat variable)
		
		return 0 on success*/
	
	struct stat fstat;
	if(stat("temp",&fstat)==0){
		printf("%s Details : \n","temp");
		printf("Inode : %d\n",fstat.st_ino); 
		printf("No. of HardLink : %d\n",fstat.st_nlink); 
	}
	else
		printf("Error Whire getting Stat\n");
}
