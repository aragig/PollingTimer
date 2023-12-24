#include "Arduino.h"
#include "PollingTimer.h"

PollingTimer task1;
PollingTimer task2;
PollingTimer task3;

void do_task1() {
    Serial.print("Do task1");
    Serial.println();
}

void do_task2() {
    Serial.print("Do task2");
    Serial.println();
}

void all_cancel() {
    Serial.println("All cancel!");
    task1.cancel();
    task2.cancel();
    task3.cancel();
}

void setup() {
    task1.setInterval(do_task1, 1000, true);
    task1.fire();
    task2.setInterval(do_task2, 3000, true);
    task2.fire();
    task3.setInterval(all_cancel, 30000, true);
    task3.fire();
}

void loop() {
    task1.handler();
    task2.handler();
    task3.handler();
    delay(10);
}