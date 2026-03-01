#include <stdio.h>
#include <stdlib.h>
/**#include <signal.h> */
#include <unistd.h>

#define EXIT_CODE 0

/**
 * creating_child_process - creates a child process and exits from the parent process
 * Return: The id of the child process
 */

int creating_child_process(void)
{
  pid_t pid;

  pid = fork();

  if (pid < 0)
  {
    printf("Child process not created successfully\n");
    _Exit(EXIT_FAILURE);
  }
  else if(pid ==  0)
  {
    printf("Child created successfully\n");
  }
  else if (pid > 1)
  {
    printf("Exiting from the parent process\n");
    _Exit(EXIT_SUCCESS);
  }

  return (pid);
}




/**
* main - entrance of the main program
* Return: Always 0
*/



int main(void)
{
  /** I create a child process */



  return (0);
}
