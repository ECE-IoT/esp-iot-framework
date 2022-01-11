#include "gas_concentration.h"

EspGasSensor::EspGasSensor(int32_t lower_boundary, int32_t upper_boundary)
{
  this->lower_boundary_ = lower_boundary;
  this->upper_boundary_ = upper_boundary;
  this->unit_           = GAS_UNIT;
  this->sensor_type_    = GAS_SENSOR_TYPE;
  this->mqtt_topic_     = GAS_MQTT_TOPIC;
}