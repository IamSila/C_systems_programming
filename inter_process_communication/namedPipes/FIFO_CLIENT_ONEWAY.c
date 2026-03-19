#include "pipes.h"
#include <sys/stat.h>
#define SIZE 1024

mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;

/**
 * sendData - send data to the FIFO_FILE
 * Return: Always 0
 */

void sendData(void)
{
  char message_buffer[SIZE];
  int write_status;
  int fd;

  fd = open("./FIFO_FILE", O_RDWR | O_CREAT, mode);
  while(1)
  {
    /** capturing input from the user */
    printf("Enter what to write in the message buffer\n Enter quit to exit\n");
    fgets(message_buffer, sizeof(message_buffer), stdin);

    /** writing to FIFO_FILE*/
    write_status = write(fd, message_buffer, sizeof(message_buffer));
    if (write_status == -1)
    {
      perror("Could not write to FIFO_FILE\n");
      break;
    }

    if((int)strcmp(message_buffer, "quit\n") == 0 || (int)strlen(message_buffer) == 0)
    {
      printf("Exit invoked: Typed quit or typed Nothing\n");
      exit(EXIT_SUCCESS);
    }
    else 
    {
      printf("FIFO_FILE contains: %s", message_buffer);
    }

  }
}

/**
* main - entry point for the program
* Return: Always 0 on success
*/


int main(void)
{
  printf("FIFO CLIENT sending data\n");
  /* send data to FIFO_FILE*/
  sendData();
  return (0);
}
