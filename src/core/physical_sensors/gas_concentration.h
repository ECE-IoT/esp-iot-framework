#ifndef ESP_IOT_GAS
#define ESP_IOT_GAS

#include "../sensor.h"
#include "Arduino.h"

#define GAS_UNIT        "ppm"
#define GAS_SENSOR_TYPE "gas"
#define GAS_MQTT_TOPIC  "/gas_concentrations"

class EspGasSensor : public EspSensor
{
public:
  EspGasSensor(int32_t lower_boundary, int32_t upper_boundary);
};

#endif