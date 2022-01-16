#include "core/config.h"
#include "core/connection_handler.h"
#include "core/mqtt.h"
#include "core/spiffs.h"
#include "core/scheduler.h"
#include "core/json.h"
#include "sensors/DHT22/DHT22.h"
#include <Arduino.h>
#include <WiFiClientSecure.h>

using EspScheduler::iotScheduler;

ESPDHT22 esp_dht22;

EspConnectionHandler esp_con_handler;
connection_states state;
EspJson esp_json;

EspMqtt* esp_mqtt;
EspConfig* esp_config;

void testPrint();

void setup()
{
  Serial.begin(9600);
  Serial.println("Start");

  //esp_mqtt = EspMqtt::getInstance();
  esp_config = EspConfig::getInstance();
  esp_config->readConfig();
  esp_con_handler.setup();
  esp_dht22.setup(25);
  Serial.println("Start loop");
}

void loop()
{
  state = esp_con_handler.runHandler();
  //Serial.println(state);
  if(state == 2)
  {
    //Serial.println("connected");
    iotScheduler(2000, testPrint);
  }
}

void testPrint()
{
  esp_dht22.setValue();
  esp_dht22.update();
}
