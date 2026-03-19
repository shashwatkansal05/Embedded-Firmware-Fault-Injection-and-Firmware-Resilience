#include "timer.h"

#include "scheduler.h"
#include "sensor_task.h"
#include "control_task.h"
#include "logger_task.h"
#include "monitor_task.h"

static unsigned int last_sensor_time = 0;
static unsigned int last_control_time = 0;

void scheduler_run(system_state_t *sys)
{
    unsigned int now = get_time();

    // Run sensor every 10 ms
    if (now - last_sensor_time >= 10)
    {
        sensor_task(sys);
        last_sensor_time = now;
    }

    // Always run monitor & logger
    monitor_task(sys);
    logger_task(sys);

    // Run control every 20 ms
    if (now - last_control_time >= 20)
    {
        control_task(sys);
        last_control_time = now;
    }
}
