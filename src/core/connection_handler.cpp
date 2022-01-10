#include "connection_handler.h"

EspConnectionHandler(EspWifi* wifi_pointer, EspMqtt* mqtt_pointer)
{
  esp_wifi = wifi_pointer;
  esp_mqtt = mqtt_pointer;
}