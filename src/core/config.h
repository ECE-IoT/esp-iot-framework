#ifndef ESP_IOT_CONFIG
#define ESP_IOT_CONFIG

#include "spiffs.h"
#include <Arduino.h>
#include <ArduinoJson.h>

#define CONFIG_FILE "/config_file.json"

class EspConfig
{
private:
  char* aws_url;
  char* mqtt_topic;
  char* wifi_ssid;
  char* wifi_pswd;
  int aws_port;
  EspSpiffs spiffs;

public:
  EspConfig();
  char* getWifiSSID();
  char* getWifiPWSD();
  char* getMqttTopic();
  char* getAwsUrl();
  int getAwsPort();
};

#endif