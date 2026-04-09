# sockets
- Connects 2 nodes to communicate together.
- They are bidectional gateway
- It is a combination of IP address and a port number.
- They build client server architectures.
- Types of sockets available are differintiated based on data transfer mechanisms.


stream sockets - tcp
datagram sockets - udp
raw sockets
Domain sockets - provide a medium to communicate with processes of the same host system
Internet domain sockets - remote communication


When designing a socket server to establish communication, it 
should follow certain guidlines:
    - communication style [how data transfers over the network]
    - namespaces [type of connection system that transfers the data]
    - protocols [tcp or udp]


- <sys/sockets.h> implements sockets programming.

- Transmission modes - half duplex, full duplex or simplex.

- OSI model AND TCP model check.




# SYSTEM CALLS FOR SOCKET PROGRAMMING.
<sys/sockets.h> // library

## socket()
- on error, returns -1.

```
/**
 * sockets - system call for creating a communication interface.
 * @domain: type of communication[AF_INET or AF_INET6]
 * @type: type of socket [SOCK_STREAM, SOCK_DGRAM, SOCK_RAW, SOCK_RDM]
 * @protocal: protocal value for communication: default is 0.
 * Return: -1 for failure.
 */

int sockets(int domain, int type, int protocal)

```

## bind()
- Binds the socket with an address and a port number.

```
/**
* bind - bind an address and a port no. to the socket.
* @sockfd: file descriptor created using sockets() sys call
* @addr: struct that contains adress structure for the socket 
* @addrlen: size in (bytes) for the socket address structure.
* Return: 0 on success and -1 on failure.
*/

struct socket_address
{
    sa_family_t sa_family; // Address family.
    char sa_data[14]; // family specific address info
}
int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
```

## listen()
- Listens for the connections on a socket.

```
/**
* listen - listens for connections from a client on a socket.
* @sockfd: file descriptor created using sockets()
* @backlog: Number of connections possible with that socket.
* Return: 0 if it working correctly and -1 on error.

int listen(int sockfd, int backlog)
```


## accept()
- It takes the first connection request from the queue and creates a new file descriptor referring to the
request socket.

```
/*
* sockfd: file  descriptor created using sockets()
* @socketaddr: socket address structure of the peer socket to establish a connection.
* addrlen: lenght of the peer address.
* Return: 0 on success and -1 on failure.
*/



int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
```

## send()
- Sends data to another socket.

```

/**
* send - sends data to another socket.
* @buf: message object that you want to transmit.
* @len: length of the message.
* @flags: handle certain excemptions while transmitting data...usully, you set this value to 0.
* Return: size of data transmitted and -1 on failure.
*/
ssize_t send(int sockfd, const void *buf, size_t len, int flags)
```

## recv()
- Recieves the message/data from a peer/connected socket.

```
/**
* @sockfd: file descriptor created using sockets.
* @buf: message recieved from the connected socket.
* @len: length of the message.
* @flags: takes external flags to handle exceptions.
* Return: Always size of the recived message, -1 on error.
*/

ssize_t recv(int sockfd, void *buf, size_t len, int flags)
```

## sendto()
- Used in udp to send data to connected socket.
```
/**
* @sockfd: Created using socket() sys call.
* @buf: message to send.
* @len: size of the message
* @flags: external flags to handle exceptions during data  transfer.
* @destaddr: takes address of the destination socket.
* @addrlen: takes address length of the destination socket.
* Return: size of message sent, -1 on failure.
*/

int sendto(int sockfd, const void *buf, size_t len,int flags, const struct sockaddr *dest_addr, socklen_t addrlen)

```

## recvfrom()
- receives message/data from the socket.
```

ssize_t recvrom(int sockfd, void *buf, size_t len, struct sockaddr *src_addr, socklen_t *addrlen);
```


## close()
- Closes connection once usage is completed.
- frees up the port.

```
/**
* sockfd: socket created using socket()
* Return: 0 for success and -1 if any error occurs.
*/
int close(int sockfd)
```


# functions
- getaddrinfo()
- freeaddrinfo()


# structs
struct addrinfo
struct sockaddr
struct sockaddr_storage --> used in accept to store address details for connected client.
getnameinfo() --> printing address details of clients.


