#include "pipes.h"
#define SIZE 1024

mode_t mode = S_IRWXU | S_IROTH | S_IRGRP;

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
    fd = open("./FIFO_FILE", O_CREAT | O_RDWR, mode);
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

    if((int)strlen(message_buffer) == 0)
    {
      printf("Read 0 bytes from message buffer: Exiting FIFO_SERVER_ONEWAY.c\n");
      break;
    }
    else
    {
      printf("Message read from FIFO file: %s", message_buffer);
      break;
    }
  }


}



/**
  * main - entry point for the program
  * Return: Always 0
  */



int main(void)
{
  
  int fd;

  /** create a FIFO file using mknod() **/ 
  
  fd = mknod("./FIFO_FILE", S_IFIFO | 0640, 0);
  if (fd == 0)
  {
    printf("Successfully created FIFO_FILE\n");
  } 


  /* function to receive the data from the file */
  receiveData();






  return (0);
}
