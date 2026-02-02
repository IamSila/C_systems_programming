#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include "creating_threads.h"
#include <stdlib.h>
/**
 * struct arguments - contains the person data
 * @name: name of the person
 * @age: age of the person
 * @bloodGroup: bloodgroup of the person
 */

struct arguments
{
	char *name;
	int age;
	char *bloodGroup;
};



/**
 * sayGreetings - prints name, group and bloodgroup
 * @data: data structure containing the data
 */


void *sayGreetings(void *data)
{
	printf("Name is %s",((struct arguments *)data)->name);
	printf("Age is %d", ((struct arguments*)data)->age);
	printf("Blood Group: %s\n", ((struct arguments*)data)->bloodGroup);
	return (NULL);
}




/**
 * main - entry point for the program
 * Return: 0 on success nonzero on failure
 */

int main(void)
{

	pthread_t thread;

	struct arguments *person =(struct arguments *) malloc(sizeof(struct arguments));
	person->name = "cee0xh4ck3r";
	person->age = 20;
	person->bloodGroup = "D";


	pthread_create(&thread, NULL, sayGreetings, (void *) person);
	pthread_join(thread, NULL);
	return (0);
}
