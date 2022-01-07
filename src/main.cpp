#include "core/mqtt.h"
#include "core/spiffs.h"
#include <Arduino.h>
#include <WiFiClientSecure.h>

WiFiClientSecure tls_client;

const char* server        = "abc.def@xyz.com";
const char* Id            = "mein cooles esp device";
const char* sub           = "asf";
const char* pub           = "sadf";

EspMqttConfig mqtt_config = {server, Id, sub, pub, 8333, tls_client};
EspMqtt* esp_mqtt;

void setup()
{
  Serial.begin(9600);
  esp_mqtt = EspMqtt::getInstance();
  esp_mqtt->setup(mqtt_config);
}

void loop()
{
}
