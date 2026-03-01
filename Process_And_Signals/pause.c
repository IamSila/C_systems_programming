#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

/**
 * SIGNAL_HANDLER - handles the signal raised
 * @signal: the signal number
 * Return: Nothing (void)
 */

void SIGNAL_HANDLER(int signal)
{
  printf("Signal raised and handled gracefully\n");
}

/**
* main - entry point for the program
* Return: Always 0
*/


int main(void)
{
  signal(SIGINT, SIGNAL_HANDLER);
  printf("Process paused, press CTRL + C to continue\n");
  pause();
  return (0);
}
