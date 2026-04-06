#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>


/** port to connect to */
#define PORT 8888
/** size of the message buffer */
#define MESSAGE_BUFFER 4096
/** MACRO for sockaddr */
#define SA struct sockaddr


int socket_file_descriptor;
int connection;
char message[MESSAGE_BUFFER];
size_t bytes;
struct sockaddr_in serveraddress;


/**
 * sendRequest - sends request to the server.
 * Return: Nothing
 */

void sendRequest(void)
{
  socket_file_descriptor = socket(AF_INET, SOCK_STREAM, 0);

  if (socket_file_descriptor == -1)
  {
    printf("Creation of socket failed.\n");
    exit(1);
  }
  memset(&serveraddress, 0, sizeof(serveraddress));

  /** setting server details */
  serveraddress.sin_addr.s_addr = inet_addr("127.0.0.1");
  serveraddress.sin_port = htons(PORT);
  serveraddress.sin_family = AF_INET;

  /** establishing connection to server */
  connection = connect(socket_file_descriptor, (SA*)&serveraddress, sizeof(serveraddress));
  if (connection == -1)
  {
    printf("Connection with the server failed\n");
    exit(1);
  }

  /** interact with the server */
  while (1)
  {
    memset(&message, 0, sizeof(message));
    printf("Enter the message you want to send to the server\n");
    scanf("%[^\n]%*c", message);

    if (strncmp(message, "end", 3) == 0)
    {
      write(socket_file_descriptor, message, sizeof(message));
      printf("Client Exit.\n");
      break;
    }
    bytes = write(socket_file_descriptor, message, sizeof(message));
    if (bytes > 0)
    {
      printf("Data sent to the server successfully.\n");
    }

    memset(&message, 0, sizeof(message));

    /** reading response from the server */
    read(socket_file_descriptor, message, sizeof(message));
    printf("Data received from the server: %s\n", message);

  }

  /** close the socket connection */
  close(socket_file_descriptor);
  
}




/**
* main - entry point for the program
* Return: Always 0 on success, otherwise failure
*/

int main(void)
{
  printf("Client is estatblishing a connection with server through port: %d\n", PORT);

  /** Calling a send request to send a request to the server */
  sendRequest();

  return (0);
}
