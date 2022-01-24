#include "config.h"

EspConfig EspConfig::esp_config_instance_;

void EspConfig::readConfig()
{
  spiffs_.spiffsBeginn();
  char* json_file = spiffs_.readSpiffs(CONFIG_FILE);
  DynamicJsonDocument doc(1024);
  deserializeJson(doc, json_file);

  aws_url_    = strdup(doc["aws_url"]);
  mqtt_pub_topic_ = strdup(doc["mqtt_pub_topic"]);
  mqtt_sub_topic_ = strdup(doc["mqtt_sub_topic"]);
  device_id_ = strdup(doc["device_id"]);
  wifi_ssid_  = strdup(doc["ssid"]);
  wifi_pswd_  = strdup(doc["password"]);
  aws_port_   = doc["aws_port"];
  logger_level_ = (uint8_t)doc["logger_level"];
  logger_output_ = (uint8_t)doc["logger_output"];
  device_position_ = strdup(doc["device_position"]);
}

char* EspConfig::getWifiSSID()
{
  return wifi_ssid_;
}

char* EspConfig::getWifiPSWD()
{
  return wifi_pswd_;
}

char* EspConfig::getMqttPubTopic()
{
  return mqtt_pub_topic_;
}

char* EspConfig::getAwsUrl()
{
  return aws_url_;
}

uint16_t EspConfig::getAwsPort()
{
  return aws_port_;
}

char* EspConfig::getMqttSubTopic()
{
  return mqtt_sub_topic_;
}

char* EspConfig::getDeviceID()
{
  return device_id_;
}

char* EspConfig::getDevicePosition()
{
  return device_position_;
}

uint8_t EspConfig::getLoggerLevel()
{
  return logger_level_;
}

uint8_t EspConfig::getLoggerOutput()
{
  return logger_output_;
}