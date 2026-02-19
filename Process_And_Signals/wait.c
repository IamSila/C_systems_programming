#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
/**
 * this example explains the use of child, parent and wait system call
 */


/**
 * main - entry point of the program
 * Return: Always 0
*/



int main(void)
{
  pid_t process;

  process = fork();

  if (process > 0)
  {
    printf("The parent process runs then waits for the child process to complete.\n");
    wait(NULL);
    printf("child process has completed running\n");
  }
  else if (process == 0)
  {
    printf("The child process: %d is running...\nChild process: %d is done\n", getpid(), getpid());
  }

  
  return (0);
}
