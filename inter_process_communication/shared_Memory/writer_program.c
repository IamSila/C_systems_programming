#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>




/**
* main - entry point for the program
* Return: Always 0 on success and otherwise on failure
*/


int main(void)
{
  /** ftok is used to generate unique key*/
  key_t key = ftok("memory", 67);

  /** using shmget to generate a sharedmemory */
  int shmid = shmget(key, 1024, 0666|IPC_CREAT);

  if (shmid == -1)
  {
    perror("Unable to create shared memory segment");
  }

  /** attaching share memory address */
  char *str = (char *) shmat(shmid,(void *)0, 0);
  printf("Enter the data to write into the shared memory segment\n");
  scanf("%[^\n]s", str);
  printf("Data written in memory: %s\n", str);

  /** detach from shared memory */
  shmdt(str);


  return (0);
}

