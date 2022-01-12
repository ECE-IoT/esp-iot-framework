#ifndef ESP_IOT_SENSOR
#define ESP_IOT_SENSOR

#include "component.h"
#include "json.h"
#include "mqtt.h"
#include <Arduino.h>
#include <string>

class EspSensor : public EspComponent<empty_unit>
{
protected:
  int32_t lower_boundary_;
  int32_t upper_boundary_;
  float current_value_;
  char* unit_;
  char* sensor_type_;
  char* mqtt_topic_;
  char* unique_id_;
  EspMqtt* esp_mqtt_;
  EspJson esp_json_;

public:
  EspSensor();
  void setValue(float value) override;
  void updateMQTT();
};

#endif