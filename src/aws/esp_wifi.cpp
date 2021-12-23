#include "esp_wifi.hpp"

EspWifi::EspWifi(char* wifi_ssid, char* wifi_pswd)
{
  ssid = wifi_ssid;
  pswd = wifi_pswd;
}

void EspWifi::beginWifi()
{
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, pswd);

  while (WiFi.status() != WL_CONNECTED)
  {
  }
}

void EspWifi::reconnectWifi()
{
  WiFi.reconnect();

  while (WiFi.status() != WL_CONNECTED)
  {
  }
}

wl_status_t EspWifi::statusWifi()
{
  return WiFi.status();
}