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

