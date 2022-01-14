#ifndef ESP_IOT_TEMPERATURE
#define ESP_IOT_TEMPERATURE

#include "../sensor.h"
#include "Arduino.h"

#define TEMP_UNIT        "°C"
#define TEMP_SENSOR_TYPE "temperature"
#define TEMP_MQTT_TOPIC  "/temperature"

class EspTemperatureSensor : public EspSensor
{
public:
  EspTemperatureSensor(int32_t lower_boundary, int32_t upper_boundary, char* unique_id);
};

#endif