#include <stdio.h>
#include <stdlib.h>


/**
* main - entrance for the program
* Return: 0 for success
*/


int main(void)
{
  char environment_variable[255];
  char environment_value[255];
  int overide_value;
  int set_status;

  printf("Enter the environment name in CAPITAL LETTERS: \n");
  scanf("%s", environment_variable);

  printf("Enter the environment value: \n");
  scanf("%s", environment_value);

  printf("Enter the override value: \n");
  scanf("%d", &overide_value);


  set_status = setenv(environment_variable, environment_value, overide_value);

  if (set_status == 0)
  {
    printf("Environment variable created successfully\n");
  }
  else if (set_status == -1)
  {
    printf("Error: Environment variable not created successfuly\n");
  }

  return (0);
}
