#include "scheduler.h"

template <class T> void EspScheduler::iotScheduler(uint16_t period, T scheduled_task)
{
  static uint32_t counter = millis();
  if ((millis() - counter) >= period)
  {
    scheduled_task();
    counter = millis();
  }
}