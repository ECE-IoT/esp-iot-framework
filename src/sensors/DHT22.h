#ifndef VERT_PROT_SENSOR
#define VERT_PROT_SENSOR

#include <DHT.h>
#include "Arduino.h"
#include "sensor.h"

class DHT22 : public EspComponent <void>
{
private:
  DHT dht22;

  Sensor temperature;
  Sensor humidity;
  
public:
  DHT22(uint type, uint pin);
};

#endif