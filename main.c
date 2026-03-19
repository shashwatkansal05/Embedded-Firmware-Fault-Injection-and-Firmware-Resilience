#include <stdio.h>

#include "system_state.h"
#include "scheduler.h"
#include "timer.h"

int main(void)
{
    system_state_t sys;

    printf("=== Firmware Fault Injection Simulator Start ===\n");

    system_init(&sys);
    timer_init();   
    while (1)
    {
        timer_tick();         

        scheduler_run(&sys);

        for (volatile int i = 0; i < 1000000; i++);
    }

    return 0;
}
