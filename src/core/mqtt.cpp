#include "mqtt.h"

EspMqtt EspMqtt::esp_mqtt_instance;

void EspMqtt::setup(struct EspMqttConfig configuration)
{
  this->server_adress_   = configuration.server_address;
  this->device_id_       = configuration.device_id;
  this->subscribe_topic_ = configuration.subscribe_topic;
  this->publish_topic_   = configuration.publish_topic;
  this->port_            = configuration.port;
  this->tls_client_      = configuration.tls_client;
}

template <class T> void EspMqtt::registerClient(T subscribe_callback(char* topic, char* payload))
{
  this->esp_mqtt_client.begin(this->server_adress_, this->port_, this->tls_client_);
  this->esp_mqtt_client.onMessage(subscribe_callback);
}

bool EspMqtt::connect()
{
  if (!this->esp_mqtt_client.connected())
  {
    if (this->esp_mqtt_client.connect(this->device_id_))
    {
      return true;
    }
    return false;
  }
  return true;
}

bool EspMqtt::publish(char* sub_topic, char* payload)
{
  char result_topic[100];
  strcpy(result_topic, this->publish_topic_);
  return this->esp_mqtt_client.publish((strcat(result_topic, sub_topic)), payload);
}

bool EspMqtt::subscribe(const char* sub_topic)
{
  if (!(sub_topic == NULL))
  {
    char result_topic[100];
    strcpy(result_topic, this->publish_topic_);
    return this->esp_mqtt_client.subscribe((strcat(result_topic, sub_topic)));
  }
  return this->esp_mqtt_client.subscribe(this->subscribe_topic_);
}
