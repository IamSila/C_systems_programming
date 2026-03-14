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
     unsigned int processes;
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
    printf("%s", line);

  }
  
  fclose(fd);


 

  fileDescriptor = open("/var/log/sysmon.log", O_RDWR | O_CREAT, mode);
  
  if (fileDescriptor > 0)
  {
    printf("/var/log/symon.log successfully created");
  }




}



int main(void)
{
  cpu_monitor();
  return (0);
}
