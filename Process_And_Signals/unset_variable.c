#include <stdio.h>
#include <stdlib.h>

/**
* main - entrance of the program
* @argc: Total number of arguments.
* @argv: actual arguments.
* Return: 0 for success
*/


int main(int argc, char *argv[])
{
  int unset_status;
  char *environment_variable;

  environment_variable = argv[1];

  unset_status = unsetenv(environment_variable);

  if (unset_status == 0)
  {
    printf("Environment %s unset successfully\n", environment_variable);
  }
  else if (unset_status == -1)
  {
    printf("Error: Environment %s not unset", environment_variable);
  }

  return (0);

}
