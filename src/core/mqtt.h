#ifndef ESP_IOT_MQTT
#define ESP_IOT_MQTT

#include "component.h"
#include <Arduino.h>
#include <MQTT.h>
#include <WiFiClientSecure.h>
#include <string>

struct EspMqttConfig
{
  const char* server_address;
  const char* device_id;
  const char* subscribe_topic;
  const char* publish_topic;
  uint16_t port;
  WiFiClientSecure tls_client;
};

class EspMqtt : public EspComponent<EspMqttConfig>
{
private:
  static EspMqtt esp_mqtt_instance;
  MQTTClient esp_mqtt_client;
  WiFiClientSecure tls_client_;
  const char* server_adress_;
  const char* device_id_;
  const char* subscribe_topic_;
  const char* publish_topic_;
  uint16_t port_;

public:
  static EspMqtt* getInstance()
  {
    return &esp_mqtt_instance;
  }
  void setup(EspMqttConfig configuration) override;
  template <class T> void registerClient(T subscribe_callback(char* topic, char* payload));
  bool connect();
  bool publish(char* sub_topic, char* payload);
  bool subscribe(const char* sub_topic = NULL);
};

#endif
