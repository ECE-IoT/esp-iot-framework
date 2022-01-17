#include "LPS25.h"

void ESPLPS25::setup()
{
  lps25             = new Adafruit_LPS25;
  this->temperature = new EspTemperatureSensor(-50, 100, "1");
  this->pressure    = new EspPressureSensor(260, 1260, "1");
  lps25->begin_I2C();
}

void ESPLPS25::setValue()
{
  temperature->setValue(lps25->get_event());
  pressure->setValue(lps25->get_event());
}

sensors_event_t temp;
sensors_event_t pressure;
lps.getEvent(&pressure, &temp);// get pressure


void ESPLPS25::update()
{
  temperature->updateMQTT();
  pressure->updateMQTT();
}