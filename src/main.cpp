#include "core/mqtt.h"
#include "core/spiffs.h"
#include "core/config.h"
#include <Arduino.h>
#include <WiFiClientSecure.h>
#include "core/connection_handler.h"


EspMqtt* esp_mqtt;
EspConfig* esp_config;

EspConnectionHandler esp_con_handler;
void setup()
{
  Serial.begin(9600);
  
  esp_mqtt = EspMqtt::getInstance();
  esp_config = EspConfig::getInstance();
  esp_config->readConfig();

  esp_con_handler.setup();

}

void loop()
{
}
