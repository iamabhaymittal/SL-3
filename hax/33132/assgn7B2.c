// C program to implement one side of FIFO 
// This side reads first, then reads 
#include <stdio.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 

int main() 
{ 
	int fd1; 
	int char_count,word_count,sent_count,i;
	
	char * myfifo = "/home/nllab15/33132/myfifo"; 
	mkfifo(myfifo, 0666); 
	char str1[80], str2[80]; 
	while (1) 
	{
		printf("\nWaiting for file 1 to write \n");
		wait(NULL);
		fd1 = open(myfifo,O_RDONLY); 
		read(fd1, str1, 80); 

		printf("\nUser1: %s\n", str1); 
		
		char_count = 0;
		word_count = 1;
		sent_count = 1;
		
		i=0; 
		
		while(str1[i] != '\0')
		{
			if((str1[i] >= 'a' && str1[i] <= 'z') || (str1[i] >= 'A' && str1[i] <= 'Z') || (str1[i] >= '0' && str1[i] <= '9'))
				char_count++;
			if(str1[i] == ' ')
				word_count++;
			if(str1[i] == '.' && str1[i+1] == ' ')
				sent_count++;
			i++;
		}
		close(fd1);
		sprintf(str2,"\n\nNo. of characters :- %d\nNo. of words :- %d\nNo. of sentences :- %d\n",char_count,word_count,sent_count);
		printf("\nFile 2 to write \n");
		fd1 = open(myfifo,O_WRONLY); 
		write(fd1, str2, strlen(str2)+1); 
		close(fd1); 
	} 
	return 0; 
} 

