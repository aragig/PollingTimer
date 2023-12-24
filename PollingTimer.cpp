/**
 * @file PollingTimer.cpp
 * @brief PollingTimer library for Arduino
 * @author Toshihiko Arai
 *
 * @version 0.2.1
 * @date 2023-12-07
 * @license MIT
 *
 * https://101010.fun/
 */
#include "PollingTimer.h"

PollingTimer::PollingTimer(bool debug, const char* name)
    : _startTime(0),
      _delay(0),
      _isLoop(0),
      _debug(debug),
      _isFired(false),
      _done(false) {
}

void PollingTimer::setInterval(PollingTimerCallback callback, unsigned long delay, bool isLoop) {
    Serial.begin(115200); //! コンストラクタで宣言すると動かない
    _callback = callback;
    _delay = delay;
    _isLoop = isLoop;
}

bool PollingTimer::isFired() { return _isFired; }

void PollingTimer::fire() {
    if (!isFired()) {
        _isFired = true;
        _done = false;
        resetTimer();
        LOG_LN("timer fired!");
    }
}

void PollingTimer::cancel() {
    _isFired = false;
    LOG_LN("timer canceled!");
}

void PollingTimer::handler() {
    if (_done || !isFired()) {
        return;
    }
    if (_isLoop) {
        if (isLimited()) {
            _callback();
            resetTimer();
        }
    } else {
        if (isLimited()) {
            _callback();
            _done = true;
        }
    }
    if (_debug) {
        printRemainTime();
    }
}

void PollingTimer::printRemainTime() {
    long remain = getRemainTime();
    LOG("         ");
    LOG("\r");
    LOG(remain);
    if (remain < 0) {
        LOG_LN();
    }
}

/* Private */
bool PollingTimer::isLimited() { return getRemainTime() < 0; }

long PollingTimer::getRemainTime() { return _delay - (millis() - _startTime); };

void PollingTimer::resetTimer() { _startTime = millis(); }