#include "system_state.h"

void system_init(system_state_t *sys)
{
    sys->system_running = 0;
    sys->sensor_value = 0;
    sys->active_fault = fault_none;
}
