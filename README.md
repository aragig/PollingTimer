# PollingTimer Library for Arduino and ESP32

## Overview
The `PollingTimer` is a simple timer library designed for Arduino and ESP32. This library offers timer functionalities based on polling, enabling pseudo-multithreading-like operations. It eschews interrupt processing for easier state management. Through its straightforward API, it allows easy scheduling of periodic tasks or operations after a specific delay.

## Key Features
- **Simple Interface**: Use the `setInterval` method to set up the callback function and execution intervals.
- **Flexible Timer Control**: Start (`fire`), stop (`cancel`), and check the state (`isFired`) of the timer.
- **Loop and One-shot Timers**: Choose between repeating or single execution.
- **Debug Support**: Detailed log output is possible in debug mode.

## How to Use
1. **Include the Library**:
   ```cpp
   #include "PollingTimer.h"
   ```

2. **Create a Timer Instance**:
   ```cpp
   PollingTimer timer;
   ```

3. **Set Up the Timer**:
   ```cpp
   timer.setInterval(yourCallbackFunction, interval, isLoop);
   ```

4. **Start the Timer**:
   ```cpp
   timer.fire();
   ```

5. **Call Handler in Main Loop**:
   ```cpp
   void loop() {
       timer.handler();
   }
   ```

## Example

[![Pseudo-multithreading-like LED blinking with PollingTimer on Arduino](docs/eyecatch-youtube.png)](https://youtu.be/0vzSfgHvaY4)

Here's a simple example of blinking an LED:
```cpp
#include "PollingTimer.h"
PollingTimer timer;

void blinkLED() {
    // Code to toggle LED state
}

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    timer.setInterval(blinkLED, 1000, true);
    timer.fire();
}

void loop() {
    timer.handler();
}
```

Please also see the examples folder.
