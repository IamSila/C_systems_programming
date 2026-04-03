#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 1024



/** GLOBAL VARIABLES */
int status; /** status of the pipe system call*/
char write_buffer[SIZE]; /** store the input from the user */
char read_buffer[SIZE]; /** store what has been read from the pipe */
int pipefdr[2]; /** the pipe descriptor */


/**
 * pipe_operation - performs reading and writing to a pipe
 * Return: nothing
 */

void pipe_operation(void)
{
  printf("Writing to pipe the content:  Message is: %s", write_buffer);
  write(pipefdr[1], write_buffer, sizeof(write_buffer));

  read(pipefdr[0], read_buffer, sizeof(read_buffer));
  printf("Reading from the pipe: Message is: %s", read_buffer);
}


/** main - entry point for the program
* Return: Always 0
*/


int main(void)
{
  status = pipe(pipefdr);

  /** if pipe sys call fails */
  if (status == -1)
  {
    perror("Pipe not created");
    exit(EXIT_FAILURE);
  }

  printf("Write the content to pass to pipe.\n Type 'quit' to exit\n");
  fgets(write_buffer, sizeof(write_buffer), stdin);

  while (strcmp(write_buffer, "quit\n") != 0)
  {
    fgets(write_buffer, sizeof(write_buffer), stdin);
    pipe_operation();
  }


  close(pipefdr[1]);
  close(pipefdr[0]);

}
