/**
 * CORE INPUTS
 */
#include "core/config.h"
#include "core/connection_handler.h"
#include "core/json.h"
#include "core/logger.h"
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
EspLogger* esp_logger;

/*Sensors*/
EspDHT22 esp_dht;
DHT22Config dht22_config;

EspLPS25 esp_lps25;
EspVEML7700 esp_veml;

EspMqtt* esp_mqtt;
EspConfig* esp_config;

void updateSensor();

void setup()
{
  Serial.begin(9600);

  dht22_config.pin = 25;
  dht22_config.id  = "dht22_lab124";

  esp_mqtt         = EspMqtt::getInstance();
  esp_config       = EspConfig::getInstance();
  esp_logger       = EspLogger::getInstance();
  esp_config->readConfig();
  esp_con_handler.setup();

  // esp_logger->logBegin(esp_config->getLoggerLevel(), esp_config->getLoggerOutput());
  esp_dht.setup(&dht22_config);
  esp_veml.setup("veml_lab124");
}

void loop()
{
  state = esp_con_handler.runHandler();
  if (state == 2)
  {
    iotScheduler(60000, updateSensor);
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
