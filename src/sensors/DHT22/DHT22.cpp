#include "DHT22.h"

void EspDHT22::setup(uint8_t pin)
{
  dht22             = new DHT(pin, DHT_TYPE);
  this->temperature = new EspTemperatureSensor(-50, 100, "1");
  this->humidity    = new EspHumiditySensor(0, 100, "1");
  dht22->begin();
}

void EspDHT22::setValue()
{
  temperature->setValue(dht22->readTemperature());
  humidity->setValue(dht22->readHumidity());
}

void EspDHT22::update()
{
  temperature->updateMQTT();
  humidity->updateMQTT();
}