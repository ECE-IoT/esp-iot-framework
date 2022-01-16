#include "json.h"

EspJson::EspJson()
{
  esp_config_ = EspConfig::getInstance();
  esp_ntp_    = EspNTP::getInstance();
}

char* EspJson::serializeForSensor(float value, char* unit, char* sensor_type, char* unique_sensor_id)
{
  StaticJsonDocument<300> json_document;
  //char json_buffer[300];
  
  json_document["MAC_ADRESS"]       = WiFi.macAddress();
  json_document["DEVICE_NAME"]      = esp_config_->getDeviceID();
  json_document["SENSOR_TYPE"]      = sensor_type;
  json_document["UNIQUE_SENSOR_ID"] = unique_sensor_id;
  json_document["VALUE"]            = value;
  json_document["UNIT"]             = unit;
  json_document["TIME"]             = esp_ntp_->getValue();
  serializeJson(json_document, json_buffer, 300);
  return json_buffer;
}