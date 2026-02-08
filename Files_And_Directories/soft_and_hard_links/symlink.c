#include <stdio.h>
#include <unistd.h>
/**
 * symlink - creates a link between 2 files
 * @filepath: the firts path
 * @linkname: the link name
 * Return: 0 for success and -1 for failure
 */



/**
* main - entry point of the program
* Return: Always 0
*/



int main(void)
{
  char filepath[255];
  char linkname[255];
  int linkstatus;

  printf("Enter the filepath you want to link");
  scanf("%s", filepath);

  printf("Enter the name of the link");
  scanf("%s", linkname);

  linkstatus = symlink(filepath, linkname);

  if (linkstatus == 0)
  {
    printf("Link successfully created");
  }
  else 
  {
    printf("Link not successfull");
  }

  return (0);
}
