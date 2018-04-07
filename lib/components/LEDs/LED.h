#include<mbed.h>

#ifndef LED_H
#define LED_H

/**
 * @brief Describes an LED component.
 *
 * Version: 1.3
 * Date: 23/03/2018
 * Originally Created: 21/03/2018
 */
class LED
{
    private:
        //[pinName] This is the name of the pin that the LED is wired to.
        PinName pinName;

    public:
        //[digitalOut] Refers to the digital output from the LED.
        DigitalOut digitalOut;

        /**
         * @brief Constructor for the LED class.
         * @param pinName This is the name of the pin that the LED is wired to.
         */
        LED(PinName pinName);

        /**
         * @return Returns the name of the pin that the LED is wired to.
         */
        PinName getPinName();

        /**
         * Turns the LED on.
         */
        void on();

        /**
         * Turns the LED off.
         */
        void off();
};

#endif // LED_H
