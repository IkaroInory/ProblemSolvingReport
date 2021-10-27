#include "IOTask.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE (1024*1024*1024)

const char fileName[]="IOFile";
void executeIOTask()
{
	char* fileBuf=(char*)malloc(BUFFER_SIZE);
	int fileFd=open(fileName,O_RDWR|O_CREAT,0644);
	if(fileFd==-1)
	{
		perror("Open File Error");
	}
	memset(fileBuf,97,BUFFER_SIZE);
	size_t writeSize = write(fileFd,fileBuf,BUFFER_SIZE);
	printf("write:%lu bytes to file:%s\n",writeSize,fileName);
	free(fileBuf);
	close(fileFd);
}
