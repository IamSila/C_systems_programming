#ifndef _SYSMON
#define _SYSMON

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <error.h>


mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;

void memory_monitor(void);
void cpu_monitor(void);





#endif
