#include "temperature.h"

EspTemperatureSensor::EspTemperatureSensor(int32_t lower_boundary, int32_t upper_boundary, char* unique_id)
{
  this->lower_boundary_ = lower_boundary;
  this->upper_boundary_ = upper_boundary;
  this->unit_           = TEMP_UNIT;
  this->sensor_type_    = TEMP_SENSOR_TYPE;
  this->mqtt_topic_     = TEMP_MQTT_TOPIC;
  this->unique_id_      = unique_id;
}