#Inter Process Communication
- There are two types of IPC mechanisms: `synchronous and asynchronous`
- IPC in processes is archieved in two ways: message passing and memory sharing


## modes of Communication
- simples
- half duplex
- full duplex


- IPC happens in 2 ways: communication between related processes and communication between unrelated processes.
- The available mechanisms that achieve IPC in operating systems are discussed next.

## Pipes
- Establishes connection between 2 related processes.
- Are of 2 types: Named/ FIFO and unname/ anonymous pipes.
- Follows half duplex mechanism to establish communication.
- Has 2 file descriptors: One for writing and one for reading.
- Operations that use pipes are read and write operations.
- Pipe creates using a pipe system call.


