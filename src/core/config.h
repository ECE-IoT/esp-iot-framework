#ifndef ESP_IOT_CONFIG
#define ESP_IOT_CONFIG

#include "spiffs.h"
#include <Arduino.h>
#include <ArduinoJson.h>

#define CONFIG_FILE "/config_file.json"

class EspConfig
{
private:
  static EspConfig esp_config_instance_;
  char* aws_url_;
  char* mqtt_pub_topic_;
  char* mqtt_sub_topic_;
  char* device_id_;
  char* wifi_ssid_;
  char* wifi_pswd_;
  char* device_position_;
  uint8_t logger_level_;
  uint8_t logger_output_;
  uint16_t aws_port_;
  EspSpiffs spiffs_;

public:
  static EspConfig* getInstance()
  {
    return &esp_config_instance_;
  }
  void readConfig();
  char* getWifiSSID();
  char* getWifiPSWD();
  char* getMqttPubTopic();
  char* getMqttSubTopic();
  char* getDeviceID();
  char* getAwsUrl();
  char* getDevicePosition();
  uint8_t getLoggerLevel();
  uint8_t getLoggerOutput();
  uint16_t getAwsPort();
};

#endif