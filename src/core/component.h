#ifndef ESP_IOT_COMPONENT
#define ESP_IOT_COMPONENT

#include <Arduino.h>
#include <functional>

class Component
{
public:
  virtual void setup();
  virtual void update();
  virtual void setValue();
};

#endif