#include <stdio.h>


/**
* main - entry point of the program
* Return: 0 for success
*/


int main(int argc, char *argv[])
{
  int i;

  printf("The total number of arguments passed is:%d\n", argc);
  for (i = 0; i < argc; i++)
  {
    printf("Argument %d is %s\n",i , argv[i]);
  }
  
  return (0);
}
