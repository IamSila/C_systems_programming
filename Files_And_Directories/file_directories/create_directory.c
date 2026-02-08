#include <stdio.h>
#include <sys/stat.h>




/**
 * mkdir - created the directory specified by the path
 * @path: the directory to create
 * Return: 0 success, -1 Error
 */


/**
* main - entrance of teh program
* Return: 0 for success
*/


int main(void)
{
  char DIR_NAME[255];
  int isCreated;

  printf("Etner the directory name to create:\n");
  scanf("%s", DIR_NAME);

  isCreated = mkdir(DIR_NAME, 0777);

  if (isCreated == 0)
  {
    printf("Directory [%s] created successfully\n", DIR_NAME);
  }
  else
  {
    printf("Error: Directory not created successfully\n");
  }
  return (0);
}

