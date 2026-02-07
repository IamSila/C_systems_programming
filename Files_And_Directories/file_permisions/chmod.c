#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int chmod(char *path, mode_t mode);
/**
 * chmod - change permisions of a file
 * @filepath: a string rep the path to the file
 * @mode: permision value
 * Return: 0 on success and -1 on fail or error
 */


/**
 * main - entry point of the program
 * Return: always 0
 */

int main(void)
{
	char filePath[255];
	int new_permission_value;
	mode_t permission_value;
	int permission_status;

	printf("enter the file path: \n");
	scanf("%s", filePath);

	printf("Enter the new permission set in format '0444': \n");
	scanf("%d", &new_permission_value);

	permission_value = (mode_t)new_permission_value;

	permission_status = chmod(filePath, permission_value);

	if (permission_status == 0)
	{
		printf("New persmission set successfully");
	}
	else
	{
		printf("permission set successfuly");
	}


	return (0);
}
