#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>


/**
 * main - entry of the program
 * Return: 0 for success and -1 for fail
 */


int main(void)
{
	char filename[255];
	int file_descriptor;
	char content[254];
	int size;

	printf("Enter the file name to open: \n");
	scanf("%s", filename);

	file_descriptor = open(filename,O_WRONLY | O_CREAT | O_APPEND | 0777);
	if (file_descriptor == -1)
	{
		perror("file not found");
		exit(1);
	}

	printf("Enter the content to write to the file");
	scanf("%[^\n]%*c", content);

	size = write(file_descriptor, content, strlen(content));
	printf("%d %lu %d\n", file_descriptor, strlen(content), size);
	close(file_descriptor);

	return (0);
}
