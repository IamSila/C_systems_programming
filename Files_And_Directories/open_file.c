#include <fcntl.h>
#include <stdio.h>


/**
 * main - entry point for the programs
 * Return: Always 0 for success, -1 for failure.
 */


int main(void)
{
	char filename[255];
	int fd;

	printf("Enter the file to open:\n ");
	scanf("%s", filename);

	fd = open(filename, O_RDONLY);
	if (fd != -1)
	{
		printf("Yaaaay!!!%s opened successfully\n", filename);
	}
	else
	{
		printf("Oooops! %s not opened\n", filename);
	}
	return (0);
}


