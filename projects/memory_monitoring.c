#include "sysmon.h"
#include <stdlib.h>

/**
 * memory_monitor - reads contents of /proc/meminfo
 * Return: Nothing
 */



void memory_monitor()
{
  FILE *fd;
  char buff[20];
  char content[50];
  int file_descriptor;

  long MemTotal = 0;
  long MemFree = 0;
  long MemAvailable = 0;
  long SwapTotal = 0;
  long SwapFree = 0;

  fd = fopen("/proc/meminfo", "r");

  if (fd == NULL)
  {
    perror("file not open. Try again\n");
    
  }

  /**
  * total memory, free memory, available memory, and swap usage.
  *
  * fgets(char *whereToStore, sizeofcharToRead, WhereToReadFrom)
  * sscanf(char *whereToStore, char *MatchString, Pointer_whereToStore)
  */

  while(fgets(buff, sizeof(buff), fd))
  {
    if(sscanf(buff, "MemTotal: %ld kB", &MemTotal) == 1)
      continue;
    if(sscanf(buff, "MemFree: %ld KB",&MemFree) == 1)
      continue;
    if(sscanf(buff, "SwapTotal: %ld KB", &SwapTotal ) == 1)
      continue;
    if(sscanf(buff, "SwapFree: %ld KB", &SwapFree) == 1)
      continue;
  }


  printf("Total Memory: %ld KB\n", MemTotal);
  printf("Free Memory: %ld KB\n", MemTotal);
  printf("Available Memory: %ld KB\n", MemAvailable);
  printf("Total Swap Memory: %ld KB\n", SwapTotal);
  printf("Free Swap Memory: %ld KB\n", SwapFree);
  printf("Used Swap Memory: %ld KB\n\n\n\n\n", (SwapTotal - SwapFree));
  printf("Credits to cii_h4ck3r -----  ;)\n");

  file_descriptor = open("/var/log/sysmon.log", O_CREAT | O_RDWR);
  if (file_descriptor == -1)
  {
    perror("File not opened\n");
    exit(EXIT_FAILURE);
  }


  /** write the stats to the file 
   * write(file_descriptor, void* buffer, size_t buffer)
   * */

  snprintf(content, sizeof(content), "Total Memory: %ld", MemTotal);
  write(file_descriptor, content, sizeof(content));


}

