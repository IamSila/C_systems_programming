#include <stdio.h>
#include <unistd.h>

/**
* main - entry point of the program
* Return: 0 for success
*/


int main(void)
{

  char DIR_NAME[255];
  int isRemoved;

  printf("Enter the directory path to delete:\n");
  scanf("%s", DIR_NAME);  

  isRemoved = rmdir(DIR_NAME);

  if (isRemoved == 0)
  {
    printf("Directory [ %s ] removed successfully\n", DIR_NAME);
  }
  else 
  {
    printf("Error: Directory not removed.\n");
  }

  return (0);
}
