#include "sysmon.h"
#define SIZE 1024;


/**
* cpu_monitor - monitor the state of the CPU
* Return: Nothong
*/


void cpu_monitor(void)
{
  FILE *fd;
  char line[20];
  char content[30];
  int fileDescriptor;
  mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;


  /** store the cpu details */
  struct cpu_metrics
  {
    long ctxt;
    long btime;
    long processes;
    long procs_running;
    long procs_blocked;
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
    sscanf(line, "ctxt %ld", &cpu1.ctxt);
    continue;
    sscanf(line, "btime %ld", &cpu1.btime);
    continue;
    sscanf(line, "processes %ld", &cpu1.processes);
    continue;
    sscanf(line, "procs_running %ld", &cpu1.procs_running);
    continue;
    sscanf(line, "procs_blocked %ld", &cpu1.procs_blocked);
    continue;
  }

  printf("%ld", cpu1.ctxt);

  fileDescriptor = open("/var/log/sysmon.log", O_CREAT | O_RDWR | O_APPEND, mode);


  snprintf(content, sizeof(content), "Ctxt: %ld\n", cpu1.ctxt);
  write(fileDescriptor, content, sizeof(content));
  snprintf(content, sizeof(content), "Btime: %ld\n", cpu1.btime);
  write(fileDescriptor, content, sizeof(content));
  snprintf(content, sizeof(content), "Processes: %ld\n", cpu1.processes);
  write(fileDescriptor, content, sizeof(content));
  snprintf(content, sizeof(content), "procs running: %ld", cpu1.procs_running);
  write(fileDescriptor, content, sizeof(content));
  snprintf(content, sizeof(content), "Procs blocked: %ld", cpu1.procs_blocked);
  write(fileDescriptor, content, sizeof(content));



}
