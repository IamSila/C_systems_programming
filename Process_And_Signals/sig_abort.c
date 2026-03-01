#include <stdio.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

/**
* main - entry point for the program
* Return: Always 0
*/


int main(void)
{
  pid_t pid;

  pid = fork();

  if (pid == 0)
  {
    printf("Child process of pid %d\n", getpid());
  }
  else
  {
    printf("Parent process of id %d\n", getpid());
  }

  abort();
  printf("This process fails because we have aborted this program\n");
  return (0);
}
