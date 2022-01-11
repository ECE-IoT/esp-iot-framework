#ifndef ESP_IOT_SENSOR
#define ESP_IOT_SENSOR

#include "component.h"
#include "mqtt.h"
#include <Arduino.h>
#include <string>

struct unit
{
};

class EspSensor : public EspComponent<unit>
{
protected:
  int32_t lower_boundary_;
  int32_t upper_boundary_;
  float current_value_;
  char* unit_;
  char* sensor_type_;
  char* mqtt_topic_;
  EspMqtt* esp_mqtt_;

public:
  EspSensor();
  void setValue(float value) override;
  void updateMQTT();
};

#endif