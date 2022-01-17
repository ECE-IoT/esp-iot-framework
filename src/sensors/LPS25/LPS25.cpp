#include "LPS25.h"

void EspLPS25::setup()
{
  lps25             = new Adafruit_LPS25;
  this->temperature = new EspTemperatureSensor(-50, 100, "1");
  this->pressure    = new EspPressureSensor(260, 1260, "1");
  lps25->begin_I2C();
}

void EspLPS25::setValue()
{
  
  lps25->getEvent(&pressure_event_, &temp_event_);// get pressure

  temperature->setValue(temp_event_.temperature);
  pressure->setValue(pressure_event_.pressure);
}

void EspLPS25::update()
{
  temperature->updateMQTT();
  pressure->updateMQTT();
}