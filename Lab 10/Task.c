#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char const *argv[]){
	int parent_fd[2], child_fd[2];
	pid_t process;
	char parent_message [80] = "Hello Child Process!\n";
	char child_message [80] = "Hi Parent Process!\n";

	if (pipe(parent_fd) == -1){
		fprintf(stderr, "Error while Pipe-ing Parent.\n");
		return 1;
	}
	if (pipe(child_fd) == -1){
		fprintf(stderr, "Error while Pipe-ing Child.\n");
		return 1;
	}

	// -ve : Fork Failed
	// +ve : Parent Process
	// 0   : Child Process
	process = fork();
	/*****	Parent Child Process Split	*****/

	// -ve : Fork Failed
	if (process < 0){
		fprintf(stderr, "Error while Forking\n");
		return 1;
	}
	// +ve : Parent Process
	else if (process > 0){
		char parent_buffer[80];
		printf("Parent Process ID\t:\t%d\n", process);

		close(parent_fd[0]);		// Close Parent Reading
		write(parent_fd[1], parent_message, strlen(parent_message) + 1);
		close(parent_fd[1]);

		wait(NULL);

		close(child_fd[1]);			// Close Parent Writing
		read(child_fd[0], parent_buffer, 80);
		printf("%s\n", parent_buffer);
		close(child_fd[0]);
	}
	// 0   : Child Process
	else{
		char child_buffer[80];
		printf("Child Process ID\t:\t%d\n", process);
		close(parent_fd[1]);			// Close Parent Writing
		read(parent_fd[0], child_buffer, 80);

		int k = strlen(child_buffer);
		for (int i = 0; i < strlen(child_message); ++i)
			child_buffer[k++] = child_message[i];

		child_buffer[k] = '\0';

		close(parent_fd[0]);
		close(child_fd[0]);

		write(child_fd[1], child_buffer, strlen(child_buffer) + 1);
		close(child_fd[1]);
	}
	return 0;
}