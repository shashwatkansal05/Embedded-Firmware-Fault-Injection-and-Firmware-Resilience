#include "logger_task.h"
#include <stdio.h>
#include "timer.h"   

void logger_task(system_state_t *sys)
{
    unsigned int now = get_time();   

   
    printf("Time: %u | Sensor: %d | Running: %d | Fault: %d\n",
           now,
           sys->sensor_value,
           sys->system_running,
           sys->active_fault);

   
    FILE *fp = fopen("log.csv", "a");

    if (fp != NULL)
    {
        fprintf(fp, "%u,%d,%d,%d\n",
                now,
                sys->sensor_value,
                sys->system_running,
                sys->active_fault);

        fclose(fp);
    }
}
