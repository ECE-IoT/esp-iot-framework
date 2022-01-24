#include "ntp.h"

EspNTP EspNTP::esp_ntp_instance;

void EspNTP::setup(char* time_zone)
{
  NTP.setTimeZone(time_zone);
  NTP.begin();
}
uint64_t EspNTP::getValue()
{
  uint64_t seconds = NTP.millis() / 1000;
  return seconds;
}