#ifndef ESP_IOT_COMPONENT
#define ESP_IOT_COMPONENT

#include <Arduino.h>
#include <functional>

struct empty_unit
{
};

template <class T> class EspComponent
{
public:
  virtual void setup(){};
  virtual void setup(T setup_config){};
  virtual void update(){};
  virtual void setValue(){};
  virtual void setValue(float value){};
};

#endif