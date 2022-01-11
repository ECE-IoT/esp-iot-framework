#include "wifi.h"

void EspWifi::beginWifi(char* wifi_ssid, char* wifi_pswd)
{
  WiFi.mode(WIFI_STA);
  WiFi.begin(wifi_ssid, wifi_pswd);
}

void EspWifi::reconnectWifi()
{
  WiFi.reconnect();
}

wl_status_t EspWifi::statusWifi()
{
  return WiFi.status();
}