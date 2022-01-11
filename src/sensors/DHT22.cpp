#include "sensor.h"
#include "DHT22.h"

DHT_Sensor::DHT_Sensor(char type, char pin) : dht_(pin, type)
{
  dht_ = DHT(pin, type);
}

void DHT_Sensor::updateValue()
{
  this->.updateValue();
  dht_.begin();
}

void DHT_Sensor::setValue()
{
  if (DHT_Sensor.unit == "%")
  {
    DHT_Sensor.sensor_value = dht_.readHumidity();
  }

  else
  {
    DHT_Sensor.sensor_value = dht_.readTemperature();
  }
}