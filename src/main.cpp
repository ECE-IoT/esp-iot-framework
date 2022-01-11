/*#include "core/mqtt.h"
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

DHT_Sensor sensor_3 = DHT_Sensor(DHTTYPE, DHTPIN);

void setup()
{
  Serial.begin(9600);
  esp_mqtt = EspMqtt::getInstance();
  esp_mqtt->setup(mqtt_config);
}

void loop()
{
}*/


#include <Arduino.h>
#include "sensors/DHT22.h"



void setup()
{
  DHT22 my_first_dht = new DHT22(22, 5);

  sensor1.updateValue();
  sensor2.updateValue();
}

void loop()
{
  value = sensor1.setValue();
  value2 = sensor2.setValue();  
}
