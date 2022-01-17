#ifndef ESP_IOT_LPS25
#define ESP_IOT_LPS25

#include "../../core/component.h"
#include "../../core/physical_sensors/pressure.h"
#include "../../core/physical_sensors/temperature.h"
#include "Arduino.h"
#include <Adafruit_LPS2X.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>

class ESPLPS25 : public EspComponent<uint8_t>
{
private:
  Adafruit_LPS25 *lps25;
  EspTemperatureSensor *temperature;
  EspPressureSensor *pressure;

public:
  void setValue() override;
  void update() override;
  void setup(uint8_t pin) override;
};

#endif