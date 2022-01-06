#ifndef ESP_IOT_AWS
#define ESP_IOT_AWS

#include "keys.h"
#include <Arduino.h>
#include <WiFiClientSecure.h>
#include <mqtt_client.h>

class AWS
{
private:
  WiFiClientSecure tls_client = WiFiClientSecure();
  Keys keys;
  char* dev_name;

  void configureTLSClient(void);

public:
  void begin(char endpoint[], uint16_t port, char device_name[]);
};

#endif