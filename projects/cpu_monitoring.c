#include "sysmon.h"
#define SIZE 300
#define NUM_CPU_MONITOR_MEMBERS 5
#define TEST_LINE "test line"

typedef unsigned long long llu;


/*
 * _strlen - returns the length of a string
 * Return: Length of a string
 */



/**
* cpu_monitor - monitor the state of the CPU
* Return: Nothong
*/


void cpu_monitor(void)
{
  FILE *fd;
  char line[SIZE];
  int fileDescriptor;
  char content[SIZE];
  char *content_ptr;
  int write_status;
  int count;
  int i; /* used this in loop */
  char *log_opening_line;

/* stores return values for snprintf 
  int Ctxt_Metric;
  int Btime_Metric;
  int Processes_Metric;
  int Procs1_Metric;
  int ProcsBlockedMetric;
  int fileDescriptor;
*/

  mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
  content_ptr = malloc(sizeof(char) * sizeof(content));
  count = 0;
  log_opening_line = "CUSTOM SYSTEM MONITOR ______author: cii0xh4ck3r";

  /** store the cpu details */
  struct cpu_metrics
  {
    int ctxt;
    int btime;
    int processes;
    int procs_running;
    int procs_blocked;
  };

  struct cpu_metrics cpu1;




  fd = fopen("/proc/stat", "r");
  

  if (fd == NULL)
  {
    printf("Error: /proc/stat not open\n");
    exit(EXIT_SUCCESS);
  }

  while (fgets(line, sizeof(line), fd))
  {
    sscanf(line, "ctxt %d", &cpu1.ctxt);
    sscanf(line, "btime %d", &cpu1.btime);
    sscanf(line, "processes %d", &cpu1.processes);
    sscanf(line, "procs_running %d", &cpu1.procs_running);
    sscanf(line, "procs_blocked %d", &cpu1.procs_blocked);
  }
 
  fclose(fd);

  fileDescriptor = open("/var/log/sysmon.log", O_RDWR | O_APPEND | O_CREAT, mode);
  
  if (fileDescriptor > 0)
  {
    printf("/var/log/symon.log successfully created\n");
  }

  /* writing ctxt to the log file */
  while ((count < NUM_CPU_MONITOR_MEMBERS))
  {
    while (read(fileDescriptor, line, sizeof(line)))
    {
      if (strlen(line) < 1)
      {
        /** pick up from here */
        execle("/bin/echo","echo", log_opening_line, ">", fileDescriptor);
      }
      if (strncmp(line, "ctxt:", 5) == 0)
      {
        continue;
      }
      else 
      {
        snprintf(content, SIZE, "ctxt: %d\n", cpu1.ctxt);
        for (i = 0; i < sizeof(content) + 1; i++)
        {
          content_ptr[i] = content[i];
        }
        content_ptr[i] = '\0';
        write_status = write(fileDescriptor, content_ptr, strlen(content_ptr));

      }


      if (strncmp(line, "btime:", 5) == 0)
      {
        continue;
      }
      else 
      {
        snprintf(content, SIZE, "btime: %d\n", cpu1.btime);
        for (i = 0; i < sizeof(content) + 1; i++)
        {
          content_ptr[i] = content[i];
        }
        content_ptr[i] = '\0';
        write_status = write(fileDescriptor, content_ptr, strlen(content_ptr));
      }

      if (strncmp(line, "processes", 9) == 0)
      {
        continue;
      }
      else 
      {
        snprintf(content, SIZE, "processes: %d\n", cpu1.processes);
        for (i = 0; i < sizeof(content) + 1; i++)
        {
          content_ptr[i] = content[i];
        }
        content_ptr[i] = '\0';
        write_status = write(fileDescriptor, content_ptr, strlen(content_ptr));
      }
      if (strncmp(line, "procs_running", 13) == 0)
      {
        continue;
      }
      else 
      {
        snprintf(content, SIZE, "procs_running: %d\n", cpu1.procs_running);
        for (i = 0; i < sizeof(content) + 1; i++)
        {
          content_ptr[i] = content[i];
        }
        content_ptr[i] = '\0';
        write_status = write(fileDescriptor, content_ptr, strlen(content_ptr));
      }
      if (strncmp(line, "procs_blocked", 13) == 0)
      {
        continue;
      }
      else 
      {
        snprintf(content, SIZE, "procs_blocked: %d\n", cpu1.procs_blocked);
        for (i = 0; i < sizeof(content) + 1; i++)
        {
          content_ptr[i] = content[i];
        }
        content_ptr[i] = '\0';
        write_status = write(fileDescriptor, content_ptr, strlen(content_ptr));
      }
      break;
    }

    if (write_status == -1)
    {
      perror("Error: Could not write to /var/log/sysmon.log\n");
    }

    count++;
  }

  free(content_ptr);

}



int main(void)
{
  cpu_monitor();
  return (0);
}
