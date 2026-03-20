#include "pipes.h"
#define SIZE 1024
#define FIFO_FILE "FIFO_FILE"



int file_descriptor;
char message_buffer[1024];
int read_buffer_bytes;

/**
 * receiveData - receives data from the FIFO file
 * Return: Nothing
 */

void receiveData()
{
    file_descriptor = open(FIFO_FILE, O_RDONLY);
    read_buffer_bytes = read(file_descriptor, message_buffer, sizeof(message_buffer));
    message_buffer[read_buffer_bytes] = '\0';

    printf("Received Message: %s\n", message_buffer);
    if((int)strlen(message_buffer) == 0)
    {
      close(file_descriptor);
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
  
  fd = mknod(FIFO_FILE, S_IFIFO | 0640, 0);
  if (fd == 0)
  {
    printf("Successfully created FIFO_FILE\n");
  } 


  /* function to receive the data from the file */
  receiveData();






  return (0);
}
