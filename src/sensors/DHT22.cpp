#include "sensor.h"
#include "DHT22.h"

DHT_Sensor::DHT_Sensor(char type, char pin) : dht_(pin, type)
{
  dht_ = DHT(pin, type);
}

void DHT_Sensor::updateValue()
{
  
}

/*
dht_.begin();
DHT_Sensor.sensor_value = dht_.readHumidity();
DHT_Sensor.sensor_value = dht_.readTemperature();
*/


