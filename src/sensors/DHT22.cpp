#include "sensor.h"
#include "DHT22.h"

DHT22::DHT22(uint type, uint pin) : dht22(pin, type)
{
  this->temperature = new Sensor(-20, 80, 0, "°C", "temperatur", "/temp");
  this->humidity = new Sensor(0, 100, 0, "%", "humidity", "/hum");
}

void DHT_Sensor::updateValue()
{
  
}

/*
dht_.begin();
DHT_Sensor.sensor_value = dht_.readHumidity();
DHT_Sensor.sensor_value = dht_.readTemperature();
*/

 