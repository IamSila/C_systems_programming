#include "sysmon.h"
#define SIZE 300

typedef unsigned long long llu;


/**
* cpu_monitor - monitor the state of the CPU
* Return: Nothong
*/


void cpu_monitor(void)
{
  FILE *fd;
  char line[SIZE];
  char content[SIZE];

/* stores return values for snprintf */
  int Ctxt_Metric;
  int Btime_Metric;
  int Processes_Metric;
  int Procs1_Metric;
  int ProcsBlockedMetric;
  int fileDescriptor;


  mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;



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
    sscanf(line, "ctxt %d\n", &cpu1.ctxt);
    continue;
    sscanf(line, "btime %d\n", &cpu1.btime);
    continue;
    sscanf(line, "processes %d\n", &cpu1.processes);
    continue;
    sscanf(line, "procs_running %d\n", &cpu1.procs_running);
    continue;
    sscanf(line, "procs_blocked %d\n", &cpu1.procs_blocked);
    continue;
  }

  fclose(fd);


 

  fileDescriptor = open("/var/log/sysmon.log", O_RDWR | O_CREAT, mode);
  
  if (fileDescriptor > 0)
  {
    printf("/var/log/symon.log successfully created");
  }



  Ctxt_Metric = snprintf(content, sizeof(content), "Ctxt: %d\n", cpu1.ctxt);
  write(fileDescriptor, content, Ctxt_Metric);


  Btime_Metric = snprintf(content, SIZE, "Btime: %d\n", cpu1.btime);
  printf("%d", Btime_Metric);
  write(fileDescriptor, content, Btime_Metric);


  /* Process */
  Processes_Metric = snprintf(content, SIZE, "Processes: %d\n", cpu1.processes);
  write(fileDescriptor, content, Processes_Metric);


  Procs1_Metric = snprintf(content, SIZE, "procs running: %d\n", cpu1.procs_running);
  printf("%d", Procs1_Metric);
  write(fileDescriptor, content, Procs1_Metric);



  ProcsBlockedMetric = snprintf(content, SIZE, "Procs blocked: %d\n", cpu1.procs_blocked);
  write(fileDescriptor, content, ProcsBlockedMetric);


}



int main(void)
{
  cpu_monitor();
  return (0);
}
