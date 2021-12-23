#ifndef VERT_PROT_KEYS
#define VERT_PROT_KEYS

#include <Arduino.h>
#include <SPIFFS.h>
#include "esp_spiffs.hpp"
class Keys
{
private:
  char *private_key_;
  char *device_cert_;
  char *root_ca_;
  EspSpiffs spiffs;

public:
  void begin(void);
  char *getPrivateKey();
  char *getDeviceCert();
  char *getRootCA();
};

#endif
