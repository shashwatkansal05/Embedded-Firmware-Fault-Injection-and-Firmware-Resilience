#ifndef SYSTEM_STATE_H
#define SYSTEM_STATE_H

typedef enum{
fault_none=0,
fault_sensor_glitch,
fault_queue_overflow,
fault_task_starvation
} fault_type_t;

typedef struct{
int system_running;
int sensor_value;
fault_type_t active_fault;
} system_state_t;

void system_init(system_state_t *sys);

#endif

