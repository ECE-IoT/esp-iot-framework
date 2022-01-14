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
  char* serialized_json_message =
      this->esp_json_.serializeForSensor(this->current_value_, this->unit_, this->sensor_type_, this->unique_id_);
  this->esp_mqtt_->publish(this->mqtt_topic_, serialized_json_message);
}