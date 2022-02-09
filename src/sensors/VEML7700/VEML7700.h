#ifndef ESP_IOT_VEML7700
#define ESP_IOT_VEML7700

#include "../../core/component.h"
#include "../../core/physical_sensors/illuminance.h"
#include "Arduino.h"
#include <Adafruit_VEML7700.h>

#define HIGH_THRESHOLD 20000 // TODO find fitting threshold
#define LOW_THRESHOLD  10000

class EspVEML7700 : public EspComponent<char*>
{
private:
  Adafruit_VEML7700* veml;
  EspIlluminanceSensor* illuminance;

public:
  void setValue() override;
  void update() override;
  void setup(char* id) override;
};

#endif