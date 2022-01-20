#ifndef ESP_IOT_SCD30
#define ESP_IOT_SCD30

#include "../../core/component.h"
#include "../../core/physical_sensors/humidity.h"
#include "../../core/physical_sensors/temperature.h"
#include "../../core/physical_sensors/gas_concentration.h"
#include "Arduino.h"
#include <Adafruit_SCD30.h>

class EspSCD30 : public EspComponent<uint8_t>
{
private:
  Adafruit_SCD30 *scd30;
  EspTemperatureSensor *temperature;
  EspHumiditySensor *humidity;
  EspGasSensor *co2;

public:
  void setValue() override;
  void update() override;
  void setup() override;
};

#endif