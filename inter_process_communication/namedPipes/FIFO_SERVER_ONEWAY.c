#include "pipes.h"
#define SIZE 1024

/**
 * receiveData - receives data from the FIFO file
 * Return: Nothing
 */


void receiveData(void)
{
  int fd;
  int read_status;
  char message_buffer[SIZE];

  while(1)
  {
    fd = open("./FIFO_FILE", O_CREAT | O_RDWR);

    if (fd == -1)
    {
      perror("Error: Could not open FIFO_FILE.\n");
      _exit(EXIT_FAILURE);
    }

    read_status = read(fd, message_buffer, sizeof(message_buffer));
    if (read_status == -1)
    {
      perror("Error: could not read from the file\n");
      _exit(EXIT_FAILURE);
    }
    if (message_buffer[read_status] == '\n')
    {
      message_buffer[read_status] = '\0';
    }

    if((int)strlen(message_buffer) == 0 || (int)strcmp(message_buffer, "quit\n") == 0)
    {
      printf("Read 0 bytes from message buffer: Exiting FIFO_SERVER_ONEWAY.c\n");
      break;
    }
    else
    {
      printf("Message read from FIFO file: %s", message_buffer);
      exit(EXIT_SUCCESS);
    }
  }


}



/**
  * main - entry point for the program
  * Return: Always 0
  */



int main(void)
{
  int fifo_status;

  /* create a FIFO file using mknod() */
  fifo_status = mknod("./FIFO_FILE", S_IFIFO | 0640, S_IRWXU);

  if (fifo_status == 0)
  {
    printf("FIFO_FILE created successfully\n");
  }


  /* function to receive the data from the file */
  receiveData();






  return (0);
}
