#include <stdio.h>
#include <unistd.h>

/**
* main - entry point for the program
* Return: 0 for success
*/


int main(void)
{

  char DIR[255];
  char buff[255];
  char *current_directory;
  int changeDirectory_status;

  printf("Enter the directory to change to\n");
  scanf("%s", DIR);

  current_directory = getcwd(buff, 255);
  printf("The current working directory is %s\n", current_directory);

  changeDirectory_status = chdir(DIR);

  if (changeDirectory_status == 0)
  {
    printf("Directory changed to %s\n", DIR);
  }
  else 
  {
    printf("Error: Directory not changed\n");
  }

  printf("Current working directory is now %s\n", current_directory);
  return (0);
}
