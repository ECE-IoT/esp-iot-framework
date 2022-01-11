#include "sensor.h"

EspSensor::EspSensor()
{
  this->esp_mqtt_->getInstance();
}

void EspSensor::setValue(float value)
{
  this->current_value_ = value;
}

void EspSensor::updateMQTT()
{
  // do some mqtt stuff here
}