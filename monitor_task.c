#include "monitor_task.h"
#include <stdio.h>
#include "timer.h"

void monitor_task(system_state_t *sys)
{
    unsigned int now = get_time();

    printf("[Time %u] Monitor running\n", now);

    
    static int sensor_fault_done = 0;
    static int queue_fault_done = 0;
    static int starvation_fault_done = 0;

    
    if (!sensor_fault_done && now >= 50)
    {
        sys->active_fault = fault_sensor_glitch;
        printf("[Time %u] Fault Injected: Sensor Glitch\n", now);
        sensor_fault_done = 1;
    }

    
    if (!queue_fault_done && now >= 100)
    {
        sys->active_fault = fault_queue_overflow;
        printf("[Time %u] Fault Injected: Queue Overflow\n", now);
        queue_fault_done = 1;
    }

   
    if (!starvation_fault_done && now >= 150)
    {
        sys->active_fault = fault_task_starvation;
        printf("[Time %u] Fault Injected: Task Starvation\n", now);
        starvation_fault_done = 1;
    }
}
