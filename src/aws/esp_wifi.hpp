#ifndef VERT_PROT_WIFI
#define VERT_PROT_WIFI

#include <Arduino.h>
#include <WiFiClientSecure.h>

class EspWifi
{
  private:
  char* ssid;
  char* pswd;

  public:
  EspWifi(char* wifi_ssid, char* wifi_pswd);
  void beginWifi();
  void reconnectWifi();
  wl_status_t statusWifi();
};

#endif