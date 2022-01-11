#include "sensor.h"

Sensor::Sensor(int lower_value, int upper_value, float value, std::string unit, std::string sensor_type, std::string mqtt_topic)
{
    this->lower_value = lower_value;
    this->upper_value = upper_value;
    this->value = value;
    this->unit = unit;
    this->sensor_type = sensor_type;
    this->mqtt_topic = mqtt_topic;
}