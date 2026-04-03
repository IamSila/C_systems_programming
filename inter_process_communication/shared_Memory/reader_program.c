#include <stdio.h>
#include <sys/shm.h>
#include <sys/ipc.h>



/**
* main - entry point to the program
* Return: Always 0 on success, otherwise on failure
*/


int main(void)
{
  /** ftok to generate a unique key */
  key_t key = ftok("memory", 67);

  /** shmget returns an identiier in shmid */
  int shmid = shmget(key, 1024, 0666| IPC_CREAT);
  if (shmid == -1)
  {
    perror("Unable to connect with the shared memory segment\n");
  }

  /** shmat to attach to shared memory */
  char *str = (char *)shmat(shmid, (void *)0, 0);

  printf("Data read from memory: %s\n", str);

  /** detach from shared memory */
  shmdt(str);

  /** destroy the shared memory */
  shmctl(shmid, IPC_RMID, NULL);

  return (0);
}
