#include <stdio.h>
#include <unistd.h>
#include <signal.h>


/**
* main - starting point for the program
* Return: Always 0
*/

void raisedAlarm(int sig);

int main(void)
{
  alarm(5);

  signal(SIGALRM, raisedAlarm);

  while(1)
  {
    printf("Hello world ...\n");
    sleep(1);
  }
  return (0);
}

void raisedAlarm(int sig)
{
  printf("SIGALM raised and handled gracefully\n");
}
