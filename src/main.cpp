/**
 * CORE INPUTS
 */
#include "core/config.h"
#include "core/connection_handler.h"
#include "core/json.h"
#include "core/mqtt.h"
#include "core/scheduler.h"
#include "core/spiffs.h"
/**
 * SENSOR INPUTS
 */
#include "sensors/DHT22/DHT22.h"
#include "sensors/LPS25/LPS25.h"
#include "sensors/VEML7700/VEML7700.h"
/**
 * LIBS
 */
#include <Arduino.h>
#include <WiFiClientSecure.h>

using EspScheduler::iotScheduler;

EspConnectionHandler esp_con_handler;
connection_states state;
EspJson esp_json;

/*Sensors*/
EspDHT22 esp_dht;
EspLPS25 esp_lps25;
EspVEML7700 esp_veml;

EspMqtt* esp_mqtt;
EspConfig* esp_config;

void updateSensor();

void setup()
{
  Serial.begin(9600);

  esp_mqtt   = EspMqtt::getInstance();
  esp_config = EspConfig::getInstance();

  esp_config->readConfig();
  esp_con_handler.setup();

  esp_dht.setup(4);
  esp_veml.setup();
}

void loop()
{
  state = esp_con_handler.runHandler();
  if (state == 2)
  {
    iotScheduler(2000, updateSensor);
  }
}

void updateSensor()
{
  /**
   * READ THE SENSOR VALUE
   */
  esp_dht.setValue();
  esp_veml.setValue();
  /**
   * PUBLISH SENSOR VALUE TO AWS
   */
  esp_dht.update();
  esp_veml.update();
}
