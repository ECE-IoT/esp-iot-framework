#include "LPS25.h"

void EspLPS25::setup(char* id)
{
  lps25             = new Adafruit_LPS25;
  this->temperature = new EspTemperatureSensor(-50, 100, id);
  this->pressure    = new EspPressureSensor(260, 1260, id);
  lps25->begin_I2C();
}

void EspLPS25::setValue()
{

  lps25->getEvent(&pressure_event_, &temp_event_); // get pressure
  float temp = temp_event_.temperature;
  float prs  = pressure_event_.pressure;
  temperature->setValue(temp);
  pressure->setValue(prs);
}

void EspLPS25::update()
{
  temperature->updateMQTT();
  pressure->updateMQTT();
}