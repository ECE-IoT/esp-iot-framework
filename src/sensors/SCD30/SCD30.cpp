#include "SCD30.h"

void EspSCD30::setup(char* id)
{
  scd30             = new Adafruit_SCD30;
  this->temperature = new EspTemperatureSensor(-50, 100, id);
  this->humidity    = new EspHumiditySensor(0, 100, id);
  this->co2         = new EspGasSensor(0, 1000000, id);
  scd30->begin();
}

void EspSCD30::setValue()
{
  scd30->read();
  temperature->setValue(scd30->temperature);
  humidity->setValue(scd30->relative_humidity);
  co2->setValue(scd30->CO2);
}

void EspSCD30::update()
{
  temperature->updateMQTT();
  humidity->updateMQTT();
  co2->updateMQTT();
}