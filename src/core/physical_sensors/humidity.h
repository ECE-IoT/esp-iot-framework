#ifndef ESP_IOT_HUMIDITY
#define ESP_IOT_HUMIDITY

#include "../sensor.h"
#include "Arduino.h"

#define HUMIDITY_UNIT        "%"
#define HUMIDITY_SENSOR_TYPE "humidity"
#define HUMIDITY_MQTT_TOPIC  "/humidity"

class EspHumiditySensor : public EspSensor
{
public:
  EspHumiditySensor(int32_t lower_boundary, int32_t upper_boundary);
};

#endif