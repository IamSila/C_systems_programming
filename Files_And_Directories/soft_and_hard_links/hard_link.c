#include <stdio.h>
#include <unistd.h>




/**
 * link - creates a hard link to a file
 * @filepath: path to the file being linked to.
 * Return: 0 success -1 failure
 */





/**
* main - entry of the program
* Return: 0 for success
*/


int main(void)
{

  char filepath[255];
  int hard_link_status;
  char hard_link_name[255];

  printf("enter the path to the file to link: \n");
  scanf("%s", filepath);

  printf("Enter the name of the hard link: \n");
  scanf("%s", hard_link_name);

  hard_link_status = link(filepath, hard_link_name);
  
  if (hard_link_status == 0)
  {
    printf("The hard link to %s created successfully.\n", filepath);

  }
  else
  {
    printf("Error: Link not created successfully");
  }
  return (0);
}
