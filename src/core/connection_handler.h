#ifndef ESP_CONNECTION_HANDLER
#define ESP_CONNECTION_HANDLER

#include "config.h"
#include "mqtt.h"
#include "ntp.h"
#include "wifi.h"
#include <Arduino.h>
#include <WiFiClientSecure.h>

enum connection_states
{
  CONNECT_WIFI,
  CONNECT_MQTT,
  CONNECTED
};

class EspConnectionHandler
{
private:
  EspWifi esp_wifi_;
  EspMqtt* esp_mqtt_;
  EspNTP* esp_ntp_;
  EspConfig* esp_config_;

  WiFiClientSecure tls_client_;
  bool wifi_reconnect_attempted = false;

  connection_states state_      = CONNECT_WIFI;

public:
  void setup();
  connection_states runHandler();
};

#endif