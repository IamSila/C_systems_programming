#include <stdio.h>
#include <unistd.h>

/**
 * fork creates 2 processes: parent and child
 * parent's pid > 0 and childs pid == 0
 */

/**
* main - entry or the program
* Return: Always 0 for success
*/

int main(void)
{
  int pid;

  pid = fork();

  if (pid > 0)
  {
    printf("Parent process created successfully\n");
  }
  else if (pid == 0)
  {
    printf("Child process created successfully\n");
  }
  else
  {
    printf("Error: Processes not created successfully\n");
  }

  return (0);
}
