#ifndef ESP_IOT_PRESSURE
#define ESP_IOT_PRESSURE

#include "../sensor.h"
#include "Arduino.h"

#define PRESSURE_UNIT        "Pa"
#define PRESSURE_SENSOR_TYPE "pressure"
#define PRESSURE_MQTT_TOPIC  "/pressure"

class EspPressureSensor : public EspSensor
{
public:
  EspPressureSensor(int32_t lower_boundary, int32_t upper_boundary, char* unique_id);
};

#endif