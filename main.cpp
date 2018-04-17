#include "mbed.h"
#include "rtos.h"

DigitalOut LED[3] = {
    DigitalOut(LED1),
    DigitalOut(LED2),
    DigitalOut(LED3)
};

void blink(void const *n) {
    LED[(int)n] = !LED[(int)n];
}

int main() {
    RtosTimer led_1_timer(blink, osTimerPeriodic, (void *)0);
    RtosTimer led_2_timer(blink, osTimerPeriodic, (void *)1);
    RtosTimer led_3_timer(blink, osTimerPeriodic, (void *)2);
        
    led_1_timer.start(2000);
    led_2_timer.start(1000);
    led_3_timer.start(500);
    Thread::wait(osWaitForever);
}
