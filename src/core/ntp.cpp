#include "ntp.h"

EspNTP EspNTP::esp_ntp_instance;

void EspNTP::setup(char* time_zone)
{
  NTP.setTimeZone(time_zone);
  NTP.begin();
}
char* EspNTP::getValueChar()
{
  return NTP.getTimeDateString();
}

char* EspNTP::getValue()
{
  return NTP.getTimeDateString();
}