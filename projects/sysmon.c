#include <stdio.h>
#include <stdlib.h>
/**#include <signal.h> */
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define EXIT_CODE 0

/**
 * creating_child_process - creates a child process and exits from the parent process
 * Return: The id of the child process
 */

int creating_child_process(void)
{
  pid_t pid;
  int pwd_status;
  int fd;
  char buff[10];
  int write_status;
  char *root_directory = "/";

  pid = fork();

  if (pid < 0)
  {
    printf("Child process not created successfully\n");
    _Exit(EXIT_FAILURE);
  }
  else if(pid ==  0)
  {
    printf("Child created successfully\n");
  }
  else if (pid > 1)
  {
    printf("Exiting from the parent process\n");
    _Exit(EXIT_SUCCESS);
  }

  /** writing the stdin, out and error to /dev/null */
  fd = open("/dev/null", O_RDWR);
  if (fd == -1)
  {
    perror("file not opened\n");
    exit(EXIT_FAILURE);
  }

  for (int i = 0; i < 3; i++)
  {
    dup2(fd, i);
  }

  if (fd > 2)
  {
    close(fd);
  }


  /** daemonising the child proces */
  if (setsid() < 0)
  {
    perror("Process not Daemonised\n");
    exit(EXIT_FAILURE);
  }
  else 
  {
    printf("Process daemonised\n");
  }

  /** sending the pid to /var/run/sysmon.pid */
  fd = open("/var/run/sysmon.pid", O_RDWR);
  if (fd > 0)
  {
    printf("File open successfully\n");
  }
  else
  {
    perror("Failed to open /var/run/sysmon.pid\n");
  }
  
  snprintf(buff, sizeof(buff), "%d", getpid());
  write_status = write(fd, buff, strlen(buff));
  
  if (write_status == -1)
  {
    perror("daemon not written in /var/run/sysmon.pid\n");
  }

  close(fd);

  while (1)
  {
    printf("Daemon running\n");
    sleep(1);
    break;
  }

  pwd_status = chdir(root_directory);

  if (pwd_status == -1)
  {
    perror("Directory not changed\n");
  }
  else {
    printf("pwd: / \n");
  }

  printf("Get pwd %s", getenv("PWD"));


  return (pid);
}




/**
* main - entrance of the main program
* Return: Always 0
*/



int main(void)
{

  /** I create a child process */
  creating_child_process();

  
  

  return (0);
}
