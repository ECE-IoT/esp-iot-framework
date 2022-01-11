#include "core/config.h"
#include "core/connection_handler.h"
#include "core/mqtt.h"
#include "core/spiffs.h"
#include <Arduino.h>
#include <WiFiClientSecure.h>

EspMqtt* esp_mqtt;
EspConfig* esp_config;

EspConnectionHandler esp_con_handler;

connection_states state;

void setup()
{
  Serial.begin(9600);

  // esp_mqtt = EspMqtt::getInstance();
  esp_config = EspConfig::getInstance();
  esp_config->readConfig();

  esp_con_handler.setup();
}

void loop()
{
  state = esp_con_handler.runHandler();
}
