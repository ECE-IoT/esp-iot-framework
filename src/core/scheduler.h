#ifndef ESP_IOT_SCHEDULER
#define ESP_IOT_SCHEDULER

#include <Arduino.h>
#include <functional>

namespace EspScheduler
{
template <class T> void iotScheduler(uint16_t period, T scheduled_task)
{
  static uint32_t counter = millis();
  if ((millis() - counter) >= period)
  {
    scheduled_task();
    counter = millis();
  }
}
} // namespace EspScheduler

#endif