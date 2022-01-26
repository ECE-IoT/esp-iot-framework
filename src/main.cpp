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
#include "sensors/SCD30/SCD30.h"
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
EspLPS25 esp_lps25;
EspSCD30 esp_scd30;

EspMqtt* esp_mqtt;
EspConfig* esp_config;

void updateSensor();

void setup()
{
  Serial.begin(9600);

  esp_mqtt   = EspMqtt::getInstance();
  esp_config = EspConfig::getInstance();
  esp_logger = EspLogger::getInstance();
  esp_config->readConfig();
  esp_con_handler.setup();

  esp_lps25.setup("lps25_124");
  esp_scd30.setup("scd30_124");
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
  esp_lps25.setValue();
  esp_scd30.setValue();
  /**
   * PUBLISH SENSOR VALUE TO AWS
   */
  esp_lps25.update();
  esp_scd30.update();
}
