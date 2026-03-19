#include "timer.h"

static unsigned int system_time = 0;

void timer_init(void)
{
    system_time = 0;
}

void timer_tick(void)
{
    system_time++;   // simulate 1 ms tick
}

unsigned int get_time(void)
{
    return system_time;
}
