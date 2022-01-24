#ifndef ESP_IOT_NTP
#define ESP_IOT_NTP

#include "component.h"
#include <Arduino.h>
#include <ESPNtpClient.h>

class EspNTP : public EspComponent<char*>
{
private:
  static EspNTP esp_ntp_instance;

public:
  static EspNTP* getInstance()
  {
    return &esp_ntp_instance;
  }
  void setup(char* time_zone) override;
  uint64_t getValue();
};

#endif