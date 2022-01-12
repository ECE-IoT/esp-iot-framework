#ifndef ESP_IOT_JSON
#define ESP_IOT_JSON

#include "config.h"
#include "ntp.h"
#include <ArduinoJson.h>
#include <WiFi.h>

class EspJson
{
private:
  EspConfig* esp_config_;
  EspNTP* esp_ntp_;

public:
  EspJson();
  char* serializeForSensor(float value, char* unit, char* senor_type, char* unique_sensor_id);
};

#endif