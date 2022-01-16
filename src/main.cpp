#include "core/config.h"
#include "core/connection_handler.h"
#include "core/json.h"
#include "core/mqtt.h"
#include "core/scheduler.h"
#include "core/spiffs.h"
#include "sensors/DHT22/DHT22.h"
#include <Arduino.h>
#include <WiFiClientSecure.h>

using EspScheduler::iotScheduler;

EspConnectionHandler esp_con_handler;
connection_states state;
EspJson esp_json;

ESPDHT22 esp_dht;

EspMqtt* esp_mqtt;
EspConfig* esp_config;

void testPrint();

void setup()
{
  Serial.begin(9600);
  Serial.println("Start");

  // esp_mqtt = EspMqtt::getInstance();
  esp_config = EspConfig::getInstance();
  esp_config->readConfig();
  esp_con_handler.setup();
  esp_dht.setup(25);
  Serial.println("Start loop");
}

void loop()
{
  state = esp_con_handler.runHandler();
  // Serial.println(state);
  if (state == 2)
  {
    // Serial.println("connected");
    iotScheduler(2000, testPrint);
  }
}

void testPrint()
{
  esp_dht.setValue();
  esp_dht.update();
}
