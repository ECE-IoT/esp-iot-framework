#include "DHT22.h"

void DHT22::setup(uint8_t pin)
{
  dht22(pin, DHT_TYPE);
  
  this->temperature = new Sensor(-20, 80, 0, "°C", "temperatur", "/temp");
  this->humidity = new Sensor(0, 100, 0, "%", "humidity", "/hum");

  dht22.begin();
}

void DHT22::setValue()
{
  temperatur.value = dht22.readTemperature();
  humidity.value = dht22.readHumidity();
}

void DHT22::update()
{
  temperature.updateValue();
  humidity.updateValue();
}


 