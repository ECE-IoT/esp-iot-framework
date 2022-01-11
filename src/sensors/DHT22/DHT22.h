#ifndef ESP_IOT_DHT22
#define ESP_IOT_DHT22
#define DHT_TYPE 22

#include <DHT.h>
#include "Arduino.h"
#include "../sensor.h"

class DHT22 : public EspComponent <uint8_t>
{
private:
  DHT dht22;

  Sensor temperature;
  Sensor humidity;
  
public:
  
  void setValue() override;
  void update() override;
  void setup(uint8_t pin) override;

};

#endif