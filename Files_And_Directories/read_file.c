#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>


/**
 * read - read contents of a file
 * @file_descriptor: the opened file
 * @buffer: number of bytes to read from the open file
 * @size: the size of the buffer
 * Return: Size of the read content on success, -1 on error
 */




/**
 * main - entrance of the program
 * Return: Always 0 for success
 */


int main(void)
{
	char filename[255];
	int file_descriptor;
	size_t size;

	char *content = (char *)calloc(100, sizeof(char));

	printf("Enter the filename to open: \n");
	scanf("%s", filename);

	file_descriptor = open(filename, O_RDONLY);
	if (file_descriptor == -1)
	{
		perror("File not found");
		exit(1);
	}

	size = read(file_descriptor, content, 100);

	printf("Number of bytes returned are: %ld", size);
	content[99] = '\0';
	printf("File content: %s", content);

	close(file_descriptor);


	return (0);
}
