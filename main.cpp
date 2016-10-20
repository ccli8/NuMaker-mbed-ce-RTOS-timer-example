#include "mbed.h"
#include "rtos.h"

DigitalOut LED[4] = {
    DigitalOut(PD_8), // rgbled_B
    DigitalOut(PD_9), // rgbled_R
    DigitalOut(PA_4), // rgbled_G
    DigitalOut(PG_0)  // greenled
};

void blink(void const *n) {
    LED[(int)n] = !LED[(int)n];
}

int main() {
    RtosTimer led_1_timer(blink, osTimerPeriodic, (void *)0);
    RtosTimer led_2_timer(blink, osTimerPeriodic, (void *)1);
    RtosTimer led_3_timer(blink, osTimerPeriodic, (void *)2);
    RtosTimer led_4_timer(blink, osTimerPeriodic, (void *)3);
        
    led_1_timer.start(2000);
    led_2_timer.start(1000);
    led_3_timer.start(500);
    led_4_timer.start(250);
    Thread::wait(osWaitForever);
}
