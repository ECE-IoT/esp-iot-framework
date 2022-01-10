#ifndef ESP_CONNECTION_HANDLER
#define ESP_CONNECTION_HANDLER

#include <Arduino.h>
#include "mqtt.h."
#include "wifi.h"

enum connection_states{CONNECT_WIFI, CONNECT_MQTT, CONNECTED};

class EspConnectionHandler
{
  private:
  EspWifi* esp_wifi;
  EspMqtt* esp_mqtt = EspMqtt::getInstance();

  connection_states state;

  public:
  EspConnectionHandler(EspWifi* wifi_pointer, EspMqtt* mqtt_pointer);
  connection_states runHandler();

  
};

#endif