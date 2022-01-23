#include "mqtt.h"

EspMqtt EspMqtt::esp_mqtt_instance;

void EspMqtt::setup(struct EspMqttConfig* configuration)
{
  esp_mqtt_instance.esp_keys.begin();

  esp_mqtt_instance.server_adress_   = configuration->server_address;
  esp_mqtt_instance.device_id_       = configuration->device_id;
  esp_mqtt_instance.subscribe_topic_ = configuration->subscribe_topic;
  esp_mqtt_instance.publish_topic_   = configuration->publish_topic;
  esp_mqtt_instance.port_            = configuration->port;

  esp_mqtt_instance.tls_client_.setCACert(esp_keys.getRootCA());
  esp_mqtt_instance.tls_client_.setPrivateKey(esp_keys.getPrivateKey());
  esp_mqtt_instance.tls_client_.setCertificate(esp_keys.getDeviceCert());

  esp_mqtt_instance.esp_mqtt_client = new MQTTClient(1024);
  esp_mqtt_instance.esp_mqtt_client->begin(this->server_adress_, this->port_, this->tls_client_);
}

template <class T> void EspMqtt::registerClient(T subscribe_callback(char* topic, char* payload))
{
  esp_mqtt_instance.esp_mqtt_client->begin(this->server_adress_, this->port_, this->tls_client_);
  esp_mqtt_instance.esp_mqtt_client->onMessage(subscribe_callback);
}

bool EspMqtt::connect()
{
  if (!esp_mqtt_instance.esp_mqtt_client->connected())
  {
    if (esp_mqtt_instance.esp_mqtt_client->connect(this->device_id_))
    {
      return true;
    }
    return false;
  }
  return true;
}

bool EspMqtt::publish(char* sub_topic, char* payload)
{
  if (sub_topic == "init")
  {
    return esp_mqtt_instance.esp_mqtt_client->publish(sub_topic, payload);
  }
  char result_topic[100];
  strcpy(result_topic, esp_mqtt_instance.publish_topic_);
  return esp_mqtt_instance.esp_mqtt_client->publish((strcat(result_topic, sub_topic)), payload);
}

bool EspMqtt::subscribe(const char* sub_topic)
{
  if (!(sub_topic == NULL))
  {
    char result_topic[100];
    strcpy(result_topic, esp_mqtt_instance.publish_topic_);
    return esp_mqtt_instance.esp_mqtt_client->subscribe((strcat(result_topic, sub_topic)));
  }
  return esp_mqtt_instance.esp_mqtt_client->subscribe(esp_mqtt_instance.subscribe_topic_);
}