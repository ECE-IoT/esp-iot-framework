#ifndef ESP_IOT_LPS25
#define ESP_IOT_LPS25

#include "../../core/component.h"
#include "../../core/physical_sensors/pressure.h"
#include "../../core/physical_sensors/temperature.h"
#include "Arduino.h"
#include <Adafruit_LPS2X.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>

class EspLPS25 : public EspComponent<char*>
{
private:
  Adafruit_LPS25 *lps25;
  EspTemperatureSensor *temperature;
  EspPressureSensor *pressure;
  sensors_event_t temp_event_;
  sensors_event_t pressure_event_;

public:
  void setValue() override;
  void update() override;
  void setup(char* id) override;
};

#endif