# Linux architecture
- Four layers...
    - Hardware layer.
        - Contains Drivers for handling peripheral devices
    - Kernel
        - Heart of the OS.
        - Interface btwn h/w and applications.
    - Shell
    - System library


# Types of Kernels
- Monolithic - User space and kernel space not shared. User space can only access the kernel space via system calls only.
- Microkernel - Different user space for user space and kernel space.
- Hybrid Kernel - Used by windows and macos.
- Nanokernel
- Exokernel


# Shell
- Executes other commands on a UNIX OS.
- Examples are : zsh, bash, cshell(csh), Tenex c shell(tcsh), korn shell(ksh), posix shell (sh)

#System Library
- Contains special fxns to access the kernel's features.

#File Permissions
- read write execute (rwx).
- [who] ->[u]user, [g]group, [o]others, [a]all
- + -> adds permissions.
- - -> removes permissions
- = -> add specified permissions and take away all the others.
[chmod ugoa-rwx filename]


# Changing permissions with weights
- Read: 4
- write: 2
- execute: 1

chmod 754 filename.txt
u - rwx -> 7 (4 + 2 + 1)
g - r-x -> 5 (4 + 0 + 1)
o - r-- -> 4 (4 + 0 + 0)

# Networking commands
- ping
- host
- nslookup
- whois
- traceroute
- dig
- ifconfig
- netstat
