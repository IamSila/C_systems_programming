# understanding POSIX standards
- POSIX -> portable Operating System Interace
- These rules are classified into 3:
    1. posix.1
    2. posix.1b
    3. posix.1c
    4. posix2

# Introduction to APIS
- It will have 2 modes: `user mode or supervisor mode`.

## User mode
- developers typically develop programs to incorporate or manipulate
custom activities in the system.

## supervisor mode
- system calls perform the actions written by the developers.

# System calls available for file operations:
    - creat: creates a new empty file, fcntl.h
    - open
    - close
    - read
    - write
- Most common modes are:
    - O_RDONLY: read only permission
    - O_WRONLY: write permisions
    - O_RDWR: read and write permissions
    - O_EXCL: prevents creation if a file exists
    - O_APPEND: add contents to an existing file
    - O_CREAT: create a file that does not exist.
    - NB: if you want to use multiple modes, you can use the bitwise OR  operator (|)
    -
