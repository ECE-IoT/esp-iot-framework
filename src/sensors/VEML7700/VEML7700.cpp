#include "VEML7700.h"

void EspVEML7700::setup()
{
  veml = new Adafruit_VEML7700();
  this->illuminance = new EspIlluminanceSensor(0, 100, "3"); // TODO set borders
  veml->begin();
  veml->setGain(VEML7700_GAIN_1); // TODO choose gain and integration time
  veml->setIntegrationTime(VEML7700_IT_800MS);

  veml->setLowThreshold(LOW_THRESHOLD);
  veml->setHighThreshold(HIGH_THRESHOLD);
  veml->interruptEnable(false);
}

void EspVEML7700::setValue()
{
  illuminance->setValue(veml->readLux());

}

void EspVEML7700::update()
{
  illuminance->updateMQTT();

}