#ifndef ESP_IOT_SCHEDULER
#define ESP_IOT_SCHEDULER

#include <Arduino.h>
#include <functional>

class EspScheduler
{
public:
  template <class T> void iotScheduler(uint16_t period, T scheduled_task);
};

#endif