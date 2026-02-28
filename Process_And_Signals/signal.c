#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

/**
* main - entry to the program
* Return: Always 0 for success
*/

void CUSTOM_HANDLER(int);

int main(void)
{
  signal(SIGINT, CUSTOM_HANDLER);

  while (1)
  {
    printf("Running an infinite while loop\n");
    sleep(1);
  }
  return (0);
}

void CUSTOM_HANDLER(int signum)
{
  printf("Caught signal %d, coming out from program\n", signum);
  exit(1);
}
