#include "humidity.h"

EspHumiditySensor::EspHumiditySensor(int32_t lower_boundary, int32_t upper_boundary)
{
  this->lower_boundary_ = lower_boundary;
  this->upper_boundary_ = upper_boundary;
  this->unit_           = HUMIDITY_UNIT;
  this->sensor_type_    = HUMIDITY_SENSOR_TYPE;
  this->mqtt_topic_     = HUMIDITY_MQTT_TOPIC;
}