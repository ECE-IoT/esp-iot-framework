#include "DHT22.h"

void DHT22::setup(uint8_t pin)
{
  dht22             = DHT(pin, DHT_TYPE);
  this->temperature = EspTemperatureSensor(-50, 100);
  this->humidity    = EspHumiditySensor(0, 100);
  dht22.begin();
}

void DHT22::setValue()
{
  temperature.setValue(dht22.readTemperature());
  humidity.setValue(dht22.readHumidity());
}

void DHT22::update()
{
  temperature.updateMQTT();
  humidity.updateMQTT();
}