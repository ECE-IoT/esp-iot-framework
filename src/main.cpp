#include "core/config.h"
#include "core/connection_handler.h"
#include "core/mqtt.h"
#include "core/spiffs.h"
#include "core/scheduler.h"
#include "core/json.h"
#include <Arduino.h>
#include <WiFiClientSecure.h>

using EspScheduler::iotScheduler;

EspMqtt* esp_mqtt;
EspConfig* esp_config;

EspConnectionHandler esp_con_handler;

connection_states state;

EspJson esp_json;

void testPrint();

void setup()
{
  Serial.begin(9600);
  Serial.println("Start");

  //esp_mqtt = EspMqtt::getInstance();
  esp_config = EspConfig::getInstance();
  Serial.println("11");
  esp_config->readConfig();
  Serial.println("22");
  esp_con_handler.setup();
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
  Serial.println("scheduler test");

  char* asdf = esp_json.serializeForSensor(22.21 , "°C", "test", "420");
  Serial.println(asdf);
}
