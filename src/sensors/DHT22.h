#ifndef VERT_PROT_SENSOR
#define VERT_PROT_SENSOR

#include "Arduino.h"
#include <DHT.h>

class DHT_Sensor : public Sensor
{
private:
  DHT dht_;

public:
  DHT_Sensor(char type, char pin);
  void updateValue();
  void setValue();
};

#endif