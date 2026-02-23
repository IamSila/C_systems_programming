#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * exit - exits a running process
 */

/**
* main - entrance of the program
* Return: Always 0 for success
*/


int main(void)
{
  int pid;

  pid = fork();

  if (pid == 0)
  {
    printf("Child process of id: %d\n", getpid());
    exit(0);
    printf("Child process exited");
  }
  else
  {
    printf("Parent running of id: %d\n", getpid());
    exit(0);
    printf("Parent process exited");
  }

  return (0);
}
