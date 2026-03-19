#include "control_task.h"
#include <stdio.h>
#include <stdlib.h>   

void control_task(system_state_t *sys)
{
    int threshold = 90;

    //  Fault: Task starvation → skip execution
    if (sys->active_fault == fault_task_starvation)
    {
        printf("[FAULT] Control Task Starved (skipping execution)\n");
        return;
    }

    int sensor = sys->sensor_value;

    //  Fault: Sensor glitch → misinterpret value
    if (sys->active_fault == fault_sensor_glitch)
    {
        printf("[FAULT] Control misinterpreting sensor value!\n");
        sensor = sensor + 50;   // distortion (not actual sensor)
    }

    //  Fault: Queue overflow → unstable/random data
    if (sys->active_fault == fault_queue_overflow)
    {
        printf("[FAULT] Queue Overflow! Unstable data\n");
        sensor = rand() % 150;  // unpredictable behavior
    }

    //  Normal control logic (using possibly modified sensor)
    if (sensor > threshold)
    {
        sys->system_running = 0;
    }
    else
    {
        sys->system_running = 1;
    }

    //  Fault handling (your original idea)
    if (sys->active_fault != fault_none)
    {
        printf("Control: Handling fault...\n");

        // simulate recovery after one cycle
        sys->active_fault = fault_none;
    }
}
