#include "illuminance.h"

EspIlluminanceSensor::EspIlluminanceSensor(int32_t lower_boundary, int32_t upper_boundary)
{
  this->lower_boundary_ = lower_boundary;
  this->upper_boundary_ = upper_boundary;
  this->unit_           = ILLUMINANCE_UNIT;
  this->sensor_type_    = ILLUMINANCE_SENSOR_TYPE;
  this->mqtt_topic_     = ILLUMINANCE_MQTT_TOPIC;
}