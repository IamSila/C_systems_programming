#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/types.h>



/** maximumm length of message that can transfer */
#define MESSAGE_LENGTH 1024
/** port number */
#define PORT 8888
/** macro for struct sockaddr */
#define SA struct sockaddr


struct sockaddr_in serveraddress;
struct sockaddr_in client;
socklen_t length;
int sock_file_descriptor, connection, bind_status, connection_status;
char message[MESSAGE_LENGTH];
size_t bytes;

/**
* main - entry point for the program
* Return: Always 0 for success.
*/

void processRequest(void)
{
  /** created a socket descriptor and handled the error */
  sock_file_descriptor = socket(AF_INET, SOCK_STREAM, 0);
  if (sock_file_descriptor == -1)
  {
    printf("Socket creation failed.!\n");
    exit(1);
  }

  /** setting zero bytes to the serveraddress */
  memset(&serveraddress, 0, sizeof(serveraddress));

  /** setting server properties */
  serveraddress.sin_addr.s_addr = htonl(INADDR_ANY);
  serveraddress.sin_port = htons(PORT);
  serveraddress.sin_family = AF_INET;

  /** binding newly created socket to the given ip addresss */
  bind_status = bind(sock_file_descriptor, (SA*)&serveraddress, sizeof(serveraddress));

  if (bind_status == -1)
  {
    printf("Socket binding failed!\n");
    exit(1);
  }

  /** server is listening for a new creation */
  connection_status = listen(sock_file_descriptor, 5);
  if (connection_status == -1)
  {
    printf("Socket is unable to listen for new connections!\n");
    exit(1);
  }
  else
  {
    printf("Server is listening for a new connection.\n");
  }

  length = sizeof(client);

  connection = accept(sock_file_descriptor, (SA*)&client, &length);
  if (connection == -1)
  {
    printf("Server is unable to accept data from client!\n");
    exit(1);
  }


  /** communication establishment */
  while (1)
  {
    memset(message, 0, sizeof(message));
    read(connection, message, sizeof(message));

    if(strncmp("end", message, 3) == 0)
    {
      printf("Client exited.\n");
      printf("Server exiting.\n");
      break;
    }
    printf("Data received from client: %s\n", message);
    memset(message, 0, sizeof(message));

    printf("Enter the message you want to send to the client: \n");
    scanf("%[^\n]%*c", message);

    /** sending data to the server by storing number of bytes transfeered in bytes */
    bytes = write(connection, message, sizeof(message));

    /** if number of bytes it > 0, data sent successfully */
    if (bytes > 0)
    {
      printf("Data is successfully sent to the client!\n");
    }
  }

  /** close the connection */
  close(sock_file_descriptor);

}



/**
  * main - program's entry point
  * Return: Always 0 for success
*/


int main(void)
{
  printf("Server is listening throught the port: %d within a local system\n", PORT);
  /** calling the process request function to process the client request */
  processRequest();
  return (0);
}

