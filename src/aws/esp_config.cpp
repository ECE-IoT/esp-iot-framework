#include "esp_config.hpp"

EspConfig::EspConfig()
{
  spiffs.spiffsBeginn();
  char* json_file = spiffs.readSpiffs(CONFIG_FILE);
  DynamicJsonDocument doc(1024);
  deserializeJson(doc, json_file);

  aws_url = strdup(doc["aws_url"]);
  mqtt_topic = strdup(doc["mqtt_topic"]);
  wifi_ssid = strdup(doc["ssid"]);
  wifi_pswd = strdup(doc["password"]);
  aws_port = doc["aws_port"];
}

char* EspConfig::getWifiSSID()
{
  return wifi_ssid;
}

char* EspConfig::getWifiPWSD()
{
  return wifi_pswd;
}

char* EspConfig::getMqttTopic()
{
  return mqtt_topic;
}

char* EspConfig::getAwsUrl()
{
  return aws_url;
}

int EspConfig::getAwsPort()
{
  return aws_port;
}