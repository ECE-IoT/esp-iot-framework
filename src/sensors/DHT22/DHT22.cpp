#include "DHT22.h"

void EspDHT22::setup(DHT22Config* config)
{
  dht22             = new DHT(config->pin, DHT_TYPE);
  this->temperature = new EspTemperatureSensor(-50, 100, config->id);
  this->humidity    = new EspHumiditySensor(0, 100, config->id);
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