#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

/**
* main - entry point for the program
* Return: Always 0
*/
void SIGNAL_HANDLER(int);

int main(void)
{
  int raise_status;

  signal(SIGINT, SIGNAL_HANDLER);
  printf("Raising a signal using raise() system call\n");
  raise_status = raise(SIGINT);

  if (raise_status == 0)
  {
    printf("signal raised\n");
  }
  else
  {
    printf("Signal not raised\n");
    _Exit(0);
  }
  return (0);
}

void SIGNAL_HANDLER(int signal)
{
  printf("Signal raised and handled gracefully\n");
}
