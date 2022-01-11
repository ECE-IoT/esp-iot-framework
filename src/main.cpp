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

sensor1 DHT22;
sensor1.value_range->lower_value = -20;
sensor1.value_range->upper_value = 80;
sensor1.sensor_unit = "°C";
sensor1.sensor_type = "temperature";
sensor1.mqtt_topic = "/temp";

sensor2 DHT22;
sensor2.value_range->lower_value = 0;
sensor2.value_range->upper_value = 100;
sensor2.sensor_unit = "%";
sensor2.sensor_type = "humidity";
sensor2.mqtt_topic = "/hum";
  
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
