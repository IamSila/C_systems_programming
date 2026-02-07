#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/**
 * main - entry point for the program
 * Return: Always 0 for success
 */

int main(void)
{
	/**
	 * open a file
	 * write to the file
	 * close the file
	 */
	char filename[255];
	int file_descriptor;
	int size;



	printf("Enter the filename to open: \n");
	scanf("%s", filename);

	file_descriptor = open(filename, O_RDWR);
	if (file_descriptor == -1)
	{
		perror("Error! Cannot open the file specified");
		exit(1);
	}
	char content[1024];
	printf("Enter the content to write to the file: \n");
	scanf("%[^\n]%*s", content);

	size = write(file_descriptor, content, strlen(content));
	printf("Size written is: %d", size);
	printf("Content written is: %s ", content);
	

	close(file_descriptor);


	return (0);
}
