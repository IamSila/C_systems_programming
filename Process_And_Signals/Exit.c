#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
* main - entry point for the program
* Return: always 0 for success
*/


int main(void)
{
  printf("Id for the running progam: %d\n", getpid());
  _Exit(0);
  printf("Exited the main program normally\n");
  return (0);
}
