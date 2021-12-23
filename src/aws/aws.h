#ifndef VERT_PROT_AWS
#define VERT_PROT_AWS

#include "keys.h"
#include <Arduino.h>
#include <MQTT.h>
#include <WiFiClientSecure.h>

class AWS
{
private:
  MQTTClient mqtt_client = MQTTClient(1024);
  WiFiClientSecure tls_client = WiFiClientSecure();
  Keys keys;
  char *dev_name;

  void configureTLSClient(void);
  void configureMQTTClient(char endpoint[], uint16_t port, char device_name[]);

public:
  void begin(char endpoint[], uint16_t port, char device_name[]);
  void publish(char topic[], const char *payload);
  void subscribe(char topic[]);
};

#endif