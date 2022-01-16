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