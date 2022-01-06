#ifndef ESP_IOT_KEYS
#define ESP_IOT_KEYS

#include "spiffs.h"
#include <Arduino.h>
#include <SPIFFS.h>

class Keys
{
private:
  char* private_key_;
  char* device_cert_;
  char* root_ca_;
  EspSpiffs spiffs;

public:
  void begin(void);
  char* getPrivateKey();
  char* getDeviceCert();
  char* getRootCA();
};

#endif
