#ifndef ESP_IOT_ILLUMINANCE
#define ESP_IOT_ILLUMINANCE

#include "../sensor.h"
#include "Arduino.h"

#define ILLUMINANCE_UNIT        "lx"
#define ILLUMINANCE_SENSOR_TYPE "illuminance"
#define ILLUMINANCE_MQTT_TOPIC  "/illuminance"

class EspIlluminanceSensor : public EspSensor
{
public:
  EspIlluminanceSensor(int32_t lower_boundary, int32_t upper_boundary);
};

#endif