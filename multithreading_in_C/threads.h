#ifndef THREADS_H
#define THREADS_H
#include <pthread.h>
/**
 * for threads we will use pthread.h library
 * create, manipulate and exit threads
 * The following functions in pthread.h are uses;
 * 				pthread_create
 * 				pthread_join
 * 				pthread_self
 * 				pthread_equal
 * 				pthread_exit
 * 				pthread_cancel
 * 				pthread_detach
 */

// pthread_create
/**
 * pthread_create - function to create a thread.
 * @thread: returns the thread id, which is unsigned long int.
 * @attr: properties assigned to a thread ... if it a normal thread, we will set the attr = NULL
 * @start_routine: Points to the subroutines that execute by thread.
 */
int pthread_create(pthread *thread, const pthread_attr_t *attr, void * (*start_routine)(void *), void *arg);

/**
 * pthread_join - waits for the termination of a running thread and joins it back the main thread.
 * @thread: the thread we are working with.
 * @return: the return value of the previous thread and is NULL
 * Return: 0 on success and -1 on failure
 */

int pthread_join(pthread_t *thread, void **thread_return);


/**
 * pthread_self - returns thread id of currently running program
 * Return: Int of id of the currently running program.
 */


pthread_t pthread_self();
// or
int pthread_self()

/**
 * pthread_equal - Checks whether 2 or more threads are equal or not.
 * @thread1: the first thread to Check
 * @thread2: the second thread to Check
 * Return: if the two threads are equal, it returns a non-zero value. If they are not equal it returns zero as the value.
 */

int pthread_equal(pthread_t thread1, pthread_t thread2);


/**
 * pthread_exit - terminates a calling thread.
 * @retval: the return value of the thread you want to detach
 * Return: Nothing
 */

void pthead_exit(void *retval)



#endif
