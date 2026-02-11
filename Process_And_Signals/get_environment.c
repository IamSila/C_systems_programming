#include <stdio.h>
#include <stdlib.h>


/**
* main - entrance to the program
* Return: Nothing
*/


int main(void)
{
  char environment_name[255];

  printf("Enter the environment name to get in CAPITAL LETTERS: \n");
  scanf("%s", environment_name);

  printf("Environment value: %s\n", getenv(environment_name));

  return (0);
}
