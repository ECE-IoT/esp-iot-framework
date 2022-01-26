#ifndef ESP_IOT_DHT22
#define ESP_IOT_DHT22

#define DHT_TYPE 22

#include "../../core/component.h"
#include "../../core/physical_sensors/humidity.h"
#include "../../core/physical_sensors/temperature.h"
#include "Arduino.h"
#include <DHT.h>

struct DHT22Config
{
  uint8_t pin;
  char* id;
};

class EspDHT22 : public EspComponent<DHT22Config*>
{
private:
  DHT* dht22;
  EspTemperatureSensor* temperature;
  EspHumiditySensor* humidity;

public:
  void setValue() override;
  void update() override;
  void setup(DHT22Config* config) override;
};

#endif