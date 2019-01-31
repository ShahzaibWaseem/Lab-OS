#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#define BUF_SIZE 256

int main(int argc, char* argv[]) {
	int input_fd, output_fd, number, i;
	ssize_t ret_in, ret_out;
	char buffer[BUF_SIZE];
	char outputlines[100][100];

    //Checks if the commmand lines arguments are correct
	if(argc != 3){
		printf ("Usage: cp -numberOfLines file");
		return 1;
	}
    //Number of lines to Print from the End
	sscanf(argv[1], "%d", &number);
	number*=-1;
	printf("Print %d Lines\n", number);

    // opening file
	input_fd = open (argv [2], O_RDONLY);
    //Error if file not found
	if(input_fd == -1){
		perror("open");
		return 2;
	}

	int lines = 0,chars=0;
   	//Reading the File
	while((ret_in = read (input_fd, &buffer, BUF_SIZE)) > 0){
		for (i=0;buffer[i]!='\0';i++){
			if (buffer[i] == '\n'){
				chars=0;lines+=1;
			}
			outputlines[lines][chars] = buffer[i];
			chars++;
		}
	}

    //Printing the lines
	while (number > 0){
		printf("%s\n", outputlines[lines-number+1]);
		number--;
	}

    /* Close file descriptors */
	close (input_fd);
	return (EXIT_SUCCESS);
}
