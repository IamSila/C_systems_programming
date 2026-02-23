#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

/**
* main - entrance to the program
* Return: Always 0 for success
*/


int main(void)
{
  int pid;
  int status;

  pid = fork();

  if (!pid)
  {
    printf("Process not created: my pid %d", getpid());
    exit(0);
  }

  waitpid(pid, &status, WUNTRACED);

  if (WIFEXITED(status))
  {
    printf("Exit normally\n");
    printf("Exit status: %d\n", WEXITSTATUS(status));
  }
  else
  {
    printf("Exit NOT normal\n");
    _exit(1);
  }

  return (0);
}
