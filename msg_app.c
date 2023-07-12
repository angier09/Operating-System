#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void msg_app()
{
   int pipe1[2], pipe2[2];
	pid_t pid;
	char buffer[100];

	if (pipe(pipe1) == -1) {
    	perror("Error creating first pipe");
    	exit(EXIT_FAILURE);
	}

	if (pipe(pipe2) == -1) {
    	perror("Error creating second pipe");
    	exit(EXIT_FAILURE);
	}

	pid = fork();

	if (pid == -1) {
    	perror("Error creating child process");
    	exit(EXIT_FAILURE);
	}

	if (pid == 0) {
    	close(pipe1[1]);
    	close(pipe2[0]);

    	while (1) {
        	if (read(pipe1[0], buffer, 100) == -1) {
            	perror("Error reading from pipe1");
            	exit(EXIT_FAILURE);
        	}
        	printf("Received message from person B: %s", buffer);

        	printf("Person A: ");
        	fgets(buffer, 100, stdin);
        	if (write(pipe2[1], buffer, strlen(buffer) + 1) == -1) {
            	perror("Error writing to pipe2");
            	exit(EXIT_FAILURE);
        	}
    	}
	} else {
    	close(pipe1[0]);
    	close(pipe2[1]);

    	while (1) {
        	printf("person B: ");
        	fgets(buffer, 100, stdin);
        	if (write(pipe1[1], buffer, strlen(buffer) + 1) == -1) {
            	perror("Error writing to pipe1");
            	exit(EXIT_FAILURE);
        	}

        	if (read(pipe2[0], buffer, 100) == -1) {
            	perror("Error reading from pipe2");
            	exit(EXIT_FAILURE);
        	}
        	printf("Received message from person A: %s", buffer);
    	}
	}

}

int main() {
   
	msg_app();
	return 0;
}






