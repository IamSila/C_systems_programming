#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include "creating_threads.h"


/**
 * customThreadFunction - used in multithreading
 * Return: Nothing
 */

void *customThreadFunction(void *number)
{
	int *num = (int *) number;
	for (int i = 0; i < 15; i++)
	{
		printf("I am a custom thread function with argument %d created by programmer Sila\n", *num);
		sleep(1);
		if (i == 3)
		{
			printf("I am being terminated by the programmer, my job is done\n");
			pthread_exit(NULL);
		}
	}
	return NULL;
}

/**
 * main - entry point of the function
 * Return: 0 success non zero for failure
 */

int main(void)
{
	pthread_t thread;
	int status;
	int number;

	number = 10;
	status = pthread_create(&thread, NULL, customThreadFunction, (void *) &number);
	if (!status)
	{
		printf("custom Function Created Successfully");
		sleep(1);
	}

	for (int i = 0; i < 15; i++)
	{
		printf("I am the process created by the compiler by default\n");
		sleep(1);
	}
	return (0);
}
