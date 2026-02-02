#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>


/**
 * threading - prints a simple value on the screen
 * Return: Nothing
 */


void *threading(void *add);

/**
 * main - entrance of the program.
 * Return: Always 0 for success, non 0 otherwise
 */

int main(void)
{
	pthread_t thread;
	int value = 10;
	pthread_create(&thread, NULL, threading, (void *) &value);
	pthread_join(thread, NULL);
	return (0);
}

void *threading(void *add)
{
	long *add_value = (long *) add;
	printf("Threading in C, %d", *add_value);
	return NULL;
}
