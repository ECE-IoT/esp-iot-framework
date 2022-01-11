#ifndef ESP_IOT_WIFI
#define ESP_IOT_WIFI

#include <Arduino.h>
#include <WiFi.h>
//#include <WiFiClientSecure.h>

class EspWifi
{
public:
  void beginWifi(char* wifi_ssid, char* wifi_pswd);
  void reconnectWifi();
  wl_status_t statusWifi();
};

#endif