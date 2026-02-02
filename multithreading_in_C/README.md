# Multithreading inc C
- Ability to execute multiple threads at the same to max out usage of the CPU
- Concurrency: executing multiple threads at the same time.


# Threads
- Light weight process that shares address space with the owner process.
- Every thread has a program counter and a stack space for storing an activity.

# Thread classification
## User level threads.
- User creates threads with thread libraries other than system calls.
- Context switching is done in user space, with a thread library.
- User level threads are represented by a program counter.
- Multiprocessing may be difficult coz it is independent of the kernel.
- They require non blocking I/O, otherwise entire process may be blocked in the kernel.

## Kernel-Level Threads.
- Created by the OS directly.
- The kernel does thread management with a thread table that helps the kernel monitor all the activities done by a thread in the system.
- Examples are `Win32 and Solaris`
- They are slower as compared to user level threads.
- Hard to create and manage.
- Multiple switching is required to transfer control from one thread to another.

# Processes vs Threads.
- Process is a program that is executing, while a thread is a light weight process within a process.
- The `5 stage life cycle` of a process and threads are:
    - New
        - new process created and added to the queue.
        - Created with `fork()`.
        - In this state, process is created but is not running.
    - Ready
        - ready for execution.
    - Wait
        - The process has been blocked for some reson or some time.
        - Once it resumes, it goes to the ready state.
    - Running
        - If we call sleep it goes to the wait state.
    - Terminated
        - State for a completed process.

# Introduction to Multithreading
## Multithreading architecture
- Multiple threads in one process to execute a task.
- All the threads share a common memory space and allocation.

## Benefits of Multithreading
- Efficient resouce sharing
- Application scalability
- Responsiveness
- Efficienct memory utilization
- Efficient CPU utilization

# Concurrency
- Mechanism that `decreases the response time of a system by using a single processing unit.`
- In concurrency, `a major task is divided into subtasks that execute simultaneously BUT NOT AT THE SAME TIME.`

# Parallelism
- `is a mechanism that increases computational speed by using multiple processors.`
- Tasks are executing simultaneously and at the same time.
