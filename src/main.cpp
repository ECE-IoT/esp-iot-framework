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
#include "DHT22"

int hum_min = 0;
int hum_max = 100;

float temp_min = -20;
float temp_max = 80;

sensor1 = DHT22(value_range->temp_min, value_range->temp_max, "°C", "temperatur", "/temp");
sensor2 = DHT22(value_range->hum_min, value_range->hum_max, "%", "humidity", "/hum");
  
void setup()
{
  sensor1.updateValue();
  sensor2.updateValue();
}

void loop()
{
  value = sensor1.setValue();
  value2 = sensor2.setValue();  
}
