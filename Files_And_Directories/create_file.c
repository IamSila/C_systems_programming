#include <stdio.h>
#include <fcntl.h>


/**
 * main - the entry of the programs
 * Return: Always 0 for success, nonzero for failure.
 */


int main(void)
{
	char filename[255];
	int fd;

	printf("Enter the file name to create: \n");
	scanf("%s", filename);

	fd = creat(filename, O_RDWR | O_CREAT);

	if (fd != -1)
	{
		printf("file created successfully\n");
	}
	else
	{
		printf("Unable to create the file\n");
	}

	return (0);

}

