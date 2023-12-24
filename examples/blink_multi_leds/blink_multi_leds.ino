/**
 * @file blink_multi_leds.ino
 * @brief Blink multiple LEDs with PollingTimer library
 *
 * This example shows how to blink multiple LEDs with PollingTimer library.
 * The PollingTimer library is a simple library for Arduino that allows you to
 * call a function periodically with a specified interval.
 *
 * @see
 */
#include "Arduino.h"
#include "PollingTimer.h"

#define RED_LED_PIN 2
#define YELLOW_LED_PIN 3

PollingTimer task1;
PollingTimer task2;
PollingTimer task3;

void blink_led_red() {
    static bool ledStateRed = LOW;

    digitalWrite(RED_LED_PIN, ledStateRed);
    ledStateRed = !ledStateRed;
}

void blink_led_yellow() {
    static bool ledStateYellow = LOW;

    digitalWrite(YELLOW_LED_PIN, ledStateYellow);
    ledStateYellow = !ledStateYellow;
}

void delay_fire() {
    task3.fire();
}

void setup() {
    pinMode(RED_LED_PIN, OUTPUT);
    pinMode(YELLOW_LED_PIN, OUTPUT);

    task1.setInterval(blink_led_red, 500, true);
    task2.setInterval(delay_fire, 10000, false);
    task3.setInterval(blink_led_yellow, 1200, true);
    task1.fire();
    task2.fire();
}

void loop() {
    task1.handler();
    task2.handler();
    task3.handler();
    delay(10);
}