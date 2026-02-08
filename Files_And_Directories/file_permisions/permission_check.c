#include <stdio.h>
#include <fcntl.h>
#include <stdio.h>


int access(char *filePath, int amode);
/**
 * access - checks the permissions a file has
 * @filePath: the file whose permissions are checked.
 * @amode: the permission to check (R_OK, W_OK, F_OK, X_OK)
 */


/**
 * main - entry point of the program
 * Return: 0 for success
 */


int main(void)
{
	char filepath[255];
	int file_status;
	int read_status;
	int write_status;
	int execute_status;
	int file_descriptor;

	printf("Enter file path to check permissions: \n");
	scanf("%s", filepath);

	printf("file to check is %s", filepath);

	file_status = access(filepath, F_OK);

	if (file_status == -1)
	{
		printf("file does not exist: creating the file: \n");

		file_descriptor = creat(filepath, O_RDWR);
		if (file_descriptor == 0)
		{
			printf("%s created successfully\n", filepath);
		}
	}	
	else
	{
		printf("file exists:\n proceeding to check for permissions for '%s'\n", filepath);
	}

	read_status = access(filepath, R_OK);
	write_status = access(filepath, W_OK);
	execute_status = access(filepath, X_OK);

	if (read_status == 0 && write_status == 0 && execute_status == 0)
	{
		printf("%s has rwx permissions\n", filepath);
	}
	else if(read_status == 0 && write_status == 0 && execute_status == -1)
	{
		printf("%s has rw_ permissions\n", filepath);
	}
	else if (read_status == 0 && write_status == -1 && execute_status == 0)
	{
		printf("%s has r_x permissions\n", filepath);
	}
	else
	{
		printf("No permissions found for %s\n", filepath);
	}
	return (0);
}
