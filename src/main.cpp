#include <mbed.h>
#include <rtos.h>
#include <mbed_events.h>
#include "components.h"

AssignmentBoard board;

LED redLED(board.K64F_RED_LED);
LED greenLED(board.SHIELD_GREEN_LED);

void flashRed(void)
{
    redLED.toggle();
}

void flashGreen(void)
{
    greenLED.toggle();
}

Serial pc(USBTX, USBRX);
Thread worker;
EventQueue queue;

Thread thread;

int main()
{
    pc.printf("ready");

    queue.call_every(500, flashRed);
    queue.call_every(500, flashGreen);

    pc.printf("dispatching...");

    //queue.dispatch_forever();

    worker.start(callback(&queue, &EventQueue::dispatch_forever ));

    pc.printf("dispatched");

    while(1){}
}
