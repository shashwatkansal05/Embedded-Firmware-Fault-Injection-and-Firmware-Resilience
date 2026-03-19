#include "sensor_task.h"
#include <stdlib.h>

void sensor_task(system_state_t *sys)
{
    int value;

    value = (rand() % 100) + 1; // GENERATE RANDOM VALUES BETWEEN 1 AND 100

    sys->sensor_value = value;
}
