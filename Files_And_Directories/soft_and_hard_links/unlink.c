#include <stdio.h>
#include <unistd.h>





/**
 * unlink - unlinks a soft linked file (ln)
 * @pathname: path to the link
 * Return: 0 for success, -1 for failure
 */





/**
* main - entrance of the program
* Return: 0 for success
*/


int main(void)
{

  char pathname[255];
  int unlink_status;

  printf("Enter the path to the linked file");
  scanf("%s", pathname);

  unlink_status = unlink(pathname);

  if (unlink_status == 0)
  {
    printf("Unlinked successfully");
  }
  else 
  {
    printf("Error during unlinking");  
  }
  return (0);
}

