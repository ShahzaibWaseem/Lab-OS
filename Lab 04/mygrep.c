#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

void checkString(char *argv[]){
	int output_fd, input_fd, memoryLocation = 0;
	char buffer, line[100];
	if( ( output_fd = open(argv[2], O_RDONLY) ) != -1){
		// Captures Character by Character
		while( ( input_fd = read(output_fd, &buffer, sizeof(char) ) ) != 0){
			// Stores till End of Line in a new Variable 'line'
			if(buffer != '\n'){
				line[memoryLocation] = buffer;
				memoryLocation++;		// goto next mem location
			}
			else{
				if(strstr(line, argv[1]) != NULL)
					printf("%s\n", line);
				memset(line, 0, sizeof(line));
				memoryLocation = 0;		// goto initial mem location
			}
		}
	}
	else{
		perror("open");
		exit(1);
	}
}

int main(int argc,char *argv[]){
	struct stat stt;

	/* Are src and dest file name arguments missing */
	if(argc!=3){
		printf ("Usage: cp file1 file2");
		return 1;
	}

	if(stat(argv[2],&stt)==0)
		checkString(argv);
	else{
		perror("stat()");
		exit(1);
	}
}