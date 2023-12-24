/**
 * @file PollingTimer.h
 * @brief PollingTimer library for Arduino
 * @author Toshihiko Arai
 *
 * @version 0.2.1
 * @date 2023-12-07
 * @license MIT
 *
 * https://101010.fun/
 */
#ifndef PollingTimer_h
#define PollingTimer_h

#include "Arduino.h"

#define POLLING_TIMER_DEBUG

#ifdef POLLING_TIMER_DEBUG
#define LOG(...)                   \
    {                              \
        Serial.print(__VA_ARGS__); \
        Serial.flush();            \
    }
#define LOG_LN(...)                  \
    {                                \
        Serial.println(__VA_ARGS__); \
        Serial.flush();              \
    }
#else
#define LOG(...)
#define LOG_LN(...)
#endif /* POLLING_TIMER_DEBUG */

typedef void (*PollingTimerCallback)();

class PollingTimer {
   public:
    PollingTimer(bool debug = false, const char* name = nullptr);

    void setInterval(PollingTimerCallback callback, unsigned long delay, bool isLoop);
    void fire();
    void cancel();
    void handler();
    void printRemainTime();
    bool isFired();

   private:
    PollingTimerCallback _callback;
    void resetTimer();
    long getRemainTime();
    bool isLimited();
    unsigned long _startTime;
    unsigned long _delay;
    bool _isFired;
    bool _done;
    bool _isLoop;
    bool _debug;
};
#endif  // PollingTimer_h