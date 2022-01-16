#ifndef ESP_IOT_DHT22
#define ESP_IOT_DHT22

#define DHT_TYPE 22

#include "../../core/component.h"
#include "../../core/physical_sensors/humidity.h"
#include "../../core/physical_sensors/temperature.h"
#include "Arduino.h"
#include <DHT.h>

class ESPDHT22 : public EspComponent<uint8_t>
{
private:
  DHT *dht22;
  EspTemperatureSensor *temperature;
  EspHumiditySensor *humidity;

public:
  void setValue() override;
  void update() override;
  void setup(uint8_t pin) override;
};

#endif