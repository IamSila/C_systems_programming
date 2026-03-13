#include "sysmon.h"


/**
 * creating_child_process - creates a child process and exits from the parent process
 * Return: The id of the child process
 */


int creating_child_process(void)
{
  pid_t pid;
  int fd;
  char buff[10];
  int write_status; 
  mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;

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
  else
  {
    printf("Exiting from the parent process\n");
    _Exit(EXIT_SUCCESS);
  }

  /** writing the stdin, out and error to /dev/null 
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

*/

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
  fd = open("/var/run/sysmon.pid", O_RDWR | O_CREAT, mode);
  if (fd > 0)
  {
    printf("/var/run/sysmon.pid: open successfully\n");
  }
  else
  {
    perror("Failed to open /var/run/sysmon.pid\n");
    _Exit(EXIT_FAILURE);
  }
  
  snprintf(buff, sizeof(buff), "%d\n", getpid());
  write_status = write(fd, buff, sizeof(buff));
  
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

  
  printf("Get pwd %s", getenv("PWD"));

  
  return (pid);
}




/**
* main - entrance of the main program
* Return: Always 0
*/



int main(void)
{
  int pwd_status;
  char *root_directory;
  char DIR[100];
  char *current_directory;

  root_directory = "/";
 
  pwd_status = chdir(root_directory);

  if (pwd_status == -1)
  {
    perror("Directory not changed\n");
    getcwd(DIR, sizeof(DIR));
  }
  else {
    current_directory = getcwd(DIR, sizeof(DIR));
    printf("Directory changed to: %s \n", current_directory);
  }


  /** I create a child process */
  creating_child_process();
  memory_monitor();
  cpu_monitor();
  return (0);
}
