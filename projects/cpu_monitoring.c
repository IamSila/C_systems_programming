#include "sysmon.h"

/**
* cpu_monitor - monitor the state of the CPU
* Return: Nothong
*/


void cpu_monitor(void)
{
  FILE *fd;
  char line[20];
  long ctxt;
  long btime;
  long processes;
  long procs_running;
  long procs_blocked;
  char content[30];
  int file_descriptor;


  fd = fopen("/proc/stat", "r");

  if (fd == NULL)
  {
    perror("Error: /proc/stat not open\n");
    exit(EXIT_SUCCESS);
  }

  while (fgets(line, sizeof(line), fd))
  {
    sscanf(line, "ctxt %ld", &ctxt);
    continue;
    sscanf(line, "btime %ld", &btime);
    continue;
    sscanf(line, "processes %ld", &processes);
    continue;
    sscanf(line, "procs_running %ld", &procs_running);
    continue;
    sscanf(line, "procs_blocked %ld", &procs_blocked);
    continue;
  }

  file_descriptor = open("/var/run/sysmon.log", O_APPEND);
  snprintf(content, sizeof(content), "ctxt: %ld\n\n\n\n", ctxt);
  write(file_descriptor, content, sizeof(content));
  snprintf(content, sizeof(content), "btime: %ld\n", btime);
  write(file_descriptor, content, sizeof(content));
  snprintf(content, sizeof(content), "Processes: %ld\n", processes);
  write(file_descriptor, content, sizeof(content));
  snprintf(content, sizeof(content), "Procs_running: %ld", procs_running);
  write(file_descriptor, content, sizeof(content));
  snprintf(content, sizeof(content), "Procs_blocked: %ld", procs_blocked);
  write(file_descriptor, content, sizeof(content));

}
