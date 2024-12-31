#include "mbed.h"
#include "rtos.h"

DigitalOut LED[3] = {
    DigitalOut(LED1),
    DigitalOut(LED2),
    DigitalOut(LED3)
};

Ticker led_1_ticker;
Ticker led_2_ticker;
Ticker led_3_ticker;

void blink(void const *n)
{
    LED[(int)n] = !LED[(int)n];
}

int main()
{
    led_1_ticker.attach(callback(blink, (void *)0), 2000ms);
    led_2_ticker.attach(callback(blink, (void *)1), 1000ms);
    led_3_ticker.attach(callback(blink, (void *)2), 500ms);

    while (1) {
        ThisThread::sleep_for(2000ms);
    }
}
